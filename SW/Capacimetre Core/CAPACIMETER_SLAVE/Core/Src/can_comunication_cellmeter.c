/*
 * can_comunication_cellmeter.c
 *
 *  Created on: Nov 8, 2024
 *      Author: Carmen Unió Cruz
 */

#include "can_comunication_cellmeter.h"
#include <stdint.h>
#include "main.h"

/* ------------------------------------------------ ERRORS */
uint8_t cellA_generalerror;
uint8_t cellA_NTCOvertemperature;
uint8_t cellA_NTCUndertemperature;
uint8_t cellA_chargegeneralerror;
uint8_t cellA_thermalshutdown;
uint8_t cellA_watchdogerror;
uint8_t cellA_overvoltage;
uint8_t cellA_dischargegeneralerror;
uint8_t cellA_overcurrentrequested;
uint8_t cellA_Rovertemperature;
uint8_t cellA_overcurrent;
uint8_t cellA_undercurrent;
uint8_t cellA_undervoltage;
uint8_t cellA_temptransistor;

uint8_t cellB_generalerror;
uint8_t cellB_NTCOvertemperature;
uint8_t cellB_NTCUndertemperature;
uint8_t cellB_chargegeneralerror;
uint8_t cellB_thermalshutdown;
uint8_t cellB_watchdogerror;
uint8_t cellB_overvoltage;
uint8_t cellB_dischargegeneralerror;
uint8_t cellB_overcurrentrequested;
uint8_t cellB_Rovertemperature;
uint8_t cellB_overcurrent;
uint8_t cellB_undercurrent;
uint8_t cellB_undervoltage;
uint8_t cellB_temptransistor;


/* --------------------------------- LECTURES*/

uint16_t cellA_voltage;
uint16_t cellA_current;
uint16_t cellA_temperature;
uint16_t cellA_timer;

uint16_t cellB_voltage;
uint16_t cellB_current;
uint16_t cellB_temperature;
uint16_t cellB_timer;

/* --------------------------------- KEEP ALIVE*/

uint8_t master_keepalive;

/* --------------------------------- SLAVE CONTROL*/

uint8_t slaveX_keepalive;
uint8_t cellA_cellstate;
uint8_t cellB_cellstate;
uint16_t cellA_tempdischargesystem;
uint16_t cellB_tempdischargesystem;


/* --------------------------------- SET LECTURES*/


uint8_t cellA_setcurrentdischarge;
uint8_t cellA_setcurrentcharge = 0;
uint8_t cellA_setmaxtemperature;
uint8_t cellA_setminvoltage = 2.5;
uint8_t cellA_setmaxvoltage = 4.2;
uint8_t cellA_setcellstate;
uint8_t cellA_setlectures_recieved;


uint8_t cellB_setcurrentdischarge;
uint8_t cellB_setcurrentcharge = 0;
uint8_t cellB_setmaxtemperature;
uint8_t cellB_setminvoltage = 2.5;
uint8_t cellB_setmaxvoltage = 4.2;
uint8_t cellB_setcellstate;
uint8_t cellB_setlectures_recieved;

/* --------------------------------- RESEND LECTURES*/

uint8_t cellA_resendcurrentdischarge;
uint8_t cellA_resendcurrentcharge = 0;
uint8_t cellA_resendmaxtemperature;
uint8_t cellA_resendminvoltage = 2.5;
uint8_t cellA_resendmaxvoltage = 4.2;
uint8_t cellA_resendcellstate;


uint8_t cellB_resendcurrentdischarge;
uint8_t cellB_resendcurrentcharge = 0;
uint8_t cellB_resendmaxtemperature;
uint8_t cellB_resendminvoltage = 2.5;
uint8_t cellB_resendmaxvoltage = 4.2;
uint8_t cellB_resendcellstate;


void CAN_Filter(CAN_FilterTypeDef filtercan){
	filtercan.FilterActivation = ENABLE;          		      // This activates the filter as it is enable
	filtercan.FilterBank = 0;                                // This refers to which filter is being configured. On this case is the filter number 0
	filtercan.FilterFIFOAssignment = CAN_FILTER_FIFO0;       // Defines at which FIFO is this filter being configured to.
	filtercan.FilterIdHigh = 0x0000;                         // MSB: Most Significant Bit. When it's in 0, accepts all the messages
	filtercan.FilterIdLow = 0x0000;                          // LSB: Least Significant Bit. When it's in 0, accepts all the messages
	filtercan.FilterMaskIdHigh = 0x0000;                     // Most Significant Bit of the mask. When it's in 0, accepts all the messages
	filtercan.FilterMaskIdLow = 0x0000;                      // Least Significant Bit of the mask. When it's in 0, accepts all the messages
	filtercan.FilterMode = CAN_FILTERMODE_IDMASK;            // FilterMode: How are we filtering the incoming messages. Only the messages that coincide with the mask and the filter are accepted
	filtercan.FilterScale = CAN_FILTERSCALE_32BIT;           // Defines the Filter Scale. (use the 32 bits)
	filtercan.SlaveStartFilterBank = 14;                     // Indicates the first filter slave number. In this case it is the principal filter.
}

void CAN_TX_ERROR_SLAVEX_CACB(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader){
	uint8_t txdata[7];
	uint32_t txmailbox;
	txheader.DLC = dlc_ERROR_SLAVEX_CACB;
	txheader.StdId = (id_ERROR_SLAVEX_CACB + SLAVEX);
	txheader.RTR = CAN_RTR_DATA;
	txheader.IDE = CAN_ID_STD;

	txdata[0] |= (cellA_generalerror & 0x01) << 7;
	txdata[0] |= (cellA_NTCOvertemperature & 0x01) << 6;
	txdata[0] |= (cellA_NTCUndertemperature & 0x01) << 5;
	txdata[0] |= (cellA_chargegeneralerror & 0x01) << 4;
	txdata[0] |= (cellA_thermalshutdown & 0x01) << 3;
	txdata[0] |= (cellA_watchdogerror & 0x01) << 2;
	txdata[0] |= (cellA_overvoltage & 0x01) << 1;
	txdata[0] |= (cellA_dischargegeneralerror & 0x01);

	txdata[1] |= (cellA_overcurrentrequested & 0x01) << 7;
	txdata[1] |= (cellA_Rovertemperature & 0x01) << 6;
	txdata[1] |= (cellA_overcurrent & 0x01) << 5;
	txdata[1] |= (cellA_undercurrent & 0x01) << 4;
	txdata[1] |= (cellA_undervoltage & 0x01) << 3;
	txdata[1] |= (cellA_temptransistor & 0x01) << 2;

	txdata[2] |= (cellB_generalerror & 0x01) << 7;
	txdata[2] |= (cellB_NTCOvertemperature & 0x01) << 6;
	txdata[2] |= (cellB_NTCUndertemperature & 0x01) << 5;
	txdata[2] |= (cellB_chargegeneralerror & 0x01) << 4;
	txdata[2] |= (cellB_thermalshutdown & 0x01) << 3;
	txdata[2] |= (cellB_watchdogerror & 0x01) << 2;
	txdata[2] |= (cellB_overvoltage & 0x01) << 1;
	txdata[2] |= (cellB_dischargegeneralerror & 0x01);

	txdata[3] |= (cellB_overcurrentrequested & 0x01) << 7;
	txdata[3] |= (cellB_Rovertemperature & 0x01) << 6;
	txdata[3] |= (cellB_overcurrent & 0x01) << 5;
	txdata[3] |= (cellB_undercurrent & 0x01) << 4;
	txdata[3] |= (cellB_undervoltage & 0x01) << 3;
	txdata[3] |= (cellB_temptransistor & 0x01) << 2;

	if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
		Error_Handler();
	}
}


void CAN_TX_CELLA_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader){
	uint8_t txdata[7];
	uint32_t txmailbox;
	txheader.DLC = dlc_SLAVEX_CX_LECTURES;
	txheader.StdId = (id_SLAVEX_CX_LECTURES + CELLA);
	txheader.RTR = CAN_RTR_DATA;
	txheader.IDE = CAN_ID_STD;

	txdata[0] = cellA_voltage;
	txdata[1] = cellA_voltage << 8;
	txdata[2] = cellA_current;
	txdata[3] = cellA_current << 8;
	txdata[4] = cellA_temperature;
	txdata[5] = cellA_temperature << 8;
	txdata[6] = cellA_timer;
	txdata[7] = cellA_timer << 8;

	if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
		Error_Handler();
	}
}

void CAN_TX_CELLB_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader){
	uint8_t txdata[7];
	uint32_t txmailbox;
	txheader.DLC = dlc_SLAVEX_CX_LECTURES;
	txheader.StdId = (id_SLAVEX_CX_LECTURES + CELLB);
	txheader.RTR = CAN_RTR_DATA;
	txheader.IDE = CAN_ID_STD;

	txdata[0] = cellB_voltage;
	txdata[1] = cellB_voltage << 8;
	txdata[2] = cellB_current;
	txdata[3] = cellB_current << 8;
	txdata[4] = cellB_temperature;
	txdata[5] = cellB_temperature << 8;
	txdata[6] = cellB_timer;
	txdata[7] = cellB_timer << 8;

	if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
		Error_Handler();
	}
}

void CAN_TX_SLAVEX_CONTROL(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader){
	uint8_t txdata[7];
	uint32_t txmailbox;
	txheader.DLC = dlc_SLAVEX_CONTROL;
	txheader.StdId = (id_SLAVEX_CONTROL + SLAVEX);
	txheader.RTR = CAN_RTR_DATA;
	txheader.IDE = CAN_ID_STD;

	txdata[0] = cellB_voltage;
	txdata[1] = cellB_voltage << 8;
	txdata[2] = cellB_current;
	txdata[3] = cellB_current << 8;
	txdata[4] = cellB_temperature;
	txdata[5] = cellB_temperature << 8;
	txdata[6] = cellB_timer;
	txdata[7] = cellB_timer << 8;

	if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
		Error_Handler();
	}
}

void CAN_TX_SLAVEX_CELLA_RESEND_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader){
	uint8_t txdata[7];
	uint32_t txmailbox;
	txheader.DLC = dlc_SLAVEX_RESEND_LECTURES;
	txheader.StdId = (id_SLAVEX_RESEND_LECTURES + CELLA);
	txheader.RTR = CAN_RTR_DATA;
	txheader.IDE = CAN_ID_STD;

	txdata[0] = cellA_resendcurrentdischarge;
	txdata[1] = cellA_resendcurrentcharge;
	txdata[2] = cellA_resendmaxtemperature;
	txdata[3] = cellA_resendminvoltage;
	txdata[4] = cellA_resendmaxvoltage;
	txdata[5] = cellA_resendcellstate << 6;

	if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
		Error_Handler();
	}
}

void CAN_TX_SLAVEX_CELLB_RESEND_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader){
	uint8_t txdata[7];
	uint32_t txmailbox;
	txheader.DLC = dlc_SLAVEX_RESEND_LECTURES;
	txheader.StdId = (id_SLAVEX_RESEND_LECTURES + CELLB);
	txheader.RTR = CAN_RTR_DATA;
	txheader.IDE = CAN_ID_STD;

	txdata[0] = cellB_resendcurrentdischarge;
	txdata[1] = cellB_resendcurrentcharge;
	txdata[2] = cellB_resendmaxtemperature;
	txdata[3] = cellB_resendminvoltage;
	txdata[4] = cellB_resendmaxvoltage;
	txdata[5] = cellB_resendcellstate << 6;

	if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
		Error_Handler();
	}
}

	void errors_reset_cellA(void){

		cellA_generalerror = 0;
		cellA_NTCOvertemperature = 0;
		cellA_NTCUndertemperature = 0;
		cellA_chargegeneralerror = 0;
		cellA_thermalshutdown = 0;
		cellA_watchdogerror = 0;
		cellA_overvoltage = 0;
		cellA_dischargegeneralerror = 0;
		cellA_overcurrentrequested = 0;
		cellA_Rovertemperature = 0;
		cellA_overcurrent = 0;
		cellA_undercurrent = 0;
		cellA_undervoltage = 0;
		cellA_temptransistor = 0;
	}

	void errors_reset_cellB(void){

		cellB_generalerror = 0;
		cellB_NTCOvertemperature = 0;
		cellB_NTCUndertemperature = 0;
		cellB_chargegeneralerror = 0;
		cellB_thermalshutdown = 0;
		cellB_watchdogerror = 0;
		cellB_overvoltage = 0;
		cellB_dischargegeneralerror = 0;
		cellB_overcurrentrequested = 0;
		cellB_Rovertemperature = 0;
		cellB_overcurrent = 0;
		cellB_undercurrent = 0;
		cellB_undervoltage = 0;
		cellB_temptransistor = 0;
	}

	void comunications_manager(CAN_HandleTypeDef hcan1,
		    CAN_RxHeaderTypeDef rxheader,CAN_TxHeaderTypeDef txheader,
		    uint8_t *rxdata){

		if (HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &rxheader, rxdata) != HAL_OK)
		{
			Error_Handler();
		}

		if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
		{
			Error_Handler();
		}

	switch(rxheader.StdId){

	case id_MASTER_CONTROL:

		master_keepalive = rxdata[0];
		int msg = 1;

		switch(msg)

			case 1:

  				CAN_TX_SLAVEX_CONTROL(hcan1, txheader);
				msg ++;

			case 2:

				if(cellA_generalerror == 1 || cellB_generalerror == 1){
					CAN_TX_ERROR_SLAVEX_CACB(hcan1, txheader);
					errors_reset_cellA();
					errors_reset_cellB();
				}
				msg ++;

			case 3:

				CAN_TX_CELLA_LECTURES(hcan1, txheader);
				msg ++;

			case 4:

				CAN_TX_CELLB_LECTURES(hcan1, txheader);
				msg ++;

			case 5:

				if (cellA_setlectures_recieved == 1){
					CAN_TX_SLAVEX_CELLA_RESEND_LECTURES(hcan1, txheader);
					cellA_setlectures_recieved = 0;
				}
				msg ++;

			case 6:

				if (cellB_setlectures_recieved == 1){
					CAN_TX_SLAVEX_CELLB_RESEND_LECTURES(hcan1, txheader);
					cellB_setlectures_recieved = 0;
				}
				msg = 0;

		break;


	case (id_SLAVEX_CELLX_SET_LECTURES + CELLA):

		cellA_setcurrentdischarge = rxdata[0];
		cellA_setcurrentcharge = rxdata[1];
		cellA_setmaxtemperature = rxdata[2];
		cellA_setminvoltage = rxdata[3];
		cellA_setmaxvoltage = rxdata[4];
		cellA_setminvoltage = rxdata[5];
		cellA_setcellstate = (rxdata[6] >> 6) & 0b11;

				// Verificar que los valores son los correctos
		if (cellA_setcurrentdischarge == 4 *cellA_setminvoltage || cellA_setcurrentdischarge > 4 *cellA_setminvoltage ){

			cellA_overcurrentrequested = 1;
			cellA_generalerror = 1;
			cellA_setlectures_recieved = 1;

		} else {
			cellA_setlectures_recieved = 1;
		}

		break;

	case (id_SLAVEX_CELLX_SET_LECTURES + CELLB):

		cellB_setcurrentdischarge = rxdata[0];
		cellB_setcurrentcharge = rxdata[1];
		cellB_setmaxtemperature = rxdata[2];
		cellB_setminvoltage = rxdata[3];
		cellB_setmaxvoltage = rxdata[4];
		cellB_setminvoltage = rxdata[5];
		cellB_setcellstate = (rxdata[6] >> 6) & 0b11;

		// Verificar que los valores son los correctos
		if (cellB_setcurrentdischarge == 4 *cellB_setminvoltage || cellB_setcurrentdischarge > 4 *cellB_setminvoltage ){

			cellB_overcurrentrequested = 1;
			cellB_generalerror = 1;
			cellB_setlectures_recieved = 1;

		} else {
			cellB_setlectures_recieved = 1;
		}
		break;

	}
}

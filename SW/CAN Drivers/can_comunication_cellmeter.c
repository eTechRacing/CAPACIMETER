/*
 * can_comunication_cellmeter.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Carmen Unio Cruz
 */

#include "can_comunication_cellmeter.h"
#include "main.h"

	// las variables se han de definir en el main se ha de definir en el main
CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;
CAN_FilterTypeDef CANFilter;

//uint32_t RxMailbox = 0;
//uint8_t TxData[8];
//uint8_t RxData[8];

	void canfilter(CAN_FilterTypeDef filtercan){
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

	void CAN_TxCellErrors(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *cellerrors1_8){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_CELLERRORS;
		txheader.StdId = ID_CELLERRORS;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = cellerrors1_8[0];
		txdata[1] = cellerrors1_8[1];
		txdata[2] = cellerrors1_8[2];
		txdata[3] = cellerrors1_8[3];
		txdata[4] = cellerrors1_8[4];
		txdata[5] = cellerrors1_8[5];

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxCurrent1_4(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint16_t *currentcell1_4){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_CURRENT1_4;
		txheader.StdId = ID_CURRENT1_4;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = currentcell1_4[0];
		txdata[1] = currentcell1_4[0] << 4;
		txdata[2] = currentcell1_4[1];
		txdata[3] = currentcell1_4[1] << 4;
		txdata[4] = currentcell1_4[2];
		txdata[5] = currentcell1_4[2] << 4;
		txdata[6] = currentcell1_4[3];
		txdata[7] = currentcell1_4[3] << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxCurrent5_8(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint16_t *currentcell5_8){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_CURRENT5_8;
		txheader.StdId = ID_CURRENT5_8;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = currentcell5_8[0];
		txdata[1] = currentcell5_8[0] << 4;
		txdata[2] = currentcell5_8[1];
		txdata[3] = currentcell5_8[1] << 4;
		txdata[4] = currentcell5_8[2];
		txdata[5] = currentcell5_8[2] << 4;
		txdata[6] = currentcell5_8[3];
		txdata[7] = currentcell5_8[3] << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxTimerCell(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *timercell1_8){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_TIMERCELL;
		txheader.StdId = ID_TIMERCELL;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = timercell1_8[0];
		txdata[1] = timercell1_8[1];
		txdata[2] = timercell1_8[2];
		txdata[3] = timercell1_8[3];
		txdata[4] = timercell1_8[4];
		txdata[5] = timercell1_8[5];
		txdata[6] = timercell1_8[6];
		txdata[7] = timercell1_8[7];

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxControlCurrent(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *controlcurrent){
		/* controlcurrent array is a 3 position array where:
		 * 		--> controlcurrent[0] contains the Entrance Current
		 * 		--> controlcurrent[1] contains the Micro Current
		 * 		--> controlcurrent[2] contains the Refri Current
		*/

		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_CONTROLCURRENT;
		txheader.StdId = ID_CONTROLCURRENT;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = controlcurrent[0];
		txdata[1] = controlcurrent[1];
		txdata[2] = controlcurrent[2];

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxVoltage1_4(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint16_t *voltagecell1_4){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_VOLTAGE1_4;
		txheader.StdId = ID_VOLTAGE1_4;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = voltagecell1_4[0];
		txdata[1] = voltagecell1_4[0] << 4;
		txdata[2] = voltagecell1_4[1];
		txdata[3] = voltagecell1_4[1] << 4;
		txdata[4] = voltagecell1_4[2];
		txdata[5] = voltagecell1_4[2] << 4;
		txdata[6] = voltagecell1_4[3];
		txdata[7] = voltagecell1_4[3] << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxVoltage5_8(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *voltagecell5_8){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_VOLTAGE5_8;
		txheader.StdId = ID_VOLTAGE5_8;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = voltagecell5_8[0];
		txdata[1] = voltagecell5_8[0] << 4;
		txdata[2] = voltagecell5_8[1];
		txdata[3] = voltagecell5_8[1] << 4;
		txdata[4] = voltagecell5_8[2];
		txdata[5] = voltagecell5_8[2] << 4;
		txdata[6] = voltagecell5_8[3];
		txdata[7] = voltagecell5_8[3] << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxTemperatures(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *temperaturecell1_8){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_TEMPERATURES;
		txheader.StdId = ID_TEMPERATURES;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = temperaturecell1_8[0];
		txdata[1] = temperaturecell1_8[1];
		txdata[2] = temperaturecell1_8[2];
		txdata[3] = temperaturecell1_8[3];
		txdata[4] = temperaturecell1_8[4];
		txdata[5] = temperaturecell1_8[5];
		txdata[6] = temperaturecell1_8[6];
		txdata[7] = temperaturecell1_8[7];

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxDischargeReTemp(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *dischargeresistance1_8){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_DISCHARGERTEMP;
		txheader.StdId = ID_DISCHARGERTEMP;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = dischargeresistance1_8[0];
		txdata[1] = dischargeresistance1_8[1];
		txdata[2] = dischargeresistance1_8[2];
		txdata[3] = dischargeresistance1_8[3];
		txdata[4] = dischargeresistance1_8[4];
		txdata[5] = dischargeresistance1_8[5];
		txdata[6] = dischargeresistance1_8[6];
		txdata[7] = dischargeresistance1_8[7];

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxRPMRefri(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *RPMFan){
		/* RPMFan array is a 3 position array where:
		 * 		--> RPMFan[0] contains the RPMs of the 1st Fan
		 * 		--> RPMFan[1] contains the RPMs of the 2nd Fan
		 */
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_RPMREFRI;
		txheader.StdId = ID_RPMREFRI;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = RPMFan[0];
		txdata[1] = RPMFan[1];


		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxCellDisconnect(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t celldisconnect){
		uint8_t txdata[7];
		uint32_t txmailbox;
		txheader.DLC = DLC_CELLDISCONNECT;
		txheader.StdId = ID_CELLDISCONNECT;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = celldisconnect;


		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void rx_sorter(CAN_HandleTypeDef hcan1, CAN_RxHeaderTypeDef rxheader, uint32_t rxmailbox, uint8_t *rxdata, uint8_t *statecell1, uint8_t *statecell2, uint8_t *statecell3, uint8_t *statecell4, uint8_t *statecell5, uint8_t *statecell6, uint8_t *statecell7, uint8_t *statecell8){

		if (HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &rxheader, rxdata)){
			Error_Handler();
		}

		if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING)){
			switch(rxheader.StdId)

			case ID_CELLSSTATE:
				*statecell1 = rxdata[0];
				*statecell2 = rxdata[1];
				*statecell3 = rxdata[2];
				*statecell4 = rxdata[3];
				*statecell5 = rxdata[4];
				*statecell6 = rxdata[5];
				*statecell7 = rxdata[6];
				*statecell8 = rxdata[7];

		}

	}


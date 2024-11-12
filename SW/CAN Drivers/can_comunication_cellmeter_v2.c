/*
 * can_comunication_cellmeter_v2.c
 *
 *  Created on: Nov 8, 2024
 *      Author: Carmen Unió Cruz
 */

#include "can_comunication_cellmeter_v2.h"
#include <stdint.h>
#include "main.h"

uint32_t error_sX_cAcB[4];
uint8_t master_keepalive;

uint8_t cellA_setcurrentdischarge;
uint8_t cellA_setcurrentcharge = 0;
uint8_t cellA_setmaxtemperature;
uint8_t cellA_setminvoltage = 2.5;
uint8_t cellA_setmaxvoltage = 4.2;
uint8_t cellA_temperaturedischargesystem;
uint8_t cellA_setcellstate;
uint8_t cellA_setlectures_recieved;


uint8_t cellB_setcurrentdischarge;
uint8_t cellB_setcurrentcharge = 0;
uint8_t cellB_setmaxtemperature;
uint8_t cellB_setminvoltage = 2.5;
uint8_t cellB_setmaxvoltage = 4.2;
uint8_t cellB_temperaturedischargesystem;
uint8_t cellB_setcellstate;
uint8_t cellB_setlectures_recieved;



	void comunications_manager(CAN_HandleTypeDef hcan1,
		    CAN_RxHeaderTypeDef rxheader,
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
				// send slave keep alive
				msg ++;
			case 2:
				// send lectures cell A
				msg ++;
			case 3:
				// send lectures cell B
				msg ++;
			case 4:
				if (error_sX_cAcB[0] != 0 || error_sX_cAcB[2] != 0){
				// send errors slave x
				}
				msg ++;
			case 5:
				if (cellA_setlectures_recieved == 1){
					// re send set lectures cell A
					cellA_setlectures_recieved = 0;
				}
				msg ++;
			case 6:
				if (cellB_setlectures_recieved == 1){
					// re send set lectures cell B
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
		cellA_temperaturedischargesystem = rxdata[6];
		cellA_setcellstate = (rxdata[6] >> 6) & 0b11;

		// Verificar que los valores son los correctos
		if (cellA_setcurrentdischarge == 4 *cellA_setminvoltage || cellA_setcurrentdischarge > 4 *cellA_setminvoltage ){
			// modify errores
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
		cellB_temperaturedischargesystem = rxdata[6];
		cellB_setcellstate = (rxdata[6] >> 6) & 0b11;

		// Verificar que los valores son los correctos
		if (cellB_setcurrentdischarge == 4 *cellB_setminvoltage || cellB_setcurrentdischarge > 4 *cellB_setminvoltage ){
			// modify errores
		} else {
			cellB_setlectures_recieved = 1;
		}
		break;





	}
}

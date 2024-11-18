/*
 * can_comunication_cellmeter_v2.h
 *
 *  Created on: Nov 8, 2024
 *      Author: Carmen Unió Cruz
 */

#ifndef INC_CAN_COMUNICATION_CELLMETER_V2_H_
#define INC_CAN_COMUNICATION_CELLMETER_V2_H_

#include <stdint.h>
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_can.h"


#define SLAVE							1
#define CELLA							1
#define CELLB							2

/* ----------------------------------------------------- TX COBID */

#define id_ERROR_SLAVEX_C3C4 			0			// to obtain the ID for the actual id_ERROR_SLAVEX_CACB + SLAVE
#define id_SLAVEX_CX_LECTURES 			10			// to obtain the ID for the actual id_SLAVEX_CX_LECTURES + CELLX
#define id_SLAVEX_CONTROL 				20			// to obtain the ID for the actual id_SLAVEX_CONTROL + SLAVE

/* ----------------------------------------------------- RX COBID */

#define id_MASTER_CONTROL 				19
#define id_SLAVEX_CELLX_SET_LECTURES 	30			// to obtain the ID for the actual id_SLAVEX_CELLX_SET_LECTURES + CELL_NUM

extern uint32_t error_sX_cAcB[4];
extern uint8_t master_keepalive;


extern uint8_t cellA_setcurrentdischarge;
extern uint8_t cellA_setcurrentcharge;
extern uint8_t cellA_setmaxtemperature;
extern uint8_t cellA_setminvoltage;
extern uint8_t cellA_setmaxvoltage;
extern uint8_t cellA_temperaturedischargesystem;
extern uint8_t cellA_setcellstate;
extern uint8_t cellA_overcurrent_requested;


extern uint8_t cellB_setcurrentdischarge;
extern uint8_t cellB_setcurrentcharge;
extern uint8_t cellB_setmaxtemperature;
extern uint8_t cellB_setminvoltage;
extern uint8_t cellB_setmaxvoltage;
extern uint8_t cellB_temperaturedischargesystem;
extern uint8_t cellB_setcellstate;
extern uint8_t cellB_overcurrent_requested;

void comunications_manager(CAN_HandleTypeDef hcan1,
	    CAN_RxHeaderTypeDef rxheader,
	    uint8_t *rxdata);

#endif /* INC_CAN_COMUNICATION_CELLMETER_V2_H_ */

/*
 * can_comunication_cellmeter.h
 *
 *  Created on: Nov 8, 2024
 *      Author: Carmen Unió Cruz
 */

#ifndef INC_CAN_COMUNICATION_CELLMETER_H_
#define INC_CAN_COMUNICATION_CELLMETER_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_can.h"



#define SLAVEX							1
#define CELLA							1
#define CELLB							2

/* ----------------------------------------------------- TX COBID */

#define id_ERROR_SLAVEX_CACB 			0			// to obtain the ID for the actual id_ERROR_SLAVEX_CACB + SLAVE
#define id_SLAVEX_CX_LECTURES 			10			// to obtain the ID for the actual id_SLAVEX_CX_LECTURES + CELLX
#define id_SLAVEX_CONTROL 				20			// to obtain the ID for the actual id_SLAVEX_CONTROL + SLAVE
#define id_SLAVEX_RESEND_LECTURES		60

/* ----------------------------------------------------- RX COBID */

#define id_MASTER_CONTROL 				19
#define id_SLAVEX_CELLX_SET_LECTURES 	30			// to obtain the ID for the actual id_SLAVEX_CELLX_SET_LECTURES + CELL_NUM

/* ------------------------------------------------------ TX DLC */

#define dlc_ERROR_SLAVEX_CACB			4
#define dlc_SLAVEX_CX_LECTURES			8
#define	dlc_SLAVEX_CONTROL				4
#define dlc_SLAVEX_RESEND_LECTURES		6


/* ----------------------------------------------------- ERRORS */
extern uint8_t cellA_generalerror;
extern uint8_t cellA_NTCOvertemperature;
extern uint8_t cellA_NTCUndertemperature;
extern uint8_t cellA_chargegeneralerror;
extern uint8_t cellA_thermalshutdown;
extern uint8_t cellA_watchdogerror;
extern uint8_t cellA_overvoltage;
extern uint8_t cellA_dischargegeneralerror;
extern uint8_t cellA_overcurrentrequested;
extern uint8_t cellA_Rovertemperature;
extern uint8_t cellA_overcurrent;
extern uint8_t cellA_undercurrent;
extern uint8_t cellA_undervoltage;
extern uint8_t cellA_temptransistor;

extern uint8_t cellB_generalerror;
extern uint8_t cellB_NTCOvertemperature;
extern uint8_t cellB_NTCUndertemperature;
extern uint8_t cellB_chargegeneralerror;
extern uint8_t cellB_thermalshutdown;
extern uint8_t cellB_watchdogerror;
extern uint8_t cellB_overvoltage;
extern uint8_t cellB_dischargegeneralerror;
extern uint8_t cellB_overcurrentrequested;
extern uint8_t cellB_Rovertemperature;
extern uint8_t cellB_overcurrent;
extern uint8_t cellB_undercurrent;
extern uint8_t cellB_undervoltage;
extern uint8_t cellB_temptransistor;

/* --------------------------------- LECTURES*/

extern uint16_t cellA_voltage;
extern uint16_t cellA_current;
extern uint16_t cellA_temperature;
extern uint16_t cellA_timer;

/* --------------------------------- KEEP ALIVE*/

extern uint8_t master_keepalive;

/* --------------------------------- SLAVE CONTROL*/

extern uint8_t slaveX_keepalive;
extern uint8_t cellA_cellstate;
extern uint8_t cellB_cellstate;
extern uint16_t cellA_tempdischargesystem;
extern uint16_t cellB_tempdischargesystem;

/* --------------------------------- SET LECTURES*/

extern uint8_t cellA_setcurrentdischarge;
extern uint8_t cellA_setcurrentcharge;
extern uint8_t cellA_setmaxtemperature;
extern uint8_t cellA_setminvoltage;
extern uint8_t cellA_setmaxvoltage;
extern uint8_t cellA_setcellstate;
extern uint8_t cellA_setlectures_recieved;

extern uint8_t cellB_setcurrentdischarge;
extern uint8_t cellB_setcurrentcharge;
extern uint8_t cellB_setmaxtemperature;
extern uint8_t cellB_setminvoltage;
extern uint8_t cellB_setmaxvoltage;
extern uint8_t cellB_setcellstate;
extern uint8_t cellB_setlectures_recieved;

/* --------------------------------- RESEND LECTURES*/

extern uint8_t cellA_resendcurrentdischarge;
extern uint8_t cellA_resendcurrentcharge;
extern uint8_t cellA_resendmaxtemperature;
extern uint8_t cellA_resendminvoltage;
extern uint8_t cellA_resendmaxvoltage;
extern uint8_t cellA_resendcellstate;

extern uint8_t cellB_resendcurrentdischarge;
extern uint8_t cellB_resendcurrentcharge;
extern uint8_t cellB_resendmaxtemperature;
extern uint8_t cellB_resendminvoltage;
extern uint8_t cellB_resendmaxvoltage;
extern uint8_t cell_resendcellstate;


void CAN_Filter(CAN_FilterTypeDef filtercan);

void CAN_TX_ERROR_SLAVEX_CACB(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader);

void CAN_TX_CELLA_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader);

void CAN_TX_CELLB_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader);

void CAN_TX_SLAVEX_CONTROL(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader);

void CAN_TX_SLAVEX_CELLA_RESEND_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader);

void CAN_TX_SLAVEX_CELLB_RESEND_LECTURES(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader);

void errors_reset_cellA(void);

void errors_reset_cellB(void);

void comunications_manager(CAN_HandleTypeDef hcan1,
	    CAN_RxHeaderTypeDef rxheader,
	    uint8_t *rxdata);

#endif /* INC_CAN_COMUNICATION_CELLMETER_H_ */

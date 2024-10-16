/*
 * can_comunication_cellmeter.h
 *
 *  Created on: Sep 18, 2024
 *      Author: cunio
 */

#ifndef INC_CAN_COMUNICATION_CELLMETER_H_
#define INC_CAN_COMUNICATION_CELLMETER_H_

#include "main.h"

/*
 * 	CAN ID MESSAGE
 */

#define ID_CELLERRORS 				0x5
#define ID_CURRENT1_4 				0xA
#define ID_CURRENT5_8 				0xB
#define ID_TIMERCELL 				0xC
#define ID_CONTROLCURRENT 			0xD
#define ID_SETCHARGECURRENT1_4 		0xE
#define ID_SETCHARGECURRENT5_8 		0xF
#define ID_SETDISCHARGECURRENT1_4 	0x10
#define ID_SETDISCHARGECURRENT5_8 	0x11
#define ID_VOLTAGE1_4 				0x14
#define ID_VOLTAGE5_8 				0x15
#define ID_TEMPERATURES 			0x1E
#define ID_DISCHARGERTEMP 			0x1F
#define ID_RPMREFRI 				0x28
#define ID_REFRISTATE 				0x29
#define ID_CELLSSTATE 				0x2A
#define ID_CELLDISCONNECT 			0x2B


#define DLC_CELLERRORS 				6
#define DLC_CURRENT1_4 				8
#define DLC_CURRENT5_8 				8
#define DLC_TIMERCELL 				8
#define DLC_CONTROLCURRENT 			3
#define DLC_SETCHARGECURRENT1_4 	8
#define DLC_SETCHARGECURRENT5_8 	8
#define DLC_SETDISCHARGECURRENT1_4 	8
#define DLC_SETDISCHARGECURRENT5_8 	8
#define DLC_VOLTAGE1_4 				8
#define DLC_VOLTAGE5_8 				8
#define DLC_TEMPERATURES 			8
#define DLC_DISCHARGERTEMP 			8
#define DLC_RPMREFRI 				2
#define DLC_REFRISTATE 				1
#define DLC_CELLSSTATE 				8
#define DLC_CELLDISCONNECT 			1


	void canfilter(CAN_FilterTypeDef filtercan);
	void CAN_TxCellErrors(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *cellerrors1_8);
	void CAN_TxCurrent1_4(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint16_t *currentcell1_4);
	void CAN_TxCurrent5_8(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint16_t *currentcell5_8);
	void CAN_TxTimerCell(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *timercell1_8);
	void CAN_TxControlCurrent(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *controlcurrent);
	void CAN_TxVoltage1_4(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint16_t *voltagecell1_4);
	void CAN_TxVoltage5_8(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *voltagecell5_8);
	void CAN_TxTemperatures(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *temperaturecell1_8);
	void CAN_TxDischargeReTemp(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *dischargeresistance1_8);
	void CAN_TxRPMRefri(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *RPMFan);
	void CAN_TxCellDisconnect(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t celldisconnect);
	void rx_sorter(CAN_HandleTypeDef hcan1, CAN_RxHeaderTypeDef rxheader, uint32_t rxmailbox, uint8_t *rxdata, uint8_t *statecell1, uint8_t *statecell2, uint8_t *statecell3, uint8_t *statecell4, uint8_t *statecell5, uint8_t *statecell6, uint8_t *statecell7, uint8_t *statecell8);


#endif /* INC_CAN_COMUNICATION_CELLMETER_H_ */

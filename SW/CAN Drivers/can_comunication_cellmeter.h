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

#define ID_CURRENT1_4 0xA
#define ID_CURRENT5_8 0xB
#define ID_DISCHARGECURRENT 0xC
#define ID_CONTROLCURRENT 0xD
#define ID_VOLTAGE1_4 0x14
#define ID_VOLTAGE5_8 0x15
#define ID_TEMPERATURES 0x1E
#define ID_DISCHARGERTEMP 0x1F
#define ID_RPMREFRI 0x28
#define ID_CELLSSTATE 0x29
#define ID_CELLDISCONNECT 0x2A
#define ID_CELLERRORS 0x2B

#define DLC_CURRENT1_4 8
#define DLC_CURRENT5_8 8
#define DLC_DISCHARGECURRENT 1
#define DLC_CONTROLCURRENT 3
#define DLC_VOLTAGE1_4 8
#define DLC_VOLTAGE5_8 8
#define DLC_TEMPERATURES 8
#define DLC_DISCHARGERTEMP 8
#define DLC_RPMREFRI 2
#define DLC_CELLSSTATE 2
#define DLC_CELLDISCONNECT 1
#define DLC_CELLERRORS 3

#endif /* INC_CAN_COMUNICATION_CELLMETER_H_ */
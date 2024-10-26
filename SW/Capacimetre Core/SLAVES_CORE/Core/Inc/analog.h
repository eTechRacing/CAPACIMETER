/*
 * analog.h
 *
 *  Created on: Oct 16, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_ANALOG_H_
#define INC_ANALOG_H_

#define MIN_VOLT 4000
#define MAX_VOLT 5000

extern uint16_t OVER_VOLT[2];
extern uint16_t UNDER_VOLT[2];

void ANALOG_LEC(void);

#endif /* INC_ANALOG_H_ */

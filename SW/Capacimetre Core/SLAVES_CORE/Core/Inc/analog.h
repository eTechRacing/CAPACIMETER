/*
 * analog.h
 *
 *  Created on: Oct 16, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_ANALOG_H_
#define INC_ANALOG_H_

#include "main.h"

#define MIN_VOLT 4000
#define MAX_VOLT 5000
#define MIN_TEMP 4000
#define MAX_TEMP 5000
#define MAX_CURR 5000

extern uint16_t OVER_VOLT[2];
extern uint16_t UNDER_VOLT[2];
extern uint16_t OVER_TEMP[2];
extern uint16_t UNDER_TEMP[2];
extern uint16_t OVER_CURR[1];
extern uint16_t ADC_NTC_CURR[3];

void ANALOG_LEC(SPI_HandleTypeDef spi_channel, ADC_HandleTypeDef adc);

#endif /* INC_ANALOG_H_ */

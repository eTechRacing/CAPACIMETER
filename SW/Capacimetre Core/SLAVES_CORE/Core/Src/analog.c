/*
 * analog.c
 *
 *  Created on: Oct 16, 2024
 *      Author: e-Tech Racing
 */

#include "analog.h"
#include "stdlib.h"
#include "main.h"

uint16_t OVER_VOLT[2];
uint16_t UNDER_VOLT[2];

void ANALOG_LEC(SPI_HandleTypeDef spi_channel){
	ADC_VOLT(spi_channel);
	for(int i = 0;i <= 2;i++){
		if(VOLTATGES[i] <= MIN_VOLT){
			UNDER_VOLT[i] = 1;
		}else{
			UNDER_VOLT[i] = 0;
		}
	}
	for(int i = 0;i <= 2;i++){
		if(VOLTATGES[i] <= MAX_VOLT){
			OVER_VOLT[i] = 1;
		}else{
			OVER_VOLT[i] = 0;
		}
	}

}

/*
 * analog.c
 *
 *  Created on: Oct 16, 2024
 *      Author: e-Tech Racing
 */

#include "analog.h"
#include "stdlib.h"
#include "MCP3302.h"
#include "main.h"

uint16_t OVER_VOLT[2];
uint16_t UNDER_VOLT[2];

void ANALOG_LEC(SPI_HandleTypeDef spi_channel, ADC_HandleTypeDef adc){
	ADC_VOLT(spi_channel);
	for(int i = 0;i <= 2;i++){
		if(VOLTATGES[i] <= MIN_VOLT){
			UNDER_VOLT[i] = 1;
		}else{
			UNDER_VOLT[i] = 0;
		}
	}
	for(int i = 0;i <= 2;i++){
		if(VOLTATGES[i] >= MAX_VOLT){
			OVER_VOLT[i] = 1;
		}else{
			OVER_VOLT[i] = 0;
		}
	}
	HAL_ADC_Start(adc);
	HAL_ADC_PollForConversion(adc, 20);
	ADC_NTC_CURR = HAL_ADC_GetValue(adc);
	for(int i = 0;i <= 2;i++){
	if(ADC_NTC_CURR[i] >= MAX_TEMP){
		OVER_TEMP[i] = 1;
	}else{
		OVER_TEMP[i] = 0;
	}
	}
	for(int i = 0;i <= 2;i++){
	if(ADC_NTC_CURR[i] <= MIN_TEMP){
		UNDER_TEMP[i] = 1;
	}else{
		UNDER_TEMP[i] = 0;
	}
	}
	if(ADC_NTC_CURR[2] >= MAX_CURR){
		OVER_CURR[0] = 1;
	}else{
		OVER_CURR[0] = 0;
	}
}

/*
 * MCP3302_DRIVER.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Bernat Carnota Torres
 */

#include "MCP3302.h"
#include "stdlib.h"
#include "main.h"

void outputCS(uint8_t CS_INPUT, uint8_t CS){
	switch(CS){
	case 1:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS1_PORT, CS1_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS1_PORT, CS1_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	case 2:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS2_PORT, CS2_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS2_PORT, CS2_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	case 3:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS3_PORT, CS3_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS3_PORT, CS3_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	case 4:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	}

}

/*
 * Dif D2  D1  D0
 * 	0 	X 	0 	0 	differential CH0 = IN+
						 	 	 CH1 = IN-
	0 	X 	0 	1 	differential CH0 = IN-
						 	 	 CH1 = IN+
	0 	X 	1 	0 	differential CH2 = IN+
						 	 	 CH3 = IN-
	0 	X 	1 	1 	differential CH2 = IN-
						 	 	 CH3 = IN+
 */

void ADC_LEC(SPI_HandleTypeDef spi_channel,uint8_t *ADC_LEC, uint8_t mode){
	switch(mode){
	case 0:
		inicialitzacio[0] = inicialitzacio[0] & 0b00000000;
		inicialitzacio[1] = inicialitzacio[1] & 0b00000000;
		break;
	case 1:
		inicialitzacio[0] = inicialitzacio[0] & 0b00000000;
		inicialitzacio[1] = inicialitzacio[1] & 0b10000000;
		break;
	case 2:
		inicialitzacio[0] = inicialitzacio[0] & 0b00000001;
		inicialitzacio[1] = inicialitzacio[1] & 0b00000000;
		break;
	case 3:
		inicialitzacio[0] = inicialitzacio[0] & 0b00000001;
		inicialitzacio[1] = inicialitzacio[1] & 0b10000000;
		break;
	}
	HAL_SPI_TransmitReceive(&spi_channel, (uint8_t*)inicialitzacio, (uint8_t *)ADC_LEC, 2, HAL_MAX_DELAY);
}

int ADC_TOT(SPI_HandleTypeDef spi_channel, uint8_t ADC_SELECT){
	int voltatge = 0;
	switch(ADC_SELECT){
	case 1:
		outputCS(0, 1);
		ADC_LEC(spi_channel, ADC1_LEC, 1);
		outputCS(1, 1);
		break;
	case 2:
		outputCS(0, 1);
		ADC_LEC(spi_channel, ADC1_LEC, 3);
		outputCS(1, 1);
		break;
	case 3:
		outputCS(0, 2);
		ADC_LEC(spi_channel, ADC1_LEC, 1);
		outputCS(1, 2);
		break;
	case 4:
		outputCS(0, 2);
		ADC_LEC(spi_channel, ADC1_LEC, 3);
		outputCS(1, 2);
		break;
	case 5:
		outputCS(0, 3);
		ADC_LEC(spi_channel, ADC1_LEC, 1);
		outputCS(1, 3);
		break;
	case 6:
		outputCS(0, 3);
		ADC_LEC(spi_channel, ADC1_LEC, 3);
		outputCS(1, 3);
		break;
	case 7:
		outputCS(0, 4);
		ADC_LEC(spi_channel, ADC1_LEC, 1);
		outputCS(1, 4);
		break;
	case 8:
		outputCS(0, 4);
		ADC_LEC(spi_channel, ADC1_LEC, 3);
		outputCS(1, 4);
		break;
	}
	ADC1_LEC[1] = ADC1_LEC[1] & 0b000111111;
	ADC1_LEC[2] = ADC1_LEC[2] & 0b111111111;
	voltatge = ADC1_LEC[1] + ADC1_LEC[2];
	return voltatge;

}

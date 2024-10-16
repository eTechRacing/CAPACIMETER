/*
 * MCP3302_DRIVER.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Bernat Carnota Torres
 */

#include "MCP3302.h"
#include "stdlib.h"
#include "main.h"

uint16_t VOLTATGES[TOTAL_IC];
uint16_t CORRENT[TOTAL_IC];
uint16_t TEMPERATURA[TOTAL_IC];

void outputCS(uint8_t CS_INPUT, uint8_t SLAVE_NUM){
	switch(SLAVE_NUM){
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
	case 5:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	case 6:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	case 7:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	case 8:
		if(CS_INPUT == 1){
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_SET);			//The High state of the chip select pin is set
		}
		else{
			HAL_GPIO_WritePin(CS4_PORT, CS4_PIN, GPIO_PIN_RESET);		//The Low state of the chip select pin is set
		}
		break;
	}

}

/* MODES
 * Dif D2  D1  D0
 * 	0 	X 	0 	0 	differential CH0 = IN+
						 	 	 CH1 = IN-
	0 	X 	0 	1 	differential CH0 = IN-
						 	 	 CH1 = IN+
	0 	X 	1 	0 	differential CH2 = IN+
						 	 	 CH3 = IN-
	0 	X 	1 	1 	differential CH2 = IN-
						 	 	 CH3 = IN+
	1 	X 	0 	0 	single ended CH0
	1 	X 	0 	1 	single ended CH1
	1 	X 	1 	0 	single ended CH2
	1 	X 	1 	1 	single ended CH3

	TX[0] 0b	0	0	0	0	1	Dif	D2	D1
	TX[1] 0b	D0	0	0	0	0	0	0	0
 */

void ADC_LEC(SPI_HandleTypeDef spi_channel, uint8_t channel){
	uint8_t inicialitzacio[2] = {0b00001000, 0b00000000};
	switch(channel){
	case 1:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001000;//Diferencial CH0 = IN+ i CH1 = IN-
		inicialitzacio[1] = inicialitzacio[1] & 0b00000000;
		break;
	case 2:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001000;//Diferencial CH0 = IN- i CH1 = IN+
		inicialitzacio[1] = inicialitzacio[1] & 0b10000000;
		break;
	case 3:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001001;//Diferencial CH2 = IN- i CH3 = IN+
		inicialitzacio[1] = inicialitzacio[1] & 0b00000000;
		break;
	case 4:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001001;//Diferencial CH2 = IN+ i CH3 = IN-
		inicialitzacio[1] = inicialitzacio[1] & 0b10000000;
		break;
	case 5:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001100;//Single ended CH0
		inicialitzacio[1] = inicialitzacio[1] & 0b00000000;
		break;
	case 6:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001100;//Single ended CH1
		inicialitzacio[1] = inicialitzacio[1] & 0b10000000;
		break;
	case 7:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001101;//Single ended CH2
		inicialitzacio[1] = inicialitzacio[1] & 0b00000000;
		break;
	case 8:
		inicialitzacio[0] = inicialitzacio[0] & 0b00001101;//Single ended CH3
		inicialitzacio[1] = inicialitzacio[1] & 0b10000000;
		break;
	}
	HAL_SPI_TransmitReceive(&spi_channel, (uint8_t*)inicialitzacio, (uint8_t *)LECTURA_ADC, 2, HAL_MAX_DELAY);
}
/*
 * RX DATA
 * RX[0] = 0b	X	X	X	X	X	X	X	X
 * RX[1] = 0b	X	X	nul	SB	B11	B10	B9	B8
 * RX[2] = 0b	B7	B6	B5	B4	B3	B2	B1	B0
 */


void ADC_TOT(SPI_HandleTypeDef spi_channel){
for(int i = 0; i>TOTAL_IC;i++){
		outputCS(0, i);
		ADC_LEC(spi_channel, ADC_CHANNEL);
		LECTURA_ADC[1] = LECTURA_ADC[1] & 0b000111111;
		LECTURA_ADC[2] = LECTURA_ADC[2] & 0b111111111;
		VOLTATGES[i] = LECTURA_ADC[1] + LECTURA_ADC[2];
		ADC_LEC(spi_channel, TEMP_CHANNEL);
		LECTURA_ADC[1] = LECTURA_ADC[1] & 0b000111111;
		LECTURA_ADC[2] = LECTURA_ADC[2] & 0b111111111;
		CORRENT[i] = LECTURA_ADC[1] + LECTURA_ADC[2];
		ADC_LEC(spi_channel, CURR_CHANNEL);
		LECTURA_ADC[1] = LECTURA_ADC[1] & 0b000111111;
		LECTURA_ADC[2] = LECTURA_ADC[2] & 0b111111111;
		TEMPERATURA[i] = LECTURA_ADC[1] + LECTURA_ADC[2];
		outputCS(1, i);
	}
}

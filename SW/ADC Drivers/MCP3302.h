/*
 * MCP3302.h
 *
 *  Created on: Sep 18, 2024
 *  Author: Bernat Carnota Torres
 */

#ifndef INC_MCP3302_H_
#define INC_MCP3302_H_

#include "main.h"

#define CS1_PIN 	GPIO_PIN_6
#define CS1_PORT 	GPIOB
#define CS2_PIN 	GPIO_PIN_6
#define CS2_PORT 	GPIOB
#define CS3_PIN 	GPIO_PIN_6
#define CS3_PORT 	GPIOB
#define CS4_PIN 	GPIO_PIN_6
#define CS4_PORT 	GPIOB

extern uint8_t ADC1_LEC[3];

uint8_t inicialitzacio[2] = {0b00001000, 0b00000000};

void outputCS(uint8_t CS_INPUT, uint8_t mode);
void ADC_LEC(SPI_HandleTypeDef spi_channel,uint8_t *ADC_LEC, uint8_t mode);
int ADC_TOT(SPI_HandleTypeDef spi_channel, uint8_t ADC_SELECT);

#endif /* INC_MCP3302_H_ */

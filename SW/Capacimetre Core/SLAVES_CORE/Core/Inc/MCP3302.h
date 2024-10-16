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
#define CS5_PIN 	GPIO_PIN_6
#define CS5_PORT 	GPIOB
#define CS6_PIN 	GPIO_PIN_6
#define CS6_PORT 	GPIOB
#define CS7_PIN 	GPIO_PIN_6
#define CS7_PORT 	GPIOB
#define CS8_PIN 	GPIO_PIN_6
#define CS8_PORT 	GPIOB
#define TOTAL_IC	8
/*
 * SELECCIÓ DE CANAL 1-4 Voltatges / 5-8 Temp-Curr
 * 1 -> DIFF CH0 = IN+ i CH1 = IN-
 * 2 -> DIFF CH0 = IN- i CH1 = IN+
 * 3 -> DIFF CH2 = IN- i CH3 = IN+
 * 4 -> DIFF CH2 = IN+ i CH3 = IN-
 * 5 -> Single ended CH0
 * 6 -> Single ended CH1
 * 7 -> Single ended CH2
 * 8 -> Single ended CH3
 */
#define ADC_CHANNEL 1
#define TEMP_CHANNEL 5
#define CURR_CHANNEL 6

extern uint8_t LECTURA_ADC[3];
extern uint16_t VOLTATGES[TOTAL_IC];
extern uint16_t CORRENT[TOTAL_IC];
extern uint16_t TEMPERATURA[TOTAL_IC];


void outputCS(uint8_t CS_INPUT, uint8_t SLAVE_NUM);
void ADC_LEC(SPI_HandleTypeDef spi_channel, uint8_t channel);
void ADC_TOT(SPI_HandleTypeDef spi_channel);

#endif /* INC_MCP3302_H_ */

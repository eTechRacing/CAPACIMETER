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
#define DIFF_ADC_0_1 1
#define DIFF_ADC_2_3 4

extern uint8_t LECTURA_ADC[3];
extern uint16_t VOLTATGES[2];

void outputCS(uint8_t CS_INPUT);
void ADC_VOLT(SPI_HandleTypeDef spi_channel);
void ADC_TOT(SPI_HandleTypeDef spi_channel);

#endif /* INC_MCP3302_H_ */

/*
 * GPIOS.h
 *
 *  Created on: Dec 3, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_GPIOS_H_
#define INC_GPIOS_H_

//USER LEDS
#define U_LED_1_PORT				GPIOE
#define U_LED_1_PIN					GPIO_PIN_7
#define U_LED_2_PORT				GPIOE
#define U_LED_2_PIN					GPIO_PIN_8
#define U_LED_3_PORT				GPIOE
#define U_LED_3_PIN					GPIO_PIN_9
#define U_LED_4_PORT				GPIOE
#define U_LED_4_PIN					GPIO_PIN_10

//SLAVE ID
#define ID1_PORT					GPIOC
#define ID1_PIN						GPIO_PIN_6
#define ID2_PORT					GPIOC
#define ID2_PIN						GPIO_PIN_7
#define ID3_PORT					GPIOC
#define ID3_PIN						GPIO_PIN_8
#define ID4_PORT					GPIOC
#define ID4_PIN						GPIO_PIN_9

//RELES
#define K11_PORT					GPIOD
#define K11_PIN						GPIO_PIN_12
#define K12_PORT					GPIOD
#define K12_PIN						GPIO_PIN_13
#define K21_PORT					GPIOE
#define K21_PIN						GPIO_PIN_4
#define K22_PORT					GPIOE
#define K22_PIN						GPIO_PIN_3

void rele_K11(uint8_t ESTAT);
void rele_K12(uint8_t ESTAT);
void rele_K21(uint8_t ESTAT);
void rele_K22(uint8_t ESTAT);

#endif /* INC_GPIOS_H_ */

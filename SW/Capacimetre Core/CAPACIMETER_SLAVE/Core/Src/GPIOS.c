/*
 * GPIOS.c
 *
 *  Created on: Dec 3, 2024
 *      Author: e-Tech Racing
 */

#include "main.h"
#include "stdlib.h"
#include "GPIOS.h"

void rele_K11(uint8_t ESTAT){
	if(ESTAT == 1){
		HAL_GPIO_WritePin(K11_PORT, K11_PIN, 1);
	}else{
		HAL_GPIO_WritePin(K11_PORT, K11_PIN, 0);
	}
}

void rele_K12(uint8_t ESTAT){
	if(ESTAT == 1){
		HAL_GPIO_WritePin(K12_PORT, K12_PIN, 1);
	}else{
		HAL_GPIO_WritePin(K12_PORT, K12_PIN, 0);
	}
}

void rele_K21(uint8_t ESTAT){
	if(ESTAT == 1){
		HAL_GPIO_WritePin(K21_PORT, K21_PIN, 1);
	}else{
		HAL_GPIO_WritePin(K21_PORT, K21_PIN, 0);
	}
}

void rele_K22(uint8_t ESTAT){
	if(ESTAT == 1){
		HAL_GPIO_WritePin(K22_PORT, K22_PIN, 1);
	}else{
		HAL_GPIO_WritePin(K22_PORT, K22_PIN, 0);
	}
}

void LED1(uint8_t ESTAT){
	if(ESTAT == 1){
		  HAL_GPIO_WritePin(U_LED_1_PORT, U_LED_1_PIN, 1);
	}else{
		  HAL_GPIO_WritePin(U_LED_1_PORT, U_LED_1_PIN, 0);
	}
}

void LED2(uint8_t ESTAT){
	if(ESTAT == 1){
		  HAL_GPIO_WritePin(U_LED_2_PORT, U_LED_2_PIN, 1);
	}else{
		  HAL_GPIO_WritePin(U_LED_2_PORT, U_LED_2_PIN, 0);
	}
}

void LED3(uint8_t ESTAT){
	if(ESTAT == 1){
		  HAL_GPIO_WritePin(U_LED_3_PORT, U_LED_3_PIN, 1);
	}else{
		  HAL_GPIO_WritePin(U_LED_3_PORT, U_LED_3_PIN, 0);
	}
}

void LED4(uint8_t ESTAT){
	if(ESTAT == 1){
		  HAL_GPIO_WritePin(U_LED_4_PORT, U_LED_4_PIN, 1);
	}else{
		  HAL_GPIO_WritePin(U_LED_4_PORT, U_LED_4_PIN, 0);
	}
}

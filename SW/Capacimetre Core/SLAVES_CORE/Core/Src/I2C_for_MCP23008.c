/*
 * I2C_for_MCP23008.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Pol
 */

#include "main.h"
#include "I2C_for_MCP23008.h"

uint8_t buffer = 0;

void MPC_etr_WritePin(I2C_HandleTypeDef i2c, uint8_t gpio, uint8_t logic){ // Writes logic value to a gpio
    if (HAL_I2C_Mem_Read(&i2c, MCPAddress, MCPreg09, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout) != HAL_OK) {
        return;
    }
    if (logic == 1) {
        buffer |= (1 << gpio);
    } else {
        buffer &= ~(1 << gpio);
    }
	if (HAL_I2C_Mem_Write(&i2c, MCPAddress, MCPreg09, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout) != HAL_OK){
		return;
	}
}

uint8_t MPC_etr_ReadPin(I2C_HandleTypeDef i2c, uint8_t gpio){ // Reads a gpio
	if (HAL_I2C_Mem_Read(&i2c, MCPAddress, MCPreg09, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout) != HAL_OK){
			return 0xFF;
		}
	return (buffer >> gpio) & 0x01;
}

void MPC_etr_TogglePin(I2C_HandleTypeDef i2c, uint8_t gpio){ // Toggles a gpio
	    if (HAL_I2C_Mem_Read(&i2c, MCPAddress, MCPreg09, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout) != HAL_OK) {
	        return;
	    }
	    buffer ^= (1 << gpio);
		if (HAL_I2C_Mem_Write(&i2c, MCPAddress, MCPreg09, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout) != HAL_OK){
			return;
		}
}

void MCP_etr_init(I2C_HandleTypeDef i2c, uint8_t interrupt){ // Configures initial parameters
	buffer = 0x00 << interrupt;
	HAL_I2C_Mem_Read(&i2c, MCPAddress, MCPreg00, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout);
	HAL_I2C_Mem_Read(&i2c, MCPAddress, MCPreg02, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout);
	HAL_I2C_Mem_Read(&i2c, MCPAddress, MCPreg04, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout);

}




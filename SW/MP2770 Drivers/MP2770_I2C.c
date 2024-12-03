/*
 * MP2770_I2C.c
 *
 *  Created on: Dec 2, 2024
 *      Author: Pol Crespiera
 */

#include "main.h"
#include "MP2770_I2C.h"

uint8_t DataChip[2*27];

void MP2770_Write(I2C_HandleTypeDef i2c, uint8_t chip, uint8_t reg, uint8_t num){
	 uint8_t buffer[num];
	 for (uint8_t i = reg; i < (reg+num); i++){
		 buffer[i - reg] = DataChip[chip*27+i];
	 }
	 if (HAL_I2C_Mem_Write(&i2c, ChipAdress, reg, I2C_MEMADD_SIZE_8BIT, buffer, num, Timeout) != HAL_OK){ // Sends registers to actual slave
		 return;
	 }
}

void MP2770_Read(I2C_HandleTypeDef i2c, uint8_t chip, uint8_t reg, uint8_t num){
	 uint8_t buffer[num];
	 if (HAL_I2C_Mem_Read(&i2c, ChipAdress, reg, I2C_MEMADD_SIZE_8BIT, buffer, num, Timeout) != HAL_OK){ // Reads all desired registers
		return;
	}
	for (uint8_t i = reg; i < (reg+num); i++){
	 	DataChip[chip*27+i] = buffer[i - reg];
	}
}

void MP2770_InitConfig(I2C_HandleTypeDef i2c, uint8_t chip){
	MP2770_Read(i2c, chip, REG00h, 27);
	DataChip[chip*27+REG08h] &= 0b11111100;
	MP2770_Write(i2c, chip, REG08h, 1);
}

void MP2770_ReadSortADC(I2C_HandleTypeDef i2c, uint8_t chip, uint16_t Cell_Voltages, uint16_t Cell_Current){
	MP2770_Read(i2c, chip, REG13h, 2);
	Cell_Voltages = DataChip[chip*27+REG13h] * 0.008;
	Cell_Current = DataChip[chip*27+REG14h] * 0.004;
}

void MP2770_StartCharge(I2C_HandleTypeDef i2c, uint8_t chip){
	DataChip[chip*27+REG08h] &= 0b11111100;
	DataChip[chip*27+REG08h] |= 0b00000001;
	MP2770_Write(i2c, chip, REG08h, 1);
}

void MP2770_ReadSortFaults(I2C_HandleTypeDef i2c, uint8_t chip, uint8_t *errors){
	MP2770_Read(i2c, chip, REG0Fh, 2);
	errors[0] |= (DataChip[chip*27+REG0Fh] & 0b00000100); //Cell1_WatchdogError
	errors[0] |= (DataChip[chip*27+REG0Fh] & 0b00000010); //Cell1_EOverVoltage
}

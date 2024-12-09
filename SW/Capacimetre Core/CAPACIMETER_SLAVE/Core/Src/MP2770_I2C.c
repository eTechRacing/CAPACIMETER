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
	 uint8_t buffer[27];
	 for (uint8_t i = reg; i < (reg+num); i++){
		 buffer[i - reg] = DataChip[chip*27+i];
	 }
	 if (HAL_I2C_Mem_Write(&i2c, ChipAdress, reg, I2C_MEMADD_SIZE_8BIT, buffer, num, Timeout) != HAL_OK){ // Sends registers to actual slave
		 return;
	 }
}

void MP2770_Read(I2C_HandleTypeDef i2c, uint8_t chip, uint8_t reg, uint8_t num){
	 uint8_t buffer[27];
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

uint8_t MP2770_CheckChargeReady(I2C_HandleTypeDef i2c, uint8_t chip){
	float Vin_OV_Values[] = {6.4, 11.2, 14.0, 16.8};
	uint8_t Vin_OV_Index;
	uint8_t Faults;
	MP2770_Read(i2c, chip, REG11h, 1);
	MP2770_Read(i2c, chip, REG01h, 1);
	Vin_OV_Index = (DataChip[chip*REG01h] & 0b01100000) >> 5;

	MP2770_Read(i2c, chip, REG13h, 1);
	MP2770_Read(i2c, chip, REG0Fh, 1);
	Faults = DataChip[chip*REG0Fh] & 0b00000011;
	if (DataChip[chip*REG11h]*0.08 > 3.2 && DataChip[chip*REG11h]*0.08 < Vin_OV_Values[Vin_OV_Index] && DataChip[chip*REG11h]*0.08 > (DataChip[chip*REG13h]*0.02+0.350) && Faults == 0){
		return 1;
	} else {
		return 0;
	}
}

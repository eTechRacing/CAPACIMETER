/*
 * I2C.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Pol Crespiera
 */


#include "main.h"
#include "I2C.h"

uint8_t AllSlaves[Slaves] = {Slave1, Slave2, Slave3, Slave4, Slave5, Slave6, Slave7, Slave8};

 void mp2770_etr_ReadAllSlaves(I2C_HandleTypeDef i2c, uint8_t *data, uint8_t reg, uint8_t num){
	 uint8_t buffer[num];
	 for(uint8_t n = 0; n < Slaves; n++){
	 	uint8_t address = AllSlaves[n]; // Actual slave address
	 	if (HAL_I2C_Mem_Read(&i2c, address, reg, I2C_MEMADD_SIZE_8BIT, buffer, num, Timeout) != HAL_OK){ // Reads all desired registers
	 		return;
	 	}
	 	for (uint8_t i = reg; i < (reg+num); i++){
	 		 		data[n*27+i] = buffer[i - reg] ; // Getting all registers data
	 	}
	 }
 }

 void mp2770_etr_ReadOneSlave(I2C_HandleTypeDef i2c, uint8_t *data, uint8_t reg, uint8_t address){
	 uint8_t buffer;
	 if (HAL_I2C_Mem_Read(&i2c, address, reg, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout) != HAL_OK){
		 return;
	 }
	 for (uint8_t i = 0; i < Slaves; i++){
		 if (AllSlaves[i] == address){
			 data [i*27+reg] = buffer;
			 return;
		 }
	 }
 }

 void mp2770_etr_WriteAllSlaves(I2C_HandleTypeDef i2c, uint8_t *data, uint8_t reg, uint8_t num){
	 uint8_t buffer[num];
	 for(uint8_t n = 0; n < Slaves; n++){
		 uint8_t address = AllSlaves[n]; // Actual slave address
		 for (uint8_t i = reg; i < (reg+num); i++){
			 buffer[i - reg] = data[n*27+i]; // Getting all registers data
		 }
		 if (HAL_I2C_Mem_Write(&i2c, address, reg, I2C_MEMADD_SIZE_8BIT, buffer, num, Timeout) != HAL_OK){ // Sends registers to actual slave
			 return;
		 }
	 }
 }

 void mp2770_etr_WriteOneSlave(I2C_HandleTypeDef i2c, uint8_t *data, uint8_t reg, uint8_t address){
	 uint8_t buffer;
	 for (uint8_t i = 0; i < Slaves; i++){
		 if (AllSlaves[i] == address){
				 buffer = data [i*27+reg];
				 return;
		 }
	 }
	 if (HAL_I2C_Mem_Write(&i2c, address, reg, I2C_MEMADD_SIZE_8BIT, &buffer, 1, Timeout) != HAL_OK){
		 return;
	 }
 }

 void mp2770_etr_init(I2C_HandleTypeDef i2c, uint8_t *data){
	 for (uint8_t i = 0; i < Slaves; i++){ // Initial parameters are stored in the buffer
		 data[i*27 + REG00h] = InitREG00h;
		 data[i*27 + REG01h] = InitREG01h;
		 data[i*27 + REG02h] = InitREG02h;
		 data[i*27 + REG03h] = InitREG03h;
		 data[i*27 + REG04h] = InitREG04h; //ADC?
		 data[i*27 + REG08h] = InitREG08h;
		 data[i*27 + REG0Ah] = InitREG0Ah;
		 data[i*27 + REG0Bh] = InitREG0Bh; //WARM_ACT?
		 data[i*27 + REG0Ch] = InitREG0Ch; //MASKS
		 data[i*27 + REG0Dh] = InitREG0Dh; //MASKS
	 }
	 mp2770_etr_WriteAllSlaves(i2c, data, REG00h, 5); // The desired registers are sent to all salves
	 mp2770_etr_WriteAllSlaves(i2c, data, REG08h, 1);
	 mp2770_etr_WriteAllSlaves(i2c, data, REG0Ah, 4);
 }

 void mp2770_etr_ReadSortADC(I2C_HandleTypeDef i2c, uint8_t *data, uint8_t *VINOK_STAT, uint8_t *CHG_STAT, uint8_t *VINDPM_STAT, uint8_t *IINDPM_STAT, uint8_t *THERM_REG, uint8_t *Q2_NO_LOAD, uint16_t *VIN, uint16_t *VSYS, uint16_t *VBATT, uint16_t *IBATT, uint16_t *IQ, uint16_t *ISYS, uint16_t *NTC, uint16_t *VPMID){
	 mp2770_etr_ReadAllSlaves(i2c, data, REG04h, 1);
	 for (uint8_t j = 0; j < Slaves; j++){
			data[j*27+REG04h] |= 0B00000010;
	 }
	 mp2770_etr_WriteAllSlaves(i2c, data, REG04h, 1); // Start ADC
	 HAL_Delay(ADCTime);
	 mp2770_etr_ReadAllSlaves(i2c, data, REG0Eh, 1); // Read all ADC registers
	 mp2770_etr_ReadAllSlaves(i2c, data, REG11h, 8);
	 for (uint8_t i = 0; i < Slaves; i++){ //Sort read data
		 //REG0Eh
		 VINOK_STAT[i] = data[i*27+REG0Eh] >> 7;
		 CHG_STAT[i] = (data[i*27+REG0Eh] >> 4) & 0x07;
		 VINDPM_STAT[i] = (data[i*27+REG0Eh] >> 3) & 0x01;
		 IINDPM_STAT[i] = (data[i*27+REG0Eh] >> 2) & 0x01;
		 THERM_REG[i] = (data[i*27+REG0Eh] >> 1) & 0x01;
		 Q2_NO_LOAD[i] = data[i*27+REG0Eh] & 0x01;
		 //REG11h
		 VIN[i] = data[i*27+REG11h] * 8; //cV
		 //REG12h
		 VSYS[i] = data[i*27+REG12h] * 8; //cV
		 //REG13h
		 VBATT[i] = data[i*27+REG13h] * 2; //cV
		 //REG14h
		 IBATT[i] = data[i*27+REG14h] * 4; //cA
		 //REG15h
		 IQ[i] = data[i*27+REG15h] * 2; //cA
		 //REG16h
		 ISYS[i] = data[i*27+REG16h] * 2; //cA
		 //REG17h
		 NTC[i] = data[i*27+REG17h] * 5; //mV
		 //REG18h
		 VPMID[i] = data[i*27+REG18h] * 8; //cV

	 }
 }

 void mp2770_etr_FaultRead(I2C_HandleTypeDef i2c, uint8_t *data, uint8_t *INPUT_OV, uint8_t *INPUT_REMOVED, uint8_t *TSD_FAULT, uint8_t *WD_FAULT, uint8_t *BATT_FAULT, uint8_t *CHGTMR_FAULT, uint8_t *IN_OC, uint8_t *SYS_OC, uint8_t *BOOST_OV, uint8_t *NTC_FAULT){
	 mp2770_etr_ReadAllSlaves(i2c, data, REG0Fh, 2); // Read fault Registers
	 for (uint8_t i = 0; i < Slaves; i++){ // Sort all faults
		 //REG0Fh
		 INPUT_OV[i] = (data[i*27+REG0Fh] >> 5) & 0x01;
		 INPUT_REMOVED[i] = (data[i*27+REG0Fh] >> 4) & 0x01;
		 TSD_FAULT[i] = (data[i*27+REG0Fh] >> 3) & 0x01;
		 WD_FAULT[i] = (data[i*27+REG0Fh] >> 2) & 0x01;
		 BATT_FAULT[i] = (data[i*27+REG0Fh] >> 1) & 0x01;
		 CHGTMR_FAULT[i] = data[i*27+REG0Fh] & 0x01;
		 //REG10h
		 IN_OC[i] = (data[i*27+REG0Fh] >> 6) & 0x01;
		 SYS_OC[i] = (data[i*27+REG0Fh] >> 5) & 0x01;
		 BOOST_OV[i] = (data[i*27+REG0Fh] >> 4) & 0x01;
		 NTC_FAULT[i] = data[i*27+REG0Fh] & 0x07;
	 }
 }

 void mp2770_etr_StartOneCharge(I2C_HandleTypeDef i2c, uint8_t *data, uint8_t address){
	 mp2770_etr_ReadOneSlave(i2c, data, REG08h, address);
	 for (uint8_t i = 0; i < Slaves; i++){
		 if (AllSlaves[i] == address){
			 data [i*27+REG08h] &= 0b11111100;
			 data [i*27+REG08h] |= 0b00000001;
			 return;
		 }
	 }
	 mp2770_etr_WriteOneSlave(i2c, data, REG08h, address);
 }

 void mp2770_etr_StartAllCharge(I2C_HandleTypeDef i2c, uint8_t *data){
	 mp2770_etr_ReadAllSlaves(i2c, data, REG08h, 1);
	 for (uint8_t i = 0; i < Slaves; i++){
		 data [i*27+REG08h] &= 0b11111100;
		 data [i*27+REG08h] |= 0b00000001;
		 return;
	 }
	 mp2770_etr_WriteAllSlaves(i2c, data, REG08h, 1);
 }

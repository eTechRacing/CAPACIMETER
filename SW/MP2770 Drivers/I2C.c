/*
 * I2C.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Pol Crespiera
 */


#include "main.h"
#include "I2C.h"



 void mp2770_etr_ReadAllSlaves(I2C_HandleTypeDef *i2c, uint8_t *Rxdata, uint8_t reg, uint8_t num){
	 uint8_t buffer[num];
	 uint8_t AllSlaves[Slaves] = {Slave1, Slave2, Slave3, Slave4, Slave5, Slave6, Slave7, Slave8}; // Slaves addresses
	 for(uint8_t n = 0; n < Slaves; n++){
	 	uint8_t address = AllSlaves[n]; // Actual slave address
	 	if (HAL_I2C_Mem_Read(i2c, address, reg, I2C_MEMADD_SIZE_8BIT, buffer, num, Timeout) != HAL_OK){ // Reads all desired registers
	 		return;
	 	}
	 	for (uint8_t i = reg; i < (reg+num); i++){
	 		 		Rxdata[n*27+i] = buffer[i - reg] ; // Getting all registers data
	 	}
	 }
 }

 void mp2770_etr_WriteAllSlaves(I2C_HandleTypeDef *i2c, uint8_t Txdata[], uint8_t reg, uint8_t num){
	 uint8_t buffer[num];
	 uint8_t AllSlaves[Slaves] = {Slave1, Slave2, Slave3, Slave4, Slave5, Slave6, Slave7, Slave8}; // Slaves addresses
	 for(uint8_t n = 0; n < Slaves; n++){
		 uint8_t address = AllSlaves[n]; // Actual slave address
		 for (uint8_t i = reg; i < (reg+num); i++){
			 buffer[i - reg] = Txdata[n*27+i]; // Getting all registers data
		 }
		 if (HAL_I2C_Mem_Write(i2c, address, reg, I2C_MEMADD_SIZE_8BIT, buffer, num, Timeout) != HAL_OK){ // Sends registers to actual slave
			 return;
		 }
	 }
 }

 void mp2770_etr_init(I2C_HandleTypeDef *i2c, uint8_t *Txdata){
	 for (uint8_t i = 0; i < Slaves; i++){ // Initial parameters are stored in the buffer
		 Txdata[i*27 + REG00h] = 0b00011000;
		 Txdata[i*27 + REG01h] = 0b10101101;
		 Txdata[i*27 + REG02h] = 0b11011101;
		 Txdata[i*27 + REG03h] = 0b01100001;
		 Txdata[i*27 + REG04h] = 0b10010100; //ADC?
		 Txdata[i*27 + REG08h] = 0b00000000;
		 Txdata[i*27 + REG0Ah] = 0b01101110;
		 Txdata[i*27 + REG0Bh] = 0b00001100; //WARM_ACT?
		 Txdata[i*27 + REG0Ch] = 0b00000001; //MASKS
		 Txdata[i*27 + REG0Dh] = 0b00011000; //MASKS
	 }
	 mp2770_etr_WriteAllSlaves(i2c, Txdata, REG00h, 5); // The desired registers are sent to all salves
	 mp2770_etr_WriteAllSlaves(i2c, Txdata, REG08h, 1);
	 mp2770_etr_WriteAllSlaves(i2c, Txdata, REG0Ah, 4);
 }

 void mp2770_etr_ReadSortADC(I2C_HandleTypeDef *i2c, uint8_t *Rxdata, uint8_t *VINOK_STAT, uint8_t *CHG_STAT, uint8_t *VINDPM_STAT, uint8_t *IINDPM_STAT, uint8_t *THERM_REG, uint8_t, uint8_t *Q2_NO_LOAD, uint8_t *INPUT_OV, uint8_t *INPUT_REMOVED, uint8_t *TSD_FAULT, uint8_t *WD_FAULT, uint8_t *BATT_FAULT, uint8_t *CHGTMR_FAULT, uint8_t *IN_OC, uint8_t *SYS_OC, uint8_t *BOOST_OV, uint8_t *NTC_FAULT, uint16_t *VIN, uint16_t *VSYS, uint16_t *VBATT, uint16_t *IBATT, uint16_t *IQ, uint16_t *ISYS, uint16_t *NTC, uint16_t *VPMID){
	 mp2770_etr_ReadAllSlaves(i2c, Rxdata, REG0Eh, 11); // Read all ADC registers
	 for (uint8_t i = 0; i < Slaves; i++){ //Sort read data
		 //REG0Eh
		 VINOK_STAT[i] = Rxdata[i*27+REG0Eh] >> 7;
		 CHG_STAT[i] = (Rxdata[i*27+REG0Eh] >> 4) & 0x07;
		 VINDPM_STAT[i] = (Rxdata[i*27+REG0Eh] >> 3) & 0x01;
		 IINDPM_STAT[i] = (Rxdata[i*27+REG0Eh] >> 2) & 0x01;
		 THERM_REG[i] = (Rxdata[i*27+REG0Eh] >> 1) & 0x01;
		 Q2_NO_LOAD[i] = Rxdata[i*27+REG0Eh] & 0x01;
		 //REG0Fh
		 INPUT_OV[i] = (Rxdata[i*27+REG0Fh] >> 5) & 0x01;
		 INPUT_REMOVED[i] = (Rxdata[i*27+REG0Fh] >> 4) & 0x01;
		 TSD_FAULT[i] = (Rxdata[i*27+REG0Fh] >> 3) & 0x01;
		 WD_FAULT[i] = (Rxdata[i*27+REG0Fh] >> 2) & 0x01;
		 BATT_FAULT[i] = (Rxdata[i*27+REG0Fh] >> 1) & 0x01;
		 CHGTMR_FAULT[i] = Rxdata[i*27+REG0Fh] & 0x01;
		 //REG10h
		 IN_OC[i] = (Rxdata[i*27+REG0Fh] >> 6) & 0x01;
		 SYS_OC[i] = (Rxdata[i*27+REG0Fh] >> 5) & 0x01;
		 BOOST_OV[i] = (Rxdata[i*27+REG0Fh] >> 4) & 0x01;
		 NTC_FAULT[i] = Rxdata[i*27+REG0Fh] & 0x07;
		 //REG11h
		 VIN[i] = Rxdata[i*27+REG11h] * 8; //cV
		 //REG12h
		 VSYS[i] = Rxdata[i*27+REG12h] * 8; //cV
		 //REG13h
		 VBATT[i] = Rxdata[i*27+REG13h] * 2; //cV
		 //REG14h
		 IBATT[i] = Rxdata[i*27+REG14h] * 4; //cA
		 //REG15h
		 IQ[i] = Rxdata[i*27+REG15h] * 2; //cA
		 //REG16h
		 ISYS[i] = Rxdata[i*27+REG16h] * 2; //cA
		 //REG17h
		 NTC[i] = Rxdata[i*27+REG17h] * 5; //mV
		 //REG18h
		 VPMID[i] = Rxdata[i*27+REG18h] * 8; //cV

	 }
 }



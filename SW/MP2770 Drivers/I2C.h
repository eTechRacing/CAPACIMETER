/*
 * I2C.h
 *
 *  Created on: Aug 26, 2024
 *      Author: Pol Crespiera
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

// Parameters

#define Slaves 8
#define Timeout 10

// Slaves addresses

#define Slave1 0x00
#define Slave2 0x00
#define Slave3 0x00
#define Slave4 0x00
#define Slave5 0x00
#define Slave6 0x00
#define Slave7 0x00
#define Slave8 0x00

// Register map defines

#define REG00h 0x00 // Minimum input voltage.
#define REG01h 0x01 // Battery voltage regulation, input OVP, sense resistor, and termination current.
#define REG02h 0x02 // Fast charge current and pre-charge current.
#define REG03h 0x03 // Timers.
#define REG04h 0x04 // Battery pre-charge threshold, NTC, ADC, and thermal regulation.
#define REG05h 0x05 // Boost current limit.
#define REG06h 0x06 // Boost voltage 1.
#define REG07h 0x07 // Boost voltage 2.
#define REG08h 0x08 // Charge configuration and input current limit.
#define REG09h 0x09 // SYS load detection and discharge protection.
#define REG0Ah 0x0A // JEITA.
#define REG0Bh 0x0B // NTC action.
#define REG0Ch 0x0C // Interrupt mask 1.
#define REG0Dh 0x0D // Interrupt mask 2.
#define REG0Eh 0x0E // Status.
#define REG0Fh 0x0F // Fault 1.
#define REG10h 0x10 // Fault 2.
#define REG11h 0x11 // Input voltage ADC conversion (charge mode and boost mode).
#define REG12h 0x12 // SYS voltage ADC conversion (boost mode).
#define REG13h 0x13 // Battery voltage ADC conversion (charge mode and boost mode).
#define REG14h 0x14 // Battery current ADC conversion (charge mode and boost mode).
#define REG15h 0x15 // Q1 current ADC conversion (charge mode and boost mode).
#define REG16h 0x16 // SYS current ADC conversion (boost mode).
#define REG17h 0x17 // NTC ADC conversion (charge mode and boost mode).
#define REG18h 0x18 // PMID ADC conversion (charge mode and boost mode).
#define REG19h 0x19 // IC address and boost LS-FET peak current limit.
#define REG1Ah 0x1A // OTP configuration control register.


// Functions


void mp2770_etr_ReadAllSlaves(I2C_HandleTypeDef *i2c, uint8_t *Rxdata, uint8_t reg, uint8_t num);
void mp2770_etr_WriteAllSlaves(I2C_HandleTypeDef *i2c, uint8_t Txdata[], uint8_t reg, uint8_t num);

void mp2770_etr_init(I2C_HandleTypeDef *i2c, uint8_t *Txdata);
void mp2770_etr_ReadSortADC(I2C_HandleTypeDef *i2c, uint8_t *Rxdata, uint8_t *VINOK_STAT, uint8_t *CHG_STAT, uint8_t *VINDPM_STAT, uint8_t *IINDPM_STAT, uint8_t *THERM_REG, uint8_t, uint8_t *Q2_NO_LOAD, uint8_t *INPUT_OV, uint8_t *INPUT_REMOVED, uint8_t *TSD_FAULT, uint8_t *WD_FAULT, uint8_t *BATT_FAULT, uint8_t *CHGTMR_FAULT, uint8_t *IN_OC, uint8_t *SYS_OC, uint8_t *BOOST_OV, uint8_t *NTC_FAULT, uint16_t *VIN, uint16_t *VSYS, uint16_t *VBATT, uint16_t *IBATT, uint16_t *IQ, uint16_t *ISYS, uint16_t *NTC, uint16_t *VPMID);

#endif /* INC_I2C_H_ */


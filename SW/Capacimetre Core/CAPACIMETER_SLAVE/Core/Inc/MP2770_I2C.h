/*
 * MP2770_I2C.h
 *
 *  Created on: Dec 2, 2024
 *      Author: Pol Crespiera
 */

#ifndef INC_MP2770_I2C_H_
#define INC_MP2770_I2C_H_

// Variables

extern uint8_t DataChip[2*27];

// Defines

#define ChipAdress 0x4B
#define Chip1 0
#define Chip2 1
#define Timeout 10

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

void MP2770_Write(I2C_HandleTypeDef i2c, uint8_t chip, uint8_t reg, uint8_t num);
void MP2770_Read(I2C_HandleTypeDef i2c, uint8_t slave, uint8_t reg, uint8_t num);
void MP2770_InitRead(I2C_HandleTypeDef i2c, uint8_t chip);
void MP2770_ReadSortADC(I2C_HandleTypeDef i2c, uint8_t chip, uint16_t Cell_Voltages, uint16_t Cell_Current);
void MP2770_StartCharge(I2C_HandleTypeDef i2c, uint8_t chip);
void MP2770_ReadSortFaults(I2C_HandleTypeDef i2c, uint8_t chip, uint8_t *errors);
uint8_t MP2770_CheckChargeReady(I2C_HandleTypeDef i2c, uint8_t chip);

#endif /* INC_MP2770_I2C_H_ */

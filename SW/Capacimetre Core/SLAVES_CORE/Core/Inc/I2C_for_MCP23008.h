/*
 * I2C_for_MCP23008.h
 *
 *  Created on: Sep 23, 2024
 *      Author: Pol
 */

#ifndef INC_I2C_FOR_MCP23008_H_
#define INC_I2C_FOR_MCP23008_H_

// Parameters

#define Timeout 10
extern uint8_t buffer;

// MCP Address

#define MCPAddress 0x00

// Registers

#define MCPreg00 0x00
#define MCPreg01 0x01
#define MCPreg02 0x02
#define MCPreg03 0x03
#define MCPreg04 0x04
#define MCPreg05 0x05
#define MCPreg06 0x06
#define MCPreg07 0x07
#define MCPreg08 0x08
#define MCPreg09 0x09
#define MCPreg0A 0x0A

// Initial parameters


// gpios

#define K1 0x00
#define K2 0x00
#define UserLed 0x00
#define Int 0x00

//Functions
void MPC_etr_WritePin(I2C_HandleTypeDef i2c, uint8_t gpio, uint8_t logic);
uint8_t MPC_etr_ReadPin(I2C_HandleTypeDef i2c, uint8_t gpio);
void MPC_etr_TogglePin(I2C_HandleTypeDef i2c, uint8_t gpio);
void MCP_etr_init(I2C_HandleTypeDef i2c, uint8_t interrupt);

#endif /* INC_I2C_FOR_MCP23008_H_ */

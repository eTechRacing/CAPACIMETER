/*
 * charge.h
 *
 *  Created on: Nov 17, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_CHARGE_H_
#define INC_CHARGE_H_


uint8_t CHECK_CHARGE_CYCLE_CONDITIONS(I2C_HandleTypeDef i2c, uint8_t selected_cell, uint8_t *errors, uint16_t Cell_Voltages, uint16_t Cell_Current);
void CHECK_ADC_VALUES_AND_FAULTS(I2C_HandleTypeDef i2c, uint8_t selected_cell, uint8_t *errors, uint16_t Cell_Voltages, uint16_t Cell_Current);
void SET_CHARGE_MODE_FOR_SELECTED_CELL(I2C_HandleTypeDef i2c, uint8_t selected_cell);
void SELECTED_CELL_CHARGE(I2C_HandleTypeDef i2c, SPI_HandleTypeDef spi_channel, uint8_t selected_cell, uint8_t *errors, uint16_t Cell_Voltages, uint16_t Cell_Current);

#endif /* INC_CHARGE_H_ */

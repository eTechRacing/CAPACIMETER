/*
 * charge.h
 *
 *  Created on: Nov 17, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_CHARGE_H_
#define INC_CHARGE_H_


uint8_t CHECK_CHARGE_CYCLE_CONDITIONS(uint8_t selected_cell);
void CHECK_ADC_VALUES_AND_FAULTS(uint8_t selected_cell);
void SET_CHARGE_MODE_FOR_SELECTED_CELL(uint8_t selected_cell);
void SELECTED_CELL_CHARGE(SPI_HandleTypeDef spi_channel, uint8_t selected_cell);

#endif /* INC_CHARGE_H_ */

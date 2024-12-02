/*
 * discharge.h
 *
 *  Created on: Nov 10, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_DISCHARGE_H_
#define INC_DISCHARGE_H_

extern uint8_t want_to_discharge_Cell1;
extern uint8_t want_to_discharge_Cell1;
extern uint8_t is_Cell1_discharging;
extern uint8_t is_Cell2_discharging;

void SELECTED_CELL_DISCHARGE(SPI_HandleTypeDef spi_channel, uint8_t selected_cell);
void DISCHARGE(SPI_HandleTypeDef spi_channel);
uint8_t VALUES_BETWEEN_MARGIN(uint8_t selected_cell);

#endif /* INC_DISCHARGE_H_ */

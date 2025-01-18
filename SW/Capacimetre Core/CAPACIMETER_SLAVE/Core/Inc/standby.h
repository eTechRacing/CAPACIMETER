/*
 * stand_by.h
 *
 *  Created on: Nov 17, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_STANDBY_H_
#define INC_STANDBY_H_

uint8_t CELL_PRESENCE(uint8_t cell_to_check_presence);
void SELECTED_CELL_STANDBY(SPI_HandleTypeDef spi_channel, uint8_t selected_cell);
#endif /* INC_STANDBY_H_ */

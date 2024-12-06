/*
 * state_manager.c
 *
 *  Created on: Nov 9, 2024
 *      Author: e-Tech Racing
 */
#include "MCP3302.h"
#include "stdlib.h"
#include "state_manager.h"
#include "can_comunication_cellmeter.h"
#include "standby.h"
#include "charge.h"
#include "discharge.h"
#include "main.h"

uint8_t controlcurrent [3];

void STATE_MANAGER(uint8_t *message, I2C_HandleTypeDef i2c, SPI_HandleTypeDef spi_channel, uint8_t selected_cell, uint8_t *errors, uint16_t Cell_Voltages, uint16_t Cell_Current){
	uint8_t state = message[0];
	switch (state){
		case 1://Charge request
			SELECTED_CELL_CHARGE(i2c, spi_channel, selected_cell, errors, Cell_Voltages, Cell_Current);
			break;
		case 2://Discharge request
			SELECTED_CELL_DISCHARGE(spi_channel, selected_cell);
			break;
		case 3://Standby request
			SELECTED_CELL_STANDBY(spi_channel, selected_cell);
			break;
	}
}

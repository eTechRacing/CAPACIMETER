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

void STATE_MANAGER(uint8_t *message, SPI_HandleTypeDef spi_channel, uint8_t selected_cell){
	uint8_t state = message[0];
	switch (state){
		case 1://Charge request
			SELECTED_CELL_CHARGE(spi_channel, selected_cell);
			break;
		case 2://Discharge request
			SELECTED_CELL_DISCHARGE(spi_channel, selected_cell);
			break;
		case 3://Standby request
			SELECTED_CELL_STANDBY(spi_channel, selected_cell);
			break;
	}
}

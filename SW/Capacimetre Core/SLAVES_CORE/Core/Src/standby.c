/*
 * stand_by.c
 *
 *  Created on: Nov 17, 2024
 *      Author: e-Tech Racing
 */

#include "MCP3302.h"
#include "stdlib.h"
#include "state_manager.h"
#include "can_comunication_cellmeter.h"
#include "main.h"
#include "standby.h"
#include "discharge.h"
#include "analog.h"


uint8_t CELL_PRESENCE(uint8_t cell_to_check_presence){
	uint8_t borrar = 0;
	if(cell_to_check_presence == 1){//Valorar si hi ha cel·la 1
		if(borrar == 0/*valorar presencia cel·la 1 lectura de voltatge superior a .!!!!!!!!!!!!!*/){
			return 1; //Si que hi ha cel·la
		}else{
			return 0; //No hi ha cel·la
		}
	}

	else if(cell_to_check_presence == 2){//Valorar si hi ha cel·la 1
		if(borrar == 0/*valorar presencia cel·la 1!!!!!!!!!!!*/){
			return 1; //Si que hi ha cel·la
		}else{
			return 0; //No hi ha cel·la
		}
	}
	return 0;
}

void SELECTED_CELL_STANDBY(SPI_HandleTypeDef spi_channel, uint8_t selected_cell){
	uint8_t ESTAT = 0;
	switch(ESTAT){
	case 0:
		if(CELL_PRESENCE(selected_cell) == 1){
			ESTAT = 1;
		}else{
			//Change cell state to standby........
			//SEND: state message-----------
		}
		break;
	case 1:
		//Kn1 to open position!!!!!!!!!!!!!!
		ANALOG_LEC(spi_channel);
		if(VALUES_BETWEEN_MARGIN(selected_cell) == 1){
			//SEND: value error-------------
		}else{
			//SEND: Values to comunication manger-------------
		}
		//SEND: Standby to communication manager----------
		break;

	}
}

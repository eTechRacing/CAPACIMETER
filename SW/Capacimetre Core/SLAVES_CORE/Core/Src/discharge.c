/*
 * discharge.c
 *
 *  Created on: Nov 10, 2024
 *      Author: e-Tech Racing
 */
#include "main.h"
#include "stdlib.h"
#include "analog.h"

uint8_t Cell1_Overtemperature = 0;
uint8_t Cell1_Overvoltage = 0;
uint8_t Cell1_Undervoltage = 0;
uint8_t Cell1_Overcurrent = 0;

uint8_t Cell2_Overtemperature = 0;
uint8_t Cell2_Overvoltage = 0;
uint8_t Cell2_Undervoltage = 0;
uint8_t Cell2_Overcurrent = 0;

uint8_t is_Cell1_discharging = 0;	//0 implica que no esta descarregant
uint8_t is_Cell2_discharging = 0;	//1 implica que estpa descarregaant


uint8_t VALUES_BETWEEN_MARGIN(uint8_t selected_cell){
		//UNDER_VOLT
	if(selected_cell == 1){
		if(UNDER_VOLT[0] == 1){
			Cell1_Undervoltage = 1;
		}else{
			Cell1_Undervoltage = 0;
		}
	}else{
		if(UNDER_VOLT[1] == 1){
			Cell2_Undervoltage = 1;
		}else{
			Cell2_Undervoltage = 0;
		}
	}


		//OVER_VOLT
	if(selected_cell == 1){
		if(OVER_VOLT[0] == 1){
			Cell1_Overvoltage = 1;
		}else{
			Cell1_Overvoltage = 0;
		}
	}else{
		if(OVER_VOLT[1] == 1){
			Cell2_Overvoltage = 1;
		}else{
			Cell2_Overvoltage = 0;
		}
	}

		//OVER_TEMP
	if(selected_cell == 1){
		if(OVER_TEMP[0] == 1){
			Cell1_Overtemperature = 1;
		}else{
			Cell1_Overtemperature = 0;
		}
	}else{
		if(OVER_TEMP[1] == 1){
			Cell2_Overtemperature = 1;
		}else{
			Cell2_Overtemperature = 0;
		}
	}


		//OVER_CURR
	if(selected_cell == 1){
		if(OVER_CURR[0] == 1){
			Cell1_Overcurrent = 1;
		}else{
			Cell1_Overcurrent = 0;
		}
	}else{
		if(OVER_CURR[0] == 1){
			Cell2_Overcurrent = 1;
		}else{
			Cell2_Overcurrent = 0;
		}
	}
	if((Cell1_Undervoltage = 1) || (Cell2_Undervoltage = 1) || (Cell1_Overvoltage = 1) || (Cell2_Overvoltage = 1) || (Cell1_Overtemperature = 1) || (Cell2_Overtemperature = 1) || (Cell1_Overcurrent = 1) || (Cell2_Overcurrent = 1)){
		return 1;
	}else{
		return 0;
	}
}

void DISCHARGE(SPI_HandleTypeDef spi_channel, uint8_t selected_cell){
	uint8_t Estat = 0;
	switch(Estat){
	case 0:
		ANALOG_LEC(spi_channel);
		Estat = 1;
		break;
	case 1:
		if(VALUES_BETWEEN_MARGIN(selected_cell) == 1){
			//SEND: value error-------------
			Estat = 0;
		}else{
			//SEND: Seady to discharge-------------
			Estat = 2;
		}
		break;
	case 2:
		//Set DAC output analog value.!!!!!!!!!!
		//Kn2 to discharge position!!!!!!!!!!!!
		//Kn1 to CLOSE postion!!!!!!!!!!!!
		//SEND: Discharge started message-----------
		if(selected_cell == 1){
			is_Cell1_discharging = 1;
		}
		if(selected_cell == 1){
			is_Cell2_discharging = 1;
		}
		break;
	}
}

void SELECTED_CELL_DISCHARGE(SPI_HandleTypeDef spi_channel, uint8_t selected_cell){
	if((selected_cell = 1) && (is_Cell1_discharging = 0)){
		DISCHARGE(spi_channel, selected_cell);
		is_Cell1_discharging = 1;
	}else if((selected_cell = 1) && (is_Cell1_discharging = 1)){
		//SEND:Discharge message error--------------
	}
	if((selected_cell = 2) && (is_Cell2_discharging = 0)){
		DISCHARGE(spi_channel, selected_cell);
		is_Cell2_discharging = 1;
	}else if((selected_cell = 2) && (is_Cell2_discharging = 1)){
		//SEND:Discharge message error-------------
	}
}

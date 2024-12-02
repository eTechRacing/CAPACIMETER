/*
 * charge.c
 *
 *  Created on: Nov 17, 2024
 *      Author: e-Tech Racing
 */


#include "MCP3302.h"
#include "stdlib.h"
#include "state_manager.h"
#include "can_comunication_cellmeter.h"
#include "charge.h"
#include "main.h"

uint8_t CHECK_CHARGE_CYCLE_CONDITIONS(uint8_t selected_cell){ //1 si les condicions SI son optimes/0 si les condicions NO son optimes per carregar
	uint8_t borrar = 0;
	//REG0h status.........
	//mp2770_etr_ReadOneSlave/mp2770_etr_ReadAllSlaves.......
	//mp2770_etr_FaultRead.........
	if(borrar == 0/*Condicions per considerar que les condicions son optimes per carregar!!!!!!!!!!!!*/){
		return 1;
	}else{
		return 0;
	}
}

void CHECK_ADC_VALUES_AND_FAULTS(uint8_t selected_cell){
	//mp2770_etr_FaultRead.........
	//mp2770_etr_ReadSortADC.........
}

void SET_CHARGE_MODE_FOR_SELECTED_CELL(uint8_t selected_cell){
	//mp2770_etr_StartOneCharge/mp2770_etr_StartAllCharge........
}

void SELECTED_CELL_CHARGE(SPI_HandleTypeDef spi_channel, uint8_t selected_cell){
	uint8_t ESTAT = 0;
	switch(ESTAT){
	case 0:
		 if(CHECK_CHARGE_CYCLE_CONDITIONS(selected_cell) == 1){
			 ESTAT = 1;
		 }else{
			 CHECK_ADC_VALUES_AND_FAULTS(selected_cell);
			 //SEND: error value to comunication manager----------------
		 }
		 break;
	case 1:
		//Kn2 to charge position!!!!!!!!!!
		//Kn1 to CLOSE position!!!!!!!!!!!!
		SET_CHARGE_MODE_FOR_SELECTED_CELL(selected_cell);
		//SEND: Charge started message to comunication manager---------------
		break;
	}
}

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
#include "MP2770_I2C.h"

uint8_t CHECK_CHARGE_CYCLE_CONDITIONS(I2C_HandleTypeDef i2c, uint8_t selected_cell){ //1 si les condicions SI son optimes/0 si les condicions NO son optimes per carregar
	uint8_t borrar = 0;
	MP2770_Read(i2c, selected_cell, REG00h, 1); //REG0h status......... 	//mp2770_etr_FaultRead.........
	//CHECK_ADC_VALUES_AND_FAULTS(i2c, selected_cell, &errors, &Cell_Voltages, &Cell_Current); //mp2770_etr_ReadOneSlave/mp2770_etr_ReadAllSlaves.......

	if(borrar == 0/*Condicions per considerar que les condicions son optimes per carregar!!!!!!!!!!!!*/){
		return 1;
	}else{
		return 0;
	}
}

void CHECK_ADC_VALUES_AND_FAULTS(I2C_HandleTypeDef i2c, uint8_t selected_cell, uint8_t *errors, uint16_t Cell_Voltages, uint16_t Cell_Current){
	MP2770_ReadSortFaults(i2c, selected_cell, errors);//mp2770_etr_FaultRead.........
	MP2770_ReadSortADC(i2c, selected_cell, Cell_Voltages, Cell_Current);//mp2770_etr_ReadSortADC.........
}

void SET_CHARGE_MODE_FOR_SELECTED_CELL(I2C_HandleTypeDef i2c, uint8_t selected_cell){
	MP2770_StartCharge(i2c, selected_cell); //mp2770_etr_StartOneCharge/mp2770_etr_StartAllCharge........
}

void SELECTED_CELL_CHARGE(I2C_HandleTypeDef i2c, SPI_HandleTypeDef spi_channel, uint8_t selected_cell, uint8_t *errors, uint16_t Cell_Voltages, uint16_t Cell_Current){
	uint8_t ESTAT = 0;
	switch(ESTAT){
	case 0:
		 if(CHECK_CHARGE_CYCLE_CONDITIONS(i2c, selected_cell) == 1){
			 ESTAT = 1;
		 }else{
			 CHECK_ADC_VALUES_AND_FAULTS(i2c, selected_cell, errors, Cell_Voltages, Cell_Current);
			 //SEND: error value to comunication manager----------------
		 }
		 break;
	case 1:
		//Kn2 to charge position!!!!!!!!!!
		//Kn1 to CLOSE position!!!!!!!!!!!!
		SET_CHARGE_MODE_FOR_SELECTED_CELL(i2c, selected_cell);
		//SEND: Charge started message to comunication manager---------------
		break;
	}
}

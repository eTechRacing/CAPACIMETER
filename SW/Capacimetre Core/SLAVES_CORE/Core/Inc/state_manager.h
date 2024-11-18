/*
 * state_manager.h
 *
 *  Created on: Nov 9, 2024
 *      Author: e-Tech Racing
 */

#ifndef INC_STATE_MANAGER_H_
#define INC_STATE_MANAGER_H_

#define ID_STATE_REQUEST 0x01
#define ID_CHARGE_DISCHARGE 0x02
#define ID_VOLT_TEMP_CHANGE 0x03


//CHARGE/DISCHARGE PARAMENTERS
extern uint8_t controlcurrent[3];

extern uint8_t Cell1_GeneralError;
extern uint8_t Cell1_NTCOvertemperature;
extern uint8_t Cell1_NTCUndertemperature;
extern uint8_t Cell1_ChargeGeneralError;
extern uint8_t Cell1_ThermalShutdown;
extern uint8_t Cell1_WatchdogError;
extern uint8_t Cell1_DischargeGeneralError;
extern uint8_t Cell1_OvercurrentRequested;
extern uint8_t Cell1_Overtemperature;
extern uint8_t Cell1_Overcurrent;
extern uint8_t Cell1_Undercurrent;
extern uint8_t Cell1_TempTransistor;
extern uint8_t Cell2_GeneralError;
extern uint8_t Cell2_NTCOvertemperature;
extern uint8_t Cell2_NTCUndertemperature;
extern uint8_t Cell2_ChargeGeneralError;
extern uint8_t Cell2_ThermalShutdown;
extern uint8_t Cell2_WatchdogError;
extern uint8_t Cell2_DischargeGeneralError;
extern uint8_t Cell2_OvercurrentRequested;
extern uint8_t Cell2_Overtemperature;
extern uint8_t Cell2_Overcurrent;
extern uint8_t Cell2_Undercurrent;
extern uint8_t Cell2_TempTransistor;

void STATE_MANAGER(uint8_t *message, SPI_HandleTypeDef spi_channel, uint8_t selected_cell);


#endif /* INC_STATE_MANAGER_H_ */

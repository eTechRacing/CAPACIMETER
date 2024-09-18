/*
 * can_comunication_cellmeter.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Carmen Unio Cruz
 */

#include "can_comunication_cellmeter.h"
#include "main.h"

	// las variables se han de definir en el main se ha de definir en el main
CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;
CAN_FilterTypeDef CANFilter;

uint32_t RxMailbox = 0;
uint8_t TxData[8];
uint8_t RxData[8];

	void canfilter(CAN_FilterTypeDef filtercan){
		filtercan.FilterActivation = ENABLE;          		      // This activates the filter as it is enable
		filtercan.FilterBank = 0;                                // This refers to which filter is being configured. On this case is the filter number 0
		filtercan.FilterFIFOAssignment = CAN_FILTER_FIFO0;       // Defines at which FIFO is this filter being configured to.
		filtercan.FilterIdHigh = 0x0000;                         // MSB: Most Significant Bit. When it's in 0, accepts all the messages
		filtercan.FilterIdLow = 0x0000;                          // LSB: Least Significant Bit. When it's in 0, accepts all the messages
		filtercan.FilterMaskIdHigh = 0x0000;                     // Most Significant Bit of the mask. When it's in 0, accepts all the messages
		filtercan.FilterMaskIdLow = 0x0000;                      // Least Significant Bit of the mask. When it's in 0, accepts all the messages
		filtercan.FilterMode = CAN_FILTERMODE_IDMASK;            // FilterMode: How are we filtering the incoming messages. Only the messages that coincide with the mask and the filter are accepted
		filtercan.FilterScale = CAN_FILTERSCALE_32BIT;           // Defines the Filter Scale. (use the 32 bits)
		filtercan.SlaveStartFilterBank = 14;                     // Indicates the first filter slave number. In this case it is the principal filter.
	}

	void CAN_TxCurrent1_4(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint8_t *txdata, uint32_t txmailbox, uint16_t currentcell1, uint16_t currentcell2, uint16_t currentcell3, uint16_t currentcell4){
		txheader.DLC = DLC_CURRENT1_4;
		txheader.StdId = ID_CURRENT1_4;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = currentcell1;
		txdata[1] = currentcell1 << 4;
		txdata[2] = currentcell2;
		txdata[3] = currentcell2 << 4;
		txdata[4] = currentcell3;
		txdata[5] = currentcell3 << 4;
		txdata[6] = currentcell4;
		txdata[7] = currentcell4 << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxCurrent5_8(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint16_t currentcell5, uint16_t currentcell6, uint16_t currentcell7, uint16_t currentcell8){
		txheader.DLC = DLC_CURRENT5_8;
		txheader.StdId = ID_CURRENT5_8;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = currentcell5;
		txdata[1] = currentcell5 << 4;
		txdata[2] = currentcell6;
		txdata[3] = currentcell6 << 4;
		txdata[4] = currentcell7;
		txdata[5] = currentcell7 << 4;
		txdata[6] = currentcell8;
		txdata[7] = currentcell8 << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxDischargeCurrent(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t currentdischarge){
		txheader.DLC = DLC_DISCHARGECURRENT;
		txheader.StdId = ID_DISCHARGECURRENT;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = currentdischarge;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_ControlCurrent(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t entrancecurrent, uint8_t microcurrent, uint8_t refricurrent){
		txheader.DLC = DLC_CONTROLCURRENT;
		txheader.StdId = ID_CONTROLCURRENT;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = entrancecurrent;
		txdata[1] = microcurrent;
		txdata[2] = refricurrent;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxVoltage1_4(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t voltagecell1, uint8_t voltagecell2, uint8_t voltagecell3, uint8_t voltagecell4){
		txheader.DLC = DLC_VOLTAGE1_4;
		txheader.StdId = ID_VOLTAGE1_4;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = voltagecell1;
		txdata[1] = voltagecell1 << 4;
		txdata[2] = voltagecell2;
		txdata[3] = voltagecell2 << 4;
		txdata[4] = voltagecell3;
		txdata[5] = voltagecell3 << 4;
		txdata[6] = voltagecell4;
		txdata[7] = voltagecell4 << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxVoltage5_8(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t voltagecell5, uint8_t voltagecell6, uint8_t voltagecell7, uint8_t voltagecell8){
		txheader.DLC = DLC_VOLTAGE5_8;
		txheader.StdId = ID_VOLTAGE5_8;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = voltagecell5;
		txdata[1] = voltagecell5 << 4;
		txdata[2] = voltagecell6;
		txdata[3] = voltagecell6 << 4;
		txdata[4] = voltagecell7;
		txdata[5] = voltagecell7 << 4;
		txdata[6] = voltagecell8;
		txdata[7] = voltagecell8 << 4;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxTemperatures(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t temperaturecell1, uint8_t temperaturecell2, uint8_t temperaturecell3, uint8_t temperaturecell4, uint8_t temperaturecell5, uint8_t temperaturecell6, uint8_t temperaturecell7, uint8_t temperaturecell8){
		txheader.DLC = DLC_TEMPERATURES;
		txheader.StdId = ID_TEMPERATURES;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = temperaturecell1;
		txdata[1] = temperaturecell2;
		txdata[2] = temperaturecell3;
		txdata[3] = temperaturecell4;
		txdata[4] = temperaturecell5;
		txdata[5] = temperaturecell6;
		txdata[6] = temperaturecell7;
		txdata[7] = temperaturecell8;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxDischargeReTemp(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t dischargeresistance1, uint8_t dischargeresistance2, uint8_t dischargeresistance3, uint8_t dischargeresistance4, uint8_t dischargeresistance5, uint8_t dischargeresistance6, uint8_t dischargeresistance7, uint8_t dischargeresistance8){
		txheader.DLC = DLC_DISCHARGERTEMP;
		txheader.StdId = ID_DISCHARGERTEMP;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = dischargeresistance1;
		txdata[1] = dischargeresistance2;
		txdata[2] = dischargeresistance3;
		txdata[3] = dischargeresistance4;
		txdata[4] = dischargeresistance5;
		txdata[5] = dischargeresistance6;
		txdata[6] = dischargeresistance7;
		txdata[7] = dischargeresistance8;

		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxRPMRefri(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t RPMFan1, uint8_t RPMFan2){
		txheader.DLC = DLC_RPMREFRI;
		txheader.StdId = ID_RPMREFRI;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = RPMFan1;
		txdata[1] = RPMFan2;


		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_CellDisconnect(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t celldisconnect){
		txheader.DLC = DLC_CELLDISCONNECT;
		txheader.StdId = ID_CELLDISCONNECT;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = celldisconnect;


		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void CAN_TxCellErrors(CAN_HandleTypeDef hcan1, CAN_TxHeaderTypeDef txheader, uint32_t txmailbox, uint8_t *txdata, uint8_t cellovervoltage, uint8_t cellovercurrent, uint8_t cellovertemperature){
		txheader.DLC = DLC_CELLERRORS;
		txheader.StdId = ID_CELLERRORS;
		txheader.RTR = CAN_RTR_DATA;
		txheader.IDE = CAN_ID_STD;

		txdata[0] = cellovervoltage;
		txdata[1] = cellovercurrent;
		txdata[2] = cellovertemperature;


		if(HAL_CAN_AddTxMessage(&hcan1, &txheader, txdata, &txmailbox) != HAL_OK){
			Error_Handler();
		}
	}

	void rx_sorter(CAN_HandleTypeDef hcan1, CAN_RxHeaderTypeDef rxheader, uint32_t rxmailbox, uint8_t *rxdata, uint8_t *statecell1, uint8_t *statecell2, uint8_t *statecell3, uint8_t *statecell4, uint8_t *statecell5, uint8_t *statecell6, uint8_t *statecell7, uint8_t *statecell8){

		if (HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &rxheader, rxdata)){
			Error_Handler();
		}

		if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING)){
			if (rxheader.StdId == ID_CELLSSTATE){
				*statecell1 = rxdata[0];
				*statecell2 = rxdata[1];
				*statecell3 = rxdata[2];
				*statecell4 = rxdata[3];
				*statecell5 = rxdata[4];
				*statecell6 = rxdata[5];
				*statecell7 = rxdata[6];
				*statecell8 = rxdata[7];
			}
		}

	}


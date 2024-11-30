/*
 * P_Controller.h
 *
 *  Created on: Jun 1, 2024
 *      Author: Andreu, Bernat Co
 */

#ifndef INC_P_CONTROLLER_H_
#define INC_P_CONTROLLER_H_

/* Controller parameters */
//ACCU---------------------------------------------------------------------------------------------------
#define SETPOINT 60
#define KP 1

typedef struct {
		/* Setpoint */
		int setpoint;

		/* Controller gains */
		int Kp;

		/* Controller output */
		int out;

	} P_Controller;

int P_Controller_Init(P_Controller *pc);
int P_Controller_Update(P_Controller *pc, float measurement, int mode);

#endif /* INC_P_CONTROLLER_H_ */

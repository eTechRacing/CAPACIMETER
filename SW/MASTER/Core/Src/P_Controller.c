/*
 * PID.c
 *
 *  Created on: Jun 1, 2024
 *      Author: Andreu, Bernat Co
 */

#include <P_Controller.h>
#include "stdio.h"
#include "stdint.h"

int P_Controller_Init(P_Controller *pc) {
	pc->out = 65;
	return pc->out;
}

int P_Controller_Update(P_Controller *pc, float measurement, int mode) {

	uint16_t limit_h=100; //limit DC PWM out

	/*
	* Error signal
	*/
    float error = measurement - pc->setpoint;

	/*
	* Proportional
	*/
    float proportional = pc->Kp * error;

	/*
	* Compute output and apply limits
	*/
    if(mode==1){
    	pc->out=0;
    }
    else if (mode==0){
    	pc->out = proportional;
    	if (pc->out > limit_h) {
    		pc->out = limit_h;
    	} else if (pc->out < 0) {
    	    pc->out = 0;
    	}
    }
    else if (mode==2){
    	pc->out=limit_h;
    }
	/* Return controller output */
    return pc->out;
}

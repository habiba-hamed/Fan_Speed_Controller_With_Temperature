/*******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_motor.h
 *
 * Description: Header file for the DC Motor
 *
 * Created on: 12�/10�/2021
 *
 * Author: Habiba Hamed
 *
 ********************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_Types.h"

/*******************************************************************************
 *                         Definitions                                  *
 *******************************************************************************/

#define FIRST_MOTOR_PIN_NUM 0
#define MOTOR_PORT_NUM 1
#define SECOND_MOTOR_PIN_NUM 1

/*******************************************************************************
 *                         Types Declaration                                  *
 *******************************************************************************/
typedef enum{
	STOP,CLOCKWISE,ANTI_CLOCKWISE
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description : Function to initialize the DC Motor driver
 * 	1. setup the direction for the two motor pins.
 * 	2. Stop at the DC-Motor at the beginning.
 */

void DcMotor_Init(void);

/*
 * Description : Function to initialize the DC Motor driver
 * 	1. setup the state of DC Motor.
 * 	2. setup the speed of the DC Motor.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
/*******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_motor.c
 *
 * Description: Source file for the DC Motor
 *
 * Created on: 12�/10�/2021
 *
 * Author: Habiba Hamed
 *
 ********************************************************************************/
#include "GPIO.h"
#include "DC_motor.h"
#include <avr/io.h>
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_Init(void){
	/*Configure the chosen 2 pins to connect the DC-Motor to as output pins */


	GPIO_setupPinDirection(MOTOR_PORT_NUM,FIRST_MOTOR_PIN_NUM,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_NUM,SECOND_MOTOR_PIN_NUM,PIN_OUTPUT);

	/* Stop at the DC-Motor at the beginning by clear the chosen 2 pins */


	GPIO_writePin(MOTOR_PORT_NUM,FIRST_MOTOR_PIN_NUM,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_NUM,SECOND_MOTOR_PIN_NUM,LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	/* configure the rotation of motor*/
	if(state==STOP){

		GPIO_writePin(MOTOR_PORT_NUM,FIRST_MOTOR_PIN_NUM,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_NUM,SECOND_MOTOR_PIN_NUM,LOGIC_LOW);
	}
	else if (state==CLOCKWISE){
		PORTB |=(1<<0);
		PORTB |=(1<<1);
		GPIO_writePin(MOTOR_PORT_NUM,FIRST_MOTOR_PIN_NUM,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_NUM,SECOND_MOTOR_PIN_NUM,LOGIC_LOW);
		/* configure the speed of motor */
		PWM_Timer0_Start(speed);
	}
	else if (state == ANTI_CLOCKWISE){

		GPIO_writePin(MOTOR_PORT_NUM,FIRST_MOTOR_PIN_NUM,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_NUM,SECOND_MOTOR_PIN_NUM,LOGIC_HIGH);
		/* configure the speed of motor */
		PWM_Timer0_Start(speed);
	}
}


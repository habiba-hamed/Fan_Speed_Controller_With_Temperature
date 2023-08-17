/************************************************************************************
 *
 *Module: ADC
 *
 *File Name: ADC_DRIVER.c
 *
 *Description: Source file for the ATmega16 ADC driver
 *
 *Created on: 12þ/10/2021
 *
 *Author: Habiba Hamed
 *
 ************************************************************************************/

#include <avr/io.h> /* to use ADC registers*/
#include "ADC_DRIVER.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void ADC_init(const ADC_ConfigType* Config_Ptr){

	/* ADMUX Register Bits Description:
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX=0;
	/* insert the required reference voltage in REFS1 and REFS0 bits ADMUX Register*/
	ADMUX=(ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);

	/*ADCSRA Register Bits Description:
	 * ADEN   = 1 to enable the ADC
	 * ADIE   = 0 to disable the interrupt because we use polling technique
	 */
	SET_BIT(ADCSRA,ADEN);
	/*
	 * insert the required prescaler value in the first three bits (ADPS2, ADPS1 and ADPS0)
	 * of ADCSRA Register
	 */
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler);

}

uint16 ADC_readChannel(uint8 channel_num){

	channel_num&=(0x07); /* to make sure that the channel number is from 0 to 7 */
	ADMUX &= 0xE0; /* clear the first five bits in ADMUX Register*/
	ADMUX |=channel_num; /* choose the channel by writing the channel number in MUX4:0 bits in ADMUX Register*/
	SET_BIT(ADCSRA,ADSC); /* setting ADSC bit in ADCSRA Register to start conversion*/
	while (BIT_IS_CLEAR(ADCSRA,ADIF)); /* waiting conversion to be finished , ADIF becomes one */
	SET_BIT(ADCSRA,ADIF); /* clear the flag by setting ADIF bit to one in ADCSRA Register */
	return ADC;
}

/*
 * PB_ARM_prog.c
 *
 *  Created on: ٠٢‏/٠٣‏/٢٠٢٣
 *      Author: houras
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include  "DIO_int.h"
#include  "RCC_interface.h"
#include  "PB_int.h"
#include  "ELC_Heater.h"
void PB_void_Init(){

	M_GPIO_void_SetPinDir(INCREASE_BUTTON_PORT,INCREASE_BUTTON_PIN,IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinValue(INCREASE_BUTTON_PORT,INCREASE_BUTTON_PIN, HIGH);

	M_GPIO_void_SetPinDir(DECREASE_BUTTON_PORT,DECREASE_BUTTON_PIN,IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinValue(DECREASE_BUTTON_PORT,DECREASE_BUTTON_PIN, HIGH);

	M_GPIO_void_SetPinDir(ON_OFF_BUTTON_PORT,ON_OFF_BUTTON_PIN,IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinValue(ON_OFF_BUTTON_PORT,ON_OFF_BUTTON_PORT, HIGH);


}
void PB_void_GetRead(u8 Port,u8 Pin,u8 *Value)
{

	M_GPIO_void_GetPinValue(Port,Pin, Value);


}

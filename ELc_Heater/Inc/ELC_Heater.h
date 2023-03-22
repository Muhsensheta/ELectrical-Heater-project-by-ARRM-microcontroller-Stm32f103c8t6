/*
 * ELC_Heater.h
 *
 *  Created on: Mar 22, 2023
 *      Author: houras
 */

#ifndef ELC_HEATER_H_
#define ELC_HEATER_H_


#define ON_OFF_BUTTON_PORT     PORTB_ID
#define ON_OFF_BUTTON_PIN      PIN6_ID

#define INCREASE_BUTTON_PORT     PORTA_ID
#define INCREASE_BUTTON_PIN      PIN12_ID

#define DECREASE_BUTTON_PORT     PORTA_ID
#define DECREASE_BUTTON_PIN      PIN15_ID


void SetON_Butt_Control(void);
void Encrease_Butt_Control(void);
u8 Butt_Control(void);



#endif /* ELC_HEATER_H_ */

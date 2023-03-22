/*
 * ELC_Heater.c
 *
 *  Created on: Mar 22, 2023
 *      Author: houras
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "PB_int.h"
#include "ELC_Heater.h"
#include  "SSD_Config.h"


u8 Count=65;
u8 Enval;
u8 Deval;
u8 Button;

void SetON_Butt_Control(void)
{

	M_GPIO_void_GetPinValue(PORTB_ID, PIN6_ID, &Button);
	 if (Button==0)
			      {
				    M_GPIO_void_TogPin(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN);
				    M_GPIO_void_TogPin(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN);

			      }
}
u8 Butt_Control(void)
{
	if ( (Count<70)&&( Count>=35))
	{
		M_GPIO_void_GetPinValue(PORTA_ID, PIN12_ID, &Enval);
		M_GPIO_void_GetPinValue(PORTA_ID, PIN15_ID, & Deval);

		   if (Enval==0)
		      {
			Count++;

		      }
	     	else if (Deval==0)
		     {
			Count--;
		     }

	  }
	else
	{
		Count=35;
	}

	H_SSD_void_DisplayNumber(Count);
	return Count;

}
void Decrease_Butt_Control(void)
{

}

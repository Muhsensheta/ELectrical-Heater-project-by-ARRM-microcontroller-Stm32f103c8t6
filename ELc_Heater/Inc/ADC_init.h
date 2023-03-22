/*
 * ADC_init.h
 *
 *  Created on: Mar 9, 2023
 *      Author: houras
 */

#ifndef ADC_INIT_H_
#define ADC_INIT_H_


typedef enum
{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7,
	CHANNEL_8,
	CHANNEL_9
}Channel_ID;

	/******************* Functions Prototypes ********************/
void	_delay_ms(u32 _ms);

void	ADC_void_init	(void);
u16		ADC_u16_read	(Channel_ID Copy_enuChannel);



#endif /* ADC_INIT_H_ */

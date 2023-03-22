#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"DIO_int.h"
#include	"NVIC_int.h"
#include     "STK_interface.h"
#include     "ADC_init.h"
#include     "LCD_int.h"
#include     "SSD_init.h"
#include     "PB_int.h"
#include     "ELC_Heater.h"


u16 global_u16Reading;
u8 Temp;

int main(void)
{
	/******************* Initialization ********************/

	// System Clk init
	MRCC_voidSysClkInit();

	// Enable Per Clk "RCC" -> DIO_A , DIO_C, DIO_B
	MRCC_voidEnablePerClk(RCC_APB2,2);
	MRCC_voidEnablePerClk(RCC_APB2,4);
	MRCC_voidEnablePerClk(RCC_APB2,3);


	// Set ADC Prescaler
	MRCC_voidSetADCPre(RCC_ADC_PRE_2);

	// Enable Per Clk "RCC" -> ADC -> 9
	MRCC_voidEnablePerClk(RCC_APB2,9);

	// Set Direction for ADC channel_0 as IN_ANALOG
	M_GPIO_void_SetPinDir(PORTA_ID, PIN0_ID, IN_ANALOG);
   // M_GPIO_void_SetPinValue(PORTA_ID, PIN0_ID, HIGH);
	// Initialize ADC
	ADC_void_init();

	// Initialize LCD
	H_LCD_void_Init();
	H_SSD_void_init();
	PB_void_Init();

	// SET LEDs direction
	M_GPIO_void_SetPinDir(PORTB_ID, PIN10_ID, OUT_10MHZ_PP);//for led red out

	M_GPIO_void_SetPinDir(PORTB_ID, PIN0_ID, OUT_10MHZ_PP);
	M_GPIO_void_SetPinDir(PORTB_ID, PIN1_ID, OUT_10MHZ_PP);
	M_GPIO_void_SetPinDir(PORTC_ID, PIN13_ID, OUT_10MHZ_PP);
	M_GPIO_void_SetPinDir(PORTC_ID, PIN14_ID, OUT_10MHZ_PP);
	M_GPIO_void_SetPinDir(PORTC_ID, PIN15_ID, OUT_10MHZ_PP);


	/*******************   Super LOOP   ********************/
	while(1)
	{

		SetON_Butt_Control();
		Temp=Butt_Control();
		if (ADC_u16_read(CHANNEL_0)<=Temp)
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN10_ID, HIGH);
		}
		else
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN10_ID, LOW);


		}
				//STK_voidBusyWait(1000);
				//H_SSD_void_Setoff();
				//STK_voidBusyWait(5000000);

				//H_SSD_void_DisplayNumber(70);
				//STK_voidBusyWait(1000);

		/*
		//H_LCD_void_gotXY(0,1);
		//H_LCD_void_sendString("ADC Value =");

		//H_LCD_void_gotXY(1,6);
		/*global_u16Reading = ADC_u16_read(CHANNEL_0);
		H_SSD_void_DisplayNumber(global_u16Reading);
		STK_voidBusyWait(1000);

		if(global_u16Reading < 50)
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN0_ID,  LOW);
			M_GPIO_void_SetPinValue(PORTB_ID, PIN1_ID,  LOW);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, HIGH);


		}
		else if(global_u16Reading < 100)
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN0_ID,  LOW);
			M_GPIO_void_SetPinValue(PORTB_ID, PIN1_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, HIGH);

		}
		else if(global_u16Reading < 400)
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN0_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTB_ID, PIN1_ID,  LOW);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, HIGH);


		}
		else if(global_u16Reading < 600)
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN0_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTB_ID, PIN1_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, LOW);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, HIGH);


		}
		else if(global_u16Reading < 800)
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN0_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTB_ID, PIN1_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID, LOW);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, HIGH);


		}
		else if(global_u16Reading < 1024)
		{
			M_GPIO_void_SetPinValue(PORTB_ID, PIN0_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTB_ID, PIN1_ID,  HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN14_ID, HIGH);
			M_GPIO_void_SetPinValue(PORTC_ID, PIN15_ID, LOW);


		}
		_delay_ms(250);*/
	}
	return 0;
}

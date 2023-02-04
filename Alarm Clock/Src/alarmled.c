/*
 * alarmled.c
 *
 *  Created on: 4/02/2023
 *      Author: tomed
 */

#include "alarmled.h"



void LED_Initalize(void)
{
	uint32_t temp = 0;

	//Initalize lower register of GPIOA first
	temp |= (1<< 0);
	temp |= (1<< 4);
	temp |= (1<< 8);
	temp |= (1<< 12);
	temp |= (1<< 16);
	temp |= (1<< 20);
	temp |= (1<< 24);
	temp |= (1<< 28);
	GPIOA->CRL = temp;

	//GPIOA high register in this case GPIOA pins 13 and 14 need to remain untouched
	//So will first clear all reigsters apart from these two then or operations
	GPIOA->CRH &= ~(0xFFFFF00F);
	temp = 0;
	temp |= (1<< 0);
	temp |= (1<< 4);
	temp |= (1<< 8);
	temp |= (1<< 12);
	temp |= (1<< 16);
	temp |= (1<< 28);
	GPIOA->CRH |= temp;

	//GPIOB low register in this case only need to set B3,4,5
	GPIOB->CRH &= ~(0x000FFF00);
	temp = 0;
	temp |= (1<< 12);
	temp |= (1<< 16);
	temp |= (1<< 20);
	GPIOB->CRL |= temp;

	//GPIO B high all registers are used
	temp = 0;
	temp |= (1<< 0);
	temp |= (1<< 4);
	temp |= (1<< 8);
	temp |= (1<< 12);
	temp |= (1<< 16);
	temp |= (1<< 20);
	temp |= (1<< 24);
	temp |= (1<< 28);
	GPIOB->CRH = temp;

	//GPIO C high only 13 14 15 are used
	GPIOC->CRH &= ~(0x00000FFF);
	temp = 0;
	temp |= (1<< 20);
	temp |= (1<< 24);
	temp |= (1<< 28);
	GPIOC->CRH |= temp;

}





/*
 * The toggling of LEDs is stored in a function.
 * These functions can then be pointed to allowing the code to be run and a blinking effect to occur when being changed.
 *
 */


void LED_NUM_4_SET_0 (void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_0_ENABLE();
	LED_NUM_4_1_ENABLE();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_4_ENABLE();
	LED_NUM_4_5_ENABLE();
	LED_NUM_4_6_ENABLE();
}
void LED_NUM_4_SET_1(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_5_ENABLE();
}
void LED_NUM_4_SET_2(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_0_ENABLE();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_3_ENABLE();
	LED_NUM_4_4_ENABLE();
	LED_NUM_4_6_ENABLE();
}
void LED_NUM_4_SET_3(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_0_ENABLE();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_3_ENABLE();
	LED_NUM_4_5_ENABLE();
	LED_NUM_4_6_ENABLE();
}
void LED_NUM_4_SET_4(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_1_ENABLE();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_3_ENABLE();
	LED_NUM_4_5_ENABLE();
}
void LED_NUM_4_SET_5(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_0_ENABLE();
	LED_NUM_4_1_ENABLE();
	LED_NUM_4_3_ENABLE();
	LED_NUM_4_5_ENABLE();
	LED_NUM_4_6_ENABLE();
}
void LED_NUM_4_SET_6(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_6_ENABLE();
	LED_NUM_4_1_ENABLE();
	LED_NUM_4_3_ENABLE();
	LED_NUM_4_4_ENABLE();
	LED_NUM_4_5_ENABLE();
	LED_NUM_4_6_ENABLE();
}
void LED_NUM_4_SET_7(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_0_ENABLE();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_5_ENABLE();
}
void LED_NUM_4_SET_8(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_0_ENABLE();
	LED_NUM_4_1_ENABLE();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_3_ENABLE();
	LED_NUM_4_4_ENABLE();
	LED_NUM_4_5_ENABLE();
	LED_NUM_4_6_ENABLE();
}
void LED_NUM_4_SET_9(void)
{
	LED_NUM_4_CLEAR();
	LED_NUM_4_0_ENABLE();
	LED_NUM_4_1_ENABLE();
	LED_NUM_4_2_ENABLE();
	LED_NUM_4_3_ENABLE();
	LED_NUM_4_5_ENABLE();
}

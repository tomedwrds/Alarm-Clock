/*
 * alarmled.h
 *
 *  Created on: 4/02/2023
 *      Author: tomed
 */

#ifndef ALARMLED_H_
#include "main.h"

//General macros
#define LED_ON 1
#define LED_OFF 0

//Function prototypes for initalizing leds
void LED_Initalize(void);

#define LED_NUM_1_CLEAR() 		do{GPIOB->ODR &= ~(5 << 3);}while(0);
#define LED_NUM_1_0_ENABLE() 	(GPIOB->ODR |= 1 << 5)




void LED_NUM_1_SET_0(void);
void LED_NUM_1_SET_1(void);
void LED_NUM_1_SET_2(void);


#define LED_NUM_2_CLEAR() 		do{GPIOA->ODR &= ~(31 << 8);GPIOB->ODR &= ~(3 << 14);}while(0);
#define LED_NUM_2_0_ENABLE() 	(GPIOA->ODR |= 1 << 12)
#define LED_NUM_2_1_ENABLE() 	(GPIOA->ODR |= 1 << 11)
#define LED_NUM_2_2_ENABLE() 	(GPIOA->ODR |= 1 << 10)
#define LED_NUM_2_3_ENABLE() 	(GPIOA->ODR |= 1 << 9)
#define LED_NUM_2_4_ENABLE() 	(GPIOA->ODR |= 1 << 8)
#define LED_NUM_2_5_ENABLE() 	(GPIOB->ODR |= 1 << 15)
#define LED_NUM_2_6_ENABLE() 	(GPIOB->ODR |= 1 << 14)


void LED_NUM_2_SET_0(void);
void LED_NUM_2_SET_1(void);
void LED_NUM_2_SET_2(void);
void LED_NUM_2_SET_3(void);
void LED_NUM_2_SET_4(void);
void LED_NUM_2_SET_5(void);
void LED_NUM_2_SET_6(void);
void LED_NUM_2_SET_7(void);
void LED_NUM_2_SET_8(void);
void LED_NUM_2_SET_9(void);


#define LED_NUM_3_CLEAR() 		do{GPIOC->ODR &= ~(7 << 13);GPIOB->ODR &= ~(15 << 8);}while(0);
#define LED_NUM_3_0_ENABLE() 	(GPIOC->ODR |= 1 << 13)
#define LED_NUM_3_1_ENABLE() 	(GPIOC->ODR |= 1 << 14)
#define LED_NUM_3_2_ENABLE() 	(GPIOC->ODR |= 1 << 15)
#define LED_NUM_3_3_ENABLE() 	(GPIOB->ODR |= 1 << 10)
#define LED_NUM_3_4_ENABLE() 	(GPIOB->ODR |= 1 << 11)
#define LED_NUM_3_5_ENABLE() 	(GPIOB->ODR |= 1 << 9)
#define LED_NUM_3_6_ENABLE() 	(GPIOB->ODR |= 1 << 8)

//Function prototypes for initalizing leds
void LED_Initalize(void);

void LED_NUM_3_SET_0(void);
void LED_NUM_3_SET_1(void);
void LED_NUM_3_SET_2(void);
void LED_NUM_3_SET_3(void);
void LED_NUM_3_SET_4(void);
void LED_NUM_3_SET_5(void);
void LED_NUM_3_SET_6(void);
void LED_NUM_3_SET_7(void);
void LED_NUM_3_SET_8(void);
void LED_NUM_3_SET_9(void);


#define LED_NUM_4_CLEAR() 		(GPIOA->ODR &= ~(127 << 0))
#define LED_NUM_4_0_ENABLE() 	(GPIOA->ODR |= 1)
#define LED_NUM_4_1_ENABLE() 	(GPIOA->ODR |= 1 << 1)
#define LED_NUM_4_2_ENABLE() 	(GPIOA->ODR |= 1 << 2)
#define LED_NUM_4_3_ENABLE() 	(GPIOA->ODR |= 1 << 3)
#define LED_NUM_4_4_ENABLE() 	(GPIOA->ODR |= 1 << 4)
#define LED_NUM_4_5_ENABLE() 	(GPIOA->ODR |= 1 << 5)
#define LED_NUM_4_6_ENABLE() 	(GPIOA->ODR |= 1 << 6)

//Function prototypes for initalizing leds
void LED_Initalize(void);

void LED_NUM_4_SET_0(void);
void LED_NUM_4_SET_1(void);
void LED_NUM_4_SET_2(void);
void LED_NUM_4_SET_3(void);
void LED_NUM_4_SET_4(void);
void LED_NUM_4_SET_5(void);
void LED_NUM_4_SET_6(void);
void LED_NUM_4_SET_7(void);
void LED_NUM_4_SET_8(void);
void LED_NUM_4_SET_9(void);






#define ALARMLED_H_



#endif /* ALARMLED_H_ */

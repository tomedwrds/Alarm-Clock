/*
 * main.h
 *
 *  Created on: 4/02/2023
 *      Author: tomed
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>

struct GPIO
{
	uint32_t CRL,CRH,IDR,ODR,BSSR,BRR,LCKR;
};

struct I2C
{
	uint32_t CR1, CR2, OAR1, OAR2, DR, SR1, SR2,CCR,TRISE;
};

struct TIM
{
	uint32_t CR1, CR2, RESERVED0, DIER, SR, EGR, RESERVED1,RESERVED2,RESERVED3,CNT,PSC,ARR;
};

#define GPIOA ((struct GPIO *) 0x40010800)
#define GPIOB ((struct GPIO *) 0x40010C00)
#define GPIOC ((struct GPIO *) 0x40011000)
#define I2C1 ((struct I2C *)   0x40005400)
#define TIM1 ((struct TIM *)	0x40012C00)
#define TIM2 ((struct TIM *)	0x40000000)
#define TIM3 ((struct TIM *)	0x40000400)
#define TIM4 ((struct TIM *)	0x40000800)


#define ALARM_CLOCK_NO_ALARM		0
#define ALARM_CLOCK_ALARM			1
#define ALARM_CLOCK_SET				2
#define ALARM_CLOCK_SET_ALARM		3

#define USER_UPDATED_TIME			1
#define USER_NOT_UPDATED_TIME		0

#define NVIC_ISER0		0xE000E100
#define NVIC_ISER1		0xE000E104


typedef struct
{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t time_format;
}RTC_time_t;





#include "alarmled.h"
#include "rtci2c.h"
#include "clocksettings.h"





#endif /* MAIN_H_ */

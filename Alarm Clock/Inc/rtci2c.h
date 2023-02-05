/*
 * rtci2c.h
 *
 *  Created on: 5/02/2023
 *      Author: tomed
 */

#ifndef RTCI2C_H_
#define RTCI2C_H_
#include "main.h"


//Macros

#define I2C_SCL_SPEED_SM 	100000
#define HSI_SPEED			8000000

#define I2C_READY 					0
#define I2C_BUSY_IN_RX 				1
#define I2C_BUSY_IN_TX 			2

#define DS1307_DEVICE_ADDR		0x68

#define DS1307_ADDR_SEC 		0x00
#define DS1307_ADDR_MIN 		0x01
#define DS1307_ADDR_HRS			0x02
#define DS1307_ADDR_DAY			0x03
#define DS1307_ADDR_DATE		0x04
#define DS1307_ADDR_MONTH		0x05
#define DS1307_ADDR_YEAR		0x06

#define TIME_FORMAT_12HRS_AM 	0
#define TIME_FORMAT_12HRS_PM 	1
#define TIME_FORMAT_24HRS 		2


//Function prototypes
uint8_t binary_to_bcd(uint8_t value);

uint8_t bcd_to_binary(uint8_t value);



void  I2C_SendData(uint8_t *pTXBuffer, uint32_t Len, uint8_t Sr);


void  I2C_RecieveData(uint8_t *pRXBuffer);
void ds1307_write(uint8_t value,uint8_t reg_addr);

uint8_t ds1307_read(uint8_t reg_addr);


void ds1307_set_current_time(RTC_time_t *rtc_time);
void ds1307_get_current_time(RTC_time_t *rtc_time);


void updateSetTime(RTC_time_t *rtc_time, uint8_t * alarmClockSetNum,uint8_t *timeSet);

#endif /* RTCI2C_H_ */

/*
 * rtci2c.c
 *
 *  Created on: 5/02/2023
 *      Author: tomed
 */

#include "rtci2c.h"

uint8_t binary_to_bcd(uint8_t value)
{
	//Ones is bit 0:3, tens is bit 4:6
	uint8_t tens, ones,bcd;
	//If only 1s bcd value is the same as binary
	bcd = value;
	if(value >= 10)
	{
		tens = value/10;
		ones = value %10;
		bcd = (uint8_t)((tens<<4)|ones );
	}
	return bcd;
}

uint8_t bcd_to_binary(uint8_t value)
{
	//Ones is bit 0:3, tens is bit 4:6
	//This function gets the amount of tens and ones
	uint8_t tens, ones,binary;
	tens = (value >>4);
	ones = (value & 0x0F);
	binary = tens*10 + ones;

	return (uint8_t)binary;
}



void  I2C_SendData(uint8_t *pTXBuffer, uint32_t Len, uint8_t Sr)
{

	//Generate START Condition
	I2C1->CR1 |= (1<< 8);

	//Poll the SB flag in SR1. Hang program until its set
	while(!(I2C1->SR1 & 1));

	//Write the slave address to the DR
	//First bit must be cleared
	I2C1->DR = DS1307_DEVICE_ADDR << 1;

	//Poll the ADDR flag in SR1. Hang program until its set
	while(!(I2C1->SR1& (1<< 1)));

	//ADDR flag cleared by reading SR1 then SR2
	uint32_t dummyread;
	dummyread = I2C1->SR1;
	dummyread = I2C1->SR2;
	(void)dummyread;

	//Send all bytes of data
	while(Len > 0)
	{
		//Hang the program until TXE SR1 is set
		while(!(I2C1->SR1& (1<< 7)));

		//1. load the data in to DR
		I2C1->DR = *(pTXBuffer);

		//2. decrement the TxLen
		Len--;

		//3. Increment the buffer address
		pTXBuffer++;
	}


	//Wait for TXE and BTF to be set as they signal end of data transfer
	while(!(I2C1->SR1& (1<< 7)));
	while(!(I2C1->SR1& (1<< 2)));


	//Generate the stop condition
	I2C1->CR1 |= (1<< 9);

}


void I2C_RecieveData(uint8_t *pRXBuffer)
{

	//Generate START Condition
	I2C1->CR1 |= (1<< 8);

	//Enable ACKING
	I2C1->CR1 |= (1<< 10);

	//Poll the SB flag in SR1. Hang program until its set
	while(!(I2C1->SR1 & 1));

	//Write the slave address to the DR last bit set 1 as write
	I2C1->DR = (DS1307_DEVICE_ADDR << 1) |(1);

	//ONLY THREE BYTES ARE EITHER RECIEVED AT A TIME AS THAT IS ALL THAT IS REQUIRED TO GET THE RTC STATE
	//THEREFORE CODE IS SET UP AS PER I2C MANUAL TO RECIEVE THESE 3 BYTES
	//pg 5 - https://www.st.com/resource/en/application_note/cd00209826-stm32f10xxx-i-c-optimized-examples-stmicroelectronics.pdf

	//Poll the ADDR flag in SR1. Hang program until its set
	while(!(I2C1->SR1& (1<< 1)));

	//ADDR flag cleared by reading SR1 then SR2
	uint32_t dummyread;
	dummyread = I2C1->SR1;
	dummyread = I2C1->SR2;
	(void)dummyread;

	//Wait until RXNE is set signifing data is received
	while(!(I2C1->SR1& (1<< 6)));

	//Wait until btf flag is set signfying two bytes of data have been recieved as both the shift and data register are full
	while(!(I2C1->SR1& (1<< 2)));

	//Disable acking so that when the next byte of data is received (final byte) it recieves a nack
	I2C1->CR1 &= ~(1<< 10);

	//Read the first byte of data
	*pRXBuffer = I2C1->DR;
	pRXBuffer++;

	//Final byte is now recieved and NACK pulse send ending data transfer

	//Generate the stop condition as no more data should be sent
	I2C1->CR1 |= (1<< 9);

	//Read the second byte of data
	*pRXBuffer = I2C1->DR;
	pRXBuffer++;

	//Wait until RXNE is set signifing last byte of data has defiently arrived
	while(!(I2C1->SR1& (1<< 6)));

	//Read the data
	*pRXBuffer = I2C1->DR;
	pRXBuffer++;

}

void ds1307_write(uint8_t value,uint8_t reg_addr)
{
	//Sends two bytes of data to enable the clock
	uint8_t tx[2];
	tx[0] = reg_addr;
	tx[1] = value;
	I2C_SendData(tx, 2,0);
}

void ds1307_read(uint8_t reg_addr,uint8_t *data)
{
	//Send address then receive data
	I2C_SendData(&reg_addr, 1,1);
	I2C_RecieveData(data);


}


void ds1307_set_current_time(RTC_time_t *rtc_time)
{
	uint8_t hrs;


	//send minutes
	ds1307_write(binary_to_bcd(rtc_time->minutes),DS1307_ADDR_MIN);

	//set hours
	hrs = binary_to_bcd(rtc_time->hours);
	//Ensure bit 7 is cleared to not turn of clock
	if(rtc_time->time_format == TIME_FORMAT_24HRS)
	{
		hrs &= ~(1 << 6);
	}
	else
	{
		hrs |= (1 << 6);
		hrs =(rtc_time->time_format ==TIME_FORMAT_12HRS_PM ) ? hrs | (1<<5) : hrs & ~(1<<5);
	}
	ds1307_write(hrs,DS1307_ADDR_HRS);
}
void ds1307_get_current_time(RTC_time_t *rtc_time)
{
	uint8_t time_data [3];
	ds1307_read(DS1307_ADDR_SEC, time_data);
	uint8_t seconds,hrs;
	seconds = time_data[0];
	seconds &= ~(1 << 7);
	rtc_time->seconds = bcd_to_binary(seconds);


	rtc_time->minutes = bcd_to_binary(time_data[1]);

	hrs = time_data[2];
	if(hrs & (1<<6))
	{
		//12hr format
		//ever gives 12hr am (0) or 12hr pm (1)
		rtc_time->time_format = !((hrs & (1<< 5)) == 0) ;
		//clear 6th and 5th position
		hrs &= ~(0x3 << 5);
	}
	else
	{
		//24hrs format
		rtc_time->time_format = TIME_FORMAT_24HRS;
	}

	rtc_time->hours = bcd_to_binary(hrs);
}


void updateClockTime(RTC_time_t *rtc_time, uint8_t alarmClockSetNum)
{
	uint8_t tens, ones;
	//Tens hours
	if(alarmClockSetNum == 0)
	{
		rtc_time->hours += 10;
		if(rtc_time->hours > 12)
		{
			rtc_time->hours %= 10;
		}
		else
		{
			rtc_time->hours %= 20;
		}

	}
	//One hours
	else if(alarmClockSetNum == 1)
	{
		tens = rtc_time->hours / 10;
		ones = (rtc_time->hours) %10;
		if(tens == 1)
		{
			ones = ((ones+1)% 3);
		}
		else if (tens == 0)
		{
			ones = ((ones+1)% 10);
			if(ones == 0) ones = 1;
		}

		rtc_time->hours = (tens*10 + ones);

	}
	//Tens minutes
	else if(alarmClockSetNum == 2)
	{
		tens = rtc_time->minutes / 10;
		ones = rtc_time->minutes % 10;
		tens += 1;
		tens %= 6;
		rtc_time->minutes = (tens*10 + ones);
	}
	//ones minutes
	else if(alarmClockSetNum == 3)
	{
		tens = rtc_time->minutes / 10;
		ones = (rtc_time->minutes +1) % 10;

		rtc_time->minutes = (tens*10 + ones);
	}
	else if(alarmClockSetNum == 4)
	{
		if(rtc_time->time_format == TIME_FORMAT_12HRS_PM)
		{
			rtc_time->time_format = TIME_FORMAT_12HRS_AM;
		}
		else if(rtc_time->time_format == TIME_FORMAT_12HRS_AM)
		{
			rtc_time->time_format = TIME_FORMAT_12HRS_PM;
		}
	}

}

void I2C_initalize(void)
{
	//Configure the gpio pins B6 and B7 for I2C -> both need to be AF and open drain value of 1101
	GPIOB->CRL &= ~(0xF << 24);
	GPIOB->CRL |= (0xD << 24);
	GPIOB->CRL &= ~(0xF << 28);
	GPIOB->CRL |= (0xD << 28);

	//Set the frequency of clock provided to cr2
	I2C1->CR2 |= ((HSI_SPEED/1000000));


	//Configure the device address will maybe do
	I2C1->OAR1 |= (0x61 << 1);

	//The 14th bit of the OAR1 register must always be mainted by software as 1
	I2C1->OAR1 |= (1<<14);

	//Set the CCR
	I2C1->CCR |= ((HSI_SPEED / (2*I2C_SCL_SPEED_SM)));

	//Set the trise value
	I2C1->TRISE =(((HSI_SPEED / 1000000) + 1) & 0x3F);

	//Enable the I2C
	I2C1->CR1 |= 1;
}

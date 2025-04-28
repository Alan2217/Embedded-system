#include "stm32f10x.h"
#include "Delay.h"
#define SCL_PORT	GPIOB
#define SCL_PIN		GPIO_Pin_10

void I2CCC_W_SCL(uint8_t BitValue)
{
	GPIO_WriteBit(SCL_PORT, SCL_PIN, (BitAction)BitValue);
	Delay_us(10);
}

void I2CCC_W_SDA(uint8_t BitValue)
{
	GPIO_WriteBit(SCL_PORT, GPIO_Pin_11, (BitAction)BitValue);
	Delay_us(10);
}

uint8_t I2CCC_R_SDA(void)
{
	uint8_t BitValue;
	BitValue = GPIO_ReadInputDataBit(SCL_PORT, GPIO_Pin_11);
	Delay_us(10);
	return BitValue;
}

void I2CCC_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_10 | GPIO_Pin_11);

}

void I2CCC_Start(void)
{
	I2CCC_W_SCL(1);
	I2CCC_W_SDA(1);
	I2CCC_W_SDA(0);
	I2CCC_W_SCL(0);
}

void I2CCC_Stop(void)
{
	I2CCC_W_SDA(0);
	I2CCC_W_SCL(1);
	I2CCC_W_SDA(1);
	
}
void I2CCC_SendByte(uint8_t Byte)		//when the SLC go 1,will send the data
{
	uint8_t i;
	for(i = 0;i<8;i++)
	{
		I2CCC_W_SDA(Byte &(0x80>>i));
		I2CCC_W_SCL(1);
		I2CCC_W_SCL(0);
	}
}

uint8_t I2CCC_ReceiveByte(void)
{
	uint8_t i, Byte = 0x00;
	I2CCC_W_SDA(1);
	for(i = 0;i<8;i++)
	{
	I2CCC_W_SCL(1);
	if(I2CCC_R_SDA()==1){Byte |= (0x80>>i);}
	I2CCC_W_SCL(0);
	}
	return Byte;
}

void I2CCC_SendACK(uint8_t ACKBit)		//when the SLC go 1,will send the data
{
	I2CCC_W_SDA(ACKBit);
	I2CCC_W_SCL(1);
	I2CCC_W_SCL(0);
}

uint8_t I2CCC_ReceiveACK(void)
{
	uint8_t ACKBit;
	I2CCC_W_SDA(1);
	I2CCC_W_SCL(1);
	ACKBit = I2CCC_R_SDA();
	I2CCC_W_SCL(0);
	return ACKBit;
}
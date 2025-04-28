#include "stm32f10x.h"
#include "Delay.h"
void Buttom_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
uint8_t Buttom_GetNumber(void)
{
	uint8_t Buttom_Number = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0);
		Delay_ms(20);
		Buttom_Number = 1;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0);
		Delay_ms(20);
		Buttom_Number = 2;
	}
	
	return Buttom_Number;
}
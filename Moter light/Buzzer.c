#include "stm32f10x.h" 

void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_Off(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_On(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_13)==0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
	}
	else if ((GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_13) == 1))
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	}
}
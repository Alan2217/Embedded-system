#include "stm32f10x.h"

int16_t count;
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	
	EXTI_InitTypeDef EXIT_Initstructure;
	EXIT_Initstructure.EXTI_Line = EXTI_Line0 | EXTI_Line1;
	EXIT_Initstructure.EXTI_LineCmd = ENABLE;
	EXIT_Initstructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXIT_Initstructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXIT_Initstructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitSturcture;
	NVIC_InitSturcture.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 1; 
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitSturcture);
	
	NVIC_InitSturcture.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 1; 
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitSturcture);
}

int16_t countGet(void)
{
	int16_t temp;
	temp = count;
	count = 0;
	return temp;
}

void EXTI0_IRQHandler(void)
{
	if (EXTI_GetFlagStatus(EXTI_Line0)==SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)==0)
		{
			if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)
			{
				count --;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}
void EXTI1_IRQHandler(void)
{
	if (EXTI_GetFlagStatus(EXTI_Line1)==SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)
		{
			if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)==0)
			{
				count ++;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
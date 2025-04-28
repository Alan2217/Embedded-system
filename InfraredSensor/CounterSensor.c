#include "stm32f10x.h"

uint16_t CoountSensor_Count;

void CounterSenor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	
	EXTI_InitTypeDef EXIT_Initstructure;
	EXIT_Initstructure.EXTI_Line = EXTI_Line14;
	EXIT_Initstructure.EXTI_LineCmd = ENABLE;
	EXIT_Initstructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXIT_Initstructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXIT_Initstructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitSturcture;
	NVIC_InitSturcture.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 1; 
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitSturcture);
}
uint16_t CounterSensorGet(void)
{
	return CoountSensor_Count;
}
void EXTI15_10_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line14)==SET)
	{
		CoountSensor_Count++;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}
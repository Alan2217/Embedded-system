#include "stm32f10x.h"



void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrucutre;
	TIM_TimeBaseInitStrucutre.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStrucutre.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStrucutre.TIM_Period = 10000 - 1;			//arr
	TIM_TimeBaseInitStrucutre.TIM_Prescaler = 7200 - 1;  //psc72M/(psc+1)/(arr+1)
	TIM_TimeBaseInitStrucutre.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStrucutre);
	
	TIM_ClearFlag(TIM2, TIM_IT_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

//void TIM2_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//	{
//		TIM_ClearITPendingBit(TIM2 ,TIM_IT_Update);
//	}
//}
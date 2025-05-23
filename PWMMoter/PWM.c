#include "stm32f10x.h"

void PWM_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrucutre;
	TIM_TimeBaseInitStrucutre.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStrucutre.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStrucutre.TIM_Period = 20000 - 1;			//arr
	TIM_TimeBaseInitStrucutre.TIM_Prescaler = 72 - 1;  //psc	72M/(psc+1)/(arr+1)
	TIM_TimeBaseInitStrucutre.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStrucutre);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;				//CCR
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

void CCR_SET(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);
}
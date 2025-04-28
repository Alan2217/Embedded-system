
#include "stm32f10x.h"
#include "Delay.h"

void Mux_Init_GPIO()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	
	GPIO_InitTypeDef GPIO_InitStructure;				
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;					//8-11
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}

void Mux_set(uint8_t pin)
{
	 uint16_t current_state = GPIOA->ODR;

   current_state &= ~(0xF << 8);
   current_state |= (pin & 0xF) << 8;

   GPIOA->ODR = current_state;
}


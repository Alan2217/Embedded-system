#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"

int16_t Num;
int main(void)
{
	OLED_Init();
	Key_Init();

	OLED_ShowString(1,1, "Num:");
	while(1)
	{
		Num += countGet();
		OLED_ShowSignedNum(1,5, Num,5);
	}
		
}

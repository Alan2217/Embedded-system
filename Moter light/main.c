#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "Lumasensor.h"
#include "OLED.h"
#include "AD.h" 
uint8_t ButtomNumber;
int main(void)
{
	
	Lsensor_Init();
	OLED_Init();
	float Num;
	AD_Init();
	
	while(1)
	{
		Num = light_AD();
		OLED_ShowNum(1,1,Num,1);
		OLED_ShowString(1,2,".");
		OLED_ShowNum(1,3,(int)(Num*1000)%1000,3);
		OLED_ShowString(1,6,"V");
		
		if(Num < 1.5)
		{
			OLED_ShowString(2,1,"Light, turn off");
		}else 
		{
			OLED_ShowString(2,1,"Dark, turn on");
		}
		
			
	}
}

#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "Lumasensor.h"

uint8_t ButtomNumber;
int main(void)
{
	Buzzer_Init();
	Lsensor_Init();
	
	while(1)
	{
		if(Lsensor_GetNumber() == 1)
			{
				Buzzer_On();
			}else if(Lsensor_GetNumber() == 0)
			{
				Buzzer_Off();
			}
	}
	
		
}

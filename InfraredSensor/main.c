#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CounterSensor.h"
int main(void)
{
	OLED_Init();
	CounterSenor_Init();

	OLED_ShowString(1,1, "Count:");
	while(1)
	{
		OLED_ShowNum(1,7, CounterSensorGet(),5);
	}
		
}

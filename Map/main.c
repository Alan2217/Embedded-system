#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "AD.h"
#include <stdio.h>
#include "Serial_USART.h"
#include "Mux.h"

int16_t ADValue;
float Voltage;
float temp;
int main(void)
{
	OLED_Init();
	AD_Init();
	Mux_Init_GPIO();
	
	OLED_ShowString(1,1, "Voltage:");
	OLED_ShowString(2,1, "Temp:");
	OLED_ShowString(2,11, ".");
	OLED_ShowString(3,1, "ADValue:");\
	while(1)
	{
		ADValue = AD_GetValue();
		temp = temp_AD(ADValue);
		
		Voltage = (float)ADValue/4095 *3.3; //1.750V 17C
		
		
		
		OLED_ShowNum(1,9, Voltage, 1);
		OLED_ShowNum(1, 11, (uint16_t)(Voltage * 1000) % 1000, 3);
		
		
		OLED_ShowNum(2,9, temp, 2);
		OLED_ShowNum(2, 12, (uint16_t)(temp * 100) % 100, 2);
		
		OLED_ShowNum(3, 9, ADValue, 4);
		
		Delay_ms(100);
		
		
		for(uint8_t num; num<9; num++)
		{
			Mux_set(num);
			
			Delay_ms(1);
		}
	}
		
	
}

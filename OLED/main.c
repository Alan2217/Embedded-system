#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
int main(void)
{
	OLED_Init();
	OLED_ShowChar(1, 1, 'A'); 
	OLED_ShowString(2, 1, "Anny");
	OLED_ShowNum(1, 3, 1606,4);
	OLED_ShowSignedNum(2, 5, 3,1);
	OLED_ShowHexNum(3, 1, 0xAA55, 4);
	OLED_ShowBinNum(4, 1, 0xAA55, 16);
	while(1)
	{
		
	}
		
}

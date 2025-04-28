#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MDMA.h"

uint8_t DA[]={0x01,0x02};
uint8_t DB[]={0,0};
int main(void)
{
	OLED_Init();
	
	
	OLED_ShowHexNum(1,1,DA[0],2);
	OLED_ShowHexNum(1,4,DA[1],2);
	
	OLED_ShowHexNum(2,1,DB[0],2);
	OLED_ShowHexNum(2,4,DB[1],2);
	
	
	MDMA_Init((uint32_t)DA,(uint32_t)DB,2 );
	
	OLED_ShowHexNum(3,1,DA[0],2);
	OLED_ShowHexNum(3,4,DA[1],2);
	
	OLED_ShowHexNum(4,1,DB[0],2);
	OLED_ShowHexNum(4,4,DB[1],2);
	
	while(1)
	{
	
		
		
	}
		
}

#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "servo.h"
#include "Key.h"
#include "Serial.h"


uint16_t Num;
uint8_t flag = 0;
float Angle = 0;
uint8_t Time = 0;
uint8_t i;

uint8_t RxData;
int main(void)
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	Serial_Init();
	OLED_ShowString(1,1,"Angle:");
	OLED_ShowString(2,3,"s");
	//OLED_ShowNum(2,1,0,2);
	while(1)
	{
		if (Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			OLED_ShowNum(3,3,RxData,1 );
			if (RxData == 1)
			{
				i = 0;
			while(i<3){
				OLED_ShowNum(2,1,i,2);
				Delay_s (1);
				i = i + 1;
			}
			Angle = 30;
			Servo_SetAngle(Angle);
			OLED_ShowNum(1,7,Angle,3);
			Delay_s (2);
			Servo_SetAngle(0);
			}
		}
		
	}
		
}


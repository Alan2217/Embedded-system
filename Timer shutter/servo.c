#include "stm32f10x.h"
#include "PWM.h"

void Servo_Init(void)
{
	PWM_init();
}

void Servo_SetAngle(float Angle)
{
	CCR_SET(Angle / 180 * 2000+ 500);
}
	
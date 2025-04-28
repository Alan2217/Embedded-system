#ifndef __COUNTER_SENSOR_H
#define __COUNTER_SENSOR_H

void CounterSenor_Init(void);
void EXTI15_10_IRQHandler(void);
uint16_t CounterSensorGet(void);
#endif
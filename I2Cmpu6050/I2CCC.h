#ifndef _I2CCC_H
#define _I2CCC_H

void I2CCC_W_SCL(uint8_t BitValue);
void I2CCC_W_SDA(uint8_t BitValue);
uint8_t I2CCC_R_SDA(void);
	
void I2CCC_Init(void);
void I2CCC_Start(void);
void I2CCC_Stop(void);
void I2CCC_SendByte(uint8_t Byte);		//when the SLC go 1,will send the data
uint8_t I2CCC_ReceiveByte(void);
void I2CCC_SendACK(uint8_t ACKBit);	
uint8_t I2CCC_ReceiveACK(void);

#endif
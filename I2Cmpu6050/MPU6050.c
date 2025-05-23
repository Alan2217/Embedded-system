#include "stm32f10x.h"
#include "Delay.h"
#include "I2CCC.h"
#include "MPU6050_Reg.h"
#define MPU6050_ADDRESS 0xD0

void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data)
{
	I2CCC_Start();
	I2CCC_SendByte(MPU6050_ADDRESS);
	I2CCC_ReceiveACK();
	I2CCC_SendByte(RegAddress);
	I2CCC_ReceiveACK();
	I2CCC_SendByte(Data);
	I2CCC_ReceiveACK();
	I2CCC_Stop();
	
}

uint8_t MPU6050_ReadReg(uint8_t RegAddress)
{
	uint8_t Data;
	
	I2CCC_Start();
	I2CCC_SendByte(MPU6050_ADDRESS);
	I2CCC_ReceiveACK();
	I2CCC_SendByte(RegAddress);
	I2CCC_ReceiveACK();
	
	I2CCC_Start();
	I2CCC_SendByte(MPU6050_ADDRESS | 0x01);
	I2CCC_ReceiveACK();
	Data = I2CCC_ReceiveByte();
	I2CCC_SendACK(1);
	I2CCC_Stop();
	
	return Data;
}

void MPU6050_Init(void)
{
	I2CCC_Init();
	MPU6050_WriteReg(MPU6050_PWR_MGMT_1,0x01);
	MPU6050_WriteReg(MPU6050_PWR_MGMT_2,0x00);
	MPU6050_WriteReg(MPU6050_SMPLRT_DIV,0x09);
	MPU6050_WriteReg(MPU6050_CONFIG,0x06);
	MPU6050_WriteReg(MPU6050_GYRO_CONFIG,0x18);
	MPU6050_WriteReg(MPU6050_ACCEL_CONFIG,0x18);
		
}

void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ, 
						int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ)
{
	uint8_t DataH,DataL;
	
	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);
	DataL= MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);
	*AccX = (DataH<<8)|DataL;
	
	DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);
	DataL= MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);
	*AccY = (DataH<<8)|DataL;
	
	DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);
	DataL= MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);
	*AccZ = (DataH<<8)|DataL;

	DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);
	DataL= MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);
	*GyroX = (DataH<<8)|DataL;
	
	DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);
	DataL= MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);
	*GyroY = (DataH<<8)|DataL;
	
	DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);
	DataL= MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);
	*GyroZ = (DataH<<8)|DataL;
}
/*******************************************************************************************************************************************************

 * Copyright 2019 <WIZnet Co.,Ltd.>
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the ��Software��),
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.


 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*********************************************************************************************************************************************************/
/**
  ******************************************************************************

  * @file    GPIO_I2C/i2c.h
  * @author  IRINA
  * @version V1.0.0
  * @date    15-MAY-2019
  ******************************************************************************
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2C_H
#define __I2C_H
/* Includes ------------------------------------------------------------------*/
#include "W7500x.h"
#include "W7500x_gpio.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup GPIO_I2C
 * @{
 */
/* Exported types ------------------------------------------------------------*/
#define I2C_PORT(X) (((uint32_t)(X) ) & 0xF)    // port number (0=A, 1=B, 2=C, 3=D)
#define I2C_PIN_INDEX(X)  (1 << ((uint32_t)(X) & 0xF))    // pin index : flag bit

/** @defgroup Direction_enumeration
 * @{
 */
typedef enum
{

    PORT_PA=0,
    PORT_PB,
    PORT_PC
}PORT_Type;


typedef struct
{
	PORT_Type  scl_port;
	uint32_t  scl_pin;
	PORT_Type sda_port;
	uint32_t sda_pin;

}I2C_ConfigStruct;


typedef enum
{
	NACK = 0,
	ACK = 1
}ACK_TypeDef;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint32_t I2C_Init(I2C_ConfigStruct* conf);
/* Control GPIO INPUT or OUTPUT*/
void I2C_SDA_MODE(I2C_ConfigStruct* conf,GPIODirection_TypeDef Set_VAULE);
/*MaKe the I2C condition using the GPIO */
void I2C_Start(I2C_ConfigStruct* conf);
void I2C_Stop(I2C_ConfigStruct* conf);
void I2C_WriteBitSDA(I2C_ConfigStruct* conf, uint8_t data);
void I2C_WriteBitSCL(I2C_ConfigStruct* conf, uint8_t data);
uint8_t I2C_ReadBitSDA(I2C_ConfigStruct* conf);
void I2C_SendACK(I2C_ConfigStruct* conf);
void I2C_SendNACK(I2C_ConfigStruct* conf);
uint8_t I2C_WriteByte(I2C_ConfigStruct* conf, uint8_t data);
uint8_t I2C_ReadByte(I2C_ConfigStruct* conf, ACK_TypeDef SetValue);

/*simple data transmission and received*/
int I2C_Write(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len);
int I2C_WriteRepeated(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len);
int I2C_Read(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len);
int I2C_ReadRepeated(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len);


 #endif

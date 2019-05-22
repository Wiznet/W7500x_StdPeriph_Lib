/*******************************************************************************************************************************************************

 * Copyright 2019 <WIZnet Co.,Ltd.>
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the ï¿½ï¿½Softwareï¿½ï¿½),
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*********************************************************************************************************************************************************/
/**
  ******************************************************************************

  * @file    GPIO_I2C/i2c.c
  * @author  IRINA
  * @version V1.0.0
  * @date    15-MAY-2019
  ******************************************************************************
  *
  ******************************************************************************
  */
/*include -------------------------------------*/
#include <stdio.h>
#include "i2c.h"
#include "W7500x_gpio.h"
/** @addtogroup W7500x_StdPeriph_Examples
 * @{
 */

/** @addtogroup GPIO_I2C
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitDef;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t scl_port_num;
uint32_t scl_pin_index;
uint32_t sda_port_num;
uint32_t sda_pin_index;
/* Private function prototypes -----------------------------------------------*/



/**
 * @brief  I2C Initialaze.
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @retval  0 or  1
 */
uint32_t I2C_Init(I2C_ConfigStruct* conf)
{
    scl_port_num = conf->scl_port;
    scl_pin_index = conf->scl_pin;

    sda_port_num = conf->sda_port;
    sda_pin_index = conf->sda_pin;

    //SCL setting
   GPIO_InitDef.GPIO_Pin = scl_pin_index;
   GPIO_InitDef.GPIO_Direction = GPIO_Direction_OUT;
 	 GPIO_InitDef.GPIO_Pad = GPIO_PuPd_UP;
	 GPIO_InitDef.GPIO_AF =  PAD_AF1;
    if(scl_port_num == 0)
    {
        GPIO_Init(GPIOA, &GPIO_InitDef);
        GPIO_SetBits(GPIOA, scl_pin_index);
    }
    else if(scl_port_num == 1)
    {
        GPIO_Init(GPIOB, &GPIO_InitDef);
        GPIO_SetBits(GPIOB, scl_pin_index);
    }
    else if(scl_port_num == 2)
    {
        GPIO_Init(GPIOC, &GPIO_InitDef);
        GPIO_SetBits(GPIOC, scl_pin_index);
    }
    else
    {
        printf("SCL pin Port number error\r\n");
        return 1;
    }
    //SDA setting
    GPIO_InitDef.GPIO_Pin = sda_pin_index;
    GPIO_InitDef.GPIO_Direction = GPIO_Direction_IN;
	GPIO_InitDef.GPIO_Pad = GPIO_PuPd_UP;
	GPIO_InitDef.GPIO_AF =  PAD_AF1;
    if(sda_port_num == 0)
    {
        GPIO_Init(GPIOA, &GPIO_InitDef);
        GPIO_ResetBits(GPIOA, sda_pin_index);
    }
    else if(sda_port_num == 1)
    {
        GPIO_Init(GPIOB, &GPIO_InitDef);
        GPIO_ResetBits(GPIOB, sda_pin_index);
    }
    else if(sda_port_num == 2)
    {
        GPIO_Init(GPIOC, &GPIO_InitDef);
        GPIO_ResetBits(GPIOC, sda_pin_index);
    }
    else
    {
        printf("SDA pin Port number error\r\n");
        return 1;
    }
    return 0;
}
/**
 * @brief  I2C Write Bir SCL.
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @param  data : Write data
 * @retval  none
 */
void I2C_WriteBitSCL(I2C_ConfigStruct* conf, uint8_t data)
{
    if(scl_port_num == 0)
    {
        if(data == 1)
			GPIO_SetBits(GPIOA, scl_pin_index);
        else
			GPIO_ResetBits(GPIOA, scl_pin_index);
    }
    else if(scl_port_num == 1)
    {

        if(data == 1)
			GPIO_SetBits(GPIOB, scl_pin_index);
        else
			GPIO_ResetBits(GPIOB, scl_pin_index);
    }
    else if(scl_port_num == 2)
    {
        if(data == 1)
			GPIO_SetBits(GPIOC, scl_pin_index);
        else

			GPIO_ResetBits(GPIOC, scl_pin_index);
    }
}
/**
 * @brief  I2C WriteBit SDA.
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @para   data : write data
 * @retval  none
 */
void I2C_WriteBitSDA(I2C_ConfigStruct* conf, uint8_t data)
{
 	if(sda_port_num == 0)
    {
        if(data == 1)
			GPIO_SetBits(GPIOA, sda_pin_index);

        else
			GPIO_ResetBits(GPIOA, sda_pin_index);
    }
	else if(sda_port_num == 1)
    {

        if(data == 1)
			GPIO_SetBits(GPIOB, sda_pin_index);
        else
			GPIO_ResetBits(GPIOB, sda_pin_index);
    }
	else if(sda_port_num == 2)
    {
        if(data == 1)
			GPIO_SetBits(GPIOC, sda_pin_index);

        else
			GPIO_ResetBits(GPIOC, sda_pin_index);
    }

}
/**
 * @brief  I2C Readbit SDA
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @retval  Read GPIO Pin
 */
uint8_t I2C_ReadBitSDA(I2C_ConfigStruct* conf)
{
    if(sda_port_num == 0)
    {
        if(GPIOA->DATA & sda_pin_index)
            return 1;
        else
            return 0;
    }
    else if(sda_port_num == 1)
    {
        if(GPIOB->DATA & sda_pin_index)
            return 1;
        else
            return 0;

    }
    else if(sda_port_num == 2)
    {
        if(GPIOC->DATA & sda_pin_index)
            return 1;
        else
            return 0;
    }
    return 0;
}
/**
 * @brief  I2C Start Condition.
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @retval  none
 */
void I2C_Start(I2C_ConfigStruct* conf)
{
	I2C_SDA_MODE(conf , GPIO_Direction_OUT);

    I2C_WriteBitSCL(conf, 1);
    I2C_WriteBitSDA(conf, 1);

    I2C_WriteBitSDA(conf, 0);
    I2C_WriteBitSCL(conf, 0);

}
/**
 * @brief  I2C Stop Condition.
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @retval  none
 */
void I2C_Stop(I2C_ConfigStruct* conf)
{
	I2C_SDA_MODE(conf , GPIO_Direction_OUT);

	I2C_WriteBitSCL(conf, 0);
    I2C_WriteBitSDA(conf, 0);

    I2C_WriteBitSCL(conf, 1);
    I2C_WriteBitSDA(conf, 1);
	I2C_SDA_MODE(conf , GPIO_Direction_IN);
}
/**
 * @brief  I2C Write Byte for 1byte transmission
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @retval  NACK or ACK
 */
uint8_t I2C_WriteByte(I2C_ConfigStruct* conf, uint8_t data)
{
    int i;
    uint8_t ret;
	uint8_t sda;


    //Write byte
	I2C_SDA_MODE(conf , GPIO_Direction_OUT);
    for(i=0; i<8; i++)
    {

        sda = ((data<<i) & 0x80) ;
		if(sda == 0x80)
			I2C_WriteBitSDA(conf, 1);
		else
			I2C_WriteBitSDA(conf, 0);

        I2C_WriteBitSCL(conf, 1);
        I2C_WriteBitSCL(conf, 0);
    }
    //Make clk for receiving ack
    I2C_SDA_MODE(conf , GPIO_Direction_IN);
	I2C_WriteBitSCL(conf, 1);


    //Read Ack/Nack
    ret = I2C_ReadBitSDA(conf);

    I2C_WriteBitSCL(conf, 0);

    return ret;
}
/**
 * @brief  I2C Send ACK. When W7500x receive the right data, it must send the ACK signal
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @retval  none
 */
void I2C_SendACK(I2C_ConfigStruct* conf)
{
    I2C_WriteBitSDA(conf, 0);
    I2C_WriteBitSCL(conf, 1);
    I2C_WriteBitSCL(conf, 0);
}
/**
 * @brief  I2C Send NACK. When W7500x receive the wrong data or last data before send stop condition, it must send the NACK signal
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @retval  none
 */
void I2C_SendNACK(I2C_ConfigStruct* conf)
{
    I2C_WriteBitSDA(conf, 1);
    I2C_WriteBitSCL(conf, 1);
    I2C_WriteBitSCL(conf, 0);
}
/**
 * @brief  I2C Read Byte.
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @param  SetValue : Select the data, it is NACK or ACK.
 * @retval  none
 */
uint8_t I2C_ReadByte(I2C_ConfigStruct* conf, ACK_TypeDef SetValue)
{
    int i;
    uint8_t ret = 0;

	I2C_SDA_MODE(conf , GPIO_Direction_IN);

    //Read byte
    for(i=0; i<8; i++)
    {
        I2C_WriteBitSCL(conf, 1);
        ret = (ret << 1) | (I2C_ReadBitSDA(conf));
        I2C_WriteBitSCL(conf, 0);
    }
	I2C_SDA_MODE(conf , GPIO_Direction_OUT);


	if(SetValue == NACK )
		I2C_SendNACK(conf);
	else
		I2C_SendACK(conf);

    I2C_SDA_MODE(conf , GPIO_Direction_IN);

    return ret;
}
/**
 * @brief  I2C Write operation.
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @param  addr : slave address
 * @param  data : the data reposity memory
 * @param  len : Data Length
 * @retval  0 or -1
 */
int I2C_Write(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len)
{
    int i;


    I2C_Start(conf);

    //Write addr
    if(I2C_WriteByte(conf, addr) != 0)
    {
        printf("Received NACK at address phase!!\r\n");
        return -1;
    }
    //Write data
    for(i=0; i<len; i++)
    {
        if(I2C_WriteByte(conf, data[i]))  return -1;
    }
    I2C_Stop(conf);
    return 0;//success
}
/**
 * @brief  I2C Write reoeated, it opreates Write operation using new slave address without STOP condition
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @param  addr : slave address
 * @param  data : the data reposity memory
 * @param  len : Data Length
 * @retval  0 or -1
 */
int I2C_WriteRepeated(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len)
{
    int i;

    I2C_Start(conf);


    //Write addr
    if(I2C_WriteByte(conf, addr) != 0)
    {
        printf("Received NACK at address phase!!\r\n");
        return -1;
    }

    //Write data
    for(i=0; i<len; i++)
    {
        if(I2C_WriteByte(conf, data[i]))    return -1;
    }
    return 0;//success
}
/**
 * @brief  I2C Read opreation,
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @param  addr : slave address
 * @param  data : the data reposity memory
 * @param  len : Data Length
 * @retval  0 or -1
 */
int I2C_Read(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len)
{
    int i;

    I2C_Start(conf);


    //Write addr | read command
    if(I2C_WriteByte(conf, (addr | 1)) != 0)
    {
        printf("Received NACK at address phase!!\r\n");
        return -1;
    }
    //Read data
    for(i=0; i<len; i++)
    {
        if( i == (len - 1))
			data[i] = I2C_ReadByte(conf,NACK);
        else
			data[i] = I2C_ReadByte(conf,ACK);

    }
    I2C_Stop(conf);

    return 0;//success
}
/**
 * @brief  I2C read reoeated, it opreates read operation using new slave address without STOP condition
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @param  addr : slave address
 * @param  data : the data reposity memory
 * @param  len : Data Length
 * @retval  0 or -1
 */
int I2C_ReadRepeated(I2C_ConfigStruct* conf, uint8_t addr, uint8_t* data, uint32_t len)
{
    int i;
    I2C_Start(conf);
    //Write addr | read command
    if(I2C_WriteByte(conf, (addr | 1)) != 0)
    {
        printf("Received NACK at address phase!!\r\n");
        return -1;
    }
    //Read data
    for(i=0; i<len; i++)
    {
        if( i == (len - 1))
			data[i] = I2C_ReadByte(conf,NACK);
        else
			data[i] = I2C_ReadByte(conf,ACK);


		I2C_SendACK(conf);
    }
    return 0;//success
}

/**
 * @brief  I2C SDA Mode, it control the GPIO INPUT/OUTPUT (GPIOx->OUTENCLR : GPIO INPUT , GPIOx->OUTENSET : GPIO OUTPUT)
 * @param  conf :  Select the GPIO peripheral for use such as scl and sda of i2c.
 * @param  Set_VAULE : Select the data, it is 0 or 1.
 * @retval  none
 */
// GPIO MODE (Input/Output setting)
void I2C_SDA_MODE(I2C_ConfigStruct* conf,GPIODirection_TypeDef Set_VAULE)
{
    if(sda_port_num == 0)
    {
        if(Set_VAULE == 0)

			GPIOA->OUTENCLR = sda_pin_index; //(GPIO INPUT)
        else
			GPIOA->OUTENSET = sda_pin_index; //(GPIO OUTPUT)
    }
    else if(sda_port_num == 1)
    {
        if(Set_VAULE == 0)
			GPIOB->OUTENCLR = sda_pin_index;
        else
			GPIOB->OUTENSET = sda_pin_index;
    }

    else if(sda_port_num == 2)
    {
        if(Set_VAULE == 0)
			GPIOC->OUTENCLR = sda_pin_index;
        else
			GPIOC->OUTENSET = sda_pin_index;
    }
}

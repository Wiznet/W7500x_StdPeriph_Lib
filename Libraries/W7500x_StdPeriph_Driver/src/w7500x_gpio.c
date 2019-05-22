/**
 ******************************************************************************
 * @file    w7500x_gpio.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the
 *          General-purpose I/Os(GPIO) peripheral.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2018 WIZnet</center></h2>
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/*includes -------------------------------------------*/
#include "w7500x_gpio.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup GPIO
 * @brief GPIO driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup GPIO_Private_Functions
 * @{
 */

/**
 * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
 * @note   By default, The GPIO pins are configured in input floating mode (except JTAG pins).
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @retval None
 */
void GPIO_DeInit(GPIO_TypeDef* GPIOx)
{
    uint32_t i, loop = 16;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    /* DeInit GPIOx Registers */
    GPIOx->OUTENCLR = 0xFFFF;
    GPIOx->INTENCLR = 0xFFFF;
    GPIOx->INTTYPECLR = 0xFFFF;
    GPIOx->INTPOLCLR = 0xFFFF;

    if (GPIOx == GPIOD) loop = 5;

    for (i = 0; i < loop; i++) {
        GPIO_PinAFConfig(GPIOx, i, PAD_AF0);
        GPIO_PinPadConfig(GPIOx, i, GPIO_Pad_Default);
    }
}

/**
 * @brief  Initializes the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that contains
 *         the configuration information for the specified GPIO peripheral.
 * @retval None
 */
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
    uint32_t pinpos = 0x00, pos = 0x00, currentpin = 0x00, loop = 16;
    uint8_t pad_value = 0;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
    assert_param(IS_GPIO_DIRECTION(GPIO_InitStruct->GPIO_Direction));
    assert_param(IS_GPIO_PAD(GPIO_InitStruct->GPIO_Pad));
    assert_param(IS_GPIO_AF(GPIO_InitStruct->GPIO_AF));

    if (GPIOx == GPIOD) loop = 5;

    for (pinpos = 0x00; pinpos < loop; pinpos++) {
        pos = ((uint32_t) 0x01) << pinpos;

        currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

        if (currentpin == pos) {
            if (GPIO_InitStruct->GPIO_Direction == GPIO_Direction_OUT) {
                GPIOx->OUTENSET = pos; /* Output Enable Set Register */
            } else {
                GPIOx->OUTENCLR = pos; /* Output Enable Clear Register */
            }

            pad_value = GPIO_Read_PinPad(GPIOx, pinpos);

            /* Configure pull-up pull-down bits */
            if ((GPIO_InitStruct->GPIO_Pad & GPIO_PuPd_NOPULL) == GPIO_PuPd_NOPULL) {
                pad_value &= ~GPIO_PuPd_NOPULL;
            } else if (GPIO_InitStruct->GPIO_Pad & GPIO_PuPd_DOWN) {
                pad_value &= ~GPIO_PuPd_NOPULL;
                pad_value |= GPIO_PuPd_DOWN;
            } else if (GPIO_InitStruct->GPIO_Pad & GPIO_PuPd_UP) {
                pad_value &= ~GPIO_PuPd_NOPULL;
                pad_value |= GPIO_PuPd_UP;
            } else {
                pad_value &= ~GPIO_PuPd_NOPULL;
            }

            /* Configure Driving strength selections bit */
            if (GPIO_InitStruct->GPIO_Pad & GPIO_LowDrivingStrength) {
                pad_value |= GPIO_LowDrivingStrength;
            } else {
                pad_value &= ~GPIO_LowDrivingStrength;
            }

            /* Configure Open Drain output mode selections bit */
            if (GPIO_InitStruct->GPIO_Pad & GPIO_OpenDrainEnable) {
                pad_value |= GPIO_OpenDrainEnable;
            } else {
                pad_value &= ~GPIO_OpenDrainEnable;
            }

            /* Configure Input buffer enable selection bit */
            if (GPIO_InitStruct->GPIO_Pad & GPIO_InputBufferEnable) {
                pad_value |= GPIO_InputBufferEnable;
            } else {
                pad_value &= ~GPIO_InputBufferEnable;
            }

            /* Configure input type (CMOS input or Summit trigger input) select bit */
            if (GPIO_InitStruct->GPIO_Pad & GPIO_CMOS) {
                pad_value |= GPIO_CMOS;
            } else {
                pad_value &= ~GPIO_CMOS;
            }

            GPIO_PinAFConfig(GPIOx, pinpos, GPIO_InitStruct->GPIO_AF);
            GPIO_PinPadConfig(GPIOx, pinpos, pad_value);
        }
    }
}

/**
 * @brief  Fills each GPIO_InitStruct member with its default value.
 * @param  GPIO_InitStruct : pointer to a GPIO_InitTypeDef structure which will be initialized.
 * @retval None
 */
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
    GPIO_InitStruct->GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStruct->GPIO_Direction = (GPIODirection_TypeDef) GPIO_Direction_IN;
    GPIO_InitStruct->GPIO_Pad = GPIO_Pad_Default;
    GPIO_InitStruct->GPIO_AF = (GPIOAf_TypeDef) (PAD_AF0);
}

/**
 * @brief  Reads the specified input port pin.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the port bit to read.
 *          This parameter can be one of  GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @retval The input port pin value.
 */
BitAction GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    BitAction bitstatus = Bit_RESET;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    /* Check the pin's value*/
    if ((GPIOx->DATA & GPIO_Pin) != (uint32_t) Bit_RESET) {
        bitstatus = Bit_SET;
    } else {
        bitstatus = Bit_RESET;
    }

    /* Return the input port pin value */
    return bitstatus;
}

/**
 * @brief  Reads the specified GPIO input data port.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @retval The input port pin value.
 */
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    /*Return the input port value */
    return (uint16_t) GPIOx->DATA;
}

/** 
 * @brief  Reads the specified output data port bit.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the port bit to read.
 *          This parameter can be one of  GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @retval The output port pin value.
 */
BitAction GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    BitAction bitstatus = Bit_RESET;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->DATAOUT & GPIO_Pin) != (uint32_t) Bit_RESET) {
        bitstatus = Bit_SET;
    } else {
        bitstatus = Bit_RESET;
    }

    return bitstatus;
}

/**
 * @brief  Reads the specified GPIO output data port.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @retval GPIO output data port value.
 */
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    return (uint16_t) GPIOx->DATAOUT;
}

/**
 * @brief  Sets the selected data port bits.
 * @note   This functions uses GPIOx_LB_MASKED and GPIOx_UB_MASKED register to allow atomic read/modify
 *         accesses. In this way, there is no risk of an IRQ occurring between
 *         the read and the modify access.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the port bits to be written.
 *          This parameter can be one of  GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @retval None
 */
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    /* fix bug 2019.05.03 */
    //(GPIOx->LB_MASKED[(uint8_t) (GPIO_Pin)]) = GPIO_Pin;
    //(GPIOx->UB_MASKED[(uint8_t) ((GPIO_Pin) >> 8)]) = GPIO_Pin;
    if (GPIO_Pin < 256)
        (GPIOx->LB_MASKED[(uint8_t) (GPIO_Pin)]) = 0xFFFF;
    else
        (GPIOx->UB_MASKED[(uint8_t) ((GPIO_Pin) >> 8)]) = 0xFFFF;
}

/**
 * @brief  Clears the selected data port bits.
 * @note   This functions uses GPIOx_LB_MASKED and GPIOx_UB_MASKED register to allow atomic read/modify
 *         accesses. In this way, there is no risk of an IRQ occurring between
 *         the read and the modify access.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the port bits to be written.
 *          This parameter can be one of  GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @retval None
 */
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    /* fix bug 2019.05.03 */
    //(GPIOx->LB_MASKED[(uint8_t) (GPIO_Pin)]) = ~(GPIO_Pin);
    //(GPIOx->UB_MASKED[(uint8_t) (GPIO_Pin >> 8)]) = ~(GPIO_Pin);
    if (GPIO_Pin < 256)
        (GPIOx->LB_MASKED[(uint8_t) (GPIO_Pin)]) = 0x0;
    else
        (GPIOx->UB_MASKED[(uint8_t) (GPIO_Pin >> 8)]) = 0x0;
}

/**
 * @brief  Sets or clears the selected data port bit.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the port bit to be written.
 *          This parameter can be one of  GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @param  BitVal: specifies the value to be written to the selected bit.
 *          This parameter can be one of the BitAction enum values:
 *            @arg Bit_RESET: to clear the port pin
 *            @arg Bit_SET: to set the port pin
 * @retval None
 */
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{
    uint32_t temp_gpio_lb;
    uint32_t temp_gpio_ub;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
    assert_param(IS_GPIO_BIT_ACTION(BitVal));

    if (GPIO_Pin < 256)
    {
        if(BitVal)
            (GPIOx->LB_MASKED[(uint8_t) (GPIO_Pin)]) = 0xFFFF;
        else
            (GPIOx->LB_MASKED[(uint8_t) (GPIO_Pin)]) = 0x0;
    }
    else
    {
        if(BitVal)
            (GPIOx->UB_MASKED[(uint8_t) (GPIO_Pin)]) = 0xFFFF;
        else
            (GPIOx->UB_MASKED[(uint8_t) (GPIO_Pin)]) = 0x0;
    }

}

/**
 * @brief  Writes data to the specified GPIO data port.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  PortVal: specifies the value to be written to the port output data register.
 * @retval None
 */
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    GPIOx->DATAOUT = PortVal;
}

/**
 * @brief  Toggles the specified GPIO pins..
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: Specifies the pins to be toggled.
 * @retval None
 */
void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->DATAOUT ^= GPIO_Pin;

}

/**
 * @brief  Initializes the GPIOx peripheral according to the specified parameters in the GPIO_ITInitStruct.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_ITInitStruct: pointer to a GPIO_ITInitTypeDef structure that contains
 *         the configuration information for the specified GPIO peripheral.
 * @retval None
 */
void GPIO_IT_Init(GPIO_TypeDef* GPIOx, GPIO_ITInitTypeDef* GPIO_ITInitStruct)
{
    uint32_t pinpos = 0x00, pos = 0x00, currentpin = 0x00, loop = 16;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_ITInitStruct->GPIO_IT_Pin));
    assert_param(IS_GPIO_IT_POL(GPIO_ITInitStruct->GPIO_IT_Polarity));
    assert_param(IS_GPIO_IT_TYPE(GPIO_ITInitStruct->GPIO_IT_Type));

    if (GPIOx == GPIOD) loop = 5;

    for (pinpos = 0x00; pinpos < loop; pinpos++) {
        pos = ((uint32_t) 0x01) << pinpos;

        currentpin = (GPIO_ITInitStruct->GPIO_IT_Pin) & pos;

        if (currentpin == pos) {

            if (GPIO_ITInitStruct->GPIO_IT_Polarity & GPIO_IT_HighRising) {
                GPIOx->INTTYPESET = currentpin;
            } else {
                GPIOx->INTTYPECLR = currentpin;
            }

            if (GPIO_ITInitStruct->GPIO_IT_Type & GPIO_IT_Edge) {
                GPIOx->INTPOLSET = currentpin;
            } else {
                GPIOx->INTPOLCLR = currentpin;
            }
        }
    }
}

/**
 * @brief  Fills each GPIO_ITInitStruct member with its default value.
 * @param  GPIO_ITInitStruct : pointer to a GPIO_IT_InitTypeDef structure which will be initialized.
 * @retval None
 */
void GPIO_ITStructInit(GPIO_ITInitTypeDef* GPIO_ITInitStruct)
{
    GPIO_ITInitStruct->GPIO_IT_Pin = GPIO_Pin_All;
    GPIO_ITInitStruct->GPIO_IT_Polarity = (GPIOITPol_TypeDef) (GPIO_IT_HighRising);
    GPIO_ITInitStruct->GPIO_IT_Type = (GPIOITType_TypeDef) (GPIO_IT_Edge);
}

/**
 * @brief  Enables or disables the specified GPIOx's pin interrupts.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the GPIO interrupt sources to be enabled or disabled.
 *          This parameter can be one of GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @param  NewState: new state of the specified GPIOx's pin interrupts.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void GPIO_ITConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        GPIOx->INTENSET = GPIO_Pin;
    } else {
        GPIOx->INTENCLR = GPIO_Pin;
    }
}

/**
 * @brief  Checks whether the specified GPIOx's pin interrupt has occurred or not.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the GPIO interrupt source to check.
 *          This parameter can be one of GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @retval The new state of selected data port pin (SET or RESET).
 */
ITStatus GPIO_GetITStatus(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    ITStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->Interrupt.INTSTATUS & GPIO_Pin) != ((uint16_t) Bit_RESET)) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clears the GPIOx's interrupt pending pin.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_Pin: specifies the interrupt pending pin to clear.
 *          This parameter can be one of GPIO_Pin_x where x can be (0..15), except for GPIOD that can be one of (0..5).
 * @retval None
 */
void GPIO_ClearITPendingPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->Interrupt.INTCLEAR = GPIO_Pin;
}

/**
 * @brief  Writes data to the specified AFC data port.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_PinSource: specifies the pin for the Alternate function.
 *          This parameter can be one of GPIO_PinSourcex where x can be (0..15), except for PAD_PD that can be one of (0..5).
 * @param  GPIO_AF: selects the pin to used as Alternate function.
 *          This parameter can be one of the GPIOAf_TypeDef enum values:
 *            @arg PAD_AF0, PAD_AF1, PAD_AF2, PAD_AF3
 * @retval None
 */
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, GPIOAf_TypeDef GPIO_AF)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
    assert_param(IS_GPIO_AF(GPIO_AF));

    if (GPIOx == GPIOA) AFC_PA->REGISTER[GPIO_PinSource] = GPIO_AF;
    else if (GPIOx == GPIOB) AFC_PB->REGISTER[GPIO_PinSource] = GPIO_AF;
    else if (GPIOx == GPIOC) AFC_PC->REGISTER[GPIO_PinSource] = GPIO_AF;
    else AFC_PD->REGISTER[GPIO_PinSource] = GPIO_AF;
}

/**
 * @brief  Read data to the specified AFC data port.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_PinSource: specifies the pin for the Alternate function.
 *          This parameter can be one of GPIO_PinSourcex where x can be (0..15), except for PAD_PD that can be one of (0..5).
 * @retval The Alternate function value.
 */
uint8_t GPIO_Read_PinAF(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));

    if (GPIOx == GPIOA) return (uint8_t) AFC_PA->REGISTER[GPIO_PinSource];
    else if (GPIOx == GPIOB) return (uint8_t) AFC_PB->REGISTER[GPIO_PinSource];
    else if (GPIOx == GPIOC) return (uint8_t) AFC_PC->REGISTER[GPIO_PinSource];
    else return (uint8_t) AFC_PD->REGISTER[GPIO_PinSource];

}

/**
 * @brief  Writes data to the specified PAD data port.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_PinSource: specifies the pin for the Pad function.
 *          This parameter can be one of GPIO_PinSourcex where x can be (0..15), except for PAD_PD that can be one of (0..5).
 * @param  GPIO_Pad: selects the pin to used as Pad function.
 *          This parameter can be one of the GPIOPad_TypeDef enum values:
 * @retval None
 */
void GPIO_PinPadConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint32_t GPIO_Pad)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
    assert_param(IS_GPIO_PAD(GPIO_Pad));

    if (GPIOx == GPIOA) PADCON_PA->REGISTER[GPIO_PinSource] = GPIO_Pad;
    else if (GPIOx == GPIOB) PADCON_PB->REGISTER[GPIO_PinSource] = GPIO_Pad;
    else if (GPIOx == GPIOC) PADCON_PC->REGISTER[GPIO_PinSource] = GPIO_Pad;
    else PADCON_PD->REGISTER[GPIO_PinSource] = GPIO_Pad;
}

/**
 * @brief  Read data to the specified PAD data port.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  GPIO_PinSource: specifies the pin for the Alternate function.
 *          This parameter can be one of GPIO_PinSourcex where x can be (0..15), except for PAD_PD that can be one of (0..5).
 * @retval The Pad function value.
 */
uint8_t GPIO_Read_PinPad(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));

    if (GPIOx == GPIOA) return (uint8_t) PADCON_PA->REGISTER[GPIO_PinSource];
    else if (GPIOx == GPIOB) return (uint8_t) PADCON_PB->REGISTER[GPIO_PinSource];
    else if (GPIOx == GPIOC) return (uint8_t) PADCON_PC->REGISTER[GPIO_PinSource];
    else return (uint8_t) PADCON_PD->REGISTER[GPIO_PinSource];
}

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

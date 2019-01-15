/**
 ******************************************************************************
 * @file    w7500x_ssp.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the
 *          Synchronous Serial Port peripheral.
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

/* Includes ------------------------------------------------------------------*/
#include "w7500x_ssp.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup SSP
 * @brief SSP driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SSP_Private_Functions
 * @{
 */

/**
 * @brief  Deinitializes the SSPx peripheral registers to their default
 *         reset values (Affects also the I2Ss).
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @retval None
 */
void SSP_DeInit(SSP_TypeDef* SSPx)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));

    SSPx->CR0 = 0x00UL;
    SSPx->CR1 = 0x00UL;
    SSPx->DR = 0x00UL;
    SSPx->SR = 0x03UL;
    SSPx->CPSR = 0x00UL;
    SSPx->IMSC = 0x00UL;
    SSPx->DMACR = 0x00UL;
}

/**
 * @brief  Initializes the SSPx peripheral according to the specified 
 *         parameters in the SSP_InitStruct.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  SSP_InitStruct: pointer to a SSP_InitTypeDef structure that
 *         contains the configuration information for the specified SSP peripheral.
 * @retval None
 */
void SSP_Init(SSP_TypeDef* SSPx, SSP_InitTypeDef* SSP_InitStruct)
{
    uint32_t tmpreg = 0;

    /* check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_SSP_CLOCK_RATE(SSP_InitStruct->SSP_ClockRate));
    assert_param(IS_SSP_CPHA(SSP_InitStruct->SSP_CPHA));
    assert_param(IS_SSP_CPOL(SSP_InitStruct->SSP_CPOL));
    assert_param(IS_SSP_FRAMEFORMAT(SSP_InitStruct->SSP_FrameFormat));
    assert_param(IS_SSP_DATASIZE(SSP_InitStruct->SSP_DataSize));
    assert_param(IS_SSP_SOD(SSP_InitStruct->SSP_SOD));
    assert_param(IS_SSP_MODE(SSP_InitStruct->SSP_Mode));
    assert_param(IS_SSP_LBM(SSP_InitStruct->SSP_LBM));
    assert_param(IS_SSP_CLOCK_PRESCALER(SSP_InitStruct->SSP_ClockPrescaler));

    /*---------------------------- SSPx CR0 Configuration ------------------------*/
    /* Get the SSPx CR0 value */
    tmpreg = SSPx->CR0;

    /* Configure clock rate bits */
    tmpreg &= ~SSP_CR0_SCR;
    tmpreg |= (SSP_InitStruct->SSP_ClockRate << 8);

    /* Configure clock phase selections bit */
    if (SSP_InitStruct->SSP_CPHA & SSP_CPHA_2Edge) {
        tmpreg |= SSP_CPHA_2Edge;
    } else {
        tmpreg &= SSP_CPHA_1Edge;
    }

    /* Configure clock polarity selections bit */
    if (SSP_InitStruct->SSP_CPOL & SSP_CPOL_High) {
        tmpreg |= SSP_CPOL_High;
    } else {
        tmpreg &= SSP_CPOL_Low;
    }

    /* Configure Frame Format selections bits */
    if (SSP_InitStruct->SSP_FrameFormat & SSP_FrameFormat_TI) {
        tmpreg &= SSP_FrameFormat_MO;
        tmpreg |= SSP_FrameFormat_TI;
    } else if (SSP_InitStruct->SSP_FrameFormat & SSP_FrameFormat_NA) {
        tmpreg &= SSP_FrameFormat_MO;
        tmpreg |= SSP_FrameFormat_NA;
    } else {
        tmpreg &= SSP_FrameFormat_MO;
    }

    /* Configure Data size bits */
    tmpreg &= ~SSP_CR0_DSS;
    tmpreg |= SSP_InitStruct->SSP_DataSize;

    /* Write to SSPx CR0 */
    SSPx->CR0 = tmpreg;

    /*---------------------------- SSPx CR1 Configuration ------------------------*/
    /* Get the SSPx CR1 value */
    tmpreg = SSPx->CR1;

    /* Configure Slave-mode output selections bit */
    if (SSP_InitStruct->SSP_SOD & SSP_SlaveOut_Disable) {
        tmpreg |= SSP_SlaveOut_Disable;
    } else {
        tmpreg &= SSP_SlaveOut_Enable;
    }

    /* Configure  Master or Slave mode selections bit */
    if (SSP_InitStruct->SSP_Mode & SSP_Mode_Slave) {
        tmpreg |= SSP_Mode_Slave;
    } else {
        tmpreg &= SSP_Mode_Master;
    }

    /* Configure Loop back mode selections bit */
    if (SSP_InitStruct->SSP_LBM & SSP_Loopback_Enable) {
        tmpreg |= SSP_Loopback_Enable;
    } else {
        tmpreg &= SSP_Loopback_Disable;
    }

    /* Write to SSPx CR1 */
    SSPx->CR1 = tmpreg;

    /*---------------------------- SSPx Clock prescale register ------------------------*/
    SSPx->CPSR = SSP_InitStruct->SSP_ClockPrescaler;
}

/**
 * @brief  Fills each SSP_InitStruct member with its default value.
 * @param  SSP_InitStruct : pointer to a SSP_InitTypeDef structure which will be initialized.
 * @retval None
 */
void SSP_StructInit(SSP_InitTypeDef* SSP_InitStruct)
{
    /* SSP_InitStruct members default value */
    SSP_InitStruct->SSP_ClockRate = 0x00;
    SSP_InitStruct->SSP_CPHA = SSP_CPHA_1Edge;
    SSP_InitStruct->SSP_CPOL = SSP_CPOL_Low;
    SSP_InitStruct->SSP_FrameFormat = SSP_FrameFormat_MO;
    SSP_InitStruct->SSP_DataSize = SSP_DataSize_Reserved;

    SSP_InitStruct->SSP_SOD = SSP_SlaveOut_Enable;
    SSP_InitStruct->SSP_Mode = SSP_Mode_Master;
    SSP_InitStruct->SSP_LBM = SSP_Loopback_Disable;
    SSP_InitStruct->SSP_ClockPrescaler = SSP_ClockPrescaler_Reserved;
}

/**
 * @brief  Enables or disables the specified UART peripheral.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  NewState: new state of the SSPx peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void SSP_Cmd(SSP_TypeDef* SSPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        SSPx->CR1 |= SSP_Enable;
    } else {
        SSPx->CR1 &= SSP_Disable;
    }
}

/**
 * @brief  Enables or disables the SS output for the selected SSP.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  NewState: new state of the SSPx SS output.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void SSP_SSOutputCmd(SSP_TypeDef* SSPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Enable the selected SSP SS output */
    if (NewState != DISABLE) {
        SSPx->CR1 &= SSP_SlaveOut_Enable;
    } else {
        SSPx->CR1 |= SSP_SlaveOut_Disable;
    }
}

/**
 * @brief  Transmits a Data through the SSPx/I2Sx peripheral.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  Data : Data to be transmitted.
 * @retval None
 */
void SSP_SendData(SSP_TypeDef* SSPx, uint16_t Data)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));

    /* Write in the DR register the data to be sent */
    SSPx->DR = Data;
}

/**
 * @brief  Returns the most recent received data by the SSPx/I2Sx peripheral.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @retval The value of the received data.
 */
uint16_t SSP_ReceiveData(SSP_TypeDef* SSPx)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));

    /* Return the data in the DR register */
    return (uint16_t) SSPx->DR;
}

/**
 * @brief  Enables or disables the SSPx/I2Sx DMA interface.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  SSP_DMAReq: specifies the SSP DMA transfer request to be enabled or disabled.
 *          This parameter can be any combination of the following values:
 *            @arg SSP_DMAReq_Tx: Tx buffer DMA transfer request
 *            @arg SSP_DMAReq_Rx: Rx buffer DMA transfer request
 * @param  NewState: new state of the selected SSP DMA transfer request.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void SSP_DMACmd(SSP_TypeDef* SSPx, uint32_t SSP_DMAReq, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_SSP_DMAREQ(SSP_DMAReq));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Enable the selected SSP DMA requests */
    if (NewState != DISABLE) {
        SSPx->DMACR |= SSP_DMAReq;
    } else {
        SSPx->DMACR &= ~SSP_DMAReq;
    }
}

/**
 * @brief  Enables or disables the specified SSP/I2S interrupts.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  SSP_IT: specifies the SSP interrupt source to be enabled or disabled.
 *          This parameter can be any combination of the following values:
 *            @arg SSP_IT_TX: Transmit FIFO interrupt
 *            @arg SSP_IT_RX: Receive FIFO interrupt
 *            @arg SSP_IT_RT: Receive timeout interrupt
 *            @arg SSP_IT_ROR: Receive overrun interrupt
 * @param  NewState: new state of the specified SSP/I2S interrupt.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void SSP_ITConfig(SSP_TypeDef* SSPx, uint32_t SSP_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_SSP_CONFIG_IT(SSP_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Enable the selected SSP/I2S interrupt */
    if (NewState != DISABLE) {
        SSPx->IMSC |= SSP_IT;
    } else {
        SSPx->IMSC &= ~SSP_IT;
    }
}

/**
 * @brief  Checks whether the specified SSP flag is set or not.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  SSP_FLAG: specifies the SSP flag to check. 
 *          This parameter can be one of the following values:
 *            @arg SSP_FLAG_BSY : SSP busy flag
 *            @arg SSP_FLAG_RFF : Receive FIFO full flag
 *            @arg SSP_FLAG_RNE : Receive FIFO not empty flag
 *            @arg SSP_FLAG_TNF : Transmit FIFO not full flag
 *            @arg SSP_FLAG_TFE : Transmit FIFO empty flag
 * @retval The new state of SSP_FLAG (SET or RESET).
 */
FlagStatus SSP_GetFlagStatus(SSP_TypeDef* SSPx, uint32_t SSP_FLAG)
{
    FlagStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_SSP_GET_FLAG(SSP_FLAG));

    /* Check the status of the specified SSP/I2S flag */
    if ((SSPx->SR & SSP_FLAG)) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    /* Return the SSP_I2S_FLAG status */
    return bitstatus;
}

/**
 * @brief  Checks whether the specified SSP interrupt has occurred or not.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  SSP_IT: specifies the SSP interrupt source to check. 
 *          This parameter can be one of the following values:
 *            @arg SSP_IT_TX: Transmit FIFO interrupt
 *            @arg SSP_IT_RX: Receive FIFO interrupt
 *            @arg SSP_IT_RT: Receive timeout interrupt
 *            @arg SSP_IT_ROR: Receive overrun interrupt
 * @retval The new state of SSP_IT (SET or RESET).
 */
ITStatus SSP_GetITStatus(SSP_TypeDef* SSPx, uint32_t SSP_IT)
{
    ITStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_SSP_GET_IT(SSP_IT));

    /* Check the status of the specified SSP interrupt */
    if (SSPx->MIS & SSP_IT) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    /* Return the SSP_IT status */
    return bitstatus;
}

/**
 * @brief  Clears the SSPx CRC Error (CRCERR) interrupt pending bit.
 * @param  SSPx: where x can be from 0 to 1 to select the SSP peripheral.
 *          This parameter can be one of the following values:
 *            @arg SSP0
 *            @arg SSP1
 * @param  SSP_IT: specifies the SSP interrupt pending bit to clear.
 * @retval None
 */
void SSP_ClearITPendingBit(SSP_TypeDef* SSPx, uint32_t SSP_IT)
{
    /* Check the parameters */
    assert_param(IS_SSP_ALL_PERIPH(SSPx));
    assert_param(IS_SSP_CLEAR_IT(SSP_IT));

    /* Clear the selected SSP  interrupt pending bit */
    SSPx->ICR |= SSP_IT;
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


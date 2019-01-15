/**
 ******************************************************************************
 * @file    w7500x_uart.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Universal
 *          asynchronous receiver transmitter (UART)
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
#include "w7500x_uart.h"
#include "system_w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup UART
 * @brief UART driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup UART_Private_Functions
 * @{
 */

/**
 * @brief  Deinitializes the UART peripheral registers to their
 *         default reset values.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @retval None
 */
void UART_DeInit(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    if (UARTx == UART0) {
        UART0->DR = 0x00UL;
        UART0->STATUS.ECR = 0x00UL;
        UART0->ILPR = 0x00UL;
        UART0->IBRD = 0x00UL;
        UART0->FBRD = 0x00UL;
        UART0->LCR_H = 0x00UL;
        UART0->CR = 0x0300;
        UART0->IFLS = 0x12UL;
        UART0->IMSC = 0x00UL;
        UART0->ICR = 0;
        UART0->DMACR = 0;
    } else {
        UART1->DR = 0x00UL;
        UART1->STATUS.ECR = 0x00UL;
        UART1->ILPR = 0x00UL;
        UART1->IBRD = 0x00UL;
        UART1->FBRD = 0x00UL;
        UART1->LCR_H = 0x00UL;
        UART1->CR = 0x0300;
        UART1->IFLS = 0x12UL;
        UART1->IMSC = 0x00UL;
        UART1->ICR = 0;
        UART1->DMACR = 0;
    }
}

/**
 * @brief  Initializes the UART peripheral according to the specified
 *         parameters in the USART_InitStruct.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure
 *         that contains the configuration information for the
 *         specified UART peripheral.
 * @retval None
 */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef* UART_InitStruct)
{
    float baud_divisor;
    uint32_t tmpreg = 0x00, uartclock = 0x00;
    uint32_t integer_baud = 0x00, fractional_baud = 0x00;

    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLength));
    assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
    assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
    assert_param(IS_UART_HARDWARE_FLOW_CONTROL(UART_InitStruct->UART_HardwareFlowControl));
    assert_param(IS_UART_MODE(UART_InitStruct->UART_Mode));

    UARTx->CR &= ~(UART_CR_UARTEN);

    uartclock = GetSystemClock() / (1 << CRG->UARTCLK_PVSR);

    /*----------------------------- UARTx IBRD and FBRD Configuration ------------------------------*/
    baud_divisor = ((float) uartclock / (16 * UART_InitStruct->UART_BaudRate));
    integer_baud = (uint32_t) baud_divisor;
    fractional_baud = (uint32_t) ((baud_divisor - integer_baud) * 64 + 0.5);

    UARTx->IBRD = integer_baud;
    UARTx->FBRD = fractional_baud;

    tmpreg = UARTx->LCR_H;
    tmpreg &= ~(0x00EE);
    tmpreg |= (UART_InitStruct->UART_WordLength | UART_InitStruct->UART_StopBits | UART_InitStruct->UART_Parity);
    UARTx->LCR_H = tmpreg;

    tmpreg = UARTx->CR;
    tmpreg &= ~(UART_CR_CTSEn | UART_CR_RTSEn | UART_CR_RXE | UART_CR_TXE | UART_CR_UARTEN);
    tmpreg |= (UART_InitStruct->UART_Mode | UART_InitStruct->UART_HardwareFlowControl);
    UARTx->CR = tmpreg;
}

/**
 * @brief  Fills each UART_InitStruct member with its default value.
 * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure
 *         which will be initialized.
 * @retval None
 */
void UART_StructInit(UART_InitTypeDef* UART_InitStruct)
{
    /* UART_InitStruct members default value */
    UART_InitStruct->UART_BaudRate = 115200;
    UART_InitStruct->UART_WordLength = UART_WordLength_8b;
    UART_InitStruct->UART_StopBits = UART_StopBits_1;
    UART_InitStruct->UART_Parity = UART_Parity_No;
    UART_InitStruct->UART_Mode = UART_Mode_Rx | UART_Mode_Tx;
    UART_InitStruct->UART_HardwareFlowControl = UART_HardwareFlowControl_None;
}

/**
 * @brief  Enables or disables the specified UART peripheral.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  NewState: new state of the UARTx peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void UART_Cmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        UARTx->CR |= UART_CR_UARTEN;
    } else {
        UARTx->CR &= ~UART_CR_UARTEN;
    }
}

/**
 * @brief  UART_FIFO_Enable
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  RX_FIFONumber
 *	        This parameter can be one of the following values:
 *            @arg UART_IFLS_RXIFLSEL7_8
 *            @arg UART_IFLS_RXIFLSEL3_4
 *            @arg UART_IFLS_RXIFLSEL1_2
 *            @arg UART_IFLS_RXIFLSEL1_4
 *            @arg UART_IFLS_RXIFLSEL1_8
 * @param  TX_FIFONumber
 *	        This parameter can be one of the following values:
 *            @arg UART_IFLS_TXIFLSEL7_8
 *            @arg UART_IFLS_TXIFLSEL3_4
 *            @arg UART_IFLS_TXIFLSEL1_2
 *            @arg UART_IFLS_TXIFLSEL1_4
 *            @arg UART_IFLS_TXIFLSEL1_8
 * @retval None
 */
void UART_FIFO_Enable(UART_TypeDef *UARTx, uint32_t RX_FIFONumber, uint32_t TX_FIFONumber)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_RX_FIFO(RX_FIFONumber));
    assert_param(IS_UART_TX_FIFO(TX_FIFONumber));

    UARTx->LCR_H |= UART_LCR_H_FEN;
    UARTx->IFLS = RX_FIFONumber | TX_FIFONumber;
}

/**
 * @brief  UART_FIFO_Disable
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @retval None
 */
void UART_FIFO_Disable(UART_TypeDef *UARTx)
{
    UARTx->LCR_H &= ~UART_LCR_H_FEN;
}

/**
 * @brief  Transmits break characters.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @retval None
 */
void UART_SendBreak(UART_TypeDef* UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->LCR_H |= UART_LCR_H_BRK;
}

/**
 * @brief  Deinitializes the UART2 peripheral registers to their
 *         default reset values.
 * @param  None
 * @retval None
 */
void S_UART_DeInit(void)
{
    UART2->SR = 0x00UL;
    UART2->CR = 0x00UL;
    UART2->INT.ICR = 0x00UL;
    UART2->BDR = 0x00UL;
}

/**
 * @brief  Initializes the UART2 peripheral
 * @param  baud
 * @retval None
 */
void S_UART_Init(uint32_t baud)
{
    uint32_t uartclock = 0x00, integer_baud = 0x00;

    uartclock = GetSystemClock();

    /* Set (Calculate) integer_baud */
    integer_baud = (uint32_t) (uartclock / baud);

    /* Write UART2 BAUDDIV */
    UART2->BDR = integer_baud;
}

/**
 * @brief  Enables or disables the UART2 peripheral.
 * @param  NewState: new state of the UART2 peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void S_UART_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        UART2->CR |= (S_UART_CTRL_FLAG_RX | S_UART_CTRL_FLAG_TX);
    } else {
        UART2->CR &= ~(S_UART_CTRL_FLAG_RX | S_UART_CTRL_FLAG_TX);
    }
}

/**
 * @brief  Transmits single data through the UARTx peripheral.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  Data: the data to transmit.
 * @retval None
 */
void UART_SendData(UART_TypeDef* UARTx, uint16_t Data)
{
    /*  Check the parameters    */
    assert_param(IS_UART_PERIPH(UARTx));

    while (UART_GetFlagStatus(UARTx, UART_FLAG_TXFF) == SET)
        continue;
    UARTx->DR = Data;
}

/**
 * @brief  Returns the most recent received data by the UARTx peripheral.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @retval The received data.
 */
uint16_t UART_ReceiveData(UART_TypeDef* UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint16_t) (UARTx->DR);
}

/**
 * @brief  Transmits single data through the UART2 peripheral.
 * @param  Data: the data to transmit.
 * @retval None
 */
void S_UART_SendData(uint16_t Data)
{
    while (UART2->SR & S_UART_FLAG_TXF)
        ;
    /* Write UART2 DATA */
    UART2->DR = Data;
}

/**
 * @brief  Returns the most recent received data by the UART2 peripheral.
 * @retval The received data.
 */
uint16_t S_UART_ReceiveData(void)
{
    return (uint16_t) UART2->DR;
}

/**
 * @brief  Enables or disables the specified UART interrupts.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_IT: specifies the USART interrupt sources to be enabled or disabled.
 *          This parameter can be any combination of the following values:
 *            @arg UART_IT_OEIM:    Overrun error interrupt
 *            @arg UART_IT_BEIM:    Break error interrupt
 *            @arg UART_IT_PEIM:    Parity error interrupt
 *            @arg UART_IT_FEIM:    Framing error interrupt
 *            @arg UART_IT_RTIM:    Receive timeout interrupt
 *            @arg UART_IT_TXIM:    Transmit interrupt
 *            @arg UART_IT_RXIM:    Receive interrupt
 *            @arg UART_IT_DSRMIM:  UARTDSR modem interrupt
 *            @arg UART_IT_DCDMIM:  UARTDCD modem interrupt
 *            @arg UART_IT_CTSMIM:  UARTCTS modem interrupt
 *            @arg UART_IT_RIMIM:   UARTRI modem  interrupt
 * @param  NewState: new state of the specified UARTx interrupts.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void UART_ITConfig(UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_IT(UART_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        UARTx->IMSC |= UART_IT;
    } else {
        UARTx->IMSC &= ~UART_IT;
    }

}

/**
 * @brief  Checks whether the specified UART flag is set or not.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_FLAG: specifies the flag to check.
 *          This parameter can be one of the following values:
 *            @arg UART_FLAG_RI:    Ring indicator flag
 *            @arg UART_FLAG_TXFE:  Transmit FIFO empty flag
 *            @arg UART_FLAG_RXFF:  Receive FIFO full flag
 *            @arg UART_FLAG_TXFF:  Transmit FIFO full flag
 *            @arg UART_FLAG_RXFE:  Receive FIFO empty flag
 *            @arg UART_FLAG_BUSY:  UART busy flag
 *            @arg UART_FLAG_DCD:   Data carrier detect flag
 *            @arg UART_FLAG_DSR:   Data set ready flag
 *            @arg UART_FLAG_CTS:   Clear to send flag
 * @retval The new state of UART_FLAG (SET or RESET).
 */
FlagStatus UART_GetFlagStatus(UART_TypeDef* UARTx, uint32_t UART_FLAG)
{
    FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_FLAG(UART_FLAG));

    if ((UARTx->FR & UART_FLAG) != (uint16_t) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Checks whether the specified UART interrupt has occurred or not.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_IT: specifies the UART interrupt source to check.
 *          This parameter can be one of the following values:
 *            @arg UART_IT_OEIM:    Overrun error interrupt
 *            @arg UART_IT_BEIM:    Break error interrupt
 *            @arg UART_IT_PEIM:    Parity error interrupt
 *            @arg UART_IT_FEIM:    Framing error interrupt
 *            @arg UART_IT_RTIM:    Receive timeout interrupt
 *            @arg UART_IT_TXIM:    Transmit interrupt
 *            @arg UART_IT_RXIM:    Receive interrupt
 *            @arg UART_IT_DSRMIM:  UARTDSR modem interrupt
 *            @arg UART_IT_DCDMIM:  UARTDCD modem interrupt
 *            @arg UART_IT_CTSMIM:  UARTCTS modem interrupt
 *            @arg UART_IT_RIMIM:   UARTRI modem  interrupt
 * @retval The new state of UART_IT (SET or RESET).
 */
ITStatus UART_GetITStatus(UART_TypeDef* UARTx, uint32_t UART_IT)
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_IT(UART_IT));

    if ((UARTx->MIS & UART_IT) != ((uint16_t) RESET)) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clears the UART interrupt pending bits.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_IT: specifies the UART interrupt source to clear.
 *          This parameter can be one of the following values:
 *            @arg UART_IT_OEIM:    Overrun error interrupt
 *            @arg UART_IT_BEIM:    Break error interrupt
 *            @arg UART_IT_PEIM:    Parity error interrupt
 *            @arg UART_IT_FEIM:    Framing error interrupt
 *            @arg UART_IT_RTIM:    Receive timeout interrupt
 *            @arg UART_IT_TXIM:    Transmit interrupt
 *            @arg UART_IT_RXIM:    Receive interrupt
 *            @arg UART_IT_DSRMIM:  UARTDSR modem interrupt
 *            @arg UART_IT_DCDMIM:  UARTDCD modem interrupt
 *            @arg UART_IT_CTSMIM:  UARTCTS modem interrupt
 *            @arg UART_IT_RIMIM:   UARTRI modem  interrupt
 * @retval None
 */
void UART_ClearITPendingBit(UART_TypeDef* UARTx, uint16_t UART_IT)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_IT(UART_IT));

    /* Set ICR */
    UARTx->ICR |= UART_IT;
}

/**
 * @brief  Checks the specified UART receive status.
 * @note   The received data character must be read first from the UARTDR Register.
 *         and then reading the error status associated with that data character from the UARTRSR Register.
 *         This read sequence cannot be reversed
 *         because the UARTRSR Register is updated only when a read occurs from the UARTDR Register.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_RECV_STATUS: specifies the receive status to check.
 *          This parameter can be one of the following values:
 *            @arg UART_RECV_STATUS_OE: Overrun error
 *            @arg UART_RECV_STATUS_BE: Break error
 *            @arg UART_RECV_STATUS_PE: Parity error
 *            @arg UART_RECV_STATUS_FE: Framing error
 * @retval The new state of UART_RECV_STATUS (SET or RESET).
 */
FlagStatus UART_GetRecvStatus(UART_TypeDef* UARTx, uint32_t UART_RECV_STATUS)
{
    FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_RECV_STATUS(UART_RECV_STATUS));

    if ((UARTx->STATUS.RSR & UART_RECV_STATUS) != (uint32_t) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clear the specified UART receive status.
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_RECV_STATUS: specifies the receive status to clear.
 *          This parameter can be one of the following values:
 *            @arg UART_RECV_STATUS_OE: Overrun error
 *            @arg UART_RECV_STATUS_BE: Break error
 *            @arg UART_RECV_STATUS_PE: Parity error
 *            @arg UART_RECV_STATUS_FE: Framing error
 * @retval None
 */
void UART_ClearRecvStatus(UART_TypeDef* UARTx, uint32_t UART_RECV_STATUS)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_RECV_STATUS(UART_RECV_STATUS));

    /* Set STATUS.ECR*/
    UARTx->STATUS.ECR = (uint16_t) UART_RECV_STATUS;
}

/**
 * @brief  Enables or disables the UART2 interrupts.
 * @param  S_UART_IT: specifies the UART2 interrupt sources to be enabled or disabled.
 *          This parameter can be any combination of the following values:
 *            @arg S_UART_CTRL_FLAG_RXOI:  RX overrun interrupt enable
 *            @arg S_UART_CTRL_FLAG_TXOI:  TX overrun interrupt enable
 *            @arg S_UART_CTRL_FLAG_RXI:   RX interrupt enable
 *            @arg S_UART_CTRL_FLAG_TXI:   TX interrupt enable
 * @param  NewState: new state of the specified UARTx interrupts.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void S_UART_ITConfig(uint32_t S_UART_IT, FunctionalState NewState)
{
    /*	Check the parameters	*/
    assert_param(IS_S_UART_CTRL_IT_FLAG(S_UART_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        UART2->CR |= S_UART_IT;
    } else {
        UART2->CR &= ~S_UART_IT;
    }

}

/**
 * @brief  Checks whether the specified UART2 flag is set or not.
 * @param  SUART_FLAG: specifies the flag to check.
 *          This parameter can be one of the following values:
 *            @arg S_UART_FLAG_RXO:   RX buffer overrun
 *            @arg S_UART_FLAG_TXO:   TX buffer overrun
 *            @arg S_UART_FLAG_RXF:   RX buffer full
 *            @arg S_UART_FLAG_TXF:   TX buffer full
 * @retval The new state of UART_FLAG (SET or RESET).
 */
FlagStatus S_UART_GetFlagStatus(uint32_t S_UART_FLAG)
{
    FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_S_UART_FLAG(S_UART_FLAG));

    if ((UART2->SR & S_UART_FLAG) != (FlagStatus) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clears the UART2 pending flags.
 * @param  SUART_FLAG: specifies the flag to clear.
 *          This parameter can be one of the following values:
 *            @arg S_UART_FLAG_RXO:   RX buffer overrun
 *            @arg S_UART_FLAG_TXO:   TX buffer overrun
 * @retval None
 */
void S_UART_ClearFlag(uint32_t S_UART_FLAG)
{
    /* Check the parameters */
    assert_param(IS_S_UART_CLEAR_FLAG(S_UART_FLAG));

    UART2->SR |= S_UART_FLAG;
}

/**
 * @brief  Checks whether the UART2 interrupt has occurred or not.
 * @param  S_UART_IT: the UART2 interrupt source to check.
 *          This parameter can be one of the following values:
 *            @arg S_UART_IT_RXOI: Overrun error interrupt
 *            @arg S_UART_IT_TXOI: Break error interrupt
 *            @arg S_UART_IT_RXI:  Parity error interrupt
 *            @arg S_UART_IT_TXI:  Framing error interrupt
 * @retval The new state of S_UART_IT (SET or RESET).
 */
ITStatus S_UART_GetITStatus(uint32_t S_UART_IT)
{
    ITStatus bitstatus = RESET;

    /* Check the parameters	*/
    assert_param(IS_S_UART_IT(S_UART_IT));

    if ((UART2->INT.ISR & (S_UART_IT)) != (uint16_t) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clears the SUART interrupt pending bits.
 * @param  S_UART_IT: the UART2 interrupt source to check.
 *          This parameter can be one of the following values:
 *            @arg S_UART_IT_RXOI: Overrun error interrupt
 *            @arg S_UART_IT_TXOI: Break error interrupt
 *            @arg S_UART_IT_RXI:  Parity error interrupt
 *            @arg S_UART_IT_TXI:  Framing error interrupt
 * @retval None
 */
void S_UART_ClearITPendingBit(uint32_t S_UART_IT)
{
    /* Check the parameters	*/
    assert_param(IS_S_UART_IT(S_UART_IT));

    /* Write UART2 INT.CLEAR: S_UART_INSTATUS */
    UART2->INT.ICR = S_UART_IT;
}

/**
 * @brief  UART_DMA_Config
 * @param  UARTx: where x can be from 0 to 1 to select the UART peripheral.
 *          This parameter can be one of the following values:
 *            @arg UART0
 *            @arg UART1
 * @param  UART_DMA_CONTROL
 * @retval None
 */
void UART_DMA_Config(UART_TypeDef* UARTx, uint16_t UART_DMA_CONTROL)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_DMA_CONTROL(UART_DMA_CONTROL));

    /*Set DMACR */
    UARTx->DMACR |= UART_DMA_CONTROL;
    NVIC_EnableIRQ(UART1_IRQn);
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

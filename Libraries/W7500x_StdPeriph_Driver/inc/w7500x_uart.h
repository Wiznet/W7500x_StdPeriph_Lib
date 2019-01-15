/**
 ******************************************************************************
 * @file    w7500x_uart.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Universal
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __W7500X_UART_H
#define __W7500X_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup UART
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/** 
 * @brief  UART Init Structure definition
 */
typedef struct
{
    uint32_t UART_BaudRate;
    uint16_t UART_WordLength;
    uint16_t UART_StopBits;
    uint16_t UART_Parity;
    uint16_t UART_Mode;
    uint16_t UART_HardwareFlowControl;
} UART_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup UART_Exported_Constants 
 * @{
 */

#define IS_UART_PERIPH(PERIPH)      (((PERIPH) == UART0) || ((PERIPH) == UART1))

/** @defgroup UART_Word_Length
 * @{
 */

#define UART_WordLength_8b          UART_LCR_H_WLEN_0 | UART_LCR_H_WLEN_1
#define UART_WordLength_7b          UART_LCR_H_WLEN_1
#define UART_WordLength_6b          UART_LCR_H_WLEN_0
#define UART_WordLength_5b          0x00UL

#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WordLength_8b) || \
                                     ((LENGTH) == UART_WordLength_7b) || \
                                     ((LENGTH) == UART_WordLength_6b) || \
                                     ((LENGTH) == UART_WordLength_5b) )
/**
 * @}
 */

/** @defgroup UART_Parity
 * @{
 */

#define UART_Parity_No              0x00UL
#define UART_Parity_Even            UART_LCR_H_PEN | UART_LCR_H_EPS
#define UART_Parity_Odd             UART_LCR_H_PEN

#define IS_UART_PARITY(PARITY)      (((PARITY) == UART_Parity_No) || \
                                     ((PARITY) == UART_Parity_Even) || \
                                     ((PARITY) == UART_Parity_Odd))
/**
 * @}
 */

/** @defgroup UART_Stop_Bits
 * @{
 */

#define UART_StopBits_1             0x00UL
#define UART_StopBits_2             UART_LCR_H_STP2

#define IS_UART_STOPBITS(STOPBITS)  (((STOPBITS) == UART_StopBits_1) || \
                                     ((STOPBITS) == UART_StopBits_2))
/**
 * @}
 */

/** @defgroup UART_Mode
 * @{
 */

#define UART_Mode_Rx        UART_CR_RXE
#define UART_Mode_Tx        UART_CR_TXE

#define IS_UART_MODE(MODE)  (((MODE) == UART_Mode_Rx) || \
                             ((MODE) == UART_Mode_Tx) || \
                             ((MODE) == (UART_Mode_Rx | UART_Mode_Tx)))
/**
 * @}
 */

/** @defgroup UART_Hardware_Flow_Control
 * @{
 */

#define UART_HardwareFlowControl_None           0x00UL
#define UART_HardwareFlowControl_RTS            UART_CR_RTSEn
#define UART_HardwareFlowControl_CTS            UART_CR_CTSEn
#define UART_HardwareFlowControl_RTS_CTS        UART_CR_RTSEn | UART_CR_CTSEn

#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)  (((CONTROL) == UART_HardwareFlowControl_None) || \
                                                 ((CONTROL) == UART_HardwareFlowControl_RTS) || \
                                                 ((CONTROL) == UART_HardwareFlowControl_CTS) || \
                                                 ((CONTROL) == UART_HardwareFlowControl_RTS_CTS))
/**
 * @}
 */

/** @defgroup UART_DMA_Control
 * @{
 */

#define UART_DMAControl_DMAONERR        UART_DMACR_DMAONERR
#define UART_DMAControl_RXDMAE          UART_DMACR_TXDMAE
#define UART_DMAControl_TXDMAE          UART_DMACR_RXDMAE

#define IS_UART_DMA_CONTROL(CONTROL)    (((CONTROL) == UART_DMAControl_DMAONERR) || \
                                         ((CONTROL) == UART_DMAControl_TXDMAE) || \
										 ((CONTROL) == UART_DMAControl_RXDMAE))
/**
 * @}
 */

/** @defgroup UART_Receive Status
 * @{
 */

#define UART_RECV_STATUS_OE         UARTR_SR_OE
#define UART_RECV_STATUS_BE         UARTR_SR_BE
#define UART_RECV_STATUS_PE         UARTR_SR_PE
#define UART_RECV_STATUS_FE         UARTR_SR_FE

#define IS_UART_RECV_STATUS(STATUS) (((STATUS) == UART_RECV_STATUS_OE) || ((STATUS) == UART_RECV_STATUS_BE) || \
                                     ((STATUS) == UART_RECV_STATUS_PE) || ((STATUS) == UART_RECV_STATUS_FE))
/**
 * @}
 */

/** @defgroup UART_Flags
 * @{
 */

#define UART_FLAG_RI                UART_FR_RI
#define UART_FLAG_TXFE              UART_FR_TXFE
#define UART_FLAG_RXFF              UART_FR_RXFF
#define UART_FLAG_TXFF              UART_FR_TXFF
#define UART_FLAG_RXFE              UART_FR_RXFE
#define UART_FLAG_BUSY              UART_FR_BUSY
#define UART_FLAG_DCD               UART_FR_DCD
#define UART_FLAG_DSR               UART_FR_DSR
#define UART_FLAG_CTS               UART_FR_CTS

#define IS_UART_FLAG(FLAG)          (((FLAG) == UART_FLAG_RI)   || ((FLAG) == UART_FLAG_TXFE) || \
                                     ((FLAG) == UART_FLAG_RXFF) || ((FLAG) == UART_FLAG_TXFF) || \
                                     ((FLAG) == UART_FLAG_RXFE) || ((FLAG) == UART_FLAG_BUSY) || \
                                     ((FLAG) == UART_FLAG_DCD)  || ((FLAG) == UART_FLAG_DSR)  || \
                                     ((FLAG) == UART_FLAG_CTS))

/**
 * @}
 */

/** @defgroup UART_Interrupt_definition
 * @brief UART Interrupt definition
 * @{
 */

#define UART_IT_OEIM            UART_IMSC_OEIM
#define UART_IT_BEIM            UART_IMSC_BEIM
#define UART_IT_PEIM            UART_IMSC_PEIM
#define UART_IT_FEIM            UART_IMSC_FEIM
#define UART_IT_RTIM            UART_IMSC_RTIM
#define UART_IT_TXIM            UART_IMSC_TXIM
#define UART_IT_RXIM            UART_IMSC_RXIM
#define UART_IT_DSRMIM          UART_IMSC_DSRMIM
#define UART_IT_DCDMIM          UART_IMSC_DCDMIM
#define UART_IT_CTSMIM          UART_IMSC_CTSMIM
#define UART_IT_RIMIM           UART_IMSC_RIMIM

#define IS_UART_IT(IT)          (((IT) & UART_IT_OEIM)|| \
                                 ((IT) & UART_IT_BEIM)|| \
                                 ((IT) & UART_IT_PEIM)|| \
                                 ((IT) & UART_IT_FEIM)|| \
                                 ((IT) & UART_IT_RTIM)|| \
                                 ((IT) & UART_IT_TXIM)|| \
                                 ((IT) & UART_IT_RXIM)|| \
                                 ((IT) & UART_IT_DSRMIM)|| \
                                 ((IT) & UART_IT_DCDMIM)|| \
                                 ((IT) & UART_IT_CTSMIM)|| \
                                 ((IT) & UART_IT_RIMIM))

/**
 * @}
 */

/** @defgroup UART_FIFO_Level Select
 * @{
 */

#define UART_IFLS_RXIFLSEL7_8   UART_IFLS_RXIFLSEL_2
#define UART_IFLS_RXIFLSEL3_4   UART_IFLS_RXIFLSEL_0 | UART_IFLS_RXIFLSEL_1
#define UART_IFLS_RXIFLSEL1_2   UART_IFLS_RXIFLSEL_1
#define UART_IFLS_RXIFLSEL1_4   UART_IFLS_RXIFLSEL_0
#define UART_IFLS_RXIFLSEL1_8   ~UART_IFLS_RXIFLSEL

#define IS_UART_RX_FIFO(FIFO)   (((FIFO) == UART_IFLS_RXIFLSEL7_8) || \
		                         ((FIFO) == UART_IFLS_RXIFLSEL3_4) || \
								 ((FIFO) == UART_IFLS_RXIFLSEL1_2) || \
	                             ((FIFO) == UART_IFLS_RXIFLSEL1_4) || \
                                 ((FIFO) == UART_IFLS_RXIFLSEL1_8))

#define UART_IFLS_TXIFLSEL7_8   UART_IFLS_TXIFLSEL_2
#define UART_IFLS_TXIFLSEL3_4   UART_IFLS_TXIFLSEL_0 | UART_IFLS_TXIFLSEL_1
#define UART_IFLS_TXIFLSEL1_2   UART_IFLS_TXIFLSEL_1
#define UART_IFLS_TXIFLSEL1_4   UART_IFLS_TXIFLSEL_0
#define UART_IFLS_TXIFLSEL1_8   ~UART_IFLS_TXIFLSEL

#define IS_UART_TX_FIFO(FIFO)   (((FIFO) == UART_IFLS_TXIFLSEL7_8) || \
                                 ((FIFO) == UART_IFLS_TXIFLSEL3_4) || \
                                 ((FIFO) == UART_IFLS_TXIFLSEL1_2) || \
                                 ((FIFO) == UART_IFLS_TXIFLSEL1_4) || \
                                 ((FIFO) == UART_IFLS_TXIFLSEL1_8))
/**
 * @}
 */

/** @defgroup S_UART_Flags
 * @{
 */

#define S_UART_FLAG_RXO             S_UART_SR_RXO
#define S_UART_FLAG_TXO             S_UART_SR_TXO
#define S_UART_FLAG_RXF             S_UART_SR_RXBF
#define S_UART_FLAG_TXF             S_UART_SR_TXBF

#define IS_S_UART_FLAG(FLAG)        (((FLAG) == S_UART_FLAG_RXO) || \
                                     ((FLAG) == S_UART_FLAG_TXO) || \
                                     ((FLAG) == S_UART_FLAG_RXF) || \
                                     ((FLAG) == S_UART_FLAG_TXF))

#define IS_S_UART_CLEAR_FLAG(FLAG)  (((FLAG) == S_UART_FLAG_RXO) || \
                                     ((FLAG) == S_UART_FLAG_TXO))
/**
 * @}
 */

/** @defgroup S_UART_CTRL_Flags
 * @{
 */

#define S_UART_CTRL_FLAG_RXOI           S_UART_CR_ROIE
#define S_UART_CTRL_FLAG_TXOI           S_UART_CR_TOIE
#define S_UART_CTRL_FLAG_RXI            S_UART_CR_RXIE
#define S_UART_CTRL_FLAG_TXI            S_UART_CR_TXIE
#define S_UART_CTRL_FLAG_RX             S_UART_CR_RXE
#define S_UART_CTRL_FLAG_TX             S_UART_CR_TXE

#define IS_S_UART_CTRL_FLAG(FLAG)       (((FLAG) == S_UART_CTRL_FLAG_RX)   || \
		                                 ((FLAG) == S_UART_CTRL_FLAG_TX))

#define IS_S_UART_CTRL_IT_FLAG(FLAG)    (((FLAG) == S_UART_CTRL_FLAG_RXOI) || \
                                         ((FLAG) == S_UART_CTRL_FLAG_TXOI) || \
                                         ((FLAG) == S_UART_CTRL_FLAG_RXI)  || \
                                         ((FLAG) == S_UART_CTRL_FLAG_TXI))
/**
 * @}
 */

/** @defgroup S_UART_IT_Flags
 * @{
 */

#define S_UART_IT_RXOI          S_UART_ISR_RXOI
#define S_UART_IT_TXOI          S_UART_ISR_TXOI
#define S_UART_IT_RXI           S_UART_ISR_RXI
#define S_UART_IT_TXI           S_UART_ISR_TXI

#define IS_S_UART_IT(IT)        (((IT) == S_UART_IT_RXOI) || \
                                 ((IT) == S_UART_IT_TXOI) || \
                                 ((IT) == S_UART_IT_RXI)  || \
                                 ((IT) == S_UART_IT_TXI))
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void UART_DeInit(UART_TypeDef *UARTx);
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef* UART_InitStruct);
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);
void UART_Cmd(UART_TypeDef *UARTx, FunctionalState NewState);

void UART_FIFO_Enable(UART_TypeDef *UARTx, uint32_t RX_FIFONumber, uint32_t TX_FIFONumber);
void UART_FIFO_Disable(UART_TypeDef *UARTx);
void UART_SendBreak(UART_TypeDef* UARTx);

void S_UART_DeInit(void);
void S_UART_Init(uint32_t baud);
void S_UART_Cmd(FunctionalState NewState);

/* Data transfers functions ***************************************************/
void UART_SendData(UART_TypeDef* UARTx, uint16_t Data);
uint16_t UART_ReceiveData(UART_TypeDef* UARTx);

void S_UART_SendData(uint16_t Data);
uint16_t S_UART_ReceiveData(void);

/* Interrupts and flags management functions **********************************/
void UART_ITConfig(UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState);
FlagStatus UART_GetFlagStatus(UART_TypeDef* UARTx, uint32_t UART_FLAG);
ITStatus UART_GetITStatus(UART_TypeDef* UARTx, uint32_t UART_IT);
void UART_ClearITPendingBit(UART_TypeDef* UARTx, uint16_t UART_IT);
FlagStatus UART_GetRecvStatus(UART_TypeDef* UARTx, uint32_t UART_RECV_STATUS);
void UART_ClearRecvStatus(UART_TypeDef* UARTx, uint32_t UART_RECV_STATUS);

void S_UART_ITConfig(uint32_t S_UART_IT, FunctionalState NewState);
FlagStatus S_UART_GetFlagStatus(uint32_t S_UART_FLAG);
void S_UART_ClearFlag(uint32_t S_UART_FLAG);
ITStatus S_UART_GetITStatus(uint32_t S_UART_IT);
void S_UART_ClearITPendingBit(uint32_t S_UART_IT);

/* DMA transfers management functions *****************************************/
void UART_DMA_Config(UART_TypeDef* UARTx, uint16_t UART_DMA_CONTROL);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_UART_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

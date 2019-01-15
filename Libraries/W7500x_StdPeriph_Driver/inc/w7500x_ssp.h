/**
 ******************************************************************************
 * @file    w7500x_ssp.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Synchronous
  *         Serial Port firmware library.
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
#ifndef __W7500X_SSP_H
#define __W7500X_SSP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup SSP
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/** 
 * @brief  SSP Init structure definition
 */

typedef struct
{

    uint32_t SSP_ClockRate;             /*!<  */

    uint32_t SSP_CPHA;                  /*!< Specifies the clock active edge for the bit capture.
                                             This parameter can be a value of @ref SSP_Clock_Phase */
    uint32_t SSP_CPOL;                  /*!< Specifies the serial clock steady state.
                                             This parameter can be a value of @ref SSP_Clock_Polarity */
    uint32_t SSP_FrameFormat;           /*!<  */

    uint32_t SSP_DataSize;              /*!< Specifies the SSP data size.
                                             This parameter can be a value of @ref SSP_data_size */
    uint32_t SSP_SOD;                   /*!< Specifies the Slave-mode output disable.
                                             This parameter can be a value of @ref SSP slave mode */
    uint32_t SSP_Mode;                  /*!< Specifies the SSP operating mode.
                                             This parameter can be a value of @ref SSP_mode */
    uint32_t SSP_LBM;                   /*!< Specifies whether the Loopback mode.
                                             This parameter can be a value of @ref SSP_Loop back mode */

    uint32_t SSP_ClockPrescaler;        /*!< Specifies the Baud Rate prescaler value which will be
                                             used to configure the transmit and receive SCK clock.
                                             This parameter can be a value of @ref SSP_BaudRate_Prescaler.
                                             @note The communication clock is derived from the master
                                             clock. The slave clock does not need to be set. */
} SSP_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup SSP_Exported_Constants
 * @{
 */

#define IS_SSP_ALL_PERIPH(PERIPH)       (((PERIPH) == SSP0) || \
                                         ((PERIPH) == SSP1))

#define IS_SSP_CLOCK_RATE(RATE)         (((RATE) > 0) && ((RATE) < 0xFF))

/** @defgroup SSP_Clock_Phase 
 * @{
 */

#define SSP_CPHA_1Edge      ~SSP_CR0_SPH
#define SSP_CPHA_2Edge      SSP_CR0_SPH
#define IS_SSP_CPHA(CPHA)   (((CPHA) == SSP_CPHA_1Edge) || \
                             ((CPHA) == SSP_CPHA_2Edge))
/**
 * @}
 */

/** @defgroup SSP_Clock_Polarity 
 * @{
 */

#define SSP_CPOL_Low        ~SSP_CR0_SPO
#define SSP_CPOL_High       SSP_CR0_SPO
#define IS_SSP_CPOL(CPOL)   (((CPOL) == SSP_CPOL_Low) || \
                             ((CPOL) == SSP_CPOL_High))
/**
 * @}
 */

/** @defgroup SSP_Frame_Format 
 * @{
 */
#define SSP_FrameFormat_MO                  ~SSP_CR0_FRF
#define SSP_FrameFormat_TI                  SSP_CR0_FRF_0
#define SSP_FrameFormat_NA                  SSP_CR0_FRF_1

#define IS_SSP_FRAMEFORMAT(FRAMEFORMAT)     (((FRAMEFORMAT) == SSP_FrameFormat_MO) || \
                                             ((FRAMEFORMAT) == SSP_FrameFormat_TI) || \
                                             ((FRAMEFORMAT) == SSP_FrameFormat_NA))
/**
 * @}
 */

/** @defgroup SSP_data_size 
 * @{
 */
#define SSP_DataSize_Reserved       (0x0UL)
#define SSP_DataSize_4b             (0x3UL)
#define SSP_DataSize_5b             (0x4UL)
#define SSP_DataSize_6b             (0x5UL)
#define SSP_DataSize_7b             (0x6UL)
#define SSP_DataSize_8b             (0x7UL)
#define SSP_DataSize_9b             (0x8UL)
#define SSP_DataSize_10b            (0x9UL)
#define SSP_DataSize_11b            (0xAUL)
#define SSP_DataSize_12b            (0xBUL)
#define SSP_DataSize_13b            (0xCUL)
#define SSP_DataSize_14b            (0xDUL)
#define SSP_DataSize_15b            (0xEUL)
#define SSP_DataSize_16b            (0xFUL)
#define IS_SSP_DATASIZE(DATASIZE)   (((DATASIZE) == SSP_DataSize_Reserved) || \
                                     ((DATASIZE) == SSP_DataSize_4b) || \
                                     ((DATASIZE) == SSP_DataSize_5b) || \
                                     ((DATASIZE) == SSP_DataSize_6b) || \
                                     ((DATASIZE) == SSP_DataSize_7b) || \
                                     ((DATASIZE) == SSP_DataSize_8b) || \
                                     ((DATASIZE) == SSP_DataSize_9b) || \
                                     ((DATASIZE) == SSP_DataSize_10b)  || \
                                     ((DATASIZE) == SSP_DataSize_11b)  || \
                                     ((DATASIZE) == SSP_DataSize_12b)  || \
                                     ((DATASIZE) == SSP_DataSize_13b)  || \
                                     ((DATASIZE) == SSP_DataSize_14b)  || \
                                     ((DATASIZE) == SSP_DataSize_15b)  || \
                                     ((DATASIZE) == SSP_DataSize_16b))
/**
 * @}
 */

/** @defgroup SSP_Slave-mode output disable
 * @{
 */

#define SSP_SlaveOut_Enable     ~SSP_CR1_SOD
#define SSP_SlaveOut_Disable    SSP_CR1_SOD
#define IS_SSP_SOD(SOD)         (((SOD) == SSP_SlaveOut_Disable) || \
                                 ((SOD) == SSP_SlaveOut_Enable))
/**
 * @}
 */

/** @defgroup SSP_mode 
 * @{
 */

#define SSP_Mode_Master     ~SSP_CR1_MS
#define SSP_Mode_Slave      SSP_CR1_MS
#define IS_SSP_MODE(MODE)   (((MODE) == SSP_Mode_Master) || \
                             ((MODE) == SSP_Mode_Slave))
/**
 * @}
 */

/** @defgroup SSP_Synchronous serial port Enable
 * @{
 */

#define SSP_Disable         ~SSP_CR1_SSE
#define SSP_Enable          SSP_CR1_SSE
#define IS_SSP_SSE(SSE)     (((SSE) == SSP_Enable) || \
                             ((SSE) == SSP_Disable))
/**
 * @}
 */

/** @defgroup SSP_Loop back mode
 * @{
 */

#define SSP_Loopback_Disable    ~SSP_CR1_LBM
#define SSP_Loopback_Enable     SSP_CR1_LBM
#define IS_SSP_LBM(LBM)         (((LBM) == SSP_Loopback_Disable) || \
                                 ((LBM) == SSP_Loopback_Enable))
/**
 * @}
 */

/** @defgroup SSP_BaudRate_Prescaler 
 * @{
 */

#define SSP_ClockPrescaler_Reserved          (0x0000UL)
#define SSP_ClockPrescaler_2                 (0x0002UL)
#define SSP_ClockPrescaler_4                 (0x0004UL)
#define SSP_ClockPrescaler_8                 (0x0008UL)
#define SSP_ClockPrescaler_16                (0x0010UL)
#define SSP_ClockPrescaler_32                (0x0020UL)
#define SSP_ClockPrescaler_64                (0x0040UL)
#define SSP_ClockPrescaler_128               (0x0080UL)
#define SSP_ClockPrescaler_254               (0x00FEUL)
#define IS_SSP_CLOCK_PRESCALER(PRESCALER)    (((PRESCALER) == SSP_ClockPrescaler_2) || \
                                              ((PRESCALER) == SSP_ClockPrescaler_4) || \
                                              ((PRESCALER) == SSP_ClockPrescaler_8) || \
                                              ((PRESCALER) == SSP_ClockPrescaler_16) || \
                                              ((PRESCALER) == SSP_ClockPrescaler_32) || \
                                              ((PRESCALER) == SSP_ClockPrescaler_64) || \
                                              ((PRESCALER) == SSP_ClockPrescaler_128) || \
                                              ((PRESCALER) == SSP_ClockPrescaler_254))
/**
 * @}
 */

/** @defgroup SSP_Flags
 * @{
 */
#define SSP_FLAG_BSY            SSP_SR_BSY
#define SSP_FLAG_RFF            SSP_SR_RFF
#define SSP_FLAG_RNE            SSP_SR_RNE
#define SSP_FLAG_TNF            SSP_SR_TNF
#define SSP_FLAG_TFE            SSP_SR_TFE
#define IS_SSP_GET_FLAG(FLAG)   (((FLAG) == SSP_FLAG_BSY) || \
                                 ((FLAG) == SSP_FLAG_RFF) || \
                                 ((FLAG) == SSP_FLAG_RNE) || \
                                 ((FLAG) == SSP_FLAG_TNF) || \
                                 ((FLAG) == SSP_FLAG_TFE))
/**
 * @}
 */

/** @defgroup SSP_Interrupt_definition
 * @brief SSP Interrupt definition
 * @{
 */

#define SSP_IT_TX               SSP_IMSC_TXIM
#define SSP_IT_RX               SSP_IMSC_RXIM
#define SSP_IT_RT               SSP_IMSC_RTIM
#define SSP_IT_ROR              SSP_IMSC_RORIM

#define IS_SSP_CONFIG_IT(IT)    (((IT) & SSP_IT_TX) || \
                                 ((IT) & SSP_IT_RX) || \
                                 ((IT) & SSP_IT_RT) || \
                                 ((IT) & SSP_IT_ROR))

#define IS_SSP_GET_IT(IT)       (((IT) == SSP_IT_TX) || \
                                 ((IT) == SSP_IT_RX) || \
                                 ((IT) == SSP_IT_RT) || \
                                 ((IT) == SSP_IT_ROR))

#define IS_SSP_CLEAR_IT(IT)     (((IT) == SSP_IT_RT) || \
                                 ((IT) == SSP_IT_ROR))
/**
 * @}
 */


#if 1
/** @defgroup SSP_DMA_transfer_requests 
 * @{
 */

#define SSP_DMAReq_Tx               (0x0002)
#define SSP_DMAReq_Rx               (0x0001)
#define IS_SSP_DMAREQ(DMAREQ)       (((DMAREQ) & SSP_DMAReq_Tx) || \
                                     ((DMAREQ) & SSP_DMAReq_Rx))
/**
 * @}
 */
#endif

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void SSP_DeInit(SSP_TypeDef* SSPx);
void SSP_Init(SSP_TypeDef* SSPx, SSP_InitTypeDef* SSP_InitStruct);
void SSP_StructInit(SSP_InitTypeDef* SSP_InitStruct);
void SSP_Cmd(SSP_TypeDef* SSPx, FunctionalState NewState);
void SSP_DataSizeConfig(SSP_TypeDef* SSPx, uint16_t SSP_DataSize);
void SSP_SSOutputCmd(SSP_TypeDef* SSPx, FunctionalState NewState);

/* Data transfers functions ***************************************************/
void SSP_SendData(SSP_TypeDef* SSPx, uint16_t Data);
uint16_t SSP_ReceiveData(SSP_TypeDef* SSPx);

/* DMA transfers management functions *****************************************/
void SSP_DMACmd(SSP_TypeDef* SSPx, uint32_t SSP_DMAReq, FunctionalState NewState);

/* Interrupts and flags management functions **********************************/
void SSP_ITConfig(SSP_TypeDef* SSPx, uint32_t SSP_IT, FunctionalState NewState);
FlagStatus SSP_GetFlagStatus(SSP_TypeDef* SSPx, uint32_t SSP_FLAG);
ITStatus SSP_GetITStatus(SSP_TypeDef* SSPx, uint32_t SSP_IT);
void SSP_ClearITPendingBit(SSP_TypeDef* SSPx, uint32_t SSP_IT);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_SSP_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

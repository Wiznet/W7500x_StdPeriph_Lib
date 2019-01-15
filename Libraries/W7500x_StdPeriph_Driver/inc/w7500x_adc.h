/**
 ******************************************************************************
 * @file    w7500x_adc.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Analog-to-
 *          digital converter (ADC) firmware library.
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
#ifndef __W7500X_ADC_H
#define __W7500X_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup ADC
 * @{
 */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup ADC_Exported_Constants
 * @{
 */

/** @defgroup ADC_channels
 * @{
 */

#define ADC_Channel_0               0x00UL
#define ADC_Channel_1               0x01UL
#define ADC_Channel_2               0x02UL
#define ADC_Channel_3               0x03UL
#define ADC_Channel_4               0x04UL
#define ADC_Channel_5               0x05UL
#define ADC_Channel_6               0x06UL
#define ADC_Channel_7               0x07UL
#define ADC_Channel_15              0x0FUL

#define IS_ADC_CHANNEL(CHANNEL)     (((CHANNEL) == ADC_Channel_0)  || \
                                     ((CHANNEL) == ADC_Channel_1)  || \
                                     ((CHANNEL) == ADC_Channel_2)  || \
                                     ((CHANNEL) == ADC_Channel_3)  || \
                                     ((CHANNEL) == ADC_Channel_4)  || \
                                     ((CHANNEL) == ADC_Channel_5)  || \
                                     ((CHANNEL) == ADC_Channel_6)  || \
                                     ((CHANNEL) == ADC_Channel_7)  || \
                                     ((CHANNEL) == ADC_Channel_15))
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void ADC_Cmd(FunctionalState NewState);

/* Channels Configuration functions *******************************************/
void ADC_ChannelConfig(uint32_t ADC_Channel);
void ADC_StartOfConversion(void);
uint16_t ADC_GetConversionValue(void);

/* Interrupts and flags management functions **********************************/
void ADC_ITConfig(FunctionalState NewState);
ITStatus ADC_GetITStatus(void);
void ADC_ClearIT(void);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_ADC_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

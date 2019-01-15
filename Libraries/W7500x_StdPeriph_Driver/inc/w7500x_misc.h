/**
 ******************************************************************************
 * @file    w7500x_misc.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the miscellaneous
 *          firmware library functions (add-on to CMSIS functions).
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
#ifndef __W7500X_MISC_H
#define __W7500X_MISC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup MISC
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/** 
 * @brief  NVIC Init Structure definition
 */

typedef struct
{
    uint8_t NVIC_IRQChannel;            /*!< Specifies the IRQ channel to be enabled or disabled.
                                             This parameter can be a value of @ref IRQn_Type
                                             (For the complete W7500x Devices IRQ Channels list,
                                             please refer to w7500x.h file) */

    uint8_t NVIC_IRQChannelPriority;    /*!< Specifies the priority level for the IRQ channel specified
                                             in NVIC_IRQChannel. This parameter can be a value
                                             between 0 and 3.  */

    FunctionalState NVIC_IRQChannelCmd; /*!< Specifies whether the IRQ channel defined in NVIC_IRQChannel
                                             will be enabled or disabled.
                                             This parameter can be set either to ENABLE or DISABLE */
} NVIC_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup MISC_Exported_Constants
 * @{
 */

/** @defgroup MISC_Preemption_Priority_Group 
 * @{
 */
#define IS_NVIC_PRIORITY(PRIORITY)  ((PRIORITY) < 0x04)

/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_MISC_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

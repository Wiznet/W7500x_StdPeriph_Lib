/**
 ******************************************************************************
 * @file    w7500x_exti.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the External
 *          Interrupt (EXTI) firmware library.
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
#ifndef __W7500X_EXTI_H
#define __W7500X_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"
#include "w7500x_gpio.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup EXTI
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/** @defgroup EXTI Trigger enumeration
 * @{
 */
typedef enum
{
    EXTI_Trigger_High_Level = 0x00UL,
    EXTI_Trigger_Low_Level = EXTI_EXTINT_POL
} EXTITrigger_TypeDef;

#define IS_EXTI_TRIGGER(TRIGGER) (((TRIGGER) == EXTI_Trigger_High_Level) || \
                                  ((TRIGGER) == EXTI_Trigger_Low_Level))
/**
 * @}
 */

/** 
 * @brief  EXTI Init Structure definition
 */
typedef struct
{
    uint32_t EXTI_Line;                 /*!< Specifies the EXTI lines to be enabled or disabled.
                                             This parameter can be any combination of @ref GPIO_pins_define */

    EXTITrigger_TypeDef EXTI_Trigger;   /*!< Specifies the trigger signal active edge for the EXTI lines.
                                             This parameter can be a value of @ref EXTIMode_TypeDef */

} EXTI_InitTypeDef;

/* Exported constants --------------------------------------------------------*/
/** @defgroup EXTI_Exported_Constants
 * @{
 */

/**
 * @}
 */
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void EXTI_DeInit(GPIO_TypeDef* GPIOx);
void EXTI_Init(GPIO_TypeDef* GPIOx, EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_EXTI_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

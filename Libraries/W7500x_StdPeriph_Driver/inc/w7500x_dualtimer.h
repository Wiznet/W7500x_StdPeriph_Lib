/**
 ******************************************************************************
 * @file    w7500x_dualtimer.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Dual timers
 *          firmware library.
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
#ifndef __W7500X_DUALTIMER_H
#define __W7500X_DUALTIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup Dualtimer
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/** @defgroup Wrapping_enumeration
 * @{
 */
typedef enum
{
    DUALTIMER_Free_Running = 0x00,              /*!< Timer is in free-running mode   */
    DUALTIMER_Periodic = DUALTIMER_CONTROL_TM   /*!< Timer is in periodic mode       */
} DUALTIMERWrapping_TypeDef;

#define IS_DUALTIMER_Wrapping(WRAPPING)     (((WRAPPING) == DUALTIMER_Free_Running)|| \
		                                     ((WRAPPING) == DUALTIMER_Periodic))
/**
 * @}
 */

/** @defgroup Prescaler_enumeration
 * @{
 */
typedef enum
{
    DUALTIMER_Prescaler_1 = 0x00,                       /*!< clock is divided by 1      */
    DUALTIMER_Prescaler_16 = DUALTIMER_CONTROL_TP_0,    /*!< clock is divided by 16     */
    DUALTIMER_Prescaler_256 = DUALTIMER_CONTROL_TP_1    /*!< clock is divided by 256    */
} DUALTIMERPrescaler_TypeDef;

#define IS_DUALTIMER_Prescaler(PRESCALER)   (((PRESCALER) == DUALTIMER_Prescaler_1)|| \
		                                     ((PRESCALER) == DUALTIMER_Prescaler_16)|| \
											 ((PRESCALER) == DUALTIMER_Prescaler_256))
/**
 * @}
 */

/** @defgroup Size_enumeration
 * @{
 */
typedef enum
{
    DUALTIMER_Size_16 = 0x00,                   /*!< 16-bit counter */
    DUALTIMER_Size_32 = DUALTIMER_CONTROL_TS    /*!< 32-bit counter */
} DUALTIMERSize_TypeDef;

#define IS_DUALTIMER_Size(SIZE)    (((SIZE) == DUALTIMER_Size_16)|| \
                                    ((SIZE) == DUALTIMER_Size_32))
/**
 * @}
 */

/** @defgroup Repetition_enumeration
 * @{
 */
typedef enum
{
    DUALTIMER_Wrapping = 0x00,                  /*!< Wrapping mode  */
    DUALTIMER_OneShot = DUALTIMER_CONTROL_OC    /*!< One-shot mode  */
} DUALTIMERRepetition_TypeDef;

#define IS_DUALTIMER_Repetition(REPETITION)     (((REPETITION) == DUALTIMER_Wrapping)|| \
                                                 ((REPETITION) == DUALTIMER_OneShot))
/**
 * @}
 */

/**
 * @brief  DUALTIMER Init Structure definition
 */
typedef struct
{
    uint32_t Timer_Load;
    DUALTIMERWrapping_TypeDef Timer_Wrapping;       /*!< Specifies the operating Wrapping for the Timer.
                                                     This parameter can be a value of @ref DUALTIMERWrapping_TypeDef   */
    DUALTIMERPrescaler_TypeDef Timer_Prescaler;     /*!< Specifies the operating Prescaler for the Timer.
                                                     This parameter can be a value of @ref DUALTIMERPrescaler_TypeDef   */
    DUALTIMERSize_TypeDef Timer_Size; /*!< Specifies the operating Size for the Timer.
                                                     This parameter can be a value of @ref DUALTIMERSize_TypeDef   */
    DUALTIMERRepetition_TypeDef Timer_Repetition;   /*!< Specifies the operating Repetition for the Timer.
                                                     This parameter can be a value of @ref DUALTIMERRepetition_TypeDef   */
} DUALTIMER_InitTypDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup DUALTIMER_Exported_Constants
 * @{
 */

/** @defgroup Channels
 * @{
 */

#define IS_DUALTIMER_PERIH(PERIH)   ((PERIH == DUALTIMER0_0) || \
                                     (PERIH == DUALTIMER0_1) || \
                                     (PERIH == DUALTIMER1_0) || \
                                     (PERIH == DUALTIMER1_1))
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void DUALTIMER_DeInit(DUALTIMER_TypeDef* DUALTIMERn);
void DUALTIMER_Init(DUALTIMER_TypeDef* DUALTIMERn, DUALTIMER_InitTypDef* DUALTIMER_InitStruct);
void DUALTIMER_Cmd(DUALTIMER_TypeDef* DUALTIMERn, FunctionalState NewState);
uint32_t DUALTIMER_GetLoad(DUALTIMER_TypeDef* DUALTIMERn);
void DUALTIMER_SetLoad(DUALTIMER_TypeDef* DUALTIMERn, uint32_t TimerLoad);
uint32_t DUALTIMER_GetBGLoad(DUALTIMER_TypeDef* DUALTIMERn);
void DUALTIMER_SetBGLoad(DUALTIMER_TypeDef* DUALTIMERn, uint32_t TimerBGLoad);

/* Interrupts and flags management functions **********************************/
void DUALTIMER_ITConfig(DUALTIMER_TypeDef* DUALTIMERn, FunctionalState NewState);
ITStatus DUALTIMER_GetITStatus(DUALTIMER_TypeDef* DUALTIMERn);
void DUALTIMER_ClearIT(DUALTIMER_TypeDef* DUALTIMERn);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_DUALTIMER_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

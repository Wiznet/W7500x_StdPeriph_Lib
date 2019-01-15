/**
 ******************************************************************************
 * @file    w7500x_pwm.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Pulse-Width
 *          Modulation(PWM) firmware library.
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
#ifndef __W7500X_PWM_H
#define __W7500X_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup PWM
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/**
 * @brief  PWM Init structure definition
 */
typedef struct
{
    uint32_t PWM_Mode;
    uint32_t PWM_Output;
    uint32_t PWM_Capture;
    uint32_t PWM_Prescale_Counter;
    uint32_t PWM_Duty;
    uint32_t PWM_Period;
    uint32_t PWM_UpDown;
    uint32_t PWM_Repetiton;
    uint32_t PWM_DeadZone;
    uint32_t PWM_DeadZone_Counter;
} PWM_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup PWM_Exported_Constants
 * @{
 */

/** @defgroup PWM_Selection
 * @{
 */
#define IS_PWM_ALL_PERIPH(PERIPH)   (((PERIPH) == PWM0) || \
                                     ((PERIPH) == PWM1) || \
									 ((PERIPH) == PWM2) || \
									 ((PERIPH) == PWM3) || \
									 ((PERIPH) == PWM4) || \
									 ((PERIPH) == PWM5) || \
									 ((PERIPH) == PWM6) || \
									 ((PERIPH) == PWM7))
/**
 * @}
 */

/** @defgroup PWM_Mode
 * @{
 */
#define PWM_Mode_Timer              0x00UL
#define PWM_Mode_CounterRising      PWM_CHn_TCMR_TCM_0
#define PWM_Mode_CounterFalling     PWM_CHn_TCMR_TCM_1
#define PWM_Mode_CounterBoth        PWM_CHn_TCMR_TCM

#define IS_PWM_MODE(MODE)           (((MODE) == PWM_Mode_Timer) || \
                                     ((MODE) == PWM_Mode_CounterRising) || \
									 ((MODE) == PWM_Mode_CounterFalling) || \
									 ((MODE) == PWM_Mode_CounterBoth))
/**
 * @}
 */

/** @defgroup PWM_Output
 * @{
 */
#define PWM_Output_OutDisable_InDisable     0x00UL
#define PWM_Output_OutDisable_InEnable      PWM_CHn_PEEER_PEEE_0
#define PWM_Output_OutEnable_InDisable      PWM_CHn_PEEER_PEEE_1

#define IS_PWM_OUTPUT(OUTPUT)               (((OUTPUT) == PWM_Output_OutDisable_InDisable) || \
                                             ((OUTPUT) == PWM_Output_OutDisable_InEnable) || \
                                             ((OUTPUT) == PWM_Output_OutEnable_InDisable))
/**
 * @}
 */

/** @defgroup PWM_Capture
 * @{
 */
#define PWM_Capture_Rising          0x00UL
#define PWM_Capture_Falling         PWM_CHn_CMR_CM

#define IS_PWM_CAPTURE(CAPTURE)     (((CAPTURE) == PWM_Capture_Rising) || \
                                     ((CAPTURE) == PWM_Capture_Falling))
/**
 * @}
 */

/** @defgroup PWM_UpDown
 * @{
 */
#define PWM_UpDown_Up               0x00UL
#define PWM_UpDown_Down             PWM_CHn_UDMR_UDM

#define IS_PWM_UPDOWN(UPDOWN)       (((UPDOWN) == PWM_UpDown_Up) || \
                                     ((UPDOWN) == PWM_UpDown_Down))
/**
 * @}
 */

/** @defgroup PWM_Repetiton
 * @{
 */
#define PWM_Repetition_Periodic         PWM_CHn_PDMR_PDM
#define PWM_Repetition_Oneshot          0x00UL

#define IS_PWM_REPETITION(REPETITION)   (((REPETITION) == PWM_Repetition_Periodic) || \
                                         ((REPETITION) == PWM_Repetition_Oneshot))
/**
 * @}
 */

/** @defgroup PWM_DeadZone
 * @{
 */
#define PWM_DeadZone_Enable             PWM_CHn_DZER_DZE
#define PWM_DeadZone_Disable            0x00UL

#define IS_PWM_DEADZONE(DEADZONE)       (((DEADZONE) == PWM_DeadZone_Enable) || \
                                         ((DEADZONE) == PWM_DeadZone_Disable))
/**
 * @}
 */

/** @defgroup PWM_Interrupt_definition
 * @{
 */
#define PWM_IT_MI         PWM_CHn_IR_MI
#define PWM_IT_OI         PWM_CHn_IR_OI
#define PWM_IT_CI         PWM_CHn_IR_CI
#define PWM_IT_ALL        PWM_IT_MI|PWM_IT_OI|PWM_IT_CI

#define IS_PWM_CONFIG_IT(IT)    (((IT) == PWM_IT_MI) || \
                                 ((IT) == PWM_IT_OI) || \
                                 ((IT) == PWM_IT_CI) || \
								 ((IT) == PWM_IT_ALL))

#define IS_PWM_GET_IT(IT)       (((IT) == PWM_IT_MI) || \
                                 ((IT) == PWM_IT_OI) || \
                                 ((IT) == PWM_IT_CI))

#define IS_PWM_CLEAR_IT(IT)     (((IT) == PWM_IT_MI) || \
                                 ((IT) == PWM_IT_OI) || \
                                 ((IT) == PWM_IT_CI))
/**
 * @}
 */

/** @defgroup PWM_Global_definition
 * @{
 */
#define IS_PWM_PRESCALE_COUNTER(COUNTER)     (((COUNTER) >= 0x00UL) && ((COUNTER) <= 0x3FUL))
#define IS_PWM_DEADZONE_COUNTER(COUNTER)     (((COUNTER) >= 0x00UL) && ((COUNTER) <= 0x3FFUL))
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void PWM_DeInit(PWM_TypeDef* PWMx);
void PWM_Init(PWM_TypeDef* PWMx, PWM_InitTypeDef* PWM_InitStruct);
void PWM_StructInit(PWM_InitTypeDef* PWM_InitStruct);
void PWM_Cmd(PWM_TypeDef* PWMx, FunctionalState NewState);
void PWM_Pause(PWM_TypeDef* PWMx, FunctionalState NewState);

/* Input Capture management ***************************************************/
uint32_t PWM_GetCapture(PWM_TypeDef* PWMx);
uint32_t PWM_GetCounter(PWM_TypeDef* PWMx);

/* Interrupts and flags management functions **********************************/
void PWM_ITConfig(PWM_TypeDef* PWMx, uint32_t PWM_IT, FunctionalState NewState);
ITStatus PWM_GetITStatus(PWM_TypeDef* PWMx, uint32_t PWM_IT);
void PWM_ClearITPendingBit(PWM_TypeDef* PWMx, uint32_t PWM_IT);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_PWM_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

/**
 ******************************************************************************
 * @file    w7500x_pwm.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Pulse-Width
 *          Modulation(PWM) peripheral.
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

/* Includes -------------------------------------------*/
#include "w7500x_pwm.h"
#include "w7500x_crg.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup PWM
 * @brief PWM driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define PWM_Channel_0                (0x01UL)  /*!< Channel 0 selected    */
#define PWM_Channel_1                (0x02UL)  /*!< Channel 1 selected    */
#define PWM_Channel_2                (0x04UL)  /*!< Channel 2 selected    */
#define PWM_Channel_3                (0x08UL)  /*!< Channel 3 selected    */
#define PWM_Channel_4                (0x10UL)  /*!< Channel 4 selected    */
#define PWM_Channel_5                (0x20UL)  /*!< Channel 5 selected    */
#define PWM_Channel_6                (0x40UL)  /*!< Channel 6 selected    */
#define PWM_Channel_7                (0x80UL)  /*!< Channel 7 selected    */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup PWM_Private_Functions
 * @{
 */

/**
 * @brief  Deinitializes the PWM peripheral registers to their default reset values.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @retval None
 */
void PWM_DeInit(PWM_TypeDef* PWMx)
{
    uint32_t tmpchannel;

    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx == PWM0) tmpchannel = PWM_Channel_0;
    else if (PWMx == PWM1) tmpchannel = PWM_Channel_1;
    else if (PWMx == PWM2) tmpchannel = PWM_Channel_2;
    else if (PWMx == PWM3) tmpchannel = PWM_Channel_3;
    else if (PWMx == PWM4) tmpchannel = PWM_Channel_4;
    else if (PWMx == PWM5) tmpchannel = PWM_Channel_5;
    else if (PWMx == PWM6) tmpchannel = PWM_Channel_6;
    else if (PWMx == PWM7) tmpchannel = PWM_Channel_7;

    PWM->SSR &= ~tmpchannel;            // Start Stop register
    PWM->PSR &= ~tmpchannel;            // Pause register
    PWM->IER &= ~tmpchannel;            // Interrupt enable register

    PWMx->IER = 0;                      // Interrupt enable register
    PWMx->ICR = PWM_CHn_ICR_MIC |
    PWM_CHn_ICR_OIC |
    PWM_CHn_ICR_CIC;                    // Interrupt clear register
    PWMx->PR = 0;                       // Prescale register
    PWMx->MR = 0;                       // Match register
    PWMx->LR = 0xFFFFFFFF;              // Limit register
    PWMx->UDMR = 0;                     // Up Dowm mode register
    PWMx->TCMR = 0;                     // Timer Counter mode register
    PWMx->PEEER = 0;                    // PWM output Enable and External input Enable register
    PWMx->CMR = 0;                      // Capture mode register
    PWMx->PDMR = 0;                     // Periodic Mode register
    PWMx->DZER = 0;                     // Dead Zone Enable register
    PWMx->DZCR = 0;                     // Dead Zone Counter register
}

/**
 * @brief  Initializes the PWM peripheral according to the specified
 *         parameters in the PWM_InitStruct.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @param  PWM_InitStruct: pointer to a PWM_InitStruct structure
 *         that contains the configuration information for the
 *         specified PWM peripheral.
 * @retval None
 */
void PWM_Init(PWM_TypeDef* PWMx, PWM_InitTypeDef* PWM_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_MODE(PWM_InitStruct->PWM_Mode));
    assert_param(IS_PWM_OUTPUT(PWM_InitStruct->PWM_Output));
    assert_param(IS_PWM_CAPTURE(PWM_InitStruct->PWM_Capture));
    assert_param(IS_PWM_PRESCALE_COUNTER(PWM_InitStruct->PWM_Prescale_Counter));
    assert_param(IS_PWM_UPDOWN(PWM_InitStruct->PWM_UpDown));
    assert_param(IS_PWM_REPETITION(PWM_InitStruct->PWM_Repetiton));
    assert_param(IS_PWM_DEADZONE(PWM_InitStruct->PWM_DeadZone));
    assert_param(IS_PWM_DEADZONE_COUNTER(PWM_InitStruct->PWM_DeadZone_Counter));

    PWMx->TCMR = PWM_InitStruct->PWM_Mode;
    PWMx->PEEER = PWM_InitStruct->PWM_Output;
    PWMx->CMR = PWM_InitStruct->PWM_Capture;
    PWMx->PR = PWM_InitStruct->PWM_Prescale_Counter;
    PWMx->MR = PWM_InitStruct->PWM_Duty;
    PWMx->LR = PWM_InitStruct->PWM_Period;
    PWMx->UDMR = PWM_InitStruct->PWM_UpDown;
    PWMx->PDMR = PWM_InitStruct->PWM_Repetiton;
    PWMx->DZER = PWM_InitStruct->PWM_DeadZone;
    PWMx->DZCR = PWM_InitStruct->PWM_DeadZone_Counter;
}

/**
 * @brief  Fills each PWM_InitStruct member with its default value.
 * @param  PWM_InitStruct: pointer to an PWM_InitTypeDef structure which will
 *         be initialized.
 * @retval None
 */
void PWM_StructInit(PWM_InitTypeDef* PWM_InitStruct)
{
    /* Set Match register value */
    PWM_InitStruct->PWM_Mode = PWM_Mode_Timer;
    PWM_InitStruct->PWM_Output = PWM_Output_OutDisable_InDisable;
    PWM_InitStruct->PWM_Capture = PWM_Capture_Rising;
    PWM_InitStruct->PWM_Prescale_Counter = 0;
    PWM_InitStruct->PWM_Duty = 0;
    PWM_InitStruct->PWM_Period = 0xFFFFFFFF;
    PWM_InitStruct->PWM_UpDown = PWM_UpDown_Up;
    PWM_InitStruct->PWM_Repetiton = PWM_Repetition_Periodic;
    PWM_InitStruct->PWM_DeadZone = PWM_DeadZone_Disable;
    PWM_InitStruct->PWM_DeadZone_Counter = 0;
}

/**
 * @brief  Start the PWM operation to select PWM channel.
 * @note	The only difference from the PWM_CHn_Start function is that the format of the parameters is different.
 *						PWM_CHn_Start's parameter is in 32-bit format and this function is in PWM_CHn format.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @param  NewState: new state of the PWMx peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void PWM_Cmd(PWM_TypeDef* PWMx, FunctionalState NewState)
{
    uint32_t tmpchannel;

    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx == PWM0) tmpchannel = PWM_Channel_0;
    else if (PWMx == PWM1) tmpchannel = PWM_Channel_1;
    else if (PWMx == PWM2) tmpchannel = PWM_Channel_2;
    else if (PWMx == PWM3) tmpchannel = PWM_Channel_3;
    else if (PWMx == PWM4) tmpchannel = PWM_Channel_4;
    else if (PWMx == PWM5) tmpchannel = PWM_Channel_5;
    else if (PWMx == PWM6) tmpchannel = PWM_Channel_6;
    else if (PWMx == PWM7) tmpchannel = PWM_Channel_7;

    if (NewState != DISABLE) {
        PWM->SSR |= tmpchannel;
    } else {
        PWM->SSR &= ~tmpchannel;
    }
}

/**
 * @brief  Pause the PWM operation of the selected PWM channel.
 * @note	The only difference from the PWM_Multi_Pause function is that the format of the parameters is different.
 *						PWM_Multi_Pause's parameter is in 32-bit format and this function is in PWM_CHn format.
 *						The Timer/Counter is paused after Timer/Counter is reached to value of limit register unlike controlling the start/stop register immediately stop.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @param  NewState: new state of the PWMx running.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void PWM_Pause(PWM_TypeDef* PWMx, FunctionalState NewState)
{
    uint32_t tmpchannel;

    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx == PWM0) tmpchannel = PWM_Channel_0;
    else if (PWMx == PWM1) tmpchannel = PWM_Channel_1;
    else if (PWMx == PWM2) tmpchannel = PWM_Channel_2;
    else if (PWMx == PWM3) tmpchannel = PWM_Channel_3;
    else if (PWMx == PWM4) tmpchannel = PWM_Channel_4;
    else if (PWMx == PWM5) tmpchannel = PWM_Channel_5;
    else if (PWMx == PWM6) tmpchannel = PWM_Channel_6;
    else if (PWMx == PWM7) tmpchannel = PWM_Channel_7;

    if (NewState != DISABLE) {
        PWM->PSR |= tmpchannel;
    } else {
        PWM->PSR &= ~tmpchannel;
    }
}

/**
 * @brief  Get the current values of the Capture of selected PWM channel.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @retval The Capture register value.
 */
uint32_t PWM_GetCapture(PWM_TypeDef* PWMx)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->CR;
}

/**
 * @brief  Get the current values of the Timer/Counter(TC) of selected PWM channel.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @retval The Timer/Counter register value.
 */
uint32_t PWM_GetCounter(PWM_TypeDef* PWMx)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->TCR;
}

/**
 * @brief  Configures the global Interrupt enable/disable of selected PWM channel.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @param  PWM_IT: specifies the PWM interrupt sources to be enabled or disabled.
 *          This parameter can be one of the following values:
 *            @arg PWM_IT_MI:  Capture Interrupt.
 *            @arg PWM_IT_OI:  Overflow Interrupt.
 *            @arg PWM_IT_CI:  Match Interrupt.
 *            @arg PWM_IT_ALL:  All interrupt.
 * @param  NewState: new state of the PWMx interrupts.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void PWM_ITConfig(PWM_TypeDef* PWMx, uint32_t PWM_IT, FunctionalState NewState)
{
    uint32_t tmpchannel;

    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CONFIG_IT(PWM_IT));

    if (PWMx == PWM0) tmpchannel = PWM_Channel_0;
    else if (PWMx == PWM1) tmpchannel = PWM_Channel_1;
    else if (PWMx == PWM2) tmpchannel = PWM_Channel_2;
    else if (PWMx == PWM3) tmpchannel = PWM_Channel_3;
    else if (PWMx == PWM4) tmpchannel = PWM_Channel_4;
    else if (PWMx == PWM5) tmpchannel = PWM_Channel_5;
    else if (PWMx == PWM6) tmpchannel = PWM_Channel_6;
    else if (PWMx == PWM7) tmpchannel = PWM_Channel_7;

    if (NewState != DISABLE) {
        PWM->IER |= tmpchannel;
        PWMx->IER |= PWM_IT;
    } else {
        PWM->IER &= ~tmpchannel;
        PWMx->IER &= ~PWM_IT;
    }
}

/**
 * @brief  Checks whether the specified PWM interrupt has occurred or not.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @param  PWM_IT: specifies the PWM interrupt source to check.
 *          This parameter can be one of the following values:
 *            @arg PWM_IT_MI:  Capture Interrupt.
 *            @arg PWM_IT_OI:  Overflow Interrupt.
 *            @arg PWM_IT_CI:  Match Interrupt.
 * @retval The new state of PWM_IT (SET or RESET).
 */
ITStatus PWM_GetITStatus(PWM_TypeDef* PWMx, uint32_t PWM_IT)
{
    ITStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_GET_IT(PWM_IT));

    if ((PWMx->IR & PWM_IT) != (uint32_t) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
 * @brief  Clears the PWM interrupt pending bits.
 * @param  PWMx: where x can be from 0 to 7 to select the PWM peripheral.
 * @param  PWM_IT: specifies the PWM interrupt source to clear.
 *          This parameter can be one of the following values:
 *            @arg PWM_IT_MI:  Capture Interrupt.
 *            @arg PWM_IT_OI:  Overflow Interrupt.
 *            @arg PWM_IT_CI:  Match Interrupt.
 * @retval None
 */
void PWM_ClearITPendingBit(PWM_TypeDef* PWMx, uint32_t PWM_IT)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CLEAR_IT(PWM_IT));

    PWMx->ICR |= PWM_IT;
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

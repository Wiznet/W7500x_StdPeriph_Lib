/**
 ******************************************************************************
 * @file    w7500x_dualtimer.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Dual timers
 *          peripheral.
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
#include "w7500x_dualtimer.h"
#include "w7500x_crg.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup Dualtimer
 * @brief Dualtimer driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup Dualtimer_Private_Functions
 * @{
 */

/**
 * @brief  Deinitializes the DUALTIMERn peripheral registers to their default reset values.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @retval None

 */
void DUALTIMER_DeInit(DUALTIMER_TypeDef* DUALTIMERn)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));

    /* Stop the timer */
    DUALTIMER_Cmd(DUALTIMERn, DISABLE);

    DUALTIMERn->LOAD = 0x0;
    DUALTIMERn->CONTROL = 0x20;
    DUALTIMERn->BGLOAD = 0x0;
}

/**
 * @brief  Initializes the DUALTIMER Unit peripheral according to
 *         the specified parameters in the TIM_TimeBaseInitStruct.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @param  DUALTIMER_InitStruct: pointer to a DUALTIMER_InitTypDef structure
 *         that contains the configuration information for the
 *         specified DUALTIMER peripheral.
 * @retval None
 */
void DUALTIMER_Init(DUALTIMER_TypeDef* DUALTIMERn, DUALTIMER_InitTypDef* DUALTIMER_InitStruct)
{
    uint32_t tmp = 0;

    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));
    assert_param(IS_DUALTIMER_Wrapping(DUALTIMER_InitStruct->Timer_Wrapping));
    assert_param(IS_DUALTIMER_Prescaler(DUALTIMER_InitStruct->Timer_Prescaler));
    assert_param(IS_DUALTIMER_Size(DUALTIMER_InitStruct->Timer_Size));
    assert_param(IS_DUALTIMER_Repetition(DUALTIMER_InitStruct->Timer_Repetition));

    /* Stop the DUALTIMER */
    DUALTIMER_Cmd(DUALTIMERn, DISABLE);

    /* Set Timer Load Value */
    DUALTIMERn->LOAD = DUALTIMER_InitStruct->Timer_Load;

    /* Store Timer control value in tmp */
    tmp = DUALTIMERn->CONTROL;

    /* Configure Timer Wrapping selections bit */
    if (DUALTIMER_InitStruct->Timer_Wrapping & DUALTIMER_Periodic) {
        tmp |= DUALTIMER_Periodic;
    } else {
        tmp &= ~DUALTIMER_Periodic;
    }

    /* Configure Timer Prescale selections bit */
    if (DUALTIMER_InitStruct->Timer_Prescaler & DUALTIMER_Prescaler_16) {
        tmp &= ~DUALTIMER_CONTROL_TP;
        tmp |= DUALTIMER_Prescaler_16;
    } else if (DUALTIMER_InitStruct->Timer_Prescaler & DUALTIMER_Prescaler_256) {
        tmp &= ~DUALTIMER_CONTROL_TP;
        tmp |= DUALTIMER_Prescaler_256;
    } else {
        tmp &= ~DUALTIMER_CONTROL_TP;
    }

    /* Configure Timer Size selections bit */
    if (DUALTIMER_InitStruct->Timer_Size & DUALTIMER_Size_32) {
        tmp |= DUALTIMER_Size_32;
    } else {
        tmp &= ~DUALTIMER_Size_32;
    }

    /* Configure Timer Repetition selections bit */
    if (DUALTIMER_InitStruct->Timer_Repetition & DUALTIMER_OneShot) {
        tmp |= DUALTIMER_OneShot;
    } else {
        tmp &= ~DUALTIMER_OneShot;
    }

    /* Set Timer control value */
    DUALTIMERn->CONTROL = tmp;
}

/**
 * @brief  Set TIMER Enable.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @param  NewState: new state of the DUALTIMERn peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void DUALTIMER_Cmd(DUALTIMER_TypeDef* DUALTIMERn, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        DUALTIMERn->CONTROL |= DUALTIMER_CONTROL_TE;
        DUALTIMERn->CE = DUALTIMER_TIMCLKEN_CE;
    } else {
        DUALTIMERn->CONTROL &= ~DUALTIMER_CONTROL_TE;
        DUALTIMERn->CE = ~DUALTIMER_TIMCLKEN_CE;

    }
}

/**
 * @brief  Get the Timer Load value.
 * @note   The Timer Load register contains the value from which the counter is to decrement. This
 *         is the value used to reload the counter when Periodic mode is enabled, and
 *         the current count reaches 0.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @retval The Timer Load value of which format is 32bit.
 */
uint32_t DUALTIMER_GetLoad(DUALTIMER_TypeDef* DUALTIMERn)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));

    /* Get the Timer Load Register value */
    return DUALTIMERn->LOAD;
}

/**
 * @brief  Set the Timer Load value in order that the counter is to decrement by the specified value.
 * @note   If you set a value in this register, the timer immediately restarts and is replaced by this value.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @param  TimerLoad: specifies the value from which the counter is to decrement.
 * @retval None
 */
void DUALTIMER_SetLoad(DUALTIMER_TypeDef* DUALTIMERn, uint32_t TimerLoad)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));

    /* Set the Timer Load Register value */
    DUALTIMERn->LOAD = TimerLoad;
}

/**
 * @brief  Get the Background Load value.
 * @note   This register contains the value from which the counter is to decrement. This
 *         is the value used to reload the counter when Periodic mode is enabled, and
 *         the current count reaches 0.
 *         This register provides an alternative method of accessing the TimerLoad
 *         Register. The difference is that writes to TimerBGLoad Register do not cause
 *         the counter to immediately restart from the new value.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @retval The Timer Background Load Register value.
 */
uint32_t DUALTIMER_GetBGLoad(DUALTIMER_TypeDef* DUALTIMERn)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));

    /* Return the Timer Background Load Register value*/
    return DUALTIMERn->BGLOAD;
}

/**
 * @brief  Set the Background Load value in order that the counter is to decrement by the specified value.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @param  TimerBGLoad: specifies the value from which the counter is to decrement.
 * @retval None
 */
void DUALTIMER_SetBGLoad(DUALTIMER_TypeDef* DUALTIMERn, uint32_t TimerBGLoad)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));

    DUALTIMERn->BGLOAD = TimerBGLoad;
}

/**
 * @brief  Initializes the DUALTIMER Interrupt Enable.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @param  NewState: new state of the specified DUALTIMERn interrupts.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void DUALTIMER_ITConfig(DUALTIMER_TypeDef* DUALTIMERn, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set timer control */
    if (NewState != DISABLE) {
        DUALTIMERn->CONTROL |= DUALTIMER_CONTROL_IE;
    } else {
        DUALTIMERn->CONTROL &= ~DUALTIMER_CONTROL_IE;
    }
}

/**
 * @brief  Checks whether the specified DUALTIMER Interrupt flag is set or not.
 * @note   This function reads the masked interrupt status value.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @retval The new state of DUALTIMER_IT (SET or RESET).
 */
ITStatus DUALTIMER_GetITStatus(DUALTIMER_TypeDef* DUALTIMERn)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));

    /* Return the Timer Masked Interrupt Status Register value */
    return (ITStatus) DUALTIMERn->MIS;
}

/**
 * @brief  Set to the DUALTIMERn clears the interrupt output from the counter.
 * @note   You must clear the interrupt to read the next interrupt.
 * @param  DUALTIMERn: where n can be 0_0, 0_1, 1_0 and 1_1 to select the Timer peripheral.
 *          This parameter can be one of the following values:
 *            @arg DUALTIMER0_0
 *            @arg DUALTIMER0_1
 *            @arg DUALTIMER1_0
 *            @arg DUALTIMER1_1
 * @retval None
 */
void DUALTIMER_ClearIT(DUALTIMER_TypeDef* DUALTIMERn)
{
    /* Check the parameters */
    assert_param(IS_DUALTIMER_PERIH(DUALTIMERn));

    /* Set to clears interrupt output */
    DUALTIMERn->INTCLR = DUALTIMER_INTCLR_TIC;
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

/**
 ******************************************************************************
 * @file    w7500x_wdt.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Watchdog
 *          Timer(WDT) peripheral.
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
#include "w7500x_wdt.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup WDT
 * @brief WDT driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define WDT_WriteAccess_Enable          (0x1ACCE551)
#define WDT_WriteAccess_Disable         (0x00000000)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint32_t load_value;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup WDT_Private_Functions
 * @{
 */

/**
 * @brief  Enables or disables write access to WDT registers.
 * @param  NewState: new state of the specified Write Access Cmd.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void WDT_WriteAccessCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        WDT->LOCK = WDT_WriteAccess_Enable;
    } else {
        WDT->LOCK = WDT_WriteAccess_Disable;
    }
}

/**
 * @brief  Set the WDT Load value.
 * @note   When the Load register is written to, the count is immediately restarted from the
 *         new value.
 * @param  load: specifies the WDT Load value.
 *          This parameter must be a number between 1 and 0xFFFFFFFF.
 * @retval None
 */
void WDT_SetloadCounter(uint32_t load)
{
    /* Check the parameters */
    assert_param(IS_WDT_LOAD(load));

    /* Set the Watchdog Timer Load Register value */
    load_value = load;
    WDT->LOAD = load;
}

/**
 * @brief  Reloads the WDT Load value.
 * @param  None
 * @retval None
 */
void WDT_ReloadCounter(void)
{
    /* Check the parameters */
    assert_param(IS_WDT_LOAD(load_value));

    /* Set the Watchdog Timer Load Register value */
    WDT->LOAD = load_value;
}

/**
 * @brief  Enables WDT.
 * @param  NewState: new state of the specified WDT peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void WDT_Enable(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        WDT->CONTROL |= (WDT_CONTROL_REN | WDT_CONTROL_IEN);
    } else {
        WDT->CONTROL &= ~(WDT_CONTROL_REN | WDT_CONTROL_IEN);
    }
}

/**
 * @brief  Checks interrupt is set or not.
 * @param  None
 * @retval The new state of the counter reaches 0 interrupt(SET or RESET).
 */
ITStatus WDT_GetITStatus(void)
{
    ITStatus bitstatus = RESET;

    if ((WDT->MIS & WDT_MIS_MIS) != (uint32_t) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clear interrupt.
 * @param  None
 * @retval None
 */
void WDT_ClearIT(void)
{
    WDT->INTCLR = WDT_INTCLR_WIC;
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

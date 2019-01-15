/**
 ******************************************************************************
 * @file    w7500x_rng.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Random
 *          number generator (RNG) peripheral.
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

/*include ----------------------------------------------------------*/
#include "w7500x_rng.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup RNG
 * @brief RNG driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup RNG_Private_Functions
 * @{
 */

/**
 * @brief  Random Number Generator manual run enable
 * @param  mode: specifies the RNG run mode
 *          This parameter can be one of the following values:
 *            @arg RNG_PLL_LOCK_signal
 *            @arg RNG_RUN_register
 * @retval None
 */
void RNG_SetMode(uint32_t mode)
{
    /* Check the parameters */
    assert_param(IS_RNG_MODE(mode));

    RNG->MODE = mode;
}

/**
 * @brief  Random Number Generator set clock source
 * @param  src: specifies the RNG clock source
 *          This parameter can be one of the following values:
 *            @arg RNG_CLK_RNGCLK
 *            @arg RNG_CLK_PCLK
 * @retval None
 */
void RNG_SetClockSource(uint32_t src)
{
    /* Check the parameters */
    assert_param(IS_RNG_CLK_SRC(src));

    RNG->CLKSEL = src;
}

/**
 * @brief  Random Number Generator set seed value
 * @param  value: Seed value(32-bit) of random number generator shift register
 * @retval None
 */
void RNG_SetSeed(uint32_t value)
{
    RNG->SEED = value;
}

/**
 * @brief  Random Number Generator POLY
 * @param  value: POLY-32bit polynomial of random number generator
 * @retval None
 */
void RNG_SetPolynomial(uint32_t value)
{
    RNG->POLY = value;
}

/**
 * @brief  Random Number Generator the NewState peripheral registers
 * @param  NewState: new state of the specified RNG Run.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void RNG_Enable(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        RNG->RUN = RNG_RUN_RUN;
    } else {
        RNG->RUN = ~RNG_RUN_RUN;
    }
}

/**
 * @brief  Random Number Generator read random number
 * @param  None
 * @retval RNG_RN: Random number of RNG shift register. These bits are read only registers.
 */
uint32_t RNG_GetRandomNumber(void)
{
    return RNG->RN;
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

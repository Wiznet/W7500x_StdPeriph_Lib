/**
 ******************************************************************************
 * @file    w7500x_adc.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Analog-to-
 *          digital converter (ADC) peripheral.
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

/*include -------------------------------------*/
#include "w7500x_adc.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup ADC
 * @brief ADC driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static FlagStatus adc_conversion_start = RESET;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup ADC_Private_Functions
 * @{
 */

/**
 * @brief  Set or Clear to enable/disable power down mode.
 * @param  NewState: new state of the ADC peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void ADC_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Set ADC to Active Operation */
        ADC->CTR &= ~ADC_CTR_PWD_PWD;
    } else {
        /* Set ADC to Power down */
        ADC->CTR |= ADC_CTR_PWD_PWD;
    }
}

/**
 * @brief  Configures for the selected ADC.
 * @param  ADC_Channel: the ADC channel to configure.
 *          This parameter can be one of the ADC_CH enum values:
 *            @arg ADC_Channel_0 : PC_15
 *            @arg ADC_Channel_1 : PC_14
 *            @arg ADC_Channel_2 : PC_13
 *            @arg ADC_Channel_3 : PC_12
 *            @arg ADC_Channel_4 : PC_11
 *            @arg ADC_Channel_5 : PC_10
 *            @arg ADC_Channel_6 : PC_09
 *            @arg ADC_Channel_7 : PC_08
 *            @arg ADC_Channel_15 : internal LDO(1.5v) voltage.
 * @retval None
 */
void ADC_ChannelConfig(uint32_t ADC_Channel)
{
    /* Check the parameters */
    assert_param(IS_ADC_CHANNEL(ADC_Channel));

    ADC->CHSEL = ADC_Channel;
}

/**
 * @brief  Start the ADC for conversion.
 * @param  None
 * @retval None
 */
void ADC_StartOfConversion(void)
{
    adc_conversion_start = SET;
    ADC->START = ADC_START_ADC_SRT;
}

/**
 * @brief  Reads the ADC conversion result data of last converted channel.
 * @param  None
 * @retval The ADC conversion result data.
 */
uint16_t ADC_GetConversionValue(void)
{
    if (adc_conversion_start == SET) {
        adc_conversion_start = RESET;
        return (uint16_t) ADC->DATA;
    }
}

/**
 * @brief  Set or Clear to enable/disable ADC Interrupt mask.
 * @param  NewState: new state of the Interrupt mask state.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void ADC_ITConfig(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* interrupt mask enable */
        ADC->INT |= ADC_INT_MASK;
    } else {
        /* interrupt mask disable */
        ADC->INT &= ~ ADC_INT_MASK;
    }
}

/**
 * @brief  Check whether the conversion is done or not.
 * @param  None
 * @retval The value that tells whether the conversion is done or not.
 */
ITStatus ADC_GetITStatus(void)
{
    ITStatus bitstatus = RESET;

    if ((ADC->INT & ADC_INT_INT) != (uint32_t) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clears the ADC interrupt bit.
 * @note   This bit clear automatically after clear interrupt and is write-only.
 * @param  None
 * @retval None
 */
void ADC_ClearIT(void)
{
    ADC->INTCLR = ADC_INTCLR_INTCLR;
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

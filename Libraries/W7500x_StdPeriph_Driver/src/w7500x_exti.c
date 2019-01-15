/**
 ******************************************************************************
 * @file    w7500x_exti.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the External
 *          Interrupt (EXTI) peripheral.
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
#include "w7500x_exti.h"
#include "w7500x_gpio.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup EXTI 
 * @brief EXTI driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup EXTI_Private_Functions
 * @{
 */

/**
 * @brief  Deinitializes the EXTI peripheral registers to their default reset values.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @retval None
 */
void EXTI_DeInit(GPIO_TypeDef* GPIOx)
{
    uint32_t pinpos = 0x00, loop = 16;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    if (GPIOx == GPIOD) loop = 5;

    for (pinpos = 0x00; pinpos < loop; pinpos++) {
        if (GPIOx == GPIOA) EXTI_PA->REGISTER[pinpos] = 0x00UL;
        else if (GPIOx == GPIOB) EXTI_PB->REGISTER[pinpos] = 0x00UL;
        else if (GPIOx == GPIOC) EXTI_PC->REGISTER[pinpos] = 0x00UL;
        else EXTI_PD->REGISTER[pinpos] = 0x00UL;
    }
}

/**
 * @brief  Initializes the EXTI peripheral according to the specified
 *         parameters in the EXTI_InitStruct.
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @param  EXTI_InitStruct: pointer to a EXTI_InitTypeDef structure
 *         that contains the configuration information for the EXTI peripheral.
 * @retval None
 */
void EXTI_Init(GPIO_TypeDef* GPIOx, EXTI_InitTypeDef* EXTI_InitStruct)
{
    uint32_t pinpos = 0x00, pos = 0x00, currentpin = 0x00, loop = 16;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    if (GPIOx == GPIOD) loop = 5;

    for (pinpos = 0x00; pinpos < loop; pinpos++) {
        pos = ((uint32_t) 0x01) << pinpos;

        currentpin = (EXTI_InitStruct->EXTI_Line) & pos;
        if (currentpin == pos) {
            if (GPIOx == GPIOA) EXTI_PA->REGISTER[pinpos] = (EXTI_PA->REGISTER[pinpos] & 0xFC) | EXTI_EXTINT_IEN | EXTI_InitStruct->EXTI_Trigger;
            else if (GPIOx == GPIOB) EXTI_PB->REGISTER[pinpos] = (EXTI_PA->REGISTER[pinpos] & 0xFC) | EXTI_EXTINT_IEN | EXTI_InitStruct->EXTI_Trigger;
            else if (GPIOx == GPIOC) EXTI_PC->REGISTER[pinpos] = (EXTI_PA->REGISTER[pinpos] & 0xFC) | EXTI_EXTINT_IEN | EXTI_InitStruct->EXTI_Trigger;
            else EXTI_PD->REGISTER[pinpos] = (EXTI_PA->REGISTER[pinpos] & 0xFC) | EXTI_EXTINT_IEN | EXTI_InitStruct->EXTI_Trigger;
        }
    }
}

/**
 * @brief  Fills each EXTI_InitStruct member with its reset value.
 * @param  EXTI_InitStruct: pointer to a EXTI_InitTypeDef structure which will
 *         be initialized.
 * @retval None
 */
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct)
{
    EXTI_InitStruct->EXTI_Line = GPIO_Pin_All;
    EXTI_InitStruct->EXTI_Trigger = EXTI_Trigger_High_Level;
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

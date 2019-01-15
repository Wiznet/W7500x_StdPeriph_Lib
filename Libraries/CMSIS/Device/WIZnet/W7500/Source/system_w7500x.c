/**
 ******************************************************************************
 * @file    system_w7500x.c
 * @author  WIZnet
 * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer System Source File.
 *
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

/** @addtogroup CMSIS
 * @{
 */

/** @addtogroup w7500x_system
 * @{
 */

/** @addtogroup W7500x_System_Private_Includes
 * @{
 */
#include "system_w7500x.h"
#include "w7500x_crg.h"
/**
 * @}
 */

/** @addtogroup W7500x_System_Private_TypesDefinitions
 * @{
 */

/**
 * @}
 */

/** @addtogroup W7500x_System_Private_Defines
 * @{
 */

/**
 * @}
 */

/** @addtogroup W7500x_System_Private_Macros
 * @{
 */

/**
 * @}
 */

/** @addtogroup W7500x_System_Private_Variables
 * @{
 */
static uint32_t SystemCoreClock = 0; /*!< System Clock Frequency (Core Clock)  */
static uint32_t SystemSourceClock = 0; /*!< PLL Clock Source Frequency           */
/**
 * @}
 */

/** @addtogroup W7500x_System_Private_FunctionPrototypes
 * @{
 */
static void SetSysClock(void);
/**
 * @}
 */

/** @addtogroup W7500x_System_Private_Functions
 * @{
 */

/**
 * @brief  Get Core Clock Frequency
 * @param  None
 * @retval Core Clock Frequency
 */
uint32_t GetSystemClock(void)
{
    return SystemCoreClock;
}

/**
 * @brief  Get PLL Source Clock Frequency
 * @param  None
 * @retval Source Clock Frequency
 */
uint32_t GetSourceClock(void)
{
    return SystemSourceClock;
}

/**
 * @brief  Setup the microcontroller system.
 *         Initialize the PLL and update the SystemCoreClock variable.
 * @param  None
 * @retval None
 */
void SystemInit(void)
{
    (*((volatile uint32_t *) (TRIM_BGT))) = (*((volatile uint32_t *) (INFO_BGT)));
    (*((volatile uint32_t *) (TRIM_OSC))) = (*((volatile uint32_t *) (INFO_OSC)));

    /* Configure the System clock frequency */
    SetSysClock();
}

/**
 * @brief  Configures the System clock frequency.
 * @param  None
 * @retval None
 */
static void SetSysClock(void)
{
    uint8_t mul;
    uint32_t PLL_FCR_DEFAULT = 0x00020100;  // Initial CRG->PLL_FCR,

#if defined (OCLK_VALUE)
    CRG_PLL_SourceSelect(CRG_OCLK);
    mul = (OCLK_VALUE * PLL_VALUE) / OCLK_VALUE;
#else
    CRG_PLL_SourceSelect(CRG_RCLK);
    mul = (RCLK_VALUE * PLL_VALUE) / RCLK_VALUE;
#endif

    if (mul <= 1) {  // Clock source bypass
        CRG_PLL_Bypass(ENABLE);
        CRG->PLL_FCR = PLL_FCR_DEFAULT;
    } else {
        CRG_PLL_Bypass(DISABLE);

        PLL_FCR_DEFAULT &= (0xFFC0FFFF);  // 'M' value clear
        PLL_FCR_DEFAULT |= ((mul & 0x3F) << 16);
        CRG->PLL_FCR = PLL_FCR_DEFAULT;
    }
    SystemCoreClockUpdate();
}

/**
 * @brief  Update SystemCoreClock according to Clock Register Values
 * @param  None
 * @retval None
 */
void SystemCoreClockUpdate(void)
{
    uint8_t M, N, OD;

#if defined (OCLK_VALUE)
    SystemSourceClock = OCLK_VALUE;
#else
    SystemSourceClock = RCLK_VALUE;
#endif

    if (PLL_VALUE == 1) {
        SystemCoreClock = SystemSourceClock;
    } else {
        OD = (1 << (CRG->PLL_FCR & 0x01)) * (1 << ((CRG->PLL_FCR & 0x02) >> 1));
        N = (CRG->PLL_FCR >> 8) & 0x3F;
        M = (CRG->PLL_FCR >> 16) & 0x3F;
        SystemCoreClock = SystemSourceClock * M / N * 1 / OD;
    }
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

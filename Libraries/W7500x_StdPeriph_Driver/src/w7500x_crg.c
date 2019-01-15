/**
 ******************************************************************************
 * @file    w7500x_crg.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Clock Reset
 *          Generator (CRG) peripheral
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

/*include --------------------------------------------*/
#include "w7500x_crg.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup CRG
 * @brief CRG driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup CRG_Private_Functions
 * @{
 */

/**
 * @brief  Deinitializes the Clock Reset Generator(CRG) peripheral registers to their default reset values.
 * @param  None
 * @retval None
 */
void CRG_DeInit(void)
{
//To Do
}

/**
 * @brief  Internal 8MHz RC oscillator power down Enable
 * @param  NewState: new state of the CRG OSC PowerDown.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval	None
 */
void CRG_OSC_PowerDown(FunctionalState NewState)
{
    if (NewState != DISABLE) CRG->OSC_PDR = CRG_OSC_PDR_OSCPD;
    else CRG->OSC_PDR = ~CRG_OSC_PDR_OSCPD;
}

/**
 * @brief  Phase Locked Loop(PLL) Power Down Enable
 * @param  NewState: new state of the CRG PLL PowerDown.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void CRG_PLL_PowerDown(FunctionalState NewState)
{
    if (NewState != DISABLE) CRG->PLL_PDR = ~CRG_PLL_PDR_PLLPD;
    else CRG->PLL_PDR = CRG_PLL_PDR_PLLPD;
}

/**
 * @brief  Clock Reset Generator(CRG) Phase Locked Loop(PLL) Output Enable
 * @param  NewState: new state of the CRG PLL Output.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void CRG_PLL_Output(FunctionalState NewState)
{
    if (NewState != DISABLE) CRG->PLL_OER = CRG_PLL_OER_PLLOEN;
    else CRG->PLL_OER = ~CRG_PLL_OER_PLLOEN;
}

/**
 * @brief  Clock Reset Generator(CRG) Phase Locked Loop(PLL) Bypass Enable
 * @param  NewState: new state of the CRG PLL Bypass.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval	None
 */
void CRG_PLL_Bypass(FunctionalState NewState)
{
    if (NewState != DISABLE) CRG->PLL_BPR = CRG_PLL_BPR_PLLBP;
    else CRG->PLL_BPR = ~CRG_PLL_BPR_PLLBP;
}

/**
 * @brief  Phase Locked Loop(PLL) Input Frequency Select
 * @param  src: It consists of CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_PLL_SourceSelect(CRG_CLK_SOURCE src)
{
    /*	Check the parameters	*/
    assert_param(IS_CRG_PLL_SRC(src));

    if (src == CRG_RCLK) CRG->PLL_IFSR = ~CRG_PLL_IFSR_PLLIS;
    else CRG->PLL_IFSR = CRG_PLL_IFSR_PLLIS;
}

/**
 * @brief  Clock Reset Generator(CRG) FCLK Source Select
 * @param  src: It consists of  CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_FCLK_SourceSelect(CRG_CLK_SOURCE src)
{
    /*	Check the parameters	*/
    assert_param(IS_CRG_FCLK_SRC(src));

    if (src == CRG_MCLK) CRG->FCLK_SSR = CRG_FCLK_SSR_FCKSRC_0;
    else if (src == CRG_RCLK) CRG->FCLK_SSR = CRG_FCLK_SSR_FCKSRC_1;
    else CRG->FCLK_SSR = CRG_FCLK_SSR_FCKSRC;
}

/**
 * @brief  Clock Reset Generator(CRG) FCLK Set Prescale
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV2, CRG_PREDIV4, CRG_PREDIV8
 * @retval None
 */
void CRG_FCLK_SetPrescale(CRG_PREDIV prediv)
{
    /*	Check the parameters	*/
    assert_param(IS_CRG_FCLK_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG->FCLK_PVSR = 0x00UL;
    else if (prediv == CRG_PREDIV2) CRG->FCLK_PVSR = CRG_FCLK_PVSR_FCKPRE_0;
    else if (prediv == CRG_PREDIV4) CRG->FCLK_PVSR = CRG_FCLK_PVSR_FCKPRE_1;
    else CRG->FCLK_PVSR = CRG_FCLK_PVSR_FCKPRE;
}

/**
 * @brief  Clock Reset Generator(CRG) SSPCLK Source Select
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_SSPCLK_SourceSelect(CRG_CLK_SOURCE src)
{
    /*	Check the parameters	*/
    assert_param(IS_CRG_SSPCLK_SRC(src));

    if (src == CRG_CLK_DIS) CRG->SSPCLK_SSR = 0x00UL;
    else if (src == CRG_MCLK) CRG->SSPCLK_SSR = CRG_SSPCLK_SSR_SSPCSS_0;
    else if (src == CRG_RCLK) CRG->SSPCLK_SSR = CRG_SSPCLK_SSR_SSPCSS_1;
    else CRG->SSPCLK_SSR = CRG_SSPCLK_SSR_SSPCSS;
}

/**
 * @brief  Clock Reset Generator(CRG) SSPCLK Set Prescale
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV2, CRG_PREDIV4, CRG_PREDIV8
 * @retval None
 */
void CRG_SSPCLK_SetPrescale(CRG_PREDIV prediv)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_SSPCLK_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG->SSPCLK_PVSR = 0x00UL;
    else if (prediv == CRG_PREDIV2) CRG->SSPCLK_PVSR = CRG_SSPCLK_PVSR_SSPCP_0;
    else if (prediv == CRG_PREDIV4) CRG->SSPCLK_PVSR = CRG_SSPCLK_PVSR_SSPCP_1;
    else CRG->SSPCLK_PVSR = CRG_SSPCLK_PVSR_SSPCP;
}

/**
 * @brief  Clock Reset Generator(CRG) SSPCLK Source Select
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_ADCCLK_SourceSelect(CRG_CLK_SOURCE src)
{
    /* Check the parameters */
    assert_param(IS_CRG_ADCCLK_SRC(src));

    if (src == CRG_CLK_DIS) CRG->ADCCLK_SSR = 0x00UL;
    else if (src == CRG_MCLK) CRG->ADCCLK_SSR = CRG_ADCCLK_SSR_ADCSS_0;
    else if (src == CRG_RCLK) CRG->ADCCLK_SSR = CRG_ADCCLK_SSR_ADCSS_1;
    else CRG->ADCCLK_SSR = CRG_ADCCLK_SSR_ADCSS;
}

/**
 * @brief  Clock Reset Generator(CRG) ADCCLK Set Prescale
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV2, CRG_PREDIV4, CRG_PREDIV8
 * @retval None
 */
void CRG_ADCCLK_SetPrescale(CRG_PREDIV prediv)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_ADCCLK_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG->ADCCLK_PVSR = 0x00UL;
    else if (prediv == CRG_PREDIV2) CRG->ADCCLK_PVSR = CRG_ADCCLK_PVSR_ADCCP_0;
    else if (prediv == CRG_PREDIV4) CRG->ADCCLK_PVSR = CRG_ADCCLK_PVSR_ADCCP_1;
    else CRG->ADCCLK_PVSR = CRG_ADCCLK_PVSR_ADCCP;
}

/**
 * @brief  Clock Reset Generator(CRG) TimeRCLK Source Select
 * @param  num: It consists of CRG_TIMER0 and CRG_TIMER1.
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_TIMERCLK_SourceSelect(CRG_TIMER num, CRG_CLK_SOURCE src)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_TIMERCLK_NUM(num));
    assert_param(IS_CRG_TIMERCLK_SRC(src));

    if (src == CRG_CLK_DIS) CRG_SET_TIMERCLK_SSR(num, 0x00UL);
    else if (src == CRG_MCLK) CRG_SET_TIMERCLK_SSR(num, CRG_TIMERCLK_SSR_TCSS_0);
    else if (src == CRG_RCLK) CRG_SET_TIMERCLK_SSR(num, CRG_TIMERCLK_SSR_TCSS_1);
    else CRG_SET_TIMERCLK_SSR(num, CRG_TIMERCLK_SSR_TCSS);
}

/**
 * @brief  Clock Reset Generator(CRG) TimeRCLK Source Select
 * @param  num: It consists of CRG_TIMER0 and CRG_TIMER1.
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1. CRG_PREDIV16, CRG_PREDIV32, CRG_PREDIV64
 * 							  CRG_PREDIV128
 * @retval None
 */
void CRG_TIMERCLK_SetPrescale(CRG_TIMER num, CRG_PREDIV prediv)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_TIMERCLK_NUM(num));
    assert_param(IS_CRG_TIMERCLK_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG_SET_TIMERCLK_PREDIV(num, 0x00UL);
    else if (prediv == CRG_PREDIV2) CRG_SET_TIMERCLK_PREDIV(num, CRG_TIMERCLK_PVSR_TCPS_0);
    else if (prediv == CRG_PREDIV4) CRG_SET_TIMERCLK_PREDIV(num, CRG_TIMERCLK_PVSR_TCPS_1);
    else if (prediv == CRG_PREDIV8) CRG_SET_TIMERCLK_PREDIV(num, CRG_TIMERCLK_PVSR_TCPS_1 | CRG_TIMERCLK_PVSR_TCPS_0);
    else if (prediv == CRG_PREDIV16) CRG_SET_TIMERCLK_PREDIV(num, CRG_TIMERCLK_PVSR_TCPS_2);
    else if (prediv == CRG_PREDIV32) CRG_SET_TIMERCLK_PREDIV(num, CRG_TIMERCLK_PVSR_TCPS_2 | CRG_TIMERCLK_PVSR_TCPS_0);
    else if (prediv == CRG_PREDIV64) CRG_SET_TIMERCLK_PREDIV(num, CRG_TIMERCLK_PVSR_TCPS_2 | CRG_TIMERCLK_PVSR_TCPS_1);
    else CRG_SET_TIMERCLK_PREDIV(num, CRG_TIMERCLK_PVSR_TCPS);
}

/**
 * @brief  Clock Reset Generator(CRG) PWMCLK Source Select
 * @param  num: It consists of CRG_TIMER0 and CRG_TIMER1.
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_PWMCLK_SourceSelect(CRG_PWM num, CRG_CLK_SOURCE src)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_PWMCLK_NUM(num));
    assert_param(IS_CRG_PWMCLK_SRC(src));

    if (src == CRG_CLK_DIS) CRG_SET_PWMCLK_SSR(num, 0x00UL);
    else if (src == CRG_MCLK) CRG_SET_PWMCLK_SSR(num, CRG_PWMCLK_SSR_PCSS_0);
    else if (src == CRG_RCLK) CRG_SET_PWMCLK_SSR(num, CRG_PWMCLK_SSR_PCSS_1);
    else CRG_SET_PWMCLK_SSR(num, CRG_PWMCLK_SSR_PCSS);
}

/**
 * @brief  Clock Reset Generator(CRG) PWMCLK Set Prescale
 * @param  num: It consists of CRG_TIMER0 and CRG_TIMER1.
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1. CRG_PREDIV16, CRG_PREDIV32, CRG_PREDIV64
 * 							  CRG_PREDIV128.
 * @retval None
 */
void CRG_PWMCLK_SetPrescale(CRG_PWM num, CRG_PREDIV prediv)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_PWMCLK_NUM(num));
    assert_param(IS_CRG_PWMCLK_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG_SET_PWMCLK_PREDIV(num, 0x00UL);
    else if (prediv == CRG_PREDIV2) CRG_SET_PWMCLK_PREDIV(num, CRG_PWMCLK_PVSR_PCPS_0);
    else if (prediv == CRG_PREDIV4) CRG_SET_PWMCLK_PREDIV(num, CRG_PWMCLK_PVSR_PCPS_1);
    else if (prediv == CRG_PREDIV8) CRG_SET_PWMCLK_PREDIV(num, CRG_PWMCLK_PVSR_PCPS_1 | CRG_PWMCLK_PVSR_PCPS_0);
    else if (prediv == CRG_PREDIV16) CRG_SET_PWMCLK_PREDIV(num, CRG_PWMCLK_PVSR_PCPS_2);
    else if (prediv == CRG_PREDIV32) CRG_SET_PWMCLK_PREDIV(num, CRG_PWMCLK_PVSR_PCPS_2 | CRG_PWMCLK_PVSR_PCPS_0);
    else if (prediv == CRG_PREDIV64) CRG_SET_PWMCLK_PREDIV(num, CRG_PWMCLK_PVSR_PCPS_2 | CRG_PWMCLK_PVSR_PCPS_1);
    else CRG_SET_PWMCLK_PREDIV(num, CRG_PWMCLK_PVSR_PCPS);
}

/**
 * @brief  Clock Reset Generator(CRG) RTC HS Source Select
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_RTC_HS_SourceSelect(CRG_CLK_SOURCE src)
{
    /* Check the parameters */
    assert_param(IS_CRG_RTC_HS_SRC(src));

    if (src == CRG_CLK_DIS) CRG->RTC_HS_SSR = 0x00UL;
    else if (src == CRG_MCLK) CRG->RTC_HS_SSR = CRG_RTC_HS_SSR_RTCHS_0;
    else if (src == CRG_RCLK) CRG->RTC_HS_SSR = CRG_RTC_HS_SSR_RTCHS_1;
    else CRG->RTC_HS_SSR = CRG_RTC_HS_SSR_RTCHS;
}

/**
 * @brief  Clock Reset Generator(CRG) RTC HS Set Prescale
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1. CRG_PREDIV16, CRG_PREDIV32, CRG_PREDIV64
 *                            CRG_PREDIV128.
 * @retval None
 */
void CRG_RTC_HS_SetPrescale(CRG_PREDIV prediv)
{
    /* Check the parameters */
    assert_param(IS_CRG_RTC_HS_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG->RTC_HS_PVSR = 0x00UL;
    else if (prediv == CRG_PREDIV2) CRG->RTC_HS_PVSR = CRG_RTC_HS_PVSR_RTCPRE_0;
    else if (prediv == CRG_PREDIV4) CRG->RTC_HS_PVSR = CRG_RTC_HS_PVSR_RTCPRE_1;
    else if (prediv == CRG_PREDIV8) CRG->RTC_HS_PVSR = CRG_RTC_HS_PVSR_RTCPRE_1 | CRG_RTC_HS_PVSR_RTCPRE_0;
    else if (prediv == CRG_PREDIV16) CRG->RTC_HS_PVSR = CRG_RTC_HS_PVSR_RTCPRE_2;
    else if (prediv == CRG_PREDIV32) CRG->RTC_HS_PVSR = CRG_RTC_HS_PVSR_RTCPRE_2 | CRG_RTC_HS_PVSR_RTCPRE_0;
    else if (prediv == CRG_PREDIV64) CRG->RTC_HS_PVSR = CRG_RTC_HS_PVSR_RTCPRE_2 | CRG_RTC_HS_PVSR_RTCPRE_1;
    else CRG->RTC_HS_PVSR = CRG_RTC_HS_PVSR_RTCPRE;
}

/**
 * @brief  Clock Reset Generator(CRG) RTC Source Select
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_RTC_SourceSelect(CLK_32K_SOURCE src)
{
    /* Check the parameters */
    assert_param(IS_32K_CLK_SRC(src));

    if (src == None) CRG->RTC_SSR = 0x00UL;
    else CRG->RTC_SSR = CRG_RTC_SSR_RTCHS;
}

/**
 * @brief  Clock Reset Generator(CRG) WDOGCLK HS Source Select
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_WDOGCLK_HS_SourceSelect(CRG_CLK_SOURCE src)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_WDOGCLK_HS_SRC(src));

    if (src == CRG_CLK_DIS) CRG->WDOGCLK_HS_SSR = 0x00UL;
    else if (src == CRG_MCLK) CRG->WDOGCLK_HS_SSR = CRG_WDOGCLK_HS_SSR_WDHS_0;
    else if (src == CRG_RCLK) CRG->WDOGCLK_HS_SSR = CRG_WDOGCLK_HS_SSR_WDHS_1;
    else CRG->WDOGCLK_HS_SSR = CRG_WDOGCLK_HS_SSR_WDHS;
}

/**
 * @brief  Clock Reset Generator(CRG) WDOGCLK HS Set Prescale
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1. CRG_PREDIV16, CRG_PREDIV32, CRG_PREDIV64
 * 							  CRG_PREDIV128.
 * @retval None
 */
void CRG_WDOGCLK_HS_SetPrescale(CRG_PREDIV prediv)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_WDOGCLK_HS_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG->WDOGCLK_HS_PVSR = 0x00UL;
    else if (prediv == CRG_PREDIV2) CRG->WDOGCLK_HS_PVSR = CRG_WDOGCLK_HS_PVSR_WDPRE_0;
    else if (prediv == CRG_PREDIV4) CRG->WDOGCLK_HS_PVSR = CRG_WDOGCLK_HS_PVSR_WDPRE_1;
    else if (prediv == CRG_PREDIV8) CRG->WDOGCLK_HS_PVSR = CRG_WDOGCLK_HS_PVSR_WDPRE_1 | CRG_WDOGCLK_HS_PVSR_WDPRE_0;
    else if (prediv == CRG_PREDIV16) CRG->WDOGCLK_HS_PVSR = CRG_WDOGCLK_HS_PVSR_WDPRE_2;
    else if (prediv == CRG_PREDIV32) CRG->WDOGCLK_HS_PVSR = CRG_WDOGCLK_HS_PVSR_WDPRE_2 | CRG_WDOGCLK_HS_PVSR_WDPRE_0;
    else if (prediv == CRG_PREDIV64) CRG->WDOGCLK_HS_PVSR = CRG_WDOGCLK_HS_PVSR_WDPRE_2 | CRG_WDOGCLK_HS_PVSR_WDPRE_1;
    else CRG->WDOGCLK_HS_PVSR = CRG_WDOGCLK_HS_PVSR_WDPRE;
}

/**
 * @brief  Clock Reset Generator(CRG) UARTCLK Source Select
 * @param  src: It consists of  CRG_CLK_DIS, CRG_MCLK, CRG_RCLK, CRG_OCLK.
 * @retval None
 */
void CRG_UARTCLK_SourceSelect(CRG_CLK_SOURCE src)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_UARTCLK_SRC(src));

    if (src == CRG_CLK_DIS) CRG->UARTCLK_SSR = 0x00UL;
    else if (src == CRG_MCLK) CRG->UARTCLK_SSR = CRG_UARTCLK_SSR_UCSS_0;
    else if (src == CRG_RCLK) CRG->UARTCLK_SSR = CRG_UARTCLK_SSR_UCSS_1;
    else CRG->UARTCLK_SSR = CRG_UARTCLK_SSR_UCSS;
}

/**
 * @brief  Clock Reset Generator(CRG) UARTCLK Set Prescale
 * @param  prediv: It consists of  CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1, CRG_PREDIV1. CRG_PREDIV16, CRG_PREDIV32, CRG_PREDIV64
 * 							  CRG_PREDIV128.
 * @retval None
 */
void CRG_UARTCLK_SetPrescale(CRG_PREDIV prediv)
{
    /*	Check the parameters	*/
    assert_param(IS_CRG_UARTCLK_PREDIV(prediv));

    if (prediv == CRG_PREDIV1) CRG->UARTCLK_PVSR = 0x00UL;
    else if (prediv == CRG_PREDIV2) CRG->UARTCLK_PVSR = CRG_UARTCLK_PVSR_UCP_0;
    else if (prediv == CRG_PREDIV4) CRG->UARTCLK_PVSR = CRG_UARTCLK_PVSR_UCP_1;
    else CRG->UARTCLK_PVSR = CRG_UARTCLK_PVSR_UCP;
}

/**
 * @brief  Clock Reset Generator(CRG) MII Enable
 * @param  rx_clk: It consists of DISABLE and ENABLE.
 * @param  tx_clk: It consists of DISABLE and ENABLE.
 * @retval None
 */
void CRG_MII_Enable(FunctionalState rx_clk, FunctionalState tx_clk)
{
    /* Check the parameters	*/
    assert_param(IS_FUNCTIONAL_STATE(rx_clk));
    assert_param(IS_FUNCTIONAL_STATE(tx_clk));

    if (rx_clk != DISABLE) CRG->MIICLK_ECR |= CRG_MIICLK_ECR_EN_MIIREN;
    else CRG->MIICLK_ECR &= ~(CRG_MIICLK_ECR_EN_MIIREN);

    if (tx_clk != DISABLE) CRG->MIICLK_ECR |= CRG_MIICLK_ECR_EN_MIITEN;
    else CRG->MIICLK_ECR &= ~(CRG_MIICLK_ECR_EN_MIITEN);
}

/**
 * @brief  Clock Reset Generator(CRG) Set Monitoring Clock
 * @param  value: 32bit type define
 * @retval None
 */
void CRG_SetMonitoringClock(uint32_t value)
{
    /* Check the parameters	*/
    assert_param(IS_CRG_MONCLK_SSR(value));
    /* Get MONCLK_SSR */
    CRG->MONCLK_SSR = value;
}

/**
 * @brief  Clock Reset Generator(CRG) Get Monitoring Clock
 * @retval MONCLK_SSR
 */
uint32_t CRG_GetMonitoringClock(void)
{
    return (uint8_t) CRG->MONCLK_SSR;
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

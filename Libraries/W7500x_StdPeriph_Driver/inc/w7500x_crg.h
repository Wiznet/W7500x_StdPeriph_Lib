/**
 ******************************************************************************
 * @file    w7500x_crg.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the CRG
 *          firmware library
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
#ifndef __W7500X_CRG_H
#define __W7500X_CRG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup CRG
 * @{
 */
/* Exported types ------------------------------------------------------------*/

/** @defgroup Clock_Source_enumeration
 * @{
 */
typedef enum
{
    CRG_CLK_DIS = 0,
    CRG_MCLK,
    CRG_RCLK,
    CRG_OCLK
} CRG_CLK_SOURCE;

#define IS_CRG_PLL_SRC(SRC)            (((SRC) == CRG_RCLK) || \
                                        ((SRC) == CRG_OCLK))

#define IS_CRG_FCLK_SRC(SRC)           (((SRC) == CRG_MCLK) || \
                                        ((SRC) == CRG_RCLK) || \
                                        ((SRC) == CRG_OCLK))

#define CRG_CLK_SRC_DEFAULT(SRC)       (((SRC) == CRG_CLK_DIS) || \
                                        ((SRC) == CRG_MCLK) || \
                                        ((SRC) == CRG_RCLK) || \
                                        ((SRC) == CRG_OCLK))

#define IS_CRG_SSPCLK_SRC(SRC)          CRG_CLK_SRC_DEFAULT(SRC)
#define IS_CRG_ADCCLK_SRC(SRC)          CRG_CLK_SRC_DEFAULT(SRC)
#define IS_CRG_TIMERCLK_SRC(SRC)        CRG_CLK_SRC_DEFAULT(SRC)
#define IS_CRG_PWMCLK_SRC(SRC)          CRG_CLK_SRC_DEFAULT(SRC)
#define IS_CRG_RTC_HS_SRC(SRC)          CRG_CLK_SRC_DEFAULT(SRC)
#define IS_CRG_WDOGCLK_HS_SRC(SRC)      CRG_CLK_SRC_DEFAULT(SRC)
#define IS_CRG_UARTCLK_SRC(SRC)         CRG_CLK_SRC_DEFAULT(SRC)

typedef enum
{
    None = 0,
    CLK_32K
} CLK_32K_SOURCE;

#define IS_32K_CLK_SRC(SRC)           (((SRC) == None) || \
                                        ((SRC) == CLK_32K))
/**
 * @}
 */

/** @defgroup Clock_Prescale_enumeration
 * @{
 */
typedef enum
{
    CRG_PREDIV1 = 0,
    CRG_PREDIV2,
    CRG_PREDIV4,
    CRG_PREDIV8,
    CRG_PREDIV16,
    CRG_PREDIV32,
    CRG_PREDIV64,
    CRG_PREDIV128
} CRG_PREDIV;

#define CRG_CLK_PREDIV_DEFAULT(DIV)    (((DIV) == CRG_PREDIV1) || \
                                        ((DIV) == CRG_PREDIV2) || \
                                        ((DIV) == CRG_PREDIV4) || \
                                        ((DIV) == CRG_PREDIV8))

#define CRG_CLK_PREDIV_ADVANCE(DIV)    (((DIV) == CRG_PREDIV1)  || ((DIV) == CRG_PREDIV2) || \
                                        ((DIV) == CRG_PREDIV4)  || ((DIV) == CRG_PREDIV8) || \
                                        ((DIV) == CRG_PREDIV16) || ((DIV) == CRG_PREDIV32) || \
                                        ((DIV) == CRG_PREDIV64)  || ((DIV) == CRG_PREDIV128))

#define IS_CRG_FCLK_PREDIV(DIV)         CRG_CLK_PREDIV_DEFAULT(DIV)
#define IS_CRG_SSPCLK_PREDIV(DIV)       CRG_CLK_PREDIV_DEFAULT(DIV)
#define IS_CRG_ADCCLK_PREDIV(DIV)       CRG_CLK_PREDIV_DEFAULT(DIV)
#define IS_CRG_TIMERCLK_PREDIV(DIV)     CRG_CLK_PREDIV_ADVANCE(DIV)
#define IS_CRG_PWMCLK_PREDIV(DIV)       CRG_CLK_PREDIV_ADVANCE(DIV)
#define IS_CRG_RTC_HS_PREDIV(DIV)       CRG_CLK_PREDIV_ADVANCE(DIV)
#define IS_CRG_WDOGCLK_HS_PREDIV(DIV)   CRG_CLK_PREDIV_ADVANCE(DIV)
#define IS_CRG_UARTCLK_PREDIV(DIV)      CRG_CLK_PREDIV_DEFAULT(DIV)
/**
 * @}
 */

/** @defgroup Timer_Number_enumeration
 * @{
 */
typedef enum
{
    CRG_TIMER0 = 0,
    CRG_TIMER1
} CRG_TIMER;

#define IS_CRG_TIMERCLK_NUM(NUM)       (((NUM) == CRG_TIMER0) || ((NUM) == CRG_TIMER1))
/**
 * @}
 */

/** @defgroup PWM_Channel_enumeration
 * @{
 */
typedef enum
{
    CRG_PWM0 = 0,
    CRG_PWM1,
    CRG_PWM2,
    CRG_PWM3,
    CRG_PWM4,
    CRG_PWM5,
    CRG_PWM6,
    CRG_PWM7
} CRG_PWM;

#define IS_CRG_PWMCLK_NUM(NUM)         (((NUM) == CRG_PWM0) || ((NUM) == CRG_PWM1) || \
                                        ((NUM) == CRG_PWM2) || ((NUM) == CRG_PWM3) || \
                                        ((NUM) == CRG_PWM4) || ((NUM) == CRG_PWM5) || \
                                        ((NUM) == CRG_PWM6) || ((NUM) == CRG_PWM7) )
/**
 * @}
 */

/* Exported constants --------------------------------------------------------*/

/** @defgroup CRG_Exported_Constants
 * @{
 */

/** @defgroup CRG_Monitoring Clock source
 * @{
 */
#define CRG_Monitoring_MCLK                 (0x00UL)
#define CRG_Monitoring_FCLK                 (0x01UL)
#define CRG_Monitoring_RCLK                 (0x02UL)
#define CRG_Monitoring_OCLK                 (0x03UL)
#define CRG_Monitoring_ADCCLK               (0x04UL)
#define CRG_Monitoring_SSPCLK               (0x05UL)
#define CRG_Monitoring_TIMCLK0              (0x06UL)
#define CRG_Monitoring_TIMCLK1              (0x07UL)
#define CRG_Monitoring_PWMCLK0              (0x08UL)
#define CRG_Monitoring_PWMCLK1              (0x09UL)
#define CRG_Monitoring_PWMCLK2              (0x0AUL)
#define CRG_Monitoring_PWMCLK3              (0x0BUL)
#define CRG_Monitoring_PWMCLK4              (0x0CUL)
#define CRG_Monitoring_PWMCLK5              (0x0DUL)
#define CRG_Monitoring_PWMCLK6              (0x0EUL)
#define CRG_Monitoring_PWMCLK7              (0x0FUL)
#define CRG_Monitoring_UARTCLK              (0x10UL)
#define CRG_Monitoring_MII_RCK              (0x11UL)
#define CRG_Monitoring_MII_TCK              (0x12UL)
#define CRG_Monitoring_RTCCLK               (0x13UL)

#define IS_CRG_MONCLK_SSR(value)            (((value) == CRG_Monitoring_MCLK) || \
                                             ((value) == CRG_Monitoring_FCLK) || \
                                             ((value) == CRG_Monitoring_RCLK) || \
                                             ((value) == CRG_Monitoring_OCLK) || \
                                             ((value) == CRG_Monitoring_ADCCLK) || \
                                             ((value) == CRG_Monitoring_SSPCLK) || \
                                             ((value) == CRG_Monitoring_TIMCLK0) || \
                                             ((value) == CRG_Monitoring_TIMCLK1) || \
                                             ((value) == CRG_Monitoring_PWMCLK0) || \
                                             ((value) == CRG_Monitoring_PWMCLK1) || \
                                             ((value) == CRG_Monitoring_PWMCLK2) || \
                                             ((value) == CRG_Monitoring_PWMCLK3) || \
                                             ((value) == CRG_Monitoring_PWMCLK4) || \
                                             ((value) == CRG_Monitoring_PWMCLK5) || \
											 ((value) == CRG_Monitoring_PWMCLK6) || \
                                             ((value) == CRG_Monitoring_PWMCLK7) || \
                                             ((value) == CRG_Monitoring_UARTCLK) || \
                                             ((value) == CRG_Monitoring_MII_RCK) || \
                                             ((value) == CRG_Monitoring_MII_TCK) || \
                                             ((value) == CRG_Monitoring_RTCCLK))
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
#define CRG_SET_TIMERCLK_SSR(NUM, VALUE) \
            (*((volatile uint32_t *)(CRG->TIMER0CLK_SSR) + (0x10UL * NUM)) = VALUE)
#define CRG_SET_TIMERCLK_PREDIV(NUM, VALUE) \
            (*((volatile uint32_t *)(CRG->TIMER0CLK_PVSR) + (0x10UL * NUM)) = VALUE)
#define CRG_SET_PWMCLK_SSR(NUM, VALUE)       \
            (*((volatile uint32_t *)(CRG->PWM0CLK_SSR) + (0x10UL * NUM)) = VALUE)
#define CRG_SET_PWMCLK_PREDIV(NUM, VALUE)    \
            (*((volatile uint32_t *)(CRG->PWM0CLK_PVSR) + (0x10UL * NUM)) = VALUE)

/* Exported functions ------------------------------------------------------- */
void CRG_DeInit(void);
void CRG_OSC_PowerDown(FunctionalState NewState);
void CRG_PLL_PowerDown(FunctionalState NewState);
void CRG_PLL_Output(FunctionalState NewState);
void CRG_PLL_Bypass(FunctionalState NewState);
void CRG_PLL_SourceSelect(CRG_CLK_SOURCE src);

void CRG_FCLK_SourceSelect(CRG_CLK_SOURCE src);
void CRG_FCLK_SetPrescale(CRG_PREDIV prediv);

void CRG_SSPCLK_SourceSelect(CRG_CLK_SOURCE src);
void CRG_SSPCLK_SetPrescale(CRG_PREDIV prediv);

void CRG_ADCCLK_SourceSelect(CRG_CLK_SOURCE src);
void CRG_ADCCLK_SetPrescale(CRG_PREDIV prediv);

void CRG_TIMERCLK_SourceSelect(CRG_TIMER num, CRG_CLK_SOURCE src);
void CRG_TIMERCLK_SetPrescale(CRG_TIMER num, CRG_PREDIV prediv);

void CRG_PWMCLK_SourceSelect(CRG_PWM num, CRG_CLK_SOURCE src);
void CRG_PWMCLK_SetPrescale(CRG_PWM num, CRG_PREDIV prediv);

void CRG_RTC_HS_SourceSelect(CRG_CLK_SOURCE src);
void CRG_RTC_HS_SetPrescale(CRG_PREDIV prediv);
void CRG_RTC_SourceSelect(CLK_32K_SOURCE src);

void CRG_WDOGCLK_HS_SourceSelect(CRG_CLK_SOURCE src);
void CRG_WDOGCLK_HS_SetPrescale(CRG_PREDIV prediv);

void CRG_UARTCLK_SourceSelect(CRG_CLK_SOURCE src);
void CRG_UARTCLK_SetPrescale(CRG_PREDIV prediv);

void CRG_MII_Enable(FunctionalState rx_clk, FunctionalState tx_clk);

void CRG_SetMonitoringClock(uint32_t value);
uint32_t CRG_GetMonitoringClock(void);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_CRG_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

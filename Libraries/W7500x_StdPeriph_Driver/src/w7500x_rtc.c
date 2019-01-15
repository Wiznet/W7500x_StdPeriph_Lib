/**
 ******************************************************************************
 * @file    w7500x_rtc.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage the following
 *          functionalities of the Real-Time Clock (RTC) peripheral:
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
#include "w7500x_rtc.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup RTC
 * @brief RTC driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define RTC_ALARM_MASK       (0x7FUL)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static uint16_t RTC_DecToBcd(uint16_t Value);
static uint16_t RTC_BcdToDec(uint16_t Value);

/* Private functions ---------------------------------------------------------*/

/** @defgroup RTC_Private_Functions
 * @{
 */

/**
 * @brief  Enables or disables the RTC.
 * @param  NewState: new state of the RTC.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void RTC_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        RTC->RTCCON |= RTC_RTCCON_CLKEN;
    } else {
        RTC->RTCCON &= ~RTC_RTCCON_CLKEN;
    }
}

/**
 * @brief  Enables or disables the RTC Divider.
 * @param  NewState: new state of the RTC Divider.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void RTC_DividerCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        RTC->RTCCON |= RTC_RTCCON_DIVRST;
    } else {
        RTC->RTCCON &= ~RTC_RTCCON_DIVRST;
    }
}

/**
 * @brief  Set the RTC current time.
 * @param  RTC_Format: specifies the format of the entered parameters.
 *          This parameter can be  one of the following values:
 *            @arg RTC_Format_BIN:  Binary data format
 *            @arg RTC_Format_BCD:  BCD data format
 * @param  RTC_TimeStruct: pointer to a RTC_TimeTypeDef structure that contains
 *                        the time configuration information for the RTC.
 * @retval None
 */
void RTC_SetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct)
{
    /* Check the parameters */
    assert_param(IS_RTC_FORMAT(RTC_Format));

    /* Check the input parameters format */
    if (RTC_Format != RTC_Format_BIN) {

        assert_param(IS_RTC_MINUTES(RTC_BcdToDec(RTC_TimeStruct->RTC_Hours)));
        assert_param(IS_RTC_MINUTES(RTC_BcdToDec(RTC_TimeStruct->RTC_Minutes)));
        assert_param(IS_RTC_SECONDS(RTC_BcdToDec(RTC_TimeStruct->RTC_Seconds)));
        RTC->BCDHOUR = RTC_TimeStruct->RTC_Hours;
        RTC->BCDMIN = RTC_TimeStruct->RTC_Minutes;
        RTC->BCDSEC = RTC_TimeStruct->RTC_Seconds;
    } else {
        assert_param(IS_RTC_HOURS(RTC_TimeStruct->RTC_Hours));
        assert_param(IS_RTC_MINUTES(RTC_TimeStruct->RTC_Minutes));
        assert_param(IS_RTC_SECONDS(RTC_TimeStruct->RTC_Seconds));
        RTC->BCDHOUR = RTC_DecToBcd(RTC_TimeStruct->RTC_Hours);
        RTC->BCDMIN = RTC_DecToBcd(RTC_TimeStruct->RTC_Minutes);
        RTC->BCDSEC = RTC_DecToBcd(RTC_TimeStruct->RTC_Seconds);
    }
}

/**
 * @brief  Fills each RTC_TimeStruct member with its default value
 *         (Time = 00h:00min:00sec).
 * @param  RTC_TimeStruct: pointer to a RTC_TimeTypeDef structure which will be
 *         initialized.
 * @retval None
 */
void RTC_TimeStructInit(RTC_TimeTypeDef* RTC_TimeStruct)
{
    /* Time = 00h:00min:00sec */
    RTC_TimeStruct->RTC_Hours = 0;
    RTC_TimeStruct->RTC_Minutes = 0;
    RTC_TimeStruct->RTC_Seconds = 0;
}

/**
 * @brief  Get the RTC current Time.
 * @param  RTC_Format: specifies the format of the returned parameters.
 *          This parameter can be  one of the following values:
 *            @arg RTC_Format_BIN:  Binary data format
 *            @arg RTC_Format_BCD:  BCD data format
 * @param  RTC_TimeStruct: pointer to a RTC_TimeTypeDef structure that will
 *                         contain the returned current time configuration.
 * @retval None
 */
void RTC_GetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct)
{
    /* Check the parameters */
    assert_param(IS_RTC_FORMAT(RTC_Format));

    /* Fill the structure fields with the read parameters */
    RTC_TimeStruct->RTC_Hours = (RTC->RTCTIME0 & RTC_RTCTIME0_CBCDHOUR) >> 16;
    RTC_TimeStruct->RTC_Minutes = (RTC->RTCTIME0 & RTC_RTCTIME0_CBCDMIN) >> 8;
    RTC_TimeStruct->RTC_Seconds = RTC->RTCTIME0 & RTC_RTCTIME0_CBCDSEC;

    /* Check the input parameters format */
    if (RTC_Format == RTC_Format_BIN) {
        /* Convert the structure parameters to Binary format */
        RTC_TimeStruct->RTC_Hours = (uint8_t) RTC_BcdToDec(RTC_TimeStruct->RTC_Hours);
        RTC_TimeStruct->RTC_Minutes = (uint8_t) RTC_BcdToDec(RTC_TimeStruct->RTC_Minutes);
        RTC_TimeStruct->RTC_Seconds = (uint8_t) RTC_BcdToDec(RTC_TimeStruct->RTC_Seconds);
    }
}

/**
 * @brief  Set the RTC current date.
 * @param  RTC_Format: specifies the format of the entered parameters.
 *          This parameter can be  one of the following values:
 *            @arg RTC_Format_BIN:  Binary data format
 *            @arg RTC_Format_BCD:  BCD data format
 * @param  RTC_DateStruct: pointer to a RTC_DateTypeDef structure that contains
 *                         the date configuration information for the RTC.
 * @retval None
 */
void RTC_SetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct)
{
    /* Check the parameters */
    assert_param(IS_RTC_FORMAT(RTC_Format));

    /* Check the input parameters format */
    if (RTC_Format != RTC_Format_BIN) {
        assert_param(IS_RTC_YEAR(RTC_BcdToDec(RTC_DateStruct->RTC_Year)));
        assert_param(IS_RTC_MONTH(RTC_BcdToDec(RTC_DateStruct->RTC_Month)));
        assert_param(IS_RTC_DATE(RTC_BcdToDec(RTC_DateStruct->RTC_Date)));
        assert_param(IS_RTC_WEEKDAY(RTC_BcdToDec(RTC_DateStruct->RTC_WeekDay)));
        RTC->BCDYEAR = RTC_DateStruct->RTC_Year;
        RTC->BCDMON = RTC_DateStruct->RTC_Month;
        RTC->BCDDATE = RTC_DateStruct->RTC_Date;
        RTC->BCDDAY = RTC_DateStruct->RTC_WeekDay;
    } else {
        assert_param(IS_RTC_YEAR(RTC_DateStruct->RTC_Year));
        assert_param(IS_RTC_MONTH(RTC_DateStruct->RTC_Month));
        assert_param(IS_RTC_DATE(RTC_DateStruct->RTC_Date));
        assert_param(IS_RTC_WEEKDAY(RTC_DateStruct->RTC_WeekDay));
        RTC->BCDYEAR = RTC_DecToBcd(RTC_DateStruct->RTC_Year);
        RTC->BCDMON = RTC_DecToBcd(RTC_DateStruct->RTC_Month);
        RTC->BCDDATE = RTC_DecToBcd(RTC_DateStruct->RTC_Date);
        RTC->BCDDAY = RTC_DecToBcd(RTC_DateStruct->RTC_WeekDay);
    }
}

/**
 * @brief  Fills each RTC_DateStruct member with its default value
 *         (Monday, January 01 xx00).
 * @param  RTC_DateStruct: pointer to a RTC_DateTypeDef structure which will be
 *         initialized.
 * @retval None
 */
void RTC_DateStructInit(RTC_DateTypeDef* RTC_DateStruct)
{
    /* Monday, January 01 0000 */
    RTC_DateStruct->RTC_WeekDay = 1;
    RTC_DateStruct->RTC_Date = 1;
    RTC_DateStruct->RTC_Month = 1;
    RTC_DateStruct->RTC_Year = 0;
}

/**
 * @brief  Get the RTC current date.
 * @param  RTC_Format: specifies the format of the returned parameters.
 *          This parameter can be one of the following values:
 *            @arg RTC_Format_BIN: Binary data format
 *            @arg RTC_Format_BCD: BCD data format
 * @param RTC_DateStruct: pointer to a RTC_DateTypeDef structure that will
 *                        contain the returned current date configuration.
 * @retval None
 */
void RTC_GetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct)
{
    /* Check the parameters */
    assert_param(IS_RTC_FORMAT(RTC_Format));

    /* Fill the structure fields with the read parameters */
    RTC_DateStruct->RTC_Year = (RTC->RTCTIME1 & RTC_RTCTIME1_CBCDYEAR) >> 16;
    RTC_DateStruct->RTC_Month = (RTC->RTCTIME1 & RTC_RTCTIME1_CBCDMON) >> 8;
    RTC_DateStruct->RTC_Date = RTC->RTCTIME1 & RTC_RTCTIME1_CBCDDATE;
    RTC_DateStruct->RTC_WeekDay = (RTC->RTCTIME0 & RTC_RTCTIME0_CBCDDAY) >> 24;

    /* Check the input parameters format */
    if (RTC_Format == RTC_Format_BIN) {
        /* Convert the structure parameters to Binary format */
        RTC_DateStruct->RTC_Year = (uint16_t) RTC_BcdToDec(RTC_DateStruct->RTC_Year);
        RTC_DateStruct->RTC_Month = (uint8_t) RTC_BcdToDec(RTC_DateStruct->RTC_Month);
        RTC_DateStruct->RTC_Date = (uint8_t) RTC_BcdToDec(RTC_DateStruct->RTC_Date);
        RTC_DateStruct->RTC_WeekDay = (uint8_t) (RTC_DateStruct->RTC_WeekDay);
    }
}

/**
 * @brief  Set the specified RTC Alarm.
 * @note   The Alarm register can only be written when the corresponding Alarm
 *         is disabled (Use the RTC_AlarmCmd(DISABLE)).
 * @param  RTC_Format: specifies the format of the returned parameters.
 *          This parameter can be one of the following values:
 *            @arg RTC_Format_BIN: Binary data format
 *            @arg RTC_Format_BCD: BCD data format
 * @param  RTC_AlarmStruct: pointer to a RTC_AlarmTypeDef structure that
 *                          contains the alarm configuration parameters.
 * @retval None
 */
void RTC_SetAlarm(uint32_t RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    /* Check the input parameters format */
    if (RTC_Format != RTC_Format_BIN) {
        assert_param(IS_RTC_MINUTES(RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours)));
        assert_param(IS_RTC_MINUTES(RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes)));
        assert_param(IS_RTC_SECONDS(RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds)));
        assert_param(IS_RTC_YEAR(RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_Year)));
        assert_param(IS_RTC_MONTH(RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_Month)));
        assert_param(IS_RTC_DATE(RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_Date)));
        assert_param(IS_RTC_WEEKDAY(RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay)));
        RTC->PREHOUR = RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours;
        RTC->PREMIN = RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes;
        RTC->PRESEC = RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds;
        RTC->PREYEAR = RTC_AlarmStruct->RTC_AlarmDate.RTC_Year;
        RTC->PREMON = RTC_AlarmStruct->RTC_AlarmDate.RTC_Month;
        RTC->PREDATE = RTC_AlarmStruct->RTC_AlarmDate.RTC_Date;
        RTC->PREDAY = RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay;
    } else {
        assert_param(IS_RTC_HOURS(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours));
        assert_param(IS_RTC_MINUTES(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes));
        assert_param(IS_RTC_SECONDS(RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds));
        assert_param(IS_RTC_YEAR(RTC_AlarmStruct->RTC_AlarmDate.RTC_Year));
        assert_param(IS_RTC_MONTH(RTC_AlarmStruct->RTC_AlarmDate.RTC_Month));
        assert_param(IS_RTC_DATE(RTC_AlarmStruct->RTC_AlarmDate.RTC_Date));
        assert_param(IS_RTC_WEEKDAY(RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay));
        RTC->PREHOUR = RTC_DecToBcd(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours);
        RTC->PREMIN = RTC_DecToBcd(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes);
        RTC->PRESEC = RTC_DecToBcd(RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds);
        RTC->PREYEAR = RTC_DecToBcd(RTC_AlarmStruct->RTC_AlarmDate.RTC_Year);
        RTC->PREMON = RTC_DecToBcd(RTC_AlarmStruct->RTC_AlarmDate.RTC_Month);
        RTC->PREDATE = RTC_DecToBcd(RTC_AlarmStruct->RTC_AlarmDate.RTC_Date);
        RTC->PREDAY = RTC_DecToBcd(RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay);
    }
}

/**
 * @brief  Fills each RTC_AlarmStruct member with its default value
 *         (Time = 00h:00mn:00sec / Date = 1st day of the month/Mask =
 *         all fields are masked).
 * @param  RTC_AlarmStruct: pointer to a @ref RTC_AlarmTypeDef structure which
 *         will be initialized.
 * @retval None
 */
void RTC_AlarmStructInit(RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    /* Alarm Time Settings : Time = 00h:00mn:00sec */
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours = 0;
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes = 0;
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds = 0;

    /* Monday, January 01 0000 */
    RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay = 1;
    RTC_AlarmStruct->RTC_AlarmDate.RTC_Date = 1;
    RTC_AlarmStruct->RTC_AlarmDate.RTC_Month = 1;
    RTC_AlarmStruct->RTC_AlarmDate.RTC_Year = 0;
}

/**
 * @brief  Get the RTC Alarm value and masks.
 * @param  RTC_Format: specifies the format of the output parameters.
 *          This parameter can be one of the following values:
 *            @arg RTC_Format_BIN: Binary data format
 *            @arg RTC_Format_BCD: BCD data format
 * @param  RTC_AlarmStruct: pointer to a RTC_AlarmTypeDef structure that will
 *                          contains the output alarm configuration values.
 * @retval None
 */
void RTC_GetAlarm(uint32_t RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    /* Check the parameters */
    assert_param(IS_RTC_FORMAT(RTC_Format));

    /* Fill the structure fields with the read parameters */
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours = RTC->PREHOUR;
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes = RTC->PREMIN;
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds = RTC->PRESEC;
    RTC_AlarmStruct->RTC_AlarmDate.RTC_Year = RTC->PREYEAR;
    RTC_AlarmStruct->RTC_AlarmDate.RTC_Month = RTC->PREMON;
    RTC_AlarmStruct->RTC_AlarmDate.RTC_Date = RTC->PREDATE;
    RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay = RTC->PREDAY;

    /* Check the input parameters format */
    if (RTC_Format == RTC_Format_BIN) {
        /* Convert the structure parameters to Binary format */
        RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours = RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours);
        RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes = RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes);
        RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds = RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds);
        RTC_AlarmStruct->RTC_AlarmDate.RTC_Year = RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_Year);
        RTC_AlarmStruct->RTC_AlarmDate.RTC_Month = RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_Month);
        RTC_AlarmStruct->RTC_AlarmDate.RTC_Date = RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_Date);
        RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay = RTC_BcdToDec(RTC_AlarmStruct->RTC_AlarmDate.RTC_WeekDay);
    }
}

/**
 * @brief  Enables or disables the RTC Alarm.
 * @param  NewState: new state of the specified alarm.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void RTC_AlarmCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Configure the Alarm state */
    if (NewState != DISABLE) {
        RTC->RTCAMR |= RTC_ALARM_MASK;
    } else {
        RTC->RTCAMR &= ~RTC_ALARM_MASK;
    }
}

/**
 * @brief  Enables or disables the specified RTC interrupts.
 * @param  RTC_IT: specifies the RTC interrupt sources to be enabled or disabled.
 *          This parameter can be any combination of the following values:
 *            @arg RTC_IT_ALARM:    Alarm interrupt mask
 *            @arg RTC_IT_MON:      Month interrupt mask
 *            @arg RTC_IT_DAY:      Day interrupt mask
 *            @arg RTC_IT_DATE:     Date interrupt mask
 *            @arg RTC_IT_HOUR:     Hour interrupt mask
 *            @arg RTC_IT_MIN:      Minute interrupt mask
 *            @arg RTC_IT_SEC:      Second interrupt mask
 * @param  NewState: new state of the specified RTC interrupts.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void RTC_ITConfig(uint32_t RTC_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RTC_CONFIG_IT(RTC_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        RTC->RTCINTE |= RTC_IT;
        RTC->RTCCON |= RTC_RTCCON_INTEN;
    } else {
        RTC->RTCINTE &= ~RTC_IT;
        RTC->RTCCON &= ~RTC_RTCCON_INTEN;
    }
}

/**
 * @brief  Checks whether the specified RTC interrupt has occurred or not.
 * @param  RTC_IT: specifies the RTC interrupt source to check.
 *          This parameter can be one of the following values:
 *            @arg RTC_IT_ALARMP:      Alarm interrupt
 *            @arg RTC_IT_COUNTERP:    Counter interrupt
 * @retval The new state of RTC_IT (SET or RESET).
 */
ITStatus RTC_GetITStatus(uint32_t RTC_IT)
{
    ITStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_RTC_GET_IT(RTC_IT));

    if ((RTC->RTCINTP & RTC_IT) != ((uint16_t) RESET)) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Clears the RTC's interrupt pending bits.
 * @param  RTC_IT: specifies the RTC interrupt pending bit to clear.
 *          This parameter can be one of the following values:
 *            @arg RTC_IT_ALARMP:      Alarm interrupt
 *            @arg RTC_IT_COUNTERP:    Counter interrupt
 * @retval None
 */
void RTC_ClearITPendingBit(uint32_t RTC_IT)
{
    /* Check the parameters */
    assert_param(IS_RTC_CLEAR_IT(RTC_IT));

    /* Set RTCINTP */
    RTC->RTCINTP = RTC_IT;
}

/**
 * @brief  Converts a 2 digit decimal to BCD format.
 * @param  Value: Byte to be converted.
 * @retval Converted byte
 */
static uint16_t RTC_DecToBcd(uint16_t Value)
{
    uint8_t bcdhigh1000 = 0;
    uint8_t bcdhigh100 = 0;
    uint8_t bcdhigh10 = 0;

    while (Value >= 1000) {
        bcdhigh1000++;
        Value -= 1000;
    }

    while (Value >= 100) {
        bcdhigh100++;
        Value -= 100;
    }

    while (Value >= 10) {
        bcdhigh10++;
        Value -= 10;
    }

    return ((uint16_t) (bcdhigh1000 << 12) | (bcdhigh100 << 8) | (bcdhigh10 << 4) | Value);
}

/**
 * @brief  Convert from 2 digit BCD to Binary.
 * @param  Value: BCD value to be converted.
 * @retval Converted word
 */
static uint16_t RTC_BcdToDec(uint16_t Value)
{
    uint16_t tmp10 = 0;
    uint16_t tmp100 = 0;
    uint16_t tmp1000 = 0;

    tmp10 = ((Value & 0x00F0) >> 4) * 10;
    tmp100 = ((Value & 0x0F00) >> 8) * 100;
    tmp1000 = ((Value & 0xF000) >> 12) * 1000;

    return (tmp1000 + tmp100 + tmp10 + (Value & 0x0F));
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

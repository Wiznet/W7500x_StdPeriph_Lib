/**
 ******************************************************************************
 * @file    w7500x_rtc.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the RTC firmware
 *          library.
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
#ifndef __W7500X_RTC_H
#define __W7500X_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup RTC
 * @{
 */
/* Exported types ------------------------------------------------------------*/
/**
 * @brief  RTC Time structure definition
 */
typedef struct
{
    uint8_t RTC_Hours;      /*!< Specifies the RTC Time Hour.
                             This parameter must be set to a value in the 0-23 range. */

    uint8_t RTC_Minutes;    /*!< Specifies the RTC Time Minutes.
                             This parameter must be set to a value in the 0-59 range. */

    uint8_t RTC_Seconds;    /*!< Specifies the RTC Time Seconds.
                             This parameter must be set to a value in the 0-59 range. */
} RTC_TimeTypeDef;

/**
 * @brief  RTC Date structure definition
 */
typedef struct
{
    uint16_t RTC_Year;       /*!< Specifies the RTC Date Year.
                             This parameter must be set to a value in the 0-4095 range. */

    uint8_t RTC_Month;      /*!< Specifies the RTC Date Month.
                             This parameter can be a value of @ref RTC_Month_Date_Definitions */

    uint8_t RTC_Date;       /*!< Specifies the RTC Date.
                             This parameter must be set to a value in the 1-31 range. */

    uint8_t RTC_WeekDay;    /*!< Specifies the RTC Date WeekDay.
                             This parameter can be a value of @ref RTC_WeekDay_Definitions */
} RTC_DateTypeDef;

/**
 * @brief  RTC Alarm structure definition
 */
typedef struct
{
    RTC_TimeTypeDef RTC_AlarmTime;      /*!< Specifies the RTC Alarm Time members. */

    RTC_DateTypeDef RTC_AlarmDate;      /*!< Specifies the RTC Alarm Date members. */

} RTC_AlarmTypeDef;

/* Exported constants --------------------------------------------------------*/
/** @defgroup RTC_Exported_Constants
 * @{
 */

/** @defgroup RTC_Input_parameter_format_definitions
  * @{
  */
#define RTC_Format_BIN                  ((uint32_t)0x000000000)
#define RTC_Format_BCD                  ((uint32_t)0x000000001)

#define IS_RTC_FORMAT(FORMAT)           (((FORMAT) == RTC_Format_BIN) || \
                                         ((FORMAT) == RTC_Format_BCD))
/**
  * @}
  */

/** @defgroup RTC_Time_Definitions
 * @{
 */

#define IS_RTC_HOURS(HOURS)             ((HOURS) <= 23)
#define IS_RTC_MINUTES(MINUTES)         ((MINUTES) <= 59)
#define IS_RTC_SECONDS(SECONDS)         ((SECONDS) <= 59)
/**
 * @}
 */

/** @defgroup RTC_Year_Date_Definitions
  * @{
  */

#define IS_RTC_YEAR(YEAR)              ((YEAR) <= 4095)
/**
  * @}
  */

/** @defgroup RTC_Month_Date_Definitions
 * @{
 */
#define IS_RTC_MONTH(MONTH)             (((MONTH) >= 1) && ((MONTH) <= 12))
#define IS_RTC_DATE(DATE)               (((DATE) >= 1) && ((DATE) <= 31))

/**
 * @}
 */

/** @defgroup RTC_WeekDay_Definitions
 * @{
 */

#define IS_RTC_WEEKDAY(WEEKDAY)         (((WEEKDAY) >= 1) && ((WEEKDAY) <= 7))
/**
 * @}
 */

/** @defgroup RTC_Interrupts_Definitions
  * @{
  */

#define RTC_IT_ALARM            RTC_RTCINTE_AINT
#define RTC_IT_MON              RTC_RTCINTE_IMMON
#define RTC_IT_DAY              RTC_RTCINTE_IMDAY
#define RTC_IT_DATE             RTC_RTCINTE_IMDATE
#define RTC_IT_HOUR             RTC_RTCINTE_IMHOUR
#define RTC_IT_MIN              RTC_RTCINTE_IMMIN
#define RTC_IT_SEC              RTC_RTCINTE_IMSEC

#define IS_RTC_CONFIG_IT(IT)    (((IT) & RTC_IT_ALARM) || \
                                 ((IT) & RTC_IT_MON)   || \
                                 ((IT) & RTC_IT_DAY)   || \
                                 ((IT) & RTC_IT_DATE)  || \
                                 ((IT) & RTC_IT_HOUR)  || \
                                 ((IT) & RTC_IT_MIN)   || \
                                 ((IT) & RTC_IT_SEC))

#define RTC_IT_ALARMP           RTC_RTCINTP_RTCALF
#define RTC_IT_COUNTERP         RTC_RTCINTP_RTCCIF

#define IS_RTC_GET_IT(IT)       (((IT) == RTC_IT_ALARMP) || \
                                 ((IT) == RTC_IT_COUNTERP))

#define IS_RTC_CLEAR_IT(IT)     (((IT) == RTC_IT_ALARMP) || \
                                 ((IT) == RTC_IT_COUNTERP))
/**
  * @}
  */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void RTC_Cmd(FunctionalState NewState);
void RTC_DividerCmd(FunctionalState NewState);

/* Time and Date configuration functions **************************************/
void RTC_SetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
void RTC_TimeStructInit(RTC_TimeTypeDef* RTC_TimeStruct);
void RTC_GetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
void RTC_SetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct);
void RTC_DateStructInit(RTC_DateTypeDef* RTC_DateStruct);
void RTC_GetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct);

/* Alarms (Alarm A) configuration functions  **********************************/
void RTC_SetAlarm(uint32_t RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct);
void RTC_AlarmStructInit(RTC_AlarmTypeDef* RTC_AlarmStruct);
void RTC_GetAlarm(uint32_t RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct);
void RTC_AlarmCmd(FunctionalState NewState);

/* Interrupts and flags management functions **********************************/
void RTC_ITConfig(uint32_t RTC_IT, FunctionalState NewState);
ITStatus RTC_GetITStatus(uint32_t RTC_IT);
void RTC_ClearITPendingBit(uint32_t RTC_IT);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_RTC_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

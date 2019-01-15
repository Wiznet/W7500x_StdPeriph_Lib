/**
 ******************************************************************************
 * @file    w7500x_wdt.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Watchdog
 *          Timer(WDT) firmware library.
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
#ifndef __W7500X_WDT_H
#define __W7500X_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup WDT
 * @{
 */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup WDT_Exported_Constants
 * @{
 */

#define IS_WDT_LOAD(LOAD)           ((LOAD) >= 1 && (LOAD) <= 0xFFFFFFFF)

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Configuration functions ****************************************************/
void WDT_WriteAccessCmd(FunctionalState NewState);
void WDT_SetloadCounter(uint32_t load);
void WDT_ReloadCounter(void);

/* WDT activation functions ***************************************************/
void WDT_Enable(FunctionalState NewState);

/* Flag management function ***************************************************/
ITStatus WDT_GetITStatus(void);
void WDT_ClearIT(void);

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

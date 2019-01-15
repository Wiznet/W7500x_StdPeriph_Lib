/**
 ******************************************************************************
 * @file    system_w7500x.h
 * @author  WIZnet
 * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer System Header File.
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

/**
 * @brief Define to prevent recursive inclusion
 */
#ifndef __SYSTEM_W7500x_H
#define __SYSTEM_W7500x_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup W7500x_System_Includes
 * @{
 */
#include "w7500x.h"
/**
 * @}
 */

/** @addtogroup W7500x_System_Exported_types
 * @{
 */

/**
 * @}
 */

/** @addtogroup W7500x_System_Exported_Constants
 * @{
 */

/**
 * @}
 */

/** @addtogroup W7500x_System_Exported_Macros
 * @{
 */

/**
 * @}
 */

/** @addtogroup W7500x_System_Exported_Functions
 * @{
 */
extern uint32_t GetSystemClock(void); /*!< Get System Clock Frequency */
extern uint32_t GetSourceClock(void); /*!< Get PLL Source Clock Frequency */
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_W7500x_H */

/**
 * @}
 */

/**
 * @}
 */
/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

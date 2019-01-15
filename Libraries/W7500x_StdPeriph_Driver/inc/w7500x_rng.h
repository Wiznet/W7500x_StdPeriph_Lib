/**
 ******************************************************************************
 * @file    w7500x_rng.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Random
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __W7500X_RNG_H
#define __W7500X_RNG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup RNG
 * @{
 */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup RNG_Exported_Constants
 * @{
 */

/** @defgroup RNG_Clock_sources
 * @{
 */
#define RNG_CLK_RNGCLK                  ~RNG_CLKSEL_CLKSEL
#define RNG_CLK_PCLK                    RNG_CLKSEL_CLKSEL

#define IS_RNG_CLK_SRC(SRC)               (((SRC) == RNG_CLK_RNGCLK || (SRC) == RNG_CLK_PCLK))
/**
 * @}
 */

/** @defgroup RNG_Mode
 * @{
 */
#define RNG_PLL_LOCK_signal                 ~RNG_MODE_MODE
#define RNG_RUN_register                    RNG_MODE_MODE

#define IS_RNG_MODE(SRC)               (((SRC) == RNG_PLL_LOCK_signal || (SRC) == RNG_RUN_register))
/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Configuration functions ****************************************************/
void RNG_SetMode(uint32_t mode);
void RNG_SetClockSource(uint32_t src);
void RNG_SetSeed(uint32_t value);
void RNG_SetPolynomial(uint32_t value);

/* RNG activation functions ***************************************************/
void RNG_Enable(FunctionalState NewState);

/* Data Read functions ********************************************************/
uint32_t RNG_GetRandomNumber(void);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_RNG_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

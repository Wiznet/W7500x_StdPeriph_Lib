/**
 ******************************************************************************
 * @file    w7500x_miim.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Media
 *          Independent Interface Management (MIIM).
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
#ifndef __W7500X_MIIM_H
#define __W7500X_MIIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x_gpio.h"
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup MIIM
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/**
 * @brief  Link Type enumeration
 */

typedef enum
{
    HalfDuplex10 = 0,
    FullDuplex10,
    AutoNego,
    HalfDuplex100,
    FullDuplex100
} Link_Type;

#define IS_LINK_TYPE(TYPE)  (((TYPE)==HalfDuplex10) || \
                             ((TYPE)==FullDuplex10) || \
                             ((TYPE)==AutoNego) || \
                             ((TYPE)==HalfDuplex100) || \
                             ((TYPE)==FullDuplex100))

/**
 * @brief  Reset Type enumeration
 */

typedef enum
{
    Software = 0,
    Hardware
} Reset_Type;

#define IS_RESET_TYPE(TYPE) (((TYPE)==Software) || \
                             ((TYPE)==Hardware) || \
							 ((TYPE)==Both))

/* Exported constants --------------------------------------------------------*/

/** @defgroup MIIM_Exported_Constants
 * @{
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
FlagStatus PHY_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_MDC, uint16_t GPIO_Pin_MDIO);
void PHY_Reset(Reset_Type reset);
FlagStatus PHY_GetLinkStatus(void);
void PHY_SetLinkType(Link_Type link);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_MIIM_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

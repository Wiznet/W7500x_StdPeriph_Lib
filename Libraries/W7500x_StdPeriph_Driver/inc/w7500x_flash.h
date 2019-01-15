/**
 ******************************************************************************
 * @file    w7500x_flash.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the Embedded
 *          Flash memory firmware library.
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
#ifndef __W7500X_FLASH_H
#define __W7500X_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup FLASH
 * @{
 */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Constants
 * @{
 */

/** @defgroup FLASH_IAP_IDs
 * @{
 */
#define IAP_ERAS_DAT0       (0x010)  /*!< Erase Data 0 block                     */
#define IAP_ERAS_DAT1       (0x011)  /*!< Erase Data 1 block                     */
#define IAP_ERAS_SECT       (0x012)  /*!< Erase a Sector in Main Flash Memory    */
#define IAP_ERAS_BLCK       (0x013)  /*!< Erase a Block in Main Flash Memory     */
#define IAP_ERAS_CHIP       (0x014)  /*!< Erase all code                         */
#define IAP_ERAS_MASS       (0x015)  /*!< Erase all code & data                  */
#define IAP_PROG            0x022
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void FLASH_IAP(uint32_t id, uint32_t dst_addr, uint8_t* src_addr, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_FLASH_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

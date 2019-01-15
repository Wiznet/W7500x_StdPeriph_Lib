/**
 ******************************************************************************
 * @file    w7500x_flash.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Embedded
 *          Flash memory peripheral.
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
#include "w7500x_flash.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup FLASH
 * @brief Flash driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define IAP_ENTRY           0x1FFF1001      /*!< Because Thum code */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup FLASH_Private_Functions
 * @{
 */

/**
 * @brief  The W7500x embedded Flash memory can be programmed using
 *         in-application programming. IAP allows the user to re-program the
 *         Flash memory while the application is running.
 * @param  id: where x can be from 0 to 1 to select the UART peripheral.
 *          his parameter can be one of the following values:
 *            @arg IAP_ERAS_DAT0:  Erase Data 0 block
 *            @arg IAP_ERAS_DAT1:  Erase Data 1 block
 *            @arg IAP_ERAS_SECT:  Erase a Sector in Main Flash Memory
 *            @arg IAP_ERAS_BLCK:  Erase a Block in Main Flash Memory
 *            @arg IAP_ERAS_CHIP:  Erase all code
 *            @arg IAP_ERAS_MASS:  Erase all code & data
 *            @arg IAP_PROG:  Write
 * @param  dst_addr: the flash memory address.
 * @param  src_addr: the buffer pointer user want to program.
 * @param  size: the flash size.
 * @retval None
 */
void FLASH_IAP(uint32_t id, uint32_t dst_addr, uint8_t* src_addr, uint32_t size)
{
    uint32_t temp_interrupt;

    /* Backup Interrupt Set Pending Register */
    temp_interrupt = (NVIC->ISPR[0]);
    (NVIC->ISPR[0]) = (uint32_t) 0xFFFFFFFF;

    /* Call IAP Function */
    ((void (*)(uint32_t, uint32_t, uint8_t*, uint32_t)) IAP_ENTRY)(id, dst_addr, src_addr, size);

    /* Restore Interrupt Set Pending Register */
    (NVIC->ISPR[0]) = temp_interrupt;
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

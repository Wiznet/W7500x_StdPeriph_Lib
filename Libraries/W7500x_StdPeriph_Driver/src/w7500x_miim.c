/**
 ******************************************************************************
 * @file    w7500x_miim.c
 * @author  WIZnet
 * @brief   This file provides firmware functions to manage of the Media
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

/*includes -------------------------------------------*/
#include <stdio.h>
#include "w7500x_miim.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @defgroup MIIM
 * @brief MIIM driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define PHYREG_CONTROL              0x0
#define PHYREG_CONTROL_RESET        (0x01UL<<15)
#define PHYREG_CONTROL_SPEED        (0x01UL<<13)
#define PHYREG_CONTROL_AUTONEGO     (0x01UL<<12)
#define PHYREG_CONTROL_POWER        (0x01UL<<12)
#define PHYREG_CONTROL_DUPLEX       (0x01UL<< 8)
#define PHYREG_STATUS               0x1
#define PHYREG_STATUS_AUTONEGO      (0x01UL<< 5)
#define PHYREG_STATUS_LINK          (0x01UL<< 2)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint16_t miim_MDIO;
static uint16_t miim_MDC;
static GPIO_TypeDef* miim_PORT;
static uint32_t PHY_ADDR = 0;

/* Private function prototypes -----------------------------------------------*/
static void MDIO_Idle(void);
static uint32_t MDIO_In(void);
static void MDIO_Out(uint32_t val, uint32_t n);
static void MDIO_Turnaround(void);
static void MDIO_SetData(uint32_t regAddr, uint32_t val);
static uint32_t MDIO_GetData(uint32_t phyAddr, uint32_t regAddr);
static FlagStatus PHY_GetId(void);
static void miim_delay(__O uint32_t count);

/* Private functions ---------------------------------------------------------*/

/** @defgroup MIIM_Private_Functions
 * @{
 */

/**
 * @brief  Initializes the PHY
 * @param  GPIOx: where x can be (A..D) to select the GPIO peripheral.
 * @note   GPIO peripheral used by MDC, MDIO signals
 * @param  GPIO_Pin_MDC: Physically connected MDC signal line.
 * @param  GPIO_Pin_MDIO: Physically connected MDIO signal line.
 * @retval The new state of PHY_Init (SET or RESET).
 */
FlagStatus PHY_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_MDC, uint16_t GPIO_Pin_MDIO)
{
    FlagStatus bitstatus = RESET;
    GPIO_InitTypeDef GPIO_InitStructure;

    miim_PORT = GPIOx;
    miim_MDC = GPIO_Pin_MDC;
    miim_MDIO = GPIO_Pin_MDIO;

#ifdef W7500
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Direction = GPIO_Direction_OUT;
    GPIO_InitStructure.GPIO_Pad = GPIO_CMOS | GPIO_InputBufferEnable | GPIO_LowDrivingStrength;
    GPIO_InitStructure.GPIO_AF = PAD_AF0;

    GPIO_Init(GPIOB, &GPIO_InitStructure);
#elif defined (W7500P)
    GPIO_PinPadConfig(GPIOB, GPIO_PinSource12, GPIO_PuPd_UP|GPIO_InputBufferEnable|GPIO_CMOS);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, PAD_AF1);
    GPIO_PinPadConfig(GPIOB, GPIO_PinSource5, GPIO_PuPd_UP|GPIO_InputBufferEnable|GPIO_CMOS);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, PAD_AF1);
    GPIO_PinPadConfig(GPIOB, GPIO_PinSource6, GPIO_PuPd_UP|GPIO_InputBufferEnable|GPIO_CMOS);

    GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, PAD_AF1);
    GPIO_PinPadConfig(GPIOD, GPIO_PinSource6, GPIO_PuPd_UP);
    // for this GPIOD pin 6, keep the following sequence, set the value & set the output enable
    GPIO_SetBits(GPIOD, GPIO_Pin_6); // PHY reset pin
    GPIOD->OUTENSET = GPIO_Pin_6; // PHY reset pin
#endif

    /* Set GPIOs for MDIO and MDC */
    GPIO_InitStructure.GPIO_Pin = miim_MDC | miim_MDIO;
    GPIO_InitStructure.GPIO_Direction = GPIO_Direction_OUT;
    GPIO_InitStructure.GPIO_Pad = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_AF = PAD_AF1;

    GPIO_Init(miim_PORT, &GPIO_InitStructure);

    PHY_Reset(0); // phy reset
    bitstatus = PHY_GetId();

    return bitstatus;
}

/**
 * @brief  Reset the PHY
 * @param  reset: To select the reset type.
 *          This parameter can be one of the following values:
 *            @arg Software
 *            @arg Hardware
 * @retval None.
 */
void PHY_Reset(Reset_Type reset)
{
/*
if (reset == Hardware) {
#ifdef W7500P
// don't touch PHY reset pin
// pls, use MDIO PHY reset.
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, PAD_AF1);
        GPIO_PinPadConfig(GPIOD, GPIO_PinSource6, GPIO_PuPd_DOWN);
        GPIOD->OUTENSET = GPIO_Pin_6;
        GPIO_ResetBits(GPIOD, GPIO_Pin_6);
        miim_delay(100);
        GPIO_SetBits(GPIOD, GPIO_Pin_6);
        miim_delay(250);
#endif
    } else {
*/
    MDIO_SetData(PHYREG_CONTROL, PHYREG_CONTROL_RESET);      // PHY Reset
//    }
}

/**
 * @brief  Get the Link Status
 * @param  None.
 * @retval The new state of Link Status (SET or RESET).
 */
FlagStatus PHY_GetLinkStatus(void)
{
    FlagStatus bitstatus = RESET;

    if ((MDIO_GetData(PHY_ADDR, PHYREG_STATUS) & PHYREG_STATUS_LINK) != (FlagStatus) RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
 * @brief  Set the PHY Link Type
 * @param  link: To select the link type.
 *          This parameter can be one of the following values:
 *            @arg HalfDuplex10
 *            @arg FullDuplex10
 *            @arg AutoNego
 *            @arg HalfDuplex100
 *            @arg FullDuplex100
 * @retval None.
 */
void PHY_SetLinkType(Link_Type link)
{
    assert_param(IS_LINK_TYPE(link));

    if (link == HalfDuplex10) {
        MDIO_SetData(PHYREG_CONTROL, 0x0000);
    } else if (link == FullDuplex10) {
        MDIO_SetData(PHYREG_CONTROL, PHYREG_CONTROL_DUPLEX);
    } else if (link == AutoNego) {
        MDIO_SetData(PHYREG_CONTROL, PHYREG_CONTROL_AUTONEGO);
    } else if (link == HalfDuplex100) {
        MDIO_SetData(PHYREG_CONTROL, PHYREG_CONTROL_SPEED);
    } else {
        MDIO_SetData(PHYREG_CONTROL, PHYREG_CONTROL_SPEED | PHYREG_CONTROL_DUPLEX);
    }
}

static void MDIO_Idle(void)
{
    miim_PORT->OUTENSET = miim_MDIO;

    GPIO_SetBits(miim_PORT, miim_MDC);
    miim_delay(10);
    GPIO_ResetBits(miim_PORT, miim_MDC);
    miim_delay(10);
}

static void MDIO_Out(uint32_t val, uint32_t n)
{
    for (val <<= (32 - n); n; val <<= 1, n--) {
        if (val & 0x80000000) GPIO_SetBits(miim_PORT, miim_MDIO);
        else GPIO_ResetBits(miim_PORT, miim_MDIO);

        miim_delay(10);
        GPIO_SetBits(miim_PORT, miim_MDC);
        miim_delay(10);
        GPIO_ResetBits(miim_PORT, miim_MDC);
    }
}

static uint32_t MDIO_In(void)
{
    uint32_t i, val = 0;

    for (i = 0; i < 16; i++) {
        val <<= 1;
        GPIO_SetBits(miim_PORT, miim_MDC);
        miim_delay(10);
        GPIO_ResetBits(miim_PORT, miim_MDC);
        miim_delay(10);
        val |= GPIO_ReadInputDataBit(miim_PORT, miim_MDIO);
    }
    return (val);
}

static void MDIO_Turnaround(void)
{
    miim_PORT->OUTENCLR = miim_MDIO;

    miim_delay(10);
    GPIO_SetBits(miim_PORT, miim_MDC);
    miim_delay(10);
    GPIO_ResetBits(miim_PORT, miim_MDC);
    miim_delay(10);
}

static uint32_t MDIO_GetData(uint32_t phyAddr, uint32_t regAddr)
{
    uint32_t val = 0;

    /* 32 Consecutive ones on MDO to establish sync */
    MDIO_Out(0xFFFFFFFF, 32);

    /* start code 01, read command (10) */
    MDIO_Out(0x06, 4);

    /* write PHY address */
    MDIO_Out(phyAddr, 5);
    MDIO_Out(regAddr, 5);

    /* turnaround MDO is tristated */
    MDIO_Turnaround();

    /* Read the data value */
    val = MDIO_In();

    /* turnaround MDO is tristated */
    MDIO_Idle();

    return val;
}

static void MDIO_SetData(uint32_t regAddr, uint32_t val)
{
    /* 32 Consecutive ones on MDO to establish sync */
    MDIO_Out(0xFFFFFFFF, 32);

    /* start code 01, write command (01) */
    MDIO_Out(0x05, 4);

    /* write PHY address */
    MDIO_Out(PHY_ADDR, 5);

    MDIO_Out(regAddr, 5);

    /* turnaround MDO */
    MDIO_Out(0x02, 2);

    /* Write the data value */
    MDIO_Out(val, 16);

    /* turnaround MDO is tristated */
    MDIO_Idle();
}

static FlagStatus PHY_GetId(void)
{
    FlagStatus bitstatus = RESET;
    uint8_t i;
    uint32_t data;

    for (i = 0; i < 8; i++) {
        data = MDIO_GetData(i, PHYREG_STATUS);

        if ((data != 0x0) && (data != 0xFFFF)) {
            PHY_ADDR = i;
            bitstatus = SET;
            break;
        }
    }

    return bitstatus;
}

static void miim_delay(__O uint32_t count)
{
    uint32_t i;

    for (i = 0; i < count; i++) {
        __NOP();
    }
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

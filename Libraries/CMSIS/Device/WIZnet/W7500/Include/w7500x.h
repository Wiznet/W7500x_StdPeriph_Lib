/**
 ******************************************************************************
 * @file    w7500x.h
 * @author  WIZnet
 * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer Header File.
 *          This file contains all the peripheral register's definitions, bits
 *          definitions and memory mapping for W7500x devices.
 *
 *          The file is the unique include file that the application programmer
 *          is using in the C source code, usually in main.c. This file contains:
 *           - Configuration section that allows to select:
 *              - The device used in the target application
 *              - To use or not the peripheral��s drivers in application code(i.e.
 *                code will be based on direct access to peripheral��s registers
 *                rather than drivers API), this option is controlled by
 *                "#define USE_STDPERIPH_DRIVER"
 *              - To change few application-specific parameters such as the HSE
 *                crystal frequency
 *           - Data structures and the address mapping for all peripherals
 *           - Peripheral's registers declarations and bits definition
 *           - Macros to access peripheral��s registers hardware
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

/** @addtogroup w7500x
 * @{
 */

#ifndef __W7500X_H
#define __W7500X_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Library_configuration_section
 * @{
 */

/* Uncomment the line below according to the target W7500x device used in your
 application
 */
#if !defined (W7500) && !defined (W7500P)
#define W7500
//#define W7500P
#endif

#if !defined (W7500) && !defined (W7500P)
#error "Please select first the target W7500x device used in your application (in w7500x.h file)"
#endif

#if !defined  USE_STDPERIPH_DRIVER
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
 In this case, these drivers will not be included and the application code will
 be based on direct access to peripherals registers
 */
#define USE_STDPERIPH_DRIVER
#endif /* USE_STDPERIPH_DRIVER */

/**
 * @brief In the following line adjust the value of External oscillator clock (8MHz ~ 24MHz)
 used in your application

 Tip: If you want to use the Internal 8MHz RC oscillator clock, uncomment the line below.
 */
//#define OCLK_VALUE 12000000UL
/**
 * @brief In the following line adjust the value of PLL
 */
#define PLL_VALUE 1

#if defined (OCLK_VALUE)
#if ((OCLK_VALUE * PLL_VALUE) > 48000000) || (OCLK_VALUE > 24000000)
#error "Can not exceed 48MHz, Please adjust the PLL value (in w7500x.h file)"
#endif
#else
#define RCLK_VALUE 8000000
#if ((RCLK_VALUE * PLL_VALUE) > 48000000)
#error "Can not exceed 48MHz, Please adjust the PLL value (in w7500x.h file)"
#endif
#endif

#if !defined (PLL_VALUE)
#define PLL_VALUE 1
#endif

/**
 * @brief W7500x Standard Peripheral Library version number
 */
#define __W7500X_STDPERIPH_VERSION_MAIN   (0x01) /*!< [23:16] main version */
#define __W7500X_STDPERIPH_VERSION_SUB1   (0x00) /*!< [15:8] sub1 version */
#define __W7500X_STDPERIPH_VERSION_SUB2   (0x00) /*!< [7:0]  sub2 version */
#define __W7500X_STDPERIPH_VERSION        ((__W7500X_STDPERIPH_VERSION_MAIN << 16)\
                                          |(__W7500X_STDPERIPH_VERSION_SUB1 << 8)\
										  |(__W7500X_STDPERIPH_VERSION_SUB2))

/**
 * @}
 */

/** @addtogroup Configuration_section_for_CMSIS
 * @{
 */

/**
 * @brief W7500x Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
#define __CM0_REV                 0x0000    /*!< Core Revision r0p0                               */
#define __MPU_PRESENT             0         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */

/*!< Interrupt Number Definition */
typedef enum IRQn
{
    /******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
    NonMaskableInt_IRQn = -14,                  /*!<  2 Cortex-M0 Non Maskable Interrupt              */
    HardFault_IRQn = -13,                       /*!<  3 Cortex-M0 Hard Fault Interrupt                */
    SVCall_IRQn = -5,                           /*!< 11 Cortex-M0 SV Call Interrupt                   */
    PendSV_IRQn = -2,                           /*!< 14 Cortex-M0 Pend SV Interrupt                   */
    SysTick_IRQn = -1,                          /*!< 15 Cortex-M0 System Tick Interrupt               */
    /******  W7500x Specific Interrupt Numbers ********************************************************/
    SSP0_IRQn = 0,                              /*!< SSP 0 Interrupt                                  */
    SSP1_IRQn = 1,                              /*!< SSP 1 Interrupt                                  */
    UART0_IRQn = 2,                             /*!< UART 0 Interrupt                                 */
    UART1_IRQn = 3,                             /*!< UART 1 Interrupt                                 */
    UART2_IRQn = 4,                             /*!< UART 2 Interrupt                                 */
                                                /*!< Reserved                                         */
                                                /*!< Reserved                                         */
    PORT0_IRQn = 7,                             /*!< Port 0 combined Interrupt                        */
    PORT1_IRQn = 8,                             /*!< Port 1 combined Interrupt                        */
    PORT2_IRQn = 9,                             /*!< Port 2 combined Interrupt                        */
    PORT3_IRQn = 10,                            /*!< Port 3 combined Interrupt                        */
    DMA_IRQn = 11,                              /*!< DMA combined Interrupt                           */
    DUALTIMER0_IRQn = 12,                       /*!< Dual Timer 0 Interrupt                           */
    DUALTIMER1_IRQn = 13,                       /*!< Dual Timer 1 Interrupt                           */
    PWM0_IRQn = 14,                             /*!< PWM 0 Interrupt                                  */
    PWM1_IRQn = 15,                             /*!< PWM 1 Interrupt                                  */
    PWM2_IRQn = 16,                             /*!< PWM 2 Interrupt                                  */
    PWM3_IRQn = 17,                             /*!< PWM 3 Interrupt                                  */
    PWM4_IRQn = 18,                             /*!< PWM 4 Interrupt                                  */
    PWM5_IRQn = 19,                             /*!< PWM 5 Interrupt                                  */
    PWM6_IRQn = 20,                             /*!< PWM 6 Interrupt                                  */
    PWM7_IRQn = 21,                             /*!< PWM 7 Interrupt                                  */
    RTC_IRQn = 22,                              /*!< RTC Interrupt                                    */
    ADC_IRQn = 23,                              /*!< ADC Interrupt                                    */
    WZTOE_IRQn = 24,                            /*!< WZTOE Interrupt                                  */
    EXTI_IRQn = 25                              /*!< EXTI Interrupt                                   */
} IRQn_Type;

/**
 * @}
 */

#include "core_cm0.h"                    /* Cortex-M0 processor and core peripherals              */
#include "system_w7500x.h"               /* W7500x System include file                            */

/** @addtogroup Exported_types
 * @{
 */

typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
    ERROR = 0,
    SUCCESS = !ERROR
} ErrorStatus;

/** @addtogroup Peripheral_registers_structures
 * @{
 */

/**
 * @brief Clock Reset Generator
 */
typedef struct
{
    __IO uint32_t OSC_PDR;              /*!< Oscillator power down register,               Address offset : 0x000 */
         uint32_t RESERVED0[3];
    __IO uint32_t PLL_PDR;              /*!< PLL power down register,                      Address offset : 0x010 */
    __IO uint32_t PLL_FCR;              /*!< PLL frequency calculating register,           Address offset : 0x014 */
    __IO uint32_t PLL_OER;              /*!< PLL output enable register,                   Address offset : 0x018 */
    __IO uint32_t PLL_BPR;              /*!< PLL bypass register,                          Address offset : 0x01C */
    __IO uint32_t PLL_IFSR;             /*!< PLL input frequency select register,          Address offset : 0x020 */
         uint32_t RESERVED1[3];
    __IO uint32_t FCLK_SSR;             /*!< FCLK source select register,                  Address offset : 0x030 */
    __IO uint32_t FCLK_PVSR;            /*!< FCLK prescale value select register,          Address offset : 0x034 */
         uint32_t RESERVED2[2];
    __IO uint32_t SSPCLK_SSR;           /*!< SSPCLK source select register,                Address offset : 0x040 */
    __IO uint32_t SSPCLK_PVSR;          /*!< SSPCLK prescale value select register,        Address offset : 0x044 */
         uint32_t RESERVED3[6];
    __IO uint32_t ADCCLK_SSR;           /*!< ADCCLK source select register,                Address offset : 0x060 */
    __IO uint32_t ADCCLK_PVSR;          /*!< ADCCLK prescale value select register,        Address offset : 0x064 */
         uint32_t RESERVED4[2];
    __IO uint32_t TIMER0CLK_SSR;        /*!< TIMER0CLK source select register,             Address offset : 0x070 */
    __IO uint32_t TIMER0CLK_PVSR;       /*!< TIMER0CLK prescale value select register,     Address offset : 0x074 */
         uint32_t RESERVED5[2];
    __IO uint32_t TIMER1CLK_SSR;        /*!< TIMER1CLK source select register,             Address offset : 0x080 */
    __IO uint32_t TIMER1CLK_PVSR;       /*!< TIMER1CLK prescale value select register,     Address offset : 0x084 */
         uint32_t RESERVED6[10];
    __IO uint32_t PWM0CLK_SSR;          /*!< PWM0CLK source select register,               Address offset : 0x0B0 */
    __IO uint32_t PWM0CLK_PVSR;         /*!< PWM0CLK prescale value select register,       Address offset : 0x0B4 */
         uint32_t RESERVED7[2];
    __IO uint32_t PWM1CLK_SSR;          /*!< PWM1CLK source select register,               Address offset : 0x0C0 */
    __IO uint32_t PWM1CLK_PVSR;         /*!< PWM1CLK prescale value select register,       Address offset : 0x0C4 */
         uint32_t RESERVED8[2];
    __IO uint32_t PWM2CLK_SSR;          /*!< PWM2CLK source select register,               Address offset : 0x0D0 */
    __IO uint32_t PWM2CLK_PVSR;         /*!< PWM2CLK prescale value select register,       Address offset : 0x0D4 */
         uint32_t RESERVED9[2];
    __IO uint32_t PWM3CLK_SSR;          /*!< PWM3CLK source select register,               Address offset : 0x0E0 */
    __IO uint32_t PWM3CLK_PVSR;         /*!< PWM3CLK prescale value select register,       Address offset : 0x0E4 */
         uint32_t RESERVED10[2];
    __IO uint32_t PWM4CLK_SSR;          /*!< PWM4CLK source select register,               Address offset : 0x0F0 */
    __IO uint32_t PWM4CLK_PVSR;         /*!< PWM4CLK prescale value select register,       Address offset : 0x0F4 */
         uint32_t RESERVED11[2];
    __IO uint32_t PWM5CLK_SSR;          /*!< PWM5CLK source select register,               Address offset : 0x100 */
    __IO uint32_t PWM5CLK_PVSR;         /*!< PWM5CLK prescale value select register,       Address offset : 0x104 */
         uint32_t RESERVED12[2];
    __IO uint32_t PWM6CLK_SSR;          /*!< PWM6CLK source select register,               Address offset : 0x110 */
    __IO uint32_t PWM6CLK_PVSR;         /*!< PWM6CLK prescale value select register,       Address offset : 0x114 */
         uint32_t RESERVED13[2];
    __IO uint32_t PWM7CLK_SSR;          /*!< PWM7CLK source select register,               Address offset : 0x120 */
    __IO uint32_t PWM7CLK_PVSR;         /*!< PWM7CLK prescale value select register,       Address offset : 0x124 */
         uint32_t RESERVED14[2];

    __IO uint32_t RTC_HS_SSR;           /*!< RTCCLK source select register,                Address offset : 0x130 */
    __IO uint32_t RTC_HS_PVSR;          /*!< RTCCLK prescale value select register,        Address offset : 0x134 */
         uint32_t RESERVED15[1];
    __IO uint32_t RTC_SSR;              /*!< RTCCLK 32K select register,                   Address offset : 0x13C */

    __IO uint32_t WDOGCLK_HS_SSR;       /*!< WDOGCLK High Speed source select register,                         Address offset : 0x140 */
    __IO uint32_t WDOGCLK_HS_PVSR;      /*!< WDOGCLK High Speed prescale value select register,                 Address offset : 0x144 */
         uint32_t RESERVED16[2];

    __IO uint32_t UARTCLK_SSR;          /*!< UARTCLK source select register,                                    Address offset : 0x150 */
    __IO uint32_t UARTCLK_PVSR;         /*!< UARTCLK prescale value select register,                            Address offset : 0x154 */
         uint32_t RESERVED17[2];
    __IO uint32_t MIICLK_ECR;           /*!< MII clock enable control register,                                 Address offset : 0x160 */
         uint32_t RESERVED18[3];
    __IO uint32_t MONCLK_SSR;           /*!< Select clock source for monitoring (monitoring pin : PA_02),       Address offset : 0x170 */
} CRG_TypeDef;

/**
 * @brief Random Number generator
 */
typedef struct
{
    __IO uint32_t RUN;                  /*!< RNG run register,                    Address offset : 0x000 */
    __IO uint32_t SEED;                 /*!< RNG seed value register,             Address offset : 0x004 */
    __IO uint32_t CLKSEL;               /*!< RNG Clock source select register,    Address offset : 0x008 */
    __IO uint32_t MODE;                 /*!< RNG MODE select register,            Address offset : 0x00C */
    __I  uint32_t RN;                   /*!< RNG random number value register,    Address offset : 0x010 */
    __IO uint32_t POLY;                 /*!< RNG polynomial register,             Address offset : 0x014 */
} RNG_TypeDef;

/**
 * @brief Alternate Function Controller, External Interrupt, Pad Controller
 */
typedef struct
{
    __IO uint32_t REGISTER[16];
} PORTX_TypeDef;

/**
 * @brief General-purpose I/Os
 */
typedef struct
{
    __I  uint32_t DATA;                 /*!< DATA register,                         Address offset : 0x000 */
    __IO uint32_t DATAOUT;              /*!< Data Output Latch register,            Address offset : 0x004 */
         uint32_t RESERVED0[2];
    __IO uint32_t OUTENSET;             /*!< Output Enable Set register,            Address offset : 0x010 */
    __IO uint32_t OUTENCLR;             /*!< Output Enable Clear register,          Address offset : 0x014 */
    __IO uint32_t RESERVED1;            /*!< Alternate Function Set register,       Address offset : 0x018 */
    __IO uint32_t RESERVED2;            /*!< Alternate Function Clear register,     Address offset : 0x01C */
    __IO uint32_t INTENSET;             /*!< Interrupt Enable Set register,         Address offset : 0x020 */
    __IO uint32_t INTENCLR;             /*!< Interrupt Enable Clear register,       Address offset : 0x024 */
    __IO uint32_t INTTYPESET;           /*!< Interrupt Type Set register,           Address offset : 0x028 */
    __IO uint32_t INTTYPECLR;           /*!< Interrupt Type Clear register,         Address offset : 0x02C */
    __IO uint32_t INTPOLSET;            /*!< Interrupt Polarity Set register,       Address offset : 0x030 */
    __IO uint32_t INTPOLCLR;            /*!< Interrupt Polarity Clear register,     Address offset : 0x034 */
    union
    {
        __I uint32_t INTSTATUS;         /*!< Interrupt Status register,             Address offset : 0x038 */
        __O uint32_t INTCLEAR;          /*!< Interrupt Clear register,              Address offset : 0x038 */
    } Interrupt;
         uint32_t RESERVED3[241];
    __IO uint32_t LB_MASKED[256];       /*!< Lower byte Masked Access register,     Address offset : 0x400 - 0x7FC */
    __IO uint32_t UB_MASKED[256];       /*!< Upper byte Masked Access register,     Address offset : 0x800 - 0xBFC */
} GPIO_TypeDef;

/**
 * @brief Direct memory access controller
 */
typedef struct
{
    __I  uint32_t STATUS;               /*!< DMA status register,                                       Address offset: 0x00 */
    __O  uint32_t CFG;                  /*!< DMA configuration register,                                Address offset: 0x04 */
    __IO uint32_t CTRL_BASE_PTR;        /*!< Channel Control Data Base Pointer register,                Address offset: 0x08 */
    __I  uint32_t ALT_CTRL_BASE_PTR;    /*!< Channel Alternate Control Data Base Pointer register,      Address offset: 0x0C */
    __I  uint32_t WAITONREQ_STATUS;     /*!< Channel Wait On Request Status register,                   Address offset: 0x10 */
    __O  uint32_t CHNL_SW_REQUEST;      /*!< Channel Software Request register,                         Address offset: 0x14 */
    __IO uint32_t CHNL_USEBURST_SET;    /*!< Channel UseBurst Set register,                             Address offset: 0x18 */
    __O  uint32_t CHNL_USEBURST_CLR;    /*!< Channel UseBurst Clear register,                           Address offset: 0x1C */
    __IO uint32_t CHNL_REQ_MASK_SET;    /*!< Channel Request Mask Set register,                         Address offset: 0x20 */
    __O  uint32_t CHNL_REQ_MASK_CLR;    /*!< Channel Request Mask Clear register,                       Address offset: 0x24 */
    __IO uint32_t CHNL_ENABLE_SET;      /*!< Channel Enable Set register,                               Address offset: 0x28 */
    __O  uint32_t CHNL_ENABLE_CLR;      /*!< Channel Enable Clear register,                             Address offset: 0x2C */
    __IO uint32_t CHNL_PRI_ALT_SET;     /*!< Channel Primary-Alterante Set register,                    Address offset: 0x30 */
    __O  uint32_t CHNL_PRI_ALT_CLR;     /*!< Channel Primary-Alterante Clear register,                  Address offset: 0x34 */
    __IO uint32_t CHNL_PRIORITY_SET;    /*!< Channel Priority Set register,                             Address offset: 0x38 */
    __O  uint32_t CHNL_PRIORITY_CLR;    /*!< Channel Priority Clear register,                           Address offset: 0x3C */
         uint32_t RESERVED0[3];
    __IO uint32_t ERR_CLR;              /*!< Bus Error Clear register,                                  Address offset: 0x4C */
} DMA_TypeDef;

/**
 * @brief Analog-to-digital converter
 */
typedef struct
{
    __IO uint32_t CTR;                  /*!< ADC control register,                    Address offset : 0x00 */
    __IO uint32_t CHSEL;                /*!< ADC channel select register,             Address offset : 0x04 */
    __O  uint32_t START;                /*!< ADC start register,                      Address offset : 0x08 */
    __I  uint32_t DATA;                 /*!< ADC conversion data register,            Address offset : 0x0C */
    __IO uint32_t INT;                  /*!< ADC interrupt register,                  Address offset : 0x10 */
         uint32_t RESERVED0[2];
    __O  uint32_t INTCLR;               /*!< ADC interrupt clear register,            Address offset : 0x1C */
} ADC_TypeDef;

/**
 * @brief Pulse-Width Modulation
 */
typedef struct
{
    __IO uint32_t IER;                  /*!< Interrupt enable register,                             Address offset : 0x00 */
    __IO uint32_t SSR;                  /*!< Start Stop register,                                   Address offset : 0x04 */
    __IO uint32_t PSR;                  /*!< Pause register,                                        Address offset : 0x08 */
} PWM_Common_TypeDef;

typedef struct
{
    __I  uint32_t IR;                   /*!< Interrupt register,                                    Address offset : 0x00 */
    __IO uint32_t IER;                  /*!< Interrupt enable register,                             Address offset : 0x04 */
    __O  uint32_t ICR;                  /*!< Interrupt clear register,                              Address offset : 0x08 */
    __I  uint32_t TCR;                  /*!< Timer/Counter register,                                Address offset : 0x0C */
    __I  uint32_t PCR;                  /*!< Prescale counter register,                             Address offset : 0x10 */
    __IO uint32_t PR;                   /*!< Prescale register,                                     Address offset : 0x14 */
    __IO uint32_t MR;                   /*!< Match register,                                        Address offset : 0x18 */
    __IO uint32_t LR;                   /*!< Limit register,                                        Address offset : 0x1C */
    __IO uint32_t UDMR;                 /*!< Up-Down mode register,                                 Address offset : 0x20 */
    __IO uint32_t TCMR;                 /*!< Timer/Counter mode register,                           Address offset : 0x24 */
    __IO uint32_t PEEER;                /*!< PWM output enable and external input enable register,  Address offset : 0x28 */
    __IO uint32_t CMR;                  /*!< Capture mode register,                                 Address offset : 0x2C */
    __I  uint32_t CR;                   /*!< Capture register,                                      Address offset : 0x30 */
    __IO uint32_t PDMR;                 /*!< Periodic mode register,                                Address offset : 0x34 */
    __IO uint32_t DZER;                 /*!< Dead-zone enable register,                             Address offset : 0x38 */
    __IO uint32_t DZCR;                 /*!< Dead-zone counter register,                            Address offset : 0x3C */
} PWM_TypeDef;

/**
 * @brief Dual timers
 */
typedef struct
{
    __IO uint32_t LOAD;                 /*!< Timer Load register,                       Address offset : 0x00 */
    __I  uint32_t VALUE;                /*!< Timer Counter Current Value register,      Address offset : 0x04 */
    __IO uint32_t CONTROL;              /*!< Timer Control register,                    Address offset : 0x08 */
    __O  uint32_t INTCLR;               /*!< Timer Interrupt Clear register,            Address offset : 0x0C */
    __I  uint32_t RIS;                  /*!< Timer Raw Interrupt Status register,       Address offset : 0x10 */
    __I  uint32_t MIS;                  /*!< Timer Masked Interrupt Status register,    Address offset : 0x14 */
    __IO uint32_t BGLOAD;               /*!< Background Load register,                  Address offset : 0x18 */
         uint32_t RESERVED[25];
    __IO uint32_t CE;                   /*!< Clock enable register,                     Address offset : 0x80 */
} DUALTIMER_TypeDef;

/**
 * @brief Watchdog timer
 */
typedef struct
{
    __IO uint32_t LOAD;                 /*!< Watchdog timer Load register,                      Address offset : 0x000 */
    __I  uint32_t VALUE;                /*!< Watchdog timer Value register,                     Address offset : 0x004 */
    __IO uint32_t CONTROL;              /*!< Watchdog timer Control register,                   Address offset : 0x008 */
    __O  uint32_t INTCLR;               /*!< Watchdog timer Clear Interrupt register,           Address offset : 0x00C */
    __I  uint32_t RIS;                  /*!< Watchdog timer Raw Interrupt Status register,      Address offset : 0x010 */
    __I  uint32_t MIS;                  /*!< Watchdog timer Masked Interrupt Status register,   Address offset : 0x014 */
         uint32_t RESERVED[762];
    __IO uint32_t LOCK;                 /*!< Watchdog timer Lock register,                      Address offset : 0xC00 */
} WDT_TypeDef;

/**
 * @brief Real-time Clock(RTC)
 */
typedef struct
{
    __IO uint32_t RTCCON;               /*!< control register,                  Address offset: 0x00 */
    __IO uint32_t RTCINTE;              /*!< Interrupt Mask register,           Address offset: 0x04 */
    __IO uint32_t RTCINTP;              /*!< Interrupt Pending register,        Address offset: 0x08 */
    __IO uint32_t RTCAMR;               /*!< Alarm Mask register,               Address offset: 0x0C */
    __IO uint32_t BCDSEC;               /*!< BCD Second register,               Address offset: 0x10 */
    __IO uint32_t BCDMIN;               /*!< BCD Minute register,               Address offset: 0x14 */
    __IO uint32_t BCDHOUR;              /*!< BCD Hour register,                 Address offset: 0x18 */
    __IO uint32_t BCDDAY;               /*!< BCD Day register,                  Address offset: 0x1C */
    __IO uint32_t BCDDATE;              /*!< BCD Date register,                 Address offset: 0x20 */
    __IO uint32_t BCDMON;               /*!< BCD Month register,                Address offset: 0x24 */
    __IO uint32_t BCDYEAR;              /*!< BCD Year register,                 Address offset: 0x28 */
    __IO uint32_t PRESEC;               /*!< Predetermining Second register,    Address offset: 0x2C */
    __IO uint32_t PREMIN;               /*!< Predetermining Minute register,    Address offset: 0x30 */
    __IO uint32_t PREHOUR;              /*!< Predetermining Hour register,      Address offset: 0x34 */
    __IO uint32_t PREDAY;               /*!< Predetermining Day register,       Address offset: 0x38 */
    __IO uint32_t PREDATE;              /*!< Predetermining Date register,      Address offset: 0x3C */
    __IO uint32_t PREMON;               /*!< Predetermining Month register,     Address offset: 0x40 */
    __IO uint32_t PREYEAR;              /*!< Predetermining Year register,      Address offset: 0x44 */
    __I  uint32_t RTCTIME0;             /*!< Consolidated Time0 register,       Address offset: 0x48 */
    __I  uint32_t RTCTIME1;             /*!< Consolidated Time1 register,       Address offset: 0x4C */
} RTC_TypeDef;

/**
 * @brief UART
 */
typedef struct
{
    __IO uint32_t DR;                   /*!< Data,                              Address offset : 0x00 */
    union
    {
        __I uint32_t RSR;               /*!< Receive Status,                    Address offset : 0x04 */
        __O uint32_t ECR;               /*!< Error Clear,                       Address offset : 0x04 */
    } STATUS;
    uint32_t RESERVED0[4];
    __I  uint32_t FR;                   /*!< Flags,                             Address offset : 0x18 */
         uint32_t RESERVED1;
    __IO uint32_t ILPR;                 /*!< IrDA Low-power Counter,            Address offset : 0x20 */
    __IO uint32_t IBRD;                 /*!< Integer Baud Rate,                 Address offset : 0x24 */
    __IO uint32_t FBRD;                 /*!< Fractional Baud Rate,              Address offset : 0x28 */
    __IO uint32_t LCR_H;                /*!< Line Control,                      Address offset : 0x2C */
    __IO uint32_t CR;                   /*!< Control,                           Address offset : 0x30 */
    __IO uint32_t IFLS;                 /*!< Interrupt FIFO Level Select,       Address offset : 0x34 */
    __IO uint32_t IMSC;                 /*!< Interrupt Mask Set / Clear,        Address offset : 0x38 */
    __I  uint32_t RIS;                  /*!< Raw Interrupt Status ,             Address offset : 0x3C */
    __I  uint32_t MIS;                  /*!< Masked Interrupt Status ,          Address offset : 0x40 */
    __O  uint32_t ICR;                  /*!< Interrupt Clear,                   Address offset : 0x44 */
    __IO uint32_t DMACR;                /*!< DMA Control,                       Address offset : 0x48 */
} UART_TypeDef;

/**
 * @brief Simple UART
 */
typedef struct
{
    __IO uint32_t DR;                   /*!< Data register,                     Address offset: 0x00 */
    __IO uint32_t SR;                   /*!< Status register,                   Address offset: 0x04 */
    __IO uint32_t CR;                   /*!< Control register,                  Address offset: 0x08 */
    union
    {
        __I uint32_t ISR;               /*!< Interrupt Status register,         Address offset: 0x0C */
        __O uint32_t ICR;               /*!< Interrupt Clear register,          Address offset: 0x0C */
    } INT;
    __IO uint32_t BDR;                  /*!< Baudrate Divider register,         Address offset: 0x10 */

} S_UART_TypeDef;

/**
 * @brief Serial Peripheral Interface
 */
typedef struct
{
    __IO uint32_t CR0;                  /*!< Control register 0,                        Address offset: 0x00 */
    __IO uint32_t CR1;                  /*!< Control register 1,                        Address offset: 0x04 */
    __IO uint32_t DR;                   /*!< Data register,                             Address offset: 0x08 */
    __IO uint32_t SR;                   /*!< Status register,                           Address offset: 0x0C */
    __IO uint32_t CPSR;                 /*!< Clock prescale register,                   Address offset: 0x10 */
    __IO uint32_t IMSC;                 /*!< Interrupt mask set or clear register,      Address offset: 0x14 */
    __IO uint32_t RIS;                  /*!< Raw interrupt status register,             Address offset: 0x18 */
    __IO uint32_t MIS;                  /*!< Masked interrupt status register,          Address offset: 0x1C */
    __IO uint32_t ICR;                  /*!< Interrupt clear register,                  Address offset: 0x20 */
    __IO uint32_t DMACR;                /*!< DMA control register,                      Address offset: 0x24 */
} SSP_TypeDef;

/**
 * @}
 */

/**
 * @brief Random Number generator
 */
typedef struct
{
    __IO uint32_t REMAP;                /*!< Remap Control Register (R/W),        Address offset: 0x00 */
    __IO uint32_t PMUCTRL;              /*!< PMU Control Register (R/W),          Address offset: 0x04 */
    __IO uint32_t RESETOP;              /*!< Reset Option Register  (R/W),        Address offset: 0x08 */
    __IO uint32_t EMICTRL;              /*!< EMI Control Register  (R/W),         Address offset: 0x0C */
    __IO uint32_t RSTINFO;              /*!< Reset Information Register (R/W),    Address offset: 0x10 */
} SYSCFG_TypeDef;

/** @addtogroup Peripheral_memory_map
 * @{
 */

/* Peripheral and SRAM base address */
#define FLASH_BASE          (0x00000000UL)  /*!< (FLASH     ) Base Address */
#define INFO_BGT            (0x0003FDB8UL)
#define INFO_OSC            (0x0003FDBCUL)
#define SRAM_BASE           (0x20000000UL)  /*!< (SRAM      ) Base Address */
#define PERIPH_BASE         (0x40000000UL)  /*!< (Peripheral) Base Address */

#define RAM_BASE            SRAM_BASE
#define APB0_BASE           PERIPH_BASE
#define APB1_BASE           (0x41000000UL)
#define AHB_BASE            (0x42000000UL)

#define WDT_BASE            (APB0_BASE + 0x00000000UL)
#define DUALTIMER0_BASE     (APB0_BASE + 0x00001000UL)
#define DUALTIMER1_BASE     (APB0_BASE + 0x00002000UL)
#define PWM_BASE            (APB0_BASE + 0x00005000UL)
#define SUART_BASE          (APB0_BASE + 0x00006000UL)
#define RNG_BASE            (APB0_BASE + 0x00007000UL)
#define SSP0_BASE 	        (APB0_BASE + 0x0000A000UL)
#define SSP1_BASE 	        (APB0_BASE + 0x0000B000UL)
#define UART0_BASE          (APB0_BASE + 0x0000C000UL)
#define UART1_BASE          (APB0_BASE + 0x0000D000UL)
#define RTC_BASE            (APB0_BASE + 0x0000E000UL)
#define SYSCFG_BASE         (APB0_BASE + 0x0001F000UL)

#define ADC_BASE            (APB1_BASE + 0x00000000UL)
#define CRG_BASE            (APB1_BASE + 0x00001000UL)
#define TRIM_OSC            (APB1_BASE + 0x00001004UL)
#define TRIM_BGT            (APB1_BASE + 0x00001210UL)
#define AFC_BASE            (APB1_BASE + 0x00002000UL)
#define EXTI_BASE           (APB1_BASE + 0x00002200UL)
#define PAD_BASE            (APB1_BASE + 0x00003000UL)
#define DMA_BASE            (APB1_BASE + 0x00004000UL)

#define GPIOA_BASE          (AHB_BASE + 0x00000000UL)
#define GPIOB_BASE          (AHB_BASE + 0x01000000UL)
#define GPIOC_BASE          (AHB_BASE + 0x02000000UL)
#define GPIOD_BASE          (AHB_BASE + 0x03000000UL)

#define WZTOE_BASE          (APB0_BASE + 0x06000000UL)
#define TXMEM_BASE          (WZTOE_BASE + 0x00020000UL)
#define RXMEM_BASE          (WZTOE_BASE + 0x00030000UL)
/**
 * @}
 */

/** @addtogroup Peripheral_declaration
 * @{
 */
#define WDT                 ((WDT_TypeDef *)            WDT_BASE)
#define DUALTIMER0_0        ((DUALTIMER_TypeDef *)      DUALTIMER0_BASE)
#define DUALTIMER0_1        ((DUALTIMER_TypeDef *)      (DUALTIMER0_BASE + 0x20UL))
#define DUALTIMER1_0        ((DUALTIMER_TypeDef *)      DUALTIMER1_BASE)
#define DUALTIMER1_1        ((DUALTIMER_TypeDef *)      (DUALTIMER1_BASE + 0x20UL))
#define PWM                 ((PWM_Common_TypeDef *)     (PWM_BASE + 0x800UL))
#define PWM0                ((PWM_TypeDef *)            PWM_BASE)
#define PWM1                ((PWM_TypeDef *)            (PWM_BASE + 0x100UL))
#define PWM2                ((PWM_TypeDef *)            (PWM_BASE + 0x200UL))
#define PWM3                ((PWM_TypeDef *)            (PWM_BASE + 0x300UL))
#define PWM4                ((PWM_TypeDef *)            (PWM_BASE + 0x400UL))
#define PWM5                ((PWM_TypeDef *)            (PWM_BASE + 0x500UL))
#define PWM6                ((PWM_TypeDef *)            (PWM_BASE + 0x600UL))
#define PWM7                ((PWM_TypeDef *)            (PWM_BASE + 0x700UL))
#define UART2               ((S_UART_TypeDef *)         SUART_BASE)
#define RNG                 ((RNG_TypeDef *)            RNG_BASE)
#define SSP0                ((SSP_TypeDef *)            SSP0_BASE)
#define SSP1                ((SSP_TypeDef *)            SSP1_BASE)
#define UART0               ((UART_TypeDef *)           UART0_BASE)
#define UART1               ((UART_TypeDef *)           UART1_BASE)
#define RTC                 ((RTC_TypeDef *)            RTC_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *)         SYSCFG_BASE)

#define ADC                 ((ADC_TypeDef *)            ADC_BASE)
#define CRG                 ((CRG_TypeDef *)            CRG_BASE)
#define AFC_PA              ((PORTX_TypeDef *)          (AFC_BASE + 0x00000000UL))
#define AFC_PB              ((PORTX_TypeDef *)          (AFC_BASE + 0x00000040UL))
#define AFC_PC              ((PORTX_TypeDef *)          (AFC_BASE + 0x00000080UL))
#define AFC_PD              ((PORTX_TypeDef *)          (AFC_BASE + 0x000000C0UL))
#define EXTI_PA             ((PORTX_TypeDef *)          (EXTI_BASE + 0x00000000UL))
#define EXTI_PB             ((PORTX_TypeDef *)          (EXTI_BASE + 0x00000040UL))
#define EXTI_PC             ((PORTX_TypeDef *)          (EXTI_BASE + 0x00000080UL))
#define EXTI_PD             ((PORTX_TypeDef *)          (EXTI_BASE + 0x000000C0UL))
#define PADCON_PA           ((PORTX_TypeDef *)          (PAD_BASE + 0x00000000UL))
#define PADCON_PB           ((PORTX_TypeDef *)          (PAD_BASE + 0x00000040UL))
#define PADCON_PC           ((PORTX_TypeDef *)          (PAD_BASE + 0x00000080UL))
#define PADCON_PD           ((PORTX_TypeDef *)          (PAD_BASE + 0x000000C0UL))
#define DMA                 ((DMA_TypeDef *)            DMA_BASE)

#define GPIOA               ((GPIO_TypeDef *)           GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)           GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)           GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)           GPIOD_BASE)

/**
 * @}
 */

/** @addtogroup Exported_constants
 * @{
 */

/** @addtogroup Peripheral_Registers_Bits_Definition
 * @{
 */

/******************************************************************************/
/*                    Peripheral Registers Bits Definition                    */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_CTR register  *******************/
#define ADC_CTR_PWD_PWD                 (0x2UL)             /*!< power down flag */
#define ADC_CTR_PWD_SMPSEL              (0x1UL)             /*!< Sampling mode */

/******************  Bit definition for ADC_CHSEL register  *******************/
#define ADC_CHSEL_CHSEL                 (0x0UL)             /*!< CHSEL[3:0] bits (ADC Channel Select bits) */
#define ADC_CHSEL_CHSEL_0               (0x0UL)             /*!< Bit 0 */
#define ADC_CHSEL_CHSEL_1               (0x0UL)             /*!< Bit 1 */
#define ADC_CHSEL_CHSEL_2               (0x0UL)             /*!< Bit 2 */
#define ADC_CHSEL_CHSEL_3               (0x0UL)             /*!< Bit 3 */

/********************  Bit definition for ADC_START register  *****************/
#define ADC_START_ADC_SRT               (0x1UL)             /*!< Start ADC for conversion */

/*******************  Bit definition for ADC_DATA register  *******************/
#define ADC_DATA_ADC_DATA               (0xFFFUL)           /*!< ADC conversion result data */

/*********************  Bit definition for ADC_INT register  ******************/
#define ADC_INT_MASK                    (0x2UL)             /*!< Interrupt mask signal */
#define ADC_INT_INT                     (0x1UL)             /*!< ADC  conversion is done of Interrupt bit */

/*******************  Bit definition for ADC_INTCLR register  *****************/
#define ADC_INTCLR_INTCLR               (0x1UL)             /*!< ADC  conversion is done of Interrupt bit */

/******************************************************************************/
/*                                                                            */
/*                    Alternate Function Controller (AFC)                     */
/*                                                                            */
/******************************************************************************/
/*********************   Bit definition for AFSR   ****************************/
#define AFC_AFR_AF                      (0x03UL)            /*!< AF[1:0] bits (Pad alternate function selection) */
#define AFC_AFR_AF_0                    (0x01UL)            /*!< Bit 0 */
#define AFC_AFR_AF_1                    (0x02UL)            /*!< Bit 1 */

/******************************************************************************/
/*                                                                            */
/*                         Clock Reset generator (CRG)                        */
/*                                                                            */
/******************************************************************************/
/****************  Bit definition for CRG_OSC_PDR register  *******************/
#define CRG_OSC_PDR_OSCPD               (0x1UL)             /*!< Internal 8MHz RC oscillator power down flag */

/****************  Bit definition for CRG_PLL_PDR register  *******************/
#define CRG_PLL_PDR_PLLPD               (0x1UL)             /*!< PLL power down flag */

/****************  Bit definition for CRG_PLL_FCR register  *******************/
#define CRG_PLL_FCR_M                   (0x3F0000UL)        /*!< Loop divider control bits */
#define CRG_PLL_FCR_N                   (0x003F00UL)        /*!< Pre divider control bits */
#define CRG_PLL_FCR_OD                  (0x000003UL)        /*!< Output divider control bits */

/****************  Bit definition for CRG_PLL_OER register  *******************/
#define CRG_PLL_OER_PLLOEN              (0x1UL)             /*!< PLL output flag */

/****************  Bit definition for CRG_PLL_BPR register  *******************/
#define CRG_PLL_BPR_PLLBP               (0x1UL)             /*!< PLL bypass flag */

/****************  Bit definition for CRG_PLL_IFSR register  ******************/
#define CRG_PLL_IFSR_PLLIS              (0x1UL)             /*!< PLL input clock source select flag */

/****************  Bit definition for CRG_FCLK_SSR register  ******************/
#define CRG_FCLK_SSR_FCKSRC             (0x03UL)            /*!< FCKSRC[1:0] bits (FCLK source select bits) */
#define CRG_FCLK_SSR_FCKSRC_0           (0x01UL)            /*!< Bit 0 */
#define CRG_FCLK_SSR_FCKSRC_1           (0x02UL)            /*!< Bit 1 */

/****************  Bit definition for CRG_FCLK_PVSR register  *****************/
#define CRG_FCLK_PVSR_FCKPRE            (0x03UL)            /*!< FCKPRE[1:0] bits (FCLK prescale value select bits) */
#define CRG_FCLK_PVSR_FCKPRE_0          (0x01UL)            /*!< Bit 0 */
#define CRG_FCLK_PVSR_FCKPRE_1          (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_SSPCLK_SSR register  ***************/
#define CRG_SSPCLK_SSR_SSPCSS           (0x03UL)            /*!< SSPCSS[1:0] bits (SSPCLK source select bits) */
#define CRG_SSPCLK_SSR_SSPCSS_0         (0x01UL)            /*!< Bit 0 */
#define CRG_SSPCLK_SSR_SSPCSS_1         (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_SSPCLK_PVSR register  **************/
#define CRG_SSPCLK_PVSR_SSPCP           (0x03UL)            /*!< SSPCP[1:0] bits (SSPCLK prescale value select bits) */
#define CRG_SSPCLK_PVSR_SSPCP_0         (0x01UL)            /*!< Bit 0 */
#define CRG_SSPCLK_PVSR_SSPCP_1         (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_ADCCLK_SSR register  ***************/
#define CRG_ADCCLK_SSR_ADCSS            (0x03UL)            /*!< ADCSS[1:0] bits (ADCCLK source select bits) */
#define CRG_ADCCLK_SSR_ADCSS_0          (0x01UL)            /*!< Bit 0 */
#define CRG_ADCCLK_SSR_ADCSS_1          (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_ADCCLK_PVSR register  **************/
#define CRG_ADCCLK_PVSR_ADCCP           (0x03UL)            /*!< ADCCP[1:0] bits (ADCCLK prescale value select bits) */
#define CRG_ADCCLK_PVSR_ADCCP_0         (0x01UL)            /*!< Bit 0 */
#define CRG_ADCCLK_PVSR_ADCCP_1         (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_TIMERnCLK_SSR register  ************/
#define CRG_TIMERCLK_SSR_TCSS           (0x03UL)            /*!< TCSS[1:0] bits (TIMERnCLK source select bits) */
#define CRG_TIMERCLK_SSR_TCSS_0         (0x01UL)            /*!< Bit 0 */
#define CRG_TIMERCLK_SSR_TCSS_1         (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_TIMERnCLK_PVSR register  ***********/
#define CRG_TIMERCLK_PVSR_TCPS          (0x07UL)            /*!< TCPS[2:0] bits (TIMERnCLK prescale value select bits) */
#define CRG_TIMERCLK_PVSR_TCPS_0        (0x01UL)            /*!< Bit 0 */
#define CRG_TIMERCLK_PVSR_TCPS_1        (0x02UL)            /*!< Bit 1 */
#define CRG_TIMERCLK_PVSR_TCPS_2        (0x04UL)            /*!< Bit 2 */

/****************   Bit definition for CRG_PWMnCLK_SSR register  **************/
#define CRG_PWMCLK_SSR_PCSS             (0x03UL)            /*!< PCSS[1:0] bits (PWMnCLK source select bits) */
#define CRG_PWMCLK_SSR_PCSS_0           (0x01UL)            /*!< Bit 0 */
#define CRG_PWMCLK_SSR_PCSS_1           (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_PWMnCLK_PVSR register  *************/
#define CRG_PWMCLK_PVSR_PCPS            (0x07UL)            /*!< PCPS[2:0] bits (PWMnCLK prescale value select bits) */
#define CRG_PWMCLK_PVSR_PCPS_0          (0x01UL)            /*!< Bit 0 */
#define CRG_PWMCLK_PVSR_PCPS_1          (0x02UL)            /*!< Bit 1 */
#define CRG_PWMCLK_PVSR_PCPS_2          (0x04UL)            /*!< Bit 2 */

/****************   Bit definition for CRG_RTC_HS_SSR register  ***************/
#define CRG_RTC_HS_SSR_RTCHS            (0x03UL)            /*!< RTCHS[1:0] bits (RTC High Speed source select bits) */
#define CRG_RTC_HS_SSR_RTCHS_0          (0x01UL)            /*!< Bit 0 */
#define CRG_RTC_HS_SSR_RTCHS_1          (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_RTC_HS_PVSR register  **************/
#define CRG_RTC_HS_PVSR_RTCPRE          (0x07UL)            /*!< RTCPRE[2:0] bits (RTC High Speed prescale value select bits) */
#define CRG_RTC_HS_PVSR_RTCPRE_0        (0x01UL)            /*!< Bit 0 */
#define CRG_RTC_HS_PVSR_RTCPRE_1        (0x02UL)            /*!< Bit 1 */
#define CRG_RTC_HS_PVSR_RTCPRE_2        (0x03UL)            /*!< Bit 2 */

/********************   Bit definition for CRG_RTC_SSR register  **************/
#define CRG_RTC_SSR_RTCHS               (0x01UL)            /*!< RTCSEL[1:0] bits (RTC source select bits) */

/****************   Bit definition for CRG_WDOGCLK_HS_SSR register  ***********/
#define CRG_WDOGCLK_HS_SSR_WDHS         (0x03UL)            /*!< WDHS[1:0] bits (WDOGCLK High Speed source select bits) */
#define CRG_WDOGCLK_HS_SSR_WDHS_0       (0x01UL)            /*!< Bit 0 */
#define CRG_WDOGCLK_HS_SSR_WDHS_1       (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_WDOGCLK_HS_PVSR register  **********/
#define CRG_WDOGCLK_HS_PVSR_WDPRE       (0x07UL)            /*!< WDPRE[2:0] bits (WDOGCLK High Speed prescale value select bits) */
#define CRG_WDOGCLK_HS_PVSR_WDPRE_0     (0x01UL)            /*!< Bit 0 */
#define CRG_WDOGCLK_HS_PVSR_WDPRE_1     (0x02UL)            /*!< Bit 1 */
#define CRG_WDOGCLK_HS_PVSR_WDPRE_2     (0x03UL)            /*!< Bit 2 */

/****************   Bit definition for CRG_WDOGCLK_SSR register  **************/
#define CRG_WDOGCLK_SSR_WDSEL           (0x03UL)            /*!< WDSEL[1:0] bits (WDOGCLK clock source select bits) */
#define CRG_WDOGCLK_SSR_WDSEL_0         (0x01UL)            /*!< Bit 0 */
#define CRG_WDOGCLK_SSR_WDSEL_1         (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_UARTCLK_SSR register  **************/
#define CRG_UARTCLK_SSR_UCSS            (0x03UL)            /*!< UCSS[1:0] bits (UARTCLK source select bits) */
#define CRG_UARTCLK_SSR_UCSS_0          (0x01UL)            /*!< Bit 0 */
#define CRG_UARTCLK_SSR_UCSS_1          (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_UARTCLK_PVSR register  *************/
#define CRG_UARTCLK_PVSR_UCP            (0x00UL)            /*!< UCP[1:0] bits (UARTCLK prescale value select bits) */
#define CRG_UARTCLK_PVSR_UCP_0          (0x01UL)            /*!< Bit 0 */
#define CRG_UARTCLK_PVSR_UCP_1          (0x02UL)            /*!< Bit 1 */

/****************   Bit definition for CRG_MIICLK_ECR register  ***************/
#define CRG_MIICLK_ECR_EN_MIITEN        (0x02UL)            /*!< MII TX Clock source enable flag */
#define CRG_MIICLK_ECR_EN_MIIREN        (0x01UL)            /*!< MII RX Clock source enable register flag */

/****************   Bit definition for CRG_MONCLK_SSR register  ***************/
#define CRG_MONCLK_SSR_CLKMON_SEL       (0x00UL)            /*!< CLKMON_SEL[4:0] bits (Monitoring Clock source select bits) */
#define CRG_MONCLK_SSR_CLKMON_SEL_0     (0x01UL)            /*!< Bit 0 */
#define CRG_MONCLK_SSR_CLKMON_SEL_1     (0x02UL)            /*!< Bit 1 */
#define CRG_MONCLK_SSR_CLKMON_SEL_2     (0x04UL)            /*!< Bit 2 */
#define CRG_MONCLK_SSR_CLKMON_SEL_3     (0x08UL)            /*!< Bit 3 */
#define CRG_MONCLK_SSR_CLKMON_SEL_4     (0x10UL)            /*!< Bit 4 */

/******************************************************************************/
/*                                                                            */
/*                Direct memory access controller Register                    */
/*                                                                            */
/******************************************************************************/
/**********************  Bit definition for DMA_STATUS register  **************/
#define DMA_STATUS_CR                   (0xF0UL)            /*!< STATE[3:0] bits (Current state of the control state machine) */
#define DMA_STATUS_STATE_0              (0x10UL)            /*!< Bit 0 */
#define DMA_STATUS_STATE_1              (0x20UL)            /*!< Bit 1 */
#define DMA_STATUS_STATE_2              (0x40UL)            /*!< Bit 2 */
#define DMA_STATUS_STATE_3              (0x80UL)            /*!< Bit 3 */
#define DMA_STATUS_ENABLE               (0x01UL)            /*!< Enable status of the controller */

/************************  Bit definition for DMA_CFG register  ***************/
#define DMA_CFG_PROT_CTRL               (0xE0UL)            /*!< PROT_CTRL[2:0] bits (Set the AHB-Lite protection) */
#define DMA_CFG_PROT_CTRL_0             (0x20UL)            /*!< Bit 0 */
#define DMA_CFG_PROT_CTRL_1             (0x40UL)            /*!< Bit 1 */
#define DMA_CFG_PROT_CTRL_2             (0x80UL)            /*!< Bit 2 */
#define DMA_CFG_ENABLE                  (0x01UL)            /*!< Enable for the controller */

/******************  Bit definition for DMA_CTRL_BASE_PTR register  ***********/
#define DMA_CTRL_BASE_PTR               (0xFFFFFF00)        /*!< Pointer to the base address of the primary data structure */

/*****************  Bit definition for DMA_ALT_CTRL_BASE_PTR register  ********/
#define DMA_ALT_CTRL_BASE_PTR           (0xFFFFFFFF)        /*!< Base address of the alternate data structure */

/*****************  Bit definition for DMA_WAITONREQ_STATUS register  *********/
#define DMA_WAITONREQ_STATUS            (0x3FUL)            /*!< DMA_WAITONREQ[5:0] bits (Channel wait on request status) */
#define DMA_WAITONREQ_STATUS_0          (0x01UL)            /*!< Bit 0 */
#define DMA_WAITONREQ_STATUS_1          (0x02UL)            /*!< Bit 1 */
#define DMA_WAITONREQ_STATUS_2          (0x04UL)            /*!< Bit 2 */
#define DMA_WAITONREQ_STATUS_3          (0x08UL)            /*!< Bit 3 */
#define DMA_WAITONREQ_STATUS_4          (0x10UL)            /*!< Bit 4 */
#define DMA_WAITONREQ_STATUS_5          (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_SW_REQUEST register  **********/
#define DMA_CHNL_SW_REQUEST             (0x3FUL)            /*!< CHNL_SW_REQUEST[5:0] bits (Set the appropriate bit to generate a software DMA request) */
#define DMA_CHNL_SW_REQUEST_0           (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_SW_REQUEST_1           (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_SW_REQUEST_2           (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_SW_REQUEST_3           (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_SW_REQUEST_4           (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_SW_REQUEST_5           (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_USEBURST_SET register  ********/
#define DMA_CHNL_USEBURST_SET           (0x3FUL)            /*!< CHNL_USEBURST_SET[5:0] bits (Returns the useburst status, or disable dma_sreq[Channel-1] form generating DMA requests) */
#define DMA_CHNL_USEBURST_SET_0         (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_USEBURST_SET_1         (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_USEBURST_SET_2         (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_USEBURST_SET_3         (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_USEBURST_SET_4         (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_USEBURST_SET_5         (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_USEBURST_CLR register  ********/
#define DMA_CHNL_USEBURST_CLR           (0x3FUL)            /*!< CHNL_USEBURST_CLR[5:0] bits (Set the appropriate bit to enable dma_sreq[Channel-1] to generate requests) */
#define DMA_CHNL_USEBURST_CLR_0         (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_USEBURST_CLR_1         (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_USEBURST_CLR_2         (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_USEBURST_CLR_3         (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_USEBURST_CLR_4         (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_USEBURST_CLR_5         (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_REQ_MASK_SET register  ********/
#define DMA_CHNL_REQ_MASK_SET           (0x3FUL)            /*!< CHNL_REQ_MASK_SET[5:0] bits (Returns the request mask status of dma_req[Channel-1] and dma_sreq[Channel-1], or disables the corresponding channel from generating DMA requests) */
#define DMA_CHNL_REQ_MASK_SET_0         (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_REQ_MASK_SET_1         (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_REQ_MASK_SET_2         (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_REQ_MASK_SET_3         (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_REQ_MASK_SET_4         (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_REQ_MASK_SET_5         (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_REQ_MASK_CLR register  ********/
#define DMA_CHNL_REQ_MASK_CLR           (0x3FUL)            /*!< CHNL_REQ_MASK_CLR[5:0] bits (Set the appropriate bit to enable DMA requests for the channel corresponding to dma_req[Channel-1] and dma_sreq[Channel-1]) */
#define DMA_CHNL_REQ_MASK_CLR_0         (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_REQ_MASK_CLR_1         (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_REQ_MASK_CLR_2         (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_REQ_MASK_CLR_3         (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_REQ_MASK_CLR_4         (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_REQ_MASK_CLR_5         (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_ENABLE_SET register  **********/
#define DMA_CHNL_ENABLE_SET             (0x3FUL)            /*!< CHNL_ENABLE_SET[5:0] bits (Set the appropriate bit to enable DMA requests for the channel corresponding to dma_req[Channel-1] and dma_sreq[Channel-1]) */
#define DMA_CHNL_ENABLE_SET_0           (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_ENABLE_SET_1           (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_ENABLE_SET_2           (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_ENABLE_SET_3           (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_ENABLE_SET_4           (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_ENABLE_SET_5           (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_ENABLE_CLR register  **********/
#define DMA_CHNL_ENABLE_CLR             (0x3FUL)            /*!< CHNL_ENABLE_CLR[5:0] bits (Set the appropriate bit to disable the corresponding DMA channel) */
#define DMA_CHNL_ENABLE_CLR_0           (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_ENABLE_CLR_1           (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_ENABLE_CLR_2           (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_ENABLE_CLR_3           (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_ENABLE_CLR_4           (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_ENABLE_CLR_5           (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_PRI_ALT_SET register  *********/
#define DMA_CHNL_PRI_ALT_SET            (0x3FUL)            /*!< CHNL_PRI_ALT_SET[5:0] bits (Returns the channel control data structure status, or selects the alternate data structure for the corresponding DMA channels) */
#define DMA_CHNL_PRI_ALT_SET_0          (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_PRI_ALT_SET_1          (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_PRI_ALT_SET_2          (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_PRI_ALT_SET_3          (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_PRI_ALT_SET_4          (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_PRI_ALT_SET_5          (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_PRI_ALT_CLR register  *********/
#define DMA_CHNL_PRI_ALT_CLR            (0x3FUL)            /*!< CHNL_PRI_ALT_CLR[5:0] bits (Set the appropriate bit to select the primary data structure for the corresponding DMA channel) */
#define DMA_CHNL_PRI_ALT_CLR_0          (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_PRI_ALT_CLR_1          (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_PRI_ALT_CLR_2          (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_PRI_ALT_CLR_3          (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_PRI_ALT_CLR_4          (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_PRI_ALT_CLR_5          (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_PRIORITY_SET register  ********/
#define DMA_CHNL_PRIORITY_SET           (0x3FUL)            /*!< CHNL_PRIORITY_SET[5:0] bits (Returns the channel priority mask status, or set the channel priority to high) */
#define DMA_CHNL_PRIORITY_SET_0         (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_PRIORITY_SET_1         (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_PRIORITY_SET_2         (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_PRIORITY_SET_3         (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_PRIORITY_SET_4         (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_PRIORITY_SET_5         (0x20UL)            /*!< Bit 5 */

/*****************  Bit definition for DMA_CHNL_PRIORITY_CLR register  ********/
#define DMA_CHNL_PRIORITY_CLR           (0x3FUL)            /*!< CHNL_PRIORITY_CLR[5:0] bits (Set the appropriate bit to select the default priority level for the specified DMA channel) */
#define DMA_CHNL_PRIORITY_CLR_0         (0x01UL)            /*!< Bit 0 */
#define DMA_CHNL_PRIORITY_CLR_1         (0x02UL)            /*!< Bit 1 */
#define DMA_CHNL_PRIORITY_CLR_2         (0x04UL)            /*!< Bit 2 */
#define DMA_CHNL_PRIORITY_CLR_3         (0x08UL)            /*!< Bit 3 */
#define DMA_CHNL_PRIORITY_CLR_4         (0x10UL)            /*!< Bit 4 */
#define DMA_CHNL_PRIORITY_CLR_5         (0x20UL)            /*!< Bit 5 */

/***********************  Bit definition for DMA_ERR_CLR register  ************/
#define DMA_ERR_CLR                     (0x3FUL)            /*!< ERR_CLR[5:0] bits (Returns the status of DMA_ERR, or set the signal LOW) */
#define DMA_ERR_CLR_0                   (0x01UL)            /*!< Bit 0 */
#define DMA_ERR_CLR_1                   (0x02UL)            /*!< Bit 1 */
#define DMA_ERR_CLR_2                   (0x04UL)            /*!< Bit 2 */
#define DMA_ERR_CLR_3                   (0x08UL)            /*!< Bit 3 */
#define DMA_ERR_CLR_4                   (0x10UL)            /*!< Bit 4 */
#define DMA_ERR_CLR_5                   (0x20UL)            /*!< Bit 5 */

/******************************************************************************/
/*                                                                            */
/*                                  Dual Timer                                */
/*                                                                            */
/******************************************************************************/
/******************************  Bit definition for LOAD register  ************/
#define DUALTIMER_LOAD_TLR              (0xFFFFFFFF)        /*!< TLR[31:0] bits (Timer Load) */

/******************************  Bit definition for VALUE register  ***********/
#define DUALTIMER_VALUE_TVR             (0xFFFFFFFF)        /*!< TVR[31:0] bits (Timer Value) */

/********************  Bit definition for CONTROL register  *******************/
#define DUALTIMER_CONTROL_TE            (0x80UL)            /*!< Timer Enable */
#define DUALTIMER_CONTROL_TM            (0x40UL)            /*!< Timer Mode */
#define DUALTIMER_CONTROL_IE            (0x20UL)            /*!< Interrupt Enable */
#define DUALTIMER_CONTROL_TP            (0x0CUL)            /*!< TP[1:0] bits (Timer Prescale) */
#define DUALTIMER_CONTROL_TP_0          (0x04UL)            /*!< Bit 0 */
#define DUALTIMER_CONTROL_TP_1          (0x08UL)            /*!< Bit 1 */
#define DUALTIMER_CONTROL_TS            (0x02UL)            /*!< Timer Size */
#define DUALTIMER_CONTROL_OC            (0x01UL)            /*!< One-shot Count */

/********************  Bit definition for INTCLR register  ********************/
#define DUALTIMER_INTCLR_TIC            (0x1UL)             /*!< Interrupt Clear */

/********************  Bit definition for RIS register  ***********************/
#define DUALTIMER_RIS_RIS               (0x1UL)             /*!< Raw Interrupt Status flag */

/********************  Bit definition for MIS register  ***********************/
#define DUALTIMER_MIS_MIS               (0x1UL)             /*!< Masked Interrupt Status flag */

/********************  Bit definition for BGLOAD register  ********************/
#define DUALTIMER_BGLOAD_BGL            (0xFFFFFFFF)        /*!< BGL[31:0] bits (Background Load) */

/********************  Bit definition for TIMCLKEN register  ******************/
#define DUALTIMER_TIMCLKEN_CE           (0x01UL)            /*!< Timer Clock Enable */

/******************************************************************************/
/*                                                                            */
/*                              External Interrupt                            */
/*                                                                            */
/******************************************************************************/
/*********************  Bit definition for EXTINT register  *******************/
#define EXTI_EXTINT_IEN                 (0x02UL)            /*!< External interrupt enable */
#define EXTI_EXTINT_POL                 (0x01UL)            /*!< External interrupt polarity selection */

/******************************************************************************/
/*                                                                            */
/*                                    GPIO                                    */
/*                                                                            */
/******************************************************************************/
/*********************  Bit definition for DATA register  *********************/
#define GPIO_DATA_DAT15                 (0x8000UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT14                 (0x4000UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT13                 (0x2000UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT12                 (0x1000UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT11                 (0x0800UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT10                 (0x0400UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT9                  (0x0200UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT8                  (0x0100UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT7                  (0x0080UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT6                  (0x0040UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT5                  (0x0020UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT4                  (0x0010UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT3                  (0x0008UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT2                  (0x0004UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT1                  (0x0002UL)          /*!< Port input data bit */
#define GPIO_DATA_DAT0                  (0x0001UL)          /*!< Port input data bit */

/*********************  Bit definition for DATAOUT register  ******************/
#define GPIO_DATAOUT_DAO15              (0x8000UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO14              (0x4000UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO13              (0x2000UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO12              (0x1000UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO11              (0x0800UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO10              (0x0400UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO9               (0x0200UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO8               (0x0100UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO7               (0x0080UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO6               (0x0040UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO5               (0x0020UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO4               (0x0010UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO3               (0x0008UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO2               (0x0004UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO1               (0x0002UL)          /*!< Port out data bit */
#define GPIO_DATAOUT_DAO0               (0x0001UL)          /*!< Port out data bit */

/*********************  Bit definition for OUTENSET register  *****************/
#define GPIO_OUTENSET_ES15              (0x8000UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES14              (0x4000UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES13              (0x2000UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES12              (0x1000UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES11              (0x0800UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES10              (0x0400UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES9               (0x0200UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES8               (0x0100UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES7               (0x0080UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES6               (0x0040UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES5               (0x0020UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES4               (0x0010UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES3               (0x0008UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES2               (0x0004UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES1               (0x0002UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */
#define GPIO_OUTENSET_ES0               (0x0001UL)          /*!< sets the corresponding output enable bit, indicates the signal direction */

/*********************  Bit definition for OUTENCLR register  *****************/
#define GPIO_OUTENCLR_EC15              (0x8000UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC14              (0x4000UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC13              (0x2000UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC12              (0x1000UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC11              (0x0800UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC10              (0x0400UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC9               (0x0200UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC8               (0x0100UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC7               (0x0080UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC6               (0x0040UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC5               (0x0020UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC4               (0x0010UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC3               (0x0008UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC2               (0x0004UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC1               (0x0002UL)          /*!< clears the output enable bit, indicates the signal direction */
#define GPIO_OUTENCLR_EC0               (0x0001UL)          /*!< clears the output enable bit, indicates the signal direction */

/*********************  Bit definition for INTENSET register  *****************/
#define GPIO_INTENSET_IES15             (0x8000UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES14             (0x4000UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES13             (0x2000UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES12             (0x1000UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES11             (0x0800UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES10             (0x0400UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES9              (0x0200UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES8              (0x0100UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES7              (0x0080UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES6              (0x0040UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES5              (0x0020UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES4              (0x0010UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES3              (0x0008UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES2              (0x0004UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES1              (0x0002UL)          /*!< sets the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENSET_IES0              (0x0001UL)          /*!< sets the interrupt enable bit, indicates the interrupt */

/*********************  Bit definition for INTENCLR register  *****************/
#define GPIO_INTENCLR_IEC15             (0x8000UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC14             (0x4000UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC13             (0x2000UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC12             (0x1000UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC11             (0x0800UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC10             (0x0400UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC9              (0x0200UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC8              (0x0100UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC7              (0x0080UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC6              (0x0040UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC5              (0x0020UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC4              (0x0010UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC3              (0x0008UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC2              (0x0004UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC1              (0x0002UL)          /*!< clears the interrupt enable bit, indicates the interrupt */
#define GPIO_INTENCLR_IEC0              (0x0001UL)          /*!< clears the interrupt enable bit, indicates the interrupt */

/*********************  Bit definition for INTTYPESET register  ***************/
#define GPIO_INTTYPESET_ITS15           (0x8000UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS14           (0x4000UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS13           (0x2000UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS12           (0x1000UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS11           (0x0800UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS10           (0x0400UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS9            (0x0200UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS8            (0x0100UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS7            (0x0080UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS6            (0x0040UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS5            (0x0020UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS4            (0x0010UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS3            (0x0008UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS2            (0x0004UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS1            (0x0002UL)          /*!< sets the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPESET_ITS0            (0x0001UL)          /*!< sets the interrupt type bit, indicates for edge or level */

/*********************  Bit definition for INTTYPECLR register  ***************/
#define GPIO_INTTYPECLR_ITC15           (0x8000UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC14           (0x4000UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC13           (0x2000UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC12           (0x1000UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC11           (0x0800UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC10           (0x0400UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC9            (0x0200UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC8            (0x0100UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC7            (0x0080UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC6            (0x0040UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC5            (0x0020UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC4            (0x0010UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC3            (0x0008UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC2            (0x0004UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC1            (0x0002UL)          /*!< clears the interrupt type bit, indicates for edge or level */
#define GPIO_INTTYPECLR_ITC0            (0x0001UL)          /*!< clears the interrupt type bit, indicates for edge or level */

/*********************  Bit definition for INTPOLSET register  ****************/
#define GPIO_INTPOLSET_IPS15            (0x8000UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS14            (0x4000UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS13            (0x2000UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS12            (0x1000UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS11            (0x0800UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS10            (0x0400UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS9             (0x0200UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS8             (0x0100UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS7             (0x0080UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS6             (0x0040UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS5             (0x0020UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS4             (0x0010UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS3             (0x0008UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS2             (0x0004UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS1             (0x0002UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLSET_IPS0             (0x0001UL)          /*!< sets the interrupt polarity bit, indicates for edge or level */

/*********************  Bit definition for INTPOLCLR register  ****************/
#define GPIO_INTPOLCLR_IPC15            (0x8000UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC14            (0x4000UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC13            (0x2000UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC12            (0x1000UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC11            (0x0800UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC10            (0x0400UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC9             (0x0200UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC8             (0x0100UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC7             (0x0080UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC6             (0x0040UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC5             (0x0020UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC4             (0x0010UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC3             (0x0008UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC2             (0x0004UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC1             (0x0002UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */
#define GPIO_INTPOLCLR_IPC0             (0x0001UL)          /*!< clears the interrupt polarity bit, indicates for edge or level */

/*********************  Bit definition for INTERRUP register  *****************/
#define GPIO_INTERRUP_ISC15             (0x8000UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC14             (0x4000UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC13             (0x2000UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC12             (0x1000UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC11             (0x0800UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC10             (0x0400UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC9              (0x0200UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC8              (0x0100UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC7              (0x0080UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC6              (0x0040UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC5              (0x0020UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC4              (0x0010UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC3              (0x0008UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC2              (0x0004UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC1              (0x0002UL)          /*!< IRQ status Register */
#define GPIO_INTERRUP_ISC0              (0x0001UL)          /*!< IRQ status Register */

/*********************  Bit definition for LB_MASKED register  ****************/
#define GPIO_LB_MASKED_LBM              (0xFFUL)            /*!< LBM[7:0] bits (Data for lower byte access) */
#define GPIO_LB_MASKED_LBM_0            (0x01UL)            /*!< Bit 0 */
#define GPIO_LB_MASKED_LBM_1            (0x02UL)            /*!< Bit 1 */
#define GPIO_LB_MASKED_LBM_2            (0x04UL)            /*!< Bit 2 */
#define GPIO_LB_MASKED_LBM_3            (0x08UL)            /*!< Bit 3 */
#define GPIO_LB_MASKED_LBM_4            (0x10UL)            /*!< Bit 4 */
#define GPIO_LB_MASKED_LBM_5            (0x20UL)            /*!< Bit 5 */
#define GPIO_LB_MASKED_LBM_6            (0x40UL)            /*!< Bit 6 */
#define GPIO_LB_MASKED_LBM_7            (0x80UL)            /*!< Bit 7 */

/*********************  Bit definition for UB_MASKED register  ****************/
#define GPIO_UB_MASKED_HBM              (0xFF00UL)          /*!< HBM[7:0] bits (Data for higher byte access) */
#define GPIO_UB_MASKED_HBM_0            (0x0100UL)          /*!< Bit 0 */
#define GPIO_UB_MASKED_HBM_1            (0x0200UL)          /*!< Bit 1 */
#define GPIO_UB_MASKED_HBM_2            (0x0400UL)          /*!< Bit 2 */
#define GPIO_UB_MASKED_HBM_3            (0x0800UL)          /*!< Bit 3 */
#define GPIO_UB_MASKED_HBM_4            (0x1000UL)          /*!< Bit 4 */
#define GPIO_UB_MASKED_HBM_5            (0x2000UL)          /*!< Bit 5 */
#define GPIO_UB_MASKED_HBM_6            (0x4000UL)          /*!< Bit 6 */
#define GPIO_UB_MASKED_HBM_7            (0x8000UL)          /*!< Bit 7 */

/******************************************************************************/
/*                                                                            */
/*                         Pad Controller Registers                           */
/*                                                                            */
/********************   Bit definition for Px_PCR register  *******************/
#define PAD_PCR_CS                      (0x40UL)            /*!< CMOS input or Summit trigger input selection */
#define PAD_PCR_IE                      (0x20UL)            /*!< Input buffer enable selection */
#define PAD_PCR_OD                      (0x08UL)            /*!< Open Drain output mode flag */
#define PAD_PCR_DS                      (0x04UL)            /*!< Driving strength selection */
#define PAD_PCR_PUPD                    (0x03UL)            /*!< PUPD[1:0] bits (Pull-up, Pull-down selection) */
#define PAD_PCR_PUPD_0                  (0x01UL)            /*!< Bit 0 */
#define PAD_PCR_PUPD_1                  (0x02UL)            /*!< Bit 1 */

/******************************************************************************/
/*                                                                            */
/*                           PWM Common Registers                             */
/*                                                                            */
/******************************************************************************/
/************** Bit definition for interrupt enable(IER) register *************/
#define PWM_CM_IER_IE7                  (0x80UL)            /*!< Channel 7 */
#define PWM_CM_IER_IE6                  (0x40UL)            /*!< Channel 6 */
#define PWM_CM_IER_IE5                  (0x20UL)            /*!< Channel 5 */
#define PWM_CM_IER_IE4                  (0x10UL)            /*!< Channel 4 */
#define PWM_CM_IER_IE3                  (0x08UL)            /*!< Channel 3 */
#define PWM_CM_IER_IE2                  (0x04UL)            /*!< Channel 2 */
#define PWM_CM_IER_IE1                  (0x02UL)            /*!< Channel 1 */
#define PWM_CM_IER_IE0                  (0x01UL)            /*!< Channel 0 */

/**************** Bit definition for Start/Stop(SSR) register ******************/
#define PWM_CM_SSR_SS7                  (0x80UL)            /*!< Channel 7 */
#define PWM_CM_SSR_SS6                  (0x40UL)            /*!< Channel 6 */
#define PWM_CM_SSR_SS5                  (0x20UL)            /*!< Channel 5 */
#define PWM_CM_SSR_SS4                  (0x10UL)            /*!< Channel 4 */
#define PWM_CM_SSR_SS3                  (0x08UL)            /*!< Channel 3 */
#define PWM_CM_SSR_SS2                  (0x04UL)            /*!< Channel 2 */
#define PWM_CM_SSR_SS1                  (0x02UL)            /*!< Channel 1 */
#define PWM_CM_SSR_SS0                  (0x01UL)            /*!< Channel 0 */

/***************** Bit definition for Pause(PSR) register **********************/
#define PWM_CM_PSR_PS7                  (0x80UL)            /*!< Channel 7 */
#define PWM_CM_PSR_PS6                  (0x40UL)            /*!< Channel 6 */
#define PWM_CM_PSR_PS5                  (0x20UL)            /*!< Channel 5 */
#define PWM_CM_PSR_PS4                  (0x10UL)            /*!< Channel 4 */
#define PWM_CM_PSR_PS3                  (0x08UL)            /*!< Channel 3 */
#define PWM_CM_PSR_PS2                  (0x04UL)            /*!< Channel 2 */
#define PWM_CM_PSR_PS1                  (0x02UL)            /*!< Channel 1 */
#define PWM_CM_PSR_PS0                  (0x01UL)            /*!< Channel 0 */

/******************************************************************************/
/*                                                                            */
/*                           PWM Channel Registers                            */
/*                                                                            */
/******************************************************************************/
/***************** Bit definition for interrupt(IR) register ******************/
#define PWM_CHn_IR_CI                   (0x04UL)            /*!< Capture Interrupt occurs */
#define PWM_CHn_IR_OI                   (0x02UL)            /*!< Overflow Interrupt occurs */
#define PWM_CHn_IR_MI                   (0x01UL)            /*!< Match Interrupt occurs */

/************ Bit definition for interrupt enable(IER) register ***************/
#define PWM_CHn_IER_CIE                 (0x04UL)            /*!< Capture Interrupt Enable */
#define PWM_CHn_IER_OIE                 (0x02UL)            /*!< Overflow Interrupt Enable */
#define PWM_CHn_IER_MIE                 (0x01UL)            /*!< Match Interrupt Enable */

/************ Bit definition for interrupt clear(ICR) register ****************/
#define PWM_CHn_ICR_CIC                 (0x04UL)            /*!< Capture Interrupt is cleared */
#define PWM_CHn_ICR_OIC                 (0x02UL)            /*!< Overflow Interrupt is cleared */
#define PWM_CHn_ICR_MIC                 (0x01UL)            /*!< Match Interrupt is cleared */

/************** Bit definition for Timer/Counter(TCR) register ****************/
#define PWM_CHn_TCR                     (0xFFFFFFFF)        /*!< Timer/Counter */

/************* Bit definition for Prescale Counter(PCR) register **************/
#define PWM_CHn_PCR                     (0x3FUL)            /*!< Prescale Counter */

/***************** Bit definition for Prescale(PR) register *******************/
#define PWM_CHn_PR                      (0x3FUL)            /*!< Prescale */

/***************** Bit definition for Match(MR) register **********************/
#define PWM_CHn_MR                      (0xFFFFFFFF)        /*!< Match */

/***************** Bit definition for Limit(LR) register **********************/
#define PWM_CHn_LR                      (0xFFFFFFFF)        /*!< Limit */

/***************** Bit definition for Up-Down Mode(UDMR) register *************/
#define PWM_CHn_UDMR_UDM                (0x1UL)             /*!< Up-Down mode */

/************** Bit definition for Timer/Counter Mode (TCMR) register *********/
#define PWM_CHn_TCMR_TCM                (0x3UL)             /*!< TCM[1:0] bits (Timer/Counter mode) */
#define PWM_CHn_TCMR_TCM_0              (0x1UL)             /*!< Bit 0 */
#define PWM_CHn_TCMR_TCM_1              (0x2UL)             /*!< Bit 1 */

/*********************** Bit definition for PEEER register ********************/
#define PWM_CHn_PEEER_PEEE              (0x3UL)             /*!< PEEE[1:0] bits (PWM output Enable and External input Enable) */
#define PWM_CHn_PEEER_PEEE_0            (0x1UL)             /*!< Bit 0 */
#define PWM_CHn_PEEER_PEEE_1            (0x2UL)             /*!< Bit 1 */

/************** Bit definition for Capture Mode(CMR) register *****************/
#define PWM_CHn_CMR_CM                  (0x1UL)             /*!< Capture mode */

/***************** Bit definition for Capture(CR) register ********************/
#define PWM_CHn_CR                      (0xFFFFFFFF)        /*!< Capture */

/************** Bit definition for Periodic Mode(PDMR) register ***************/
#define PWM_CHn_PDMR_PDM                (0x1UL)             /*!< Periodic Mode */

/***************** Bit definition for Dead Zone Enable(DZER) register *********/
#define PWM_CHn_DZER_DZE                (0x1UL)             /*!< Dead Zone Enable */

/********** Bit definition for Dead Zone Counter(DZCR) register ***************/
#define PWM_CHn_DZCR_DZC                (0x3FFUL)           /*!< Dead Zone Counter value */

/******************************************************************************/
/*                                                                            */
/*                      Random number generator Register                      */
/*                                                                            */
/******************************************************************************/
/********************* Bit definition for RNG_RUN register  *******************/
#define RNG_RUN_RUN                     (0x1UL)             /*!< RUN RNG shift flag */

/********************* Bit definition for RNG_SEED register  ******************/
#define RNG_SEED_SEED                   (0xFFFFFFFF)        /*!< seed value of random number generator shift register */

/**************** Bit definition for RNG_CLKSEL register  *********************/
#define RNG_CLKSEL_CLKSEL               (0x1UL)             /*!< select clock source register of RNG shift register */

/*********************** Bit definition for RNG_MODE register  ****************/
#define RNG_MODE_MODE                   (0x1UL)             /*!< RNG run mode select register */

/*********************** Bit definition for RNG_RN register  ******************/
#define RNG_RN_RN                       (0xFFFFFFFF)        /*!< random number of RNG shift register */

/********************* Bit definition for RNG_POLY register  ******************/
#define RNG_POLY_POLY                   (0xFFFFFFFF)        /*!< 32bit polynomial of random number generator */

/******************************************************************************/
/*                                                                            */
/*                                  SSP                                       */
/*                                                                            */
/******************************************************************************/
/****** Bit definition for Control register 0 (SSP0CR0) register **************/
#define SSP_CR0_SCR                     (0xFF00UL)          /*!< SCR[7:0] bits (Serial clock rate) */
#define SSP_CR0_SPH                     (0x0080UL)          /*!< SSPCLKOUT phase */
#define SSP_CR0_SPO                     (0x0040UL)          /*!< SSPCLKOUT polarity */
#define SSP_CR0_FRF                     (0x0030UL)          /*!< FRF[1:0] bits (Frame Format) */
#define SSP_CR0_FRF_0                   (0x0010UL)          /*!< Bit 0 */
#define SSP_CR0_FRF_1                   (0x0020UL)          /*!< Bit 1 */
#define SSP_CR0_DSS                     (0x000FUL)          /*!< DSS[3:0] bits (Data size select) */
#define SSP_CR0_DSS_0                   (0x0001UL)          /*!< Bit 0 */
#define SSP_CR0_DSS_1                   (0x0002UL)          /*!< Bit 1 */
#define SSP_CR0_DSS_2                   (0x0004UL)          /*!< Bit 2 */
#define SSP_CR0_DSS_3                   (0x0008UL)          /*!< Bit 3 */

/****** Bit definition for Control register 1 (SSP0CR1) register **************/
#define SSP_CR1_SOD                     (0x0008UL)          /*!< Slave-mode output disable */
#define SSP_CR1_MS                      (0x0004UL)          /*!< Master or Slave mode select */
#define SSP_CR1_SSE                     (0x0002UL)          /*!< Synchronous serial port enable */
#define SSP_CR1_LBM                     (0x0001UL)          /*!< Loop back mode */

/****** Bit definition for Data register (SSP0DR) register ********************/
#define SSP_DR_DATA                     (0xFFFFUL)          /*!< Transmit/Receive FIFO */

/****** Bit definition for Status register (SSP0SR) register ******************/
#define SSP_SR_BSY                      (0x0010UL)          /*!< SSP busy flag */
#define SSP_SR_RFF                      (0x0008UL)          /*!< Receive FIFO full */
#define SSP_SR_RNE                      (0x0004UL)          /*!< Receive FIFO not empty */
#define SSP_SR_TNF                      (0x0002UL)          /*!< Transmit FIFO not full */
#define SSP_SR_TFE                      (0x0001UL)          /*!< Transmit FIFO empty */

/****** Bit definition for Clock prescale register (SSP0CPSR) *****************/
#define SSP_CPSR_CPSDVSR                (0x00FFUL)          /*!< CPSDVSR[7:0] bits (Clock prescale divisor) */

/****** Bit definition for Interrupt mask set or clear register (SSP0IMSC) ****/
#define SSP_IMSC_TXIM                   (0x0008UL)          /*!< Transmit FIFO interrupt mask */
#define SSP_IMSC_RXIM                   (0x0004UL)          /*!< Receive FIFO interrupt mask */
#define SSP_IMSC_RTIM                   (0x0002UL)          /*!< Receive timeout interrupt mask */
#define SSP_IMSC_RORIM                  (0x0001UL)          /*!< Receive overrun interrupt mask */

/****** Bit definition for Raw interrupt status register (SSP0RIS) ************/
#define SSP_RIS_TXRIS                   (0x0008UL)          /*!< Transmit FIFO interrupt status */
#define SSP_RIS_RXRIS                   (0x0004UL)          /*!< Receive FIFO interrupt status */
#define SSP_RIS_RTRIS                   (0x0002UL)          /*!< Receive timeout interrupt status */
#define SSP_RIS_RORRIS                  (0x0001UL)          /*!< Receive overrun interrupt status */

/****** Bit definition for Masked interrupt status register, (SSP0MIS) ********/
#define SSP_MIS_TXMIS                   (0x0008UL)          /*!< Transmit FIFO masked interrupt status */
#define SSP_MIS_RXMIS                   (0x0004UL)          /*!< Receive FIFO masked interrupt status */
#define SSP_MIS_RTMIS                   (0x0002UL)          /*!< Receive timeout masked interrupt status */
#define SSP_MIS_RORMIS                  (0x0001UL)          /*!< Receive overrun masked interrupt status */

/****** Bit definition for Interrupt clear register (SSP0ICR) *****************/
#define SSP_ICR_RTIC                    (0x0002UL)          /*!< Receive timeout interrupt clear */
#define SSP_ICR_RORIC                   (0x0001UL)          /*!< Receive overrun interrupt clear */

/****** Bit definition for DMA control register, (SSP0DMACR) ******************/
#define SSP_DMACR_TXDMAE                (0x0001UL)          /*!< Receive DMA Enable */
#define SSP_DMACR_RXDMAE                (0x0002UL)          /*!< Transmit DMA Enable */

/******************************************************************************/
/*                                                                            */
/*                               RTC Registers                                */
/*                                                                            */
/******************************************************************************/
/*************** Bit definition for control register (RTCCON)  ****************/
#define RTC_RTCCON_INTEN                (0x20UL)            /*!< RTC Interrupt Enable */
#define RTC_RTCCON_DIVRST               (0x02UL)            /*!< RTC Divider Reset */
#define RTC_RTCCON_CLKEN                (0x01UL)            /*!< Clock Enable */

/*********** Bit definition for Interrupt Mask register (RTCINTE)  ************/
#define RTC_RTCINTE_AINT                (0x40UL)            /*!< RTC Alarm Interrupt Enable */
#define RTC_RTCINTE_IMMON               (0x20UL)            /*!< RTC Month Interrupt Enable */
#define RTC_RTCINTE_IMDAY               (0x10UL)            /*!< RTC Day Interrupt Enable */
#define RTC_RTCINTE_IMDATE              (0x08UL)            /*!< RTC Date Interrupt Enable */
#define RTC_RTCINTE_IMHOUR              (0x04UL)            /*!< RTC Hour Interrupt Enable */
#define RTC_RTCINTE_IMMIN               (0x02UL)            /*!< RTC Minute Interrupt Enable */
#define RTC_RTCINTE_IMSEC               (0x01UL)            /*!< RTC Second Interrupt Enable */

/********** Bit definition for Interrupt Pending register (RTCINTP)  **********/
#define RTC_RTCINTP_RTCALF              (0x02UL)            /*!< RTC Alarm interrupt pending flag */
#define RTC_RTCINTP_RTCCIF              (0x01UL)            /*!< RTC Counter Interrupt pending flag */

/************** Bit definition for Alarm Mask register (RTCAMR)  **************/
#define RTC_RTCAMR_AMRYEAR              (0x40UL)            /*!< RTC Alarm Mask for Year */
#define RTC_RTCAMR_AMRMON               (0x20UL)            /*!< RTC Alarm Mask for Month */
#define RTC_RTCAMR_AMRDATE              (0x10UL)            /*!< RTC Alarm Mask for Date */
#define RTC_RTCAMR_AMRDAY               (0x08UL)            /*!< RTC Alarm Mask for Day */
#define RTC_RTCAMR_AMRHOUR              (0x04UL)            /*!< RTC Alarm Mask for Hour */
#define RTC_RTCAMR_AMRMIN               (0x02UL)            /*!< RTC Alarm Mask for Minute */
#define RTC_RTCAMR_AMRSEC               (0x01UL)            /*!< RTC Alarm Mask for Second */

/************** Bit definition for BCD Second register (BCDSEC)  **************/
#define RTC_BCDSEC_BCDSEC               (0x7FUL)            /*!< BCDSEC[6:0] bits (RTC Seconds value (0 to 59)) */

/************** Bit definition for BCD Minute register (BCDMIN)  **************/
#define RTC_BCDMIN_BCDMIN               (0x7FUL)            /*!< BCDMIN[6:0] bits (RTC Minute value (0 to 59)) */

/************** Bit definition for BCD Hour register (BCDHOUR)  ***************/
#define RTC_BCDHOUR_BCDHOUR             (0x3FUL)            /*!< BCDHOUR[5:0] bits (RTC Hour value (0 to 23)) */

/*************** Bit definition for BCD Day register (BCDDAY)  ****************/
#define RTC_BCDDAY_BCDDAY               (0x0FUL)            /*!< BCDDAY[3:0] bits (RTC Day of Week value (1 to 7)) */

/************** Bit definition for BCD Date register (BCDDATE)  ***************/
#define RTC_BCDDATE_BCDDATE             (0x3FUL)            /*!< BCDDATE[5:0] bits (RTC Day of Month value (1 to 28, 29, 30, or 31)) */

/************** Bit definition for BCD Month register (BCDMON)  ***************/
#define RTC_BCDMON_BCDMON               (0x1FUL)            /*!< BCDMON[4:0] bits (RTC Month value (1 to 12)) */

/************** Bit definition for BCD Year register (BCDYEAR)  ***************/
#define RTC_BCDYEAR_BCDYEAR             (0xFFFFUL)          /*!< BCDYEAR[15:0] bits (RTC Year value (0 to 4095)) */

/******** Bit definition for Predetermining Second register (PRESEC)  *********/
#define RTC_PRESEC_PRESEC               (0x7FUL)            /*!< PRESEC[6:0] bits (RTC PREDETERMINING Seconds value (0 to 59)) */

/******** Bit definition for Predetermining Minute register (PREMIN)  *********/
#define RTC_PREMIN_PREMIN               (0x7FUL)            /*!< PREMIN[6:0] bits (RTC Predetermining Minute value (0 to 59)) */

/********* Bit definition for Predetermining Hour register (PREHOUR)  *********/
#define RTC_PREHOUR_PREHOUR             (0x3FUL)            /*!< PREHOUR[5:0] bits (RTC Predetermining Hour value (0 to 23)) */

/********** Bit definition for Predetermining Day register (PREDAY)  **********/
#define RTC_PREDAY_PREDAY               (0x0FUL)            /*!< PREDAY[3:0] bits (RTC Predetermining Day of Week value (1 to 7)) */

/********* Bit definition for Predetermining Date register (PREDATE)  *********/
#define RTC_PREDATE_PREDATE             (0x3FUL)            /*!< PREDATE[3:0] bits (RTC Predetermining Day of Month value (1 to 28, 29, 30, or 31)) */

/********* Bit definition for Predetermining Month register (PREMON)  *********/
#define RTC_PREMON_PREMON               (0x1FUL)            /*!< PREMON[3:0] bits (RTC Predetermining Month value (1 to 12)) */

/********* Bit definition for Predetermining Year register (PREYEAR)  *********/
#define RTC_PREYEAR_PREYEAR             (0xFFFFUL)          /*!< PREYEAR[15:0] bits (RTC Predetermining Year value (0 to 4095)) */

/********* Bit definition for Consolidated Time0 register (RTCTIME0)  *********/
#define RTC_RTCTIME0_CBCDDAY            (0x0F000000)        /*!< CBCDDAY[27:24] bits ( RTC Consolidated Day of Week value (1 to 7)) */
#define RTC_RTCTIME0_CBCDHOUR           (0x003F0000)        /*!< CBCDHOUR[21:16] bits (RTC Consolidated Hour value (0 to 23)) */
#define RTC_RTCTIME0_CBCDMIN            (0x00007F00)        /*!< CBCDMIN[14:8] bits (RTC Consolidated Minute value (0 to 59)) */
#define RTC_RTCTIME0_CBCDSEC            (0x0000007F)        /*!< CBCDSEC[6:0] bits (RTC Consolidated Second value (0 to 59)) */

/********* Bit definition for Consolidated Time1 register (RTCTIME1)  *********/
#define RTC_RTCTIME1_CBCDYEAR           (0xFFFF0000)        /*!< CBCDYEAR[31:16] bits (RTC Consolidated Year value (0 to 4095)) */
#define RTC_RTCTIME1_CBCDMON            (0x00001F00)        /*!< CBCDMON[12:8] bits (RTC Consolidated Month value (1 to 12)) */
#define RTC_RTCTIME1_CBCDDATE           (0x0000003F)        /*!< CBCDDATE[5:0] bits (RTC Consolidated Day of Month value (1 to 28, 29, 30, or 31)) */

/******************************************************************************/
/*                                                                            */
/*                                  UART                                      */
/*                                                                            */
/******************************************************************************/
/****** Bit definition for UART Data(UARTDR) register *************************/
#define UART_DR_OE                      (0x800UL)           /*!< Overrun Error */
#define UART_DR_BE                      (0x400UL)           /*!< Break Error */
#define UART_DR_PE                      (0x200UL)           /*!< Parity Error */
#define UART_DR_FE                      (0x100UL)           /*!< Framing Error */
#define UART_DR_DATA                    (0x0FFUL)           /*!< DATA[7:0] bits (Receive (READ)/Transmit (WRITE) data) */

/****** Bit definition for UART Receive Status(UARTRSR) register **************/
#define UARTR_SR_OE                     (0x08UL)            /*!< Overrun Error */
#define UARTR_SR_BE                     (0x04UL)            /*!< Break Error */
#define UARTR_SR_PE                     (0x02UL)            /*!< Parity Error */
#define UARTR_SR_FE                     (0x01UL)            /*!< Framing Error */

/****** Bit definition for UART Error Clear(UARTECR) register *****************/
#define UARTR_CR_OE                     (0x08UL)            /*!< Overrun Error */
#define UARTR_CR_BE                     (0x04UL)            /*!< Break Error */
#define UARTR_CR_PE                     (0x02UL)            /*!< Parity Error */
#define UARTR_CR_FE                     (0x01UL)            /*!< Framing Error */

/****** Bit definition for UART Flags(UARTFR) register ************************/
#define UART_FR_RI                      (0x100UL)           /*!< Ring indicator */
#define UART_FR_TXFE                    (0x080UL)           /*!< Transmit FIFO empty */
#define UART_FR_RXFF                    (0x040UL)           /*!< Receive FIFO full */
#define UART_FR_TXFF                    (0x020UL)           /*!< Transmit FIFO fULl */
#define UART_FR_RXFE                    (0x010UL)           /*!< Receive FIFO empty */
#define UART_FR_BUSY                    (0x008UL)           /*!< UART busy */
#define UART_FR_DCD                     (0x004UL)           /*!< Data carrier detect */
#define UART_FR_DSR                     (0x002UL)           /*!< Data set ready */
#define UART_FR_CTS                     (0x001UL)           /*!< Clear to send */

/****** Bit definition for UART Low-power Counter(UARTILPR) register **********/
#define UART_ILPR_ILPDVSR               (0xFFUL)            /*!< ILPDVSR[7:0] bits (low-power divisor value) */

/****** Bit definition for Line Control(UARTLCR_H) register *******************/
#define UART_LCR_H_SPS                  (0x80UL)            /*!< Stick parity select */
#define UART_LCR_H_WLEN                 (0x60UL)            /*!< WLEN[1:0] bits (Word length) */
#define UART_LCR_H_WLEN_0               (0x20UL)            /*!< Bit 0 */
#define UART_LCR_H_WLEN_1               (0x40UL)            /*!< Bit 1 */
#define UART_LCR_H_FEN                  (0x10UL)            /*!< Enable FIFOs */
#define UART_LCR_H_STP2                 (0x08UL)            /*!< Two stop bits select */
#define UART_LCR_H_EPS                  (0x04UL)            /*!< Even parity select */
#define UART_LCR_H_PEN                  (0x02UL)            /*!< Parity enable */
#define UART_LCR_H_BRK                  (0x01UL)            /*!< Send break */

/****** Bit definition for Control(UARTCR) register ***************************/
#define UART_CR_CTSEn                   (0x8000UL)          /*!< CTS hardware flow control enable */
#define UART_CR_RTSEn                   (0x4000UL)          /*!< RTS hardware flow control enable */
#define UART_CR_Out2                    (0x2000UL)          /*!< Complement of Out2 modem status output */
#define UART_CR_Out1                    (0x1000UL)          /*!< Complement of Out1 modem status output */
#define UART_CR_RTS                     (0x0800UL)          /*!< Request to send */
#define UART_CR_DTR                     (0x0400UL)          /*!< Data transmit ready */
#define UART_CR_RXE                     (0x0200UL)          /*!< Receive enable */
#define UART_CR_TXE                     (0x0100UL)          /*!< Transmit enable */
#define UART_CR_SIRLP                   (0x0004UL)          /*!< IrDA SIR low power mode */
#define UART_CR_SIREN                   (0x0002UL)          /*!< SIR enable */
#define UART_CR_UARTEN                  (0x0001UL)          /*!< UART enable */

/****** Bit definition for Interrupt FIFO Level Select(UARTIFLS) register *****/
#define UART_IFLS_RXIFLSEL              (0x38UL)            /*!< RXIFLSEL[2:0] bits (Receive interrupt FIFO level select) */
#define UART_IFLS_RXIFLSEL_0            (0x08UL)            /*!< Bit 0 */
#define UART_IFLS_RXIFLSEL_1            (0x10UL)            /*!< Bit 1 */
#define UART_IFLS_RXIFLSEL_2            (0x20UL)            /*!< Bit 2 */
#define UART_IFLS_TXIFLSEL              (0x07UL)            /*!< TXIFLSEL[2:0] bits (Transmit interrupt FIFO level select) */
#define UART_IFLS_TXIFLSEL_0            (0x04UL)            /*!< Bit 0 */
#define UART_IFLS_TXIFLSEL_1            (0x02UL)            /*!< Bit 1 */
#define UART_IFLS_TXIFLSEL_2            (0x01UL)            /*!< Bit 2 */

/****** Bit definition for Interrupt Mask Set/Clear(UARTstatus) register ********/
#define UART_IMSC_OEIM                  (0x400UL)           /*!< Overrun error interrupt mask */
#define UART_IMSC_BEIM                  (0x200UL)           /*!< Break error interrupt mask */
#define UART_IMSC_PEIM                  (0x100UL)           /*!< Parity error interrupt mask */
#define UART_IMSC_FEIM                  (0x080UL)           /*!< Framing error interrupt mask */
#define UART_IMSC_RTIM                  (0x040UL)           /*!< Receive interrupt mask */
#define UART_IMSC_TXIM                  (0x020UL)           /*!< Transmit interrupt mask */
#define UART_IMSC_RXIM                  (0x010UL)           /*!< Receive interrupt mask */
#define UART_IMSC_DSRMIM                (0x008UL)           /*!< nUARTDSR modem interrupt mask */
#define UART_IMSC_DCDMIM                (0x004UL)           /*!< nUARTDCD modem interrupt mask */
#define UART_IMSC_CTSMIM                (0x002UL)           /*!< nUARTCTS modem interrupt mask */
#define UART_IMSC_RIMIM                 (0x001UL)           /*!< nUARTRI modem interrupt mask */

/****** Bit definition for Raw Interrupt Status(UARTRIS) register *************/
#define UART_RIS_OEIM                   (0x400UL)           /*!< Overrun error interrupt status */
#define UART_RIS_BEIM                   (0x200UL)           /*!< Break error interrupt status */
#define UART_RIS_PEIM                   (0x100UL)           /*!< Parity error interrupt status */
#define UART_RIS_FEIM                   (0x080UL)           /*!< Framing error interrupt status */
#define UART_RIS_RTIM                   (0x040UL)           /*!< Receive interrupt status */
#define UART_RIS_TXIM                   (0x020UL)           /*!< Transmit interrupt status */
#define UART_RIS_RXIM                   (0x010UL)           /*!< Receive interrupt status */
#define UART_RIS_DSRMIM                 (0x008UL)           /*!< nUARTDSR modem interrupt status */
#define UART_RIS_DCDMIM                 (0x004UL)           /*!< nUARTDCD modem interrupt status */
#define UART_RIS_CTSMIM                 (0x002UL)           /*!< nUARTCTS modem interrupt status */
#define UART_RIS_RIMIM                  (0x001UL)           /*!< nUARTRI modem interrupt status */

/****** Bit definition for Masked Interrupt Status(UARTMIS) register **********/
#define UART_MIS_OEIM                   (0x400UL)           /*!< Overrun error masked interrupt status */
#define UART_MIS_BEIM                   (0x200UL)           /*!< Break error masked interrupt status */
#define UART_MIS_PEIM                   (0x100UL)           /*!< Parity error masked interrupt status */
#define UART_MIS_FEIM                   (0x080UL)           /*!< Framing error masked interrupt status */
#define UART_MIS_RTIM                   (0x040UL)           /*!< Receive masked interrupt status */
#define UART_MIS_TXIM                   (0x020UL)           /*!< Transmit masked interrupt status */
#define UART_MIS_RXIM                   (0x010UL)           /*!< Receive masked interrupt status */
#define UART_MIS_DSRMIM                 (0x008UL)           /*!< nUARTDSR modem masked interrupt status */
#define UART_MIS_DCDMIM                 (0x004UL)           /*!< nUARTDCD modem masked interrupt status */
#define UART_MIS_CTSMIM                 (0x002UL)           /*!< nUARTCTS modem masked interrupt status */
#define UART_MIS_RIMIM                  (0x001UL)           /*!< nUARTRI modem masked interrupt status */

/****** Bit definition for Interrupt Clear(UARTICR) register ******************/
#define UART_ICR_OEIM                   (0x400UL)           /*!< Overrun error interrupt clear */
#define UART_ICR_BEIM                   (0x200UL)           /*!< Break error interrupt clear */
#define UART_ICR_PEIM                   (0x100UL)           /*!< Parity error interrupt clear */
#define UART_ICR_FEIM                   (0x080UL)           /*!< Framing error interrupt clear */
#define UART_ICR_RTIM                   (0x040UL)           /*!< Receive interrupt clear */
#define UART_ICR_TXIM                   (0x020UL)           /*!< Transmit interrupt clear */
#define UART_ICR_RXIM                   (0x010UL)           /*!< Receive interrupt clear */
#define UART_ICR_DSRMIM                 (0x008UL)           /*!< nUARTDSR modem interrupt clear */
#define UART_ICR_DCDMIM                 (0x004UL)           /*!< nUARTDCD modem interrupt clear */
#define UART_ICR_CTSMIM                 (0x002UL)           /*!< nUARTCTS modem interrupt clear */
#define UART_ICR_RIMIM                  (0x001UL)           /*!< nUARTRI modem interrupt clear */

/****** Bit definition for DMA Control(UARTDMACR) register ********************/
#define UART_DMACR_DMAONERR             (0x004UL)           /*!< DMA on error */
#define UART_DMACR_TXDMAE               (0x002UL)           /*!< Transmit DMA enable */
#define UART_DMACR_RXDMAE               (0x001UL)           /*!< Receive DMA enable */

/******************************************************************************/
/*                                                                            */
/*                           Simple UART                                      */
/*                                                                            */
/******************************************************************************/
/************** Bit definition for S_UART Data () register ********************/
#define S_UART_DR_DATA                  (0xFFUL)
/************** Bit definition for S_UART State() register ********************/
#define S_UART_SR_RXO                   (0x08UL)            /*!< RX buffer overrun, wirte 1 to clear */
#define S_UART_SR_TXO                   (0x04UL)            /*!< TX buffer overrun, wirte 1 to clear */
#define S_UART_SR_RXBF                  (0x02UL)            /*!< RX buffer full, read only */
#define S_UART_SR_TXBF                  (0x01UL)            /*!< TX buffer full, read only */

/************** Bit definition for S_UART Control() register ******************/
#define S_UART_CR_ROIE                  (0x20UL)            /*!< RX overrun interrupt enable */
#define S_UART_CR_TOIE                  (0x10UL)            /*!< TX overrun interrupt enable */
#define S_UART_CR_RXIE                  (0x08UL)            /*!< RX interrupt enable */
#define S_UART_CR_TXIE                  (0x04UL)            /*!< TX interrupt enable */
#define S_UART_CR_RXE                   (0x02UL)            /*!< RX enable */
#define S_UART_CR_TXE                   (0x01UL)            /*!< TX enable */

/************** Bit definition for S_UART Interrupt Status() register *********/
#define S_UART_ISR_RXOI                 (0x08UL)            /*!< Receive Overrun Interrupt */
#define S_UART_ISR_TXOI                 (0x04UL)            /*!< Transmit Overrun Interrupt */
#define S_UART_ISR_RXI                  (0x02UL)            /*!< Receive Interrupt */
#define S_UART_ISR_TXI                  (0x01UL)            /*!< Transmit Interrupt */

/************** Bit definition for S_UART Interrupt Clear() register **********/
#define S_UART_ICR_RXOI                 (0x08UL)            /*!< Receive Overrun Interrupt. Wirte 1 to clear */
#define S_UART_ICR_TXOI                 (0x04UL)            /*!< Transmit Overrun Interrupt. Wirte 1 to clear */
#define S_UART_ICR_RXI                  (0x02UL)            /*!< Receive Interrupt. Wirte 1 to clear */
#define S_UART_ICR_TXI                  (0x01UL)            /*!< Transmit Interrupt. Wirte 1 to clear */

/************** Bit definition for S_UART Interrupt() register ****************/
#define S_UART_BDR_BAUDDIV              (0xFFFFFUL)         /*!< BAUDDIV[19:0] bits (Baud rate divider) */

/******************************************************************************/
/*                                                                            */
/*                          Watchdog timer Registers                          */
/*                                                                            */
/******************************************************************************/
/***************** Bit definition for WDTLoad register ************************/
#define WDT_LOAD_WLR                    (0xFFFFFFFF)        /*!< WLR[31:0] bits (Watchdog timer Load) */

/***************** Bit definition for WDTValue register ***********************/
#define WDT_VALUE_WVR                   (0xFFFFFFFF)        /*!< WVR[31:0] bits (Watchdog timer Value) */

/***************** Bit definition for WDTControl register *********************/
#define WDT_CONTROL_REN                 (0x02UL)            /*!< Reset Request Enable */
#define WDT_CONTROL_IEN                 (0x01UL)            /*!< Interrupt Enable */

/***************** Bit definition for WDTIntClr register **********************/
#define WDT_INTCLR_WIC                  (0x01UL)            /*!< Watchdog timer Interrupt Clear */

/***************** Bit definition for WDTRIS register *************************/
#define WDT_RIS_RIS                     (0x01UL)            /*!< Watchdog timer Raw Interrupt Status */

/***************** Bit definition for WDTMIS register *************************/
#define WDT_MIS_MIS                     (0x01UL)            /*!< Watchdog timer Masked Interrupt Status */

/***************** Bit definition for WDTLock register *************************/
#define WDT_LOCK_ERW                    (0xFFFFFFFE)        /*!< ERW[31:1] bits (Enable Register Writes) */
#define WDT_LOCK_WES                    (0x01UL)            /*!< Register Write Enable status */

/******************************************************************************/
/*                                                                            */
/*            System configuration controller (SYSCFG) Registers              */
/*                                                                            */
/******************************************************************************/
/***************** Bit definition for RSTINFO register ************************/
#define SYSCFG_RSTINFO_SYS              (0x01UL)            /*!< Reset Request Enable */
#define SYSCFG_RSTINFO_RST              (0x02UL)            /*!< Interrupt Enable */

/**
 * @}
 */

/**
 * @}
 */

#ifdef USE_STDPERIPH_DRIVER
#include "w7500x_conf.h"
#endif

/** @addtogroup Exported_macro
 * @{
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif  /* __W7500X_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT WIZnet *****END OF FILE****************/

/**
 ******************************************************************************
 * @file    w7500x_gpio.h
 * @author  WIZnet
 * @brief   This file contains all the functions prototypes for the
 *          General-purpose I/Os(GPIO) peripheral.
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
#ifndef __W7500X_GPIO_H
#define __W7500X_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w7500x.h"

/** @addtogroup W7500x_StdPeriph_Driver
 * @{
 */

/** @addtogroup GPIO
 * @{
 */

/* Exported types ------------------------------------------------------------*/

#define IS_GPIO_ALL_PERIPH(PERIPH)  (((PERIPH) == GPIOA) || \
                                     ((PERIPH) == GPIOB) || \
                                     ((PERIPH) == GPIOC) || \
                                     ((PERIPH) == GPIOD))

/** @defgroup Direction_enumeration
 * @{
 */
typedef enum
{
    GPIO_Direction_IN = 0x00, /*!< GPIO Input Mode */
    GPIO_Direction_OUT = 0x01 /*!< GPIO Output Mode */
} GPIODirection_TypeDef;

#define IS_GPIO_DIRECTION(DIRECTION)    (((DIRECTION) == GPIO_Direction_IN)|| \
                                         ((DIRECTION) == GPIO_Direction_OUT))
/**
 * @}
 */

/** @defgroup GPIO_Pad
 * @{
 */
#define GPIO_SummitTrigger          0x00UL
#define GPIO_CMOS                   PAD_PCR_CS

#define GPIO_InputBufferDisable     0x00UL
#define GPIO_InputBufferEnable      PAD_PCR_IE

#define GPIO_OpenDrainDisable       0x00UL
#define GPIO_OpenDrainEnable        PAD_PCR_OD

#define GPIO_HighDrivingStrength    0x00UL
#define GPIO_LowDrivingStrength     PAD_PCR_DS

#define GPIO_PuPd_NOPULL            PAD_PCR_PUPD
#define GPIO_PuPd_UP                PAD_PCR_PUPD_1
#define GPIO_PuPd_DOWN              PAD_PCR_PUPD_0

#define GPIO_Pad_Default            GPIO_LowDrivingStrength|GPIO_PuPd_UP

#define IS_GPIO_PAD(PAD)        (((PAD) == GPIO_PuPd_NOPULL)|| \
                                 ((PAD) == GPIO_PuPd_UP)|| \
                                 ((PAD) == GPIO_PuPd_DOWN)|| \
                                 ((PAD) == GPIO_HighDrivingStrength)|| \
                                 ((PAD) == GPIO_LowDrivingStrength)|| \
                                 ((PAD) == GPIO_OpenDrainEnable)|| \
                                 ((PAD) == GPIO_OpenDrainDisable)|| \
                                 ((PAD) == GPIO_InputBufferEnable)|| \
                                 ((PAD) == GPIO_InputBufferDisable)|| \
                                 ((PAD) == GPIO_SummitTrigger)|| \
                                 ((PAD) == GPIO_CMOS)|| \
                                 ((PAD) == GPIO_Pad_Default))
/**
 * @}
 */

/** @defgroup Alternate_function_enumeration
 * @{
 */
typedef enum
{
    PAD_AF0 = 0x00UL,
    PAD_AF1 = AFC_AFR_AF_0,
    PAD_AF2 = AFC_AFR_AF_1,
    PAD_AF3 = AFC_AFR_AF
} GPIOAf_TypeDef;

#define IS_GPIO_AF(AF)       (((AF) == PAD_AF0) || ((AF) == PAD_AF1) || \
                              ((AF) == PAD_AF2) || ((AF) == PAD_AF3))
/**
 * @}
 */

/**
 * @brief  GPIO Init structure definition
 */
typedef struct
{
    uint32_t GPIO_Pin;                      /*!< Specifies the GPIO pins to be configured.
                                                 This parameter can be any value of @ref GPIO_pins_define */

    GPIODirection_TypeDef GPIO_Direction;   /*!< Specifies the operating Direction for the selected pins.
                                                 This parameter can be a value of @ref GPIODirection_TypeDef   */

    uint32_t GPIO_Pad;                      /*!< Specifies the operating Pad type for the selected pins.
                                                 This parameter can be a value of @ref GPIOPad_TypeDef   */

    GPIOAf_TypeDef GPIO_AF;                 /*!< Specifies the operating  Alternate function for the selected pins.
                                                 This parameter can be a value of @ref GPIOAf_TypeDef   */
} GPIO_InitTypeDef;

/** @defgroup GPIO_Interrupt_Polarity_enumeration
 * @{
 */

typedef enum
{
    GPIO_IT_LowFalling = 0,
    GPIO_IT_HighRising = 1
} GPIOITPol_TypeDef;

#define IS_GPIO_IT_POL(POL)     (((POL) == GPIO_IT_LowFalling) || \
                                 ((POL) == GPIO_IT_HighRising))
/**
 * @}
 */

/** @defgroup GPIO_Interrupt_Type_enumeration
 * @{
 */

typedef enum
{
    GPIO_IT_Level = 0,
    GPIO_IT_Edge = 1
} GPIOITType_TypeDef;

#define IS_GPIO_IT_TYPE(TYPE)   (((TYPE) == GPIO_IT_Level) || \
                                 ((TYPE) == GPIO_IT_Edge))
/**
 * @}
 */

/**
 * @brief  GPIO IT Init structure definition
 */

typedef struct
{
    uint32_t GPIO_IT_Pin;
    GPIOITPol_TypeDef GPIO_IT_Polarity;
    GPIOITType_TypeDef GPIO_IT_Type;
} GPIO_ITInitTypeDef;

/** @defgroup Bit_SET_and_Bit_RESET_enumeration
 * @{
 */

typedef enum
{
    Bit_RESET = 0,
    Bit_SET
} BitAction;

#define IS_GPIO_BIT_ACTION(ACTION)  (((ACTION == Bit_RESET) || (ACTION) ==Bit_SET))
/**
 * @}
 */

/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants
 * @{
 */

/** @defgroup GPIO_pins_define
 * @{
 */
#define GPIO_Pin_0      (uint16_t)(0x01 <<  0)     /*!< Pin 0 selected     */
#define GPIO_Pin_1      (uint16_t)(0x01 <<  1)     /*!< Pin 1 selected     */
#define GPIO_Pin_2      (uint16_t)(0x01 <<  2)     /*!< Pin 2 selected     */
#define GPIO_Pin_3      (uint16_t)(0x01 <<  3)     /*!< Pin 3 selected     */
#define GPIO_Pin_4      (uint16_t)(0x01 <<  4)     /*!< Pin 4 selected     */
#define GPIO_Pin_5      (uint16_t)(0x01 <<  5)     /*!< Pin 5 selected     */
#define GPIO_Pin_6      (uint16_t)(0x01 <<  6)     /*!< Pin 6 selected     */
#define GPIO_Pin_7      (uint16_t)(0x01 <<  7)     /*!< Pin 7 selected     */
#define GPIO_Pin_8      (uint16_t)(0x01 <<  8)     /*!< Pin 8 selected     */
#define GPIO_Pin_9      (uint16_t)(0x01 <<  9)     /*!< Pin 9 selected     */
#define GPIO_Pin_10     (uint16_t)(0x01 << 10)     /*!< Pin 10 selected    */
#define GPIO_Pin_11     (uint16_t)(0x01 << 11)     /*!< Pin 11 selected    */
#define GPIO_Pin_12     (uint16_t)(0x01 << 12)     /*!< Pin 12 selected    */
#define GPIO_Pin_13     (uint16_t)(0x01 << 13)     /*!< Pin 13 selected    */
#define GPIO_Pin_14     (uint16_t)(0x01 << 14)     /*!< Pin 14 selected    */
#define GPIO_Pin_15     (uint16_t)(0x01 << 15)     /*!< Pin 15 selected    */
#define GPIO_Pin_All    (uint16_t)(0xFF)           /*!< All pins selected  */

#define IS_GPIO_PIN(PIN)        ((PIN) != (uint16_t)0x00)

#define IS_GET_GPIO_PIN(PIN)    (((PIN) == GPIO_Pin_0)  || ((PIN) == GPIO_Pin_1)  || \
                                 ((PIN) == GPIO_Pin_2)  || ((PIN) == GPIO_Pin_3)  || \
                                 ((PIN) == GPIO_Pin_4)  || ((PIN) == GPIO_Pin_5)  || \
                                 ((PIN) == GPIO_Pin_6)  || ((PIN) == GPIO_Pin_7)  || \
                                 ((PIN) == GPIO_Pin_8)  || ((PIN) == GPIO_Pin_9)  || \
                                 ((PIN) == GPIO_Pin_10) || ((PIN) == GPIO_Pin_11) || \
                                 ((PIN) == GPIO_Pin_12) || ((PIN) == GPIO_Pin_13) || \
                                 ((PIN) == GPIO_Pin_14) || ((PIN) == GPIO_Pin_15) )
/**
 * @}
 */

/** @defgroup GPIO_Pin_sources
 * @{
 */
#define GPIO_PinSource0            ((uint8_t)0x00)
#define GPIO_PinSource1            ((uint8_t)0x01)
#define GPIO_PinSource2            ((uint8_t)0x02)
#define GPIO_PinSource3            ((uint8_t)0x03)
#define GPIO_PinSource4            ((uint8_t)0x04)
#define GPIO_PinSource5            ((uint8_t)0x05)
#define GPIO_PinSource6            ((uint8_t)0x06)
#define GPIO_PinSource7            ((uint8_t)0x07)
#define GPIO_PinSource8            ((uint8_t)0x08)
#define GPIO_PinSource9            ((uint8_t)0x09)
#define GPIO_PinSource10           ((uint8_t)0x0A)
#define GPIO_PinSource11           ((uint8_t)0x0B)
#define GPIO_PinSource12           ((uint8_t)0x0C)
#define GPIO_PinSource13           ((uint8_t)0x0D)
#define GPIO_PinSource14           ((uint8_t)0x0E)
#define GPIO_PinSource15           ((uint8_t)0x0F)

#define IS_GPIO_PIN_SOURCE(PINSOURCE)   (((PINSOURCE) == GPIO_PinSource0) || \
                                         ((PINSOURCE) == GPIO_PinSource1) || \
										 ((PINSOURCE) == GPIO_PinSource2) || \
										 ((PINSOURCE) == GPIO_PinSource3) || \
										 ((PINSOURCE) == GPIO_PinSource4) || \
										 ((PINSOURCE) == GPIO_PinSource5) || \
										 ((PINSOURCE) == GPIO_PinSource6) || \
										 ((PINSOURCE) == GPIO_PinSource7) || \
										 ((PINSOURCE) == GPIO_PinSource8) || \
										 ((PINSOURCE) == GPIO_PinSource9) || \
										 ((PINSOURCE) == GPIO_PinSource10) || \
										 ((PINSOURCE) == GPIO_PinSource11) || \
										 ((PINSOURCE) == GPIO_PinSource12) || \
										 ((PINSOURCE) == GPIO_PinSource13) || \
										 ((PINSOURCE) == GPIO_PinSource14) || \
										 ((PINSOURCE) == GPIO_PinSource15))
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/* Initialization and Configuration functions *********************************/
void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);

/* GPIO Read and Write functions **********************************************/
BitAction GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
BitAction GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/* Interrupts and flags management functions **********************************/
void GPIO_IT_Init(GPIO_TypeDef* GPIOx, GPIO_ITInitTypeDef* GPIO_ITInitStruct);
void GPIO_ITStructInit(GPIO_ITInitTypeDef* GPIO_ITInitStruct);
void GPIO_ITConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, FunctionalState NewState);
ITStatus GPIO_GetITStatus(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ClearITPendingPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/* GPIO Alternate functions configuration functions ***************************/
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOAf_TypeDef GPIO_AF);
uint8_t GPIO_Read_PinAF(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/* GPIO Pad configuration functions *******************************************/
void GPIO_PinPadConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint32_t GPIO_Pad);
uint8_t GPIO_Read_PinPad(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* __W7500X_GPIO_H */

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

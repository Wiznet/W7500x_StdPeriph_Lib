/**
 ******************************************************************************
 * @file    Flash/Flash_IAP/main.c
 * @author  WIZnet
 * @brief   Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup W7500x_StdPeriph_Examples
 * @{
 */

/** @addtogroup Flash_IAP
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
typedef enum
{
    FAILED = 0, PASSED = !FAILED
} TestStatus;

/* Private define ------------------------------------------------------------*/
#define DAT0_START_ADDR     0x0003FE00
#define DAT1_START_ADDR     0x0003FF00
#define CODE_TEST_ADDR      0x0001F000
#define BLOCK_SIZE          4096
#define SECT_SIZE           256

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
volatile TestStatus TransferStatus = FAILED;
uint8_t save_buff[BLOCK_SIZE];

/* Private function prototypes -----------------------------------------------*/
static void UART_Config(void);
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
int main(void)
{
    uint32_t i, result;

    SystemInit();

    UART_Config();

    printf("W7500x Standard Peripheral Library version : %d.%d.%d\r\n", __W7500X_STDPERIPH_VERSION_MAIN, __W7500X_STDPERIPH_VERSION_SUB1, __W7500X_STDPERIPH_VERSION_SUB2);

    printf("SourceClock : %d\r\n", (int) GetSourceClock());
    printf("SystemClock : %d\r\n", (int) GetSystemClock());

    /* Make Dummy Data for Flash Write Test */
    for (i = 0; i < SECT_SIZE; i++) {
        save_buff[i] = i;
    }

    /* Step 1 DATA0 Flash Block Erase, Write, Read Test */
    FLASH_IAP(IAP_ERAS_DAT0, 0, 0, 0); //Erase
    FLASH_IAP(IAP_PROG, DAT0_START_ADDR, save_buff, SECT_SIZE); //Write
    result = Buffercmp((uint8_t*) save_buff, ((uint8_t *) (DAT0_START_ADDR)), SECT_SIZE); //Read

    if (result == PASSED) printf("Step1 Test Passed\r\n");
    else printf("Step1 Test Failed\r\n");

    /* Step 2 DATA1 Flash Block Erase, Write, Read Test */
    FLASH_IAP(IAP_ERAS_DAT1, 0, 0, 0); //Erase
    FLASH_IAP(IAP_PROG, DAT1_START_ADDR, save_buff, SECT_SIZE); //Write
    result = Buffercmp((uint8_t*) save_buff, ((uint8_t *) (DAT1_START_ADDR)), SECT_SIZE); //Read

    if (result == PASSED) printf("Step2 Test Passed\r\n");
    else printf("Step2 Test Failed\r\n");

    /* Step 3 CODE Flash Block Erase, Write, Read Test */
    for (i = 0; i < BLOCK_SIZE; i++) {
        save_buff[i] = i;
    }
    FLASH_IAP(IAP_ERAS_BLCK, CODE_TEST_ADDR, 0, 0); //Erase
    FLASH_IAP(IAP_PROG, CODE_TEST_ADDR, save_buff, BLOCK_SIZE); //Write
    result = Buffercmp((uint8_t*) save_buff, ((uint8_t *) (CODE_TEST_ADDR)), BLOCK_SIZE); //Read

    if (result == PASSED) printf("Step3 Test Passed\r\n");
    else printf("Step3 Test Failed\r\n");

    printf("System Loop Start\r\n");

    while (1) {

    }
	
	return 0;
}

/**
 * @brief  Configures the UART Peripheral.
 * @note
 * @param  None
 * @retval None
 */
static void UART_Config(void)
{
    UART_InitTypeDef UART_InitStructure;

    UART_StructInit(&UART_InitStructure);
	
#if defined (USE_WIZWIKI_W7500_EVAL)
    UART_Init(UART1, &UART_InitStructure);
    UART_Cmd(UART1, ENABLE);
#else
    S_UART_Init(115200);
    S_UART_Cmd(ENABLE);
#endif
}

/**
 * @brief  Compares two buffers.
 * @param  pBuffer1, pBuffer2: buffers to be compared.
 * @param  BufferLength: buffer's length
 * @retval PASSED: pBuffer1 identical to pBuffer2
 *         FAILED: pBuffer1 differs from pBuffer2
 */
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
    while (BufferLength--) {
        if (*pBuffer1 != *pBuffer2) {
            return FAILED;
        }

        pBuffer1++;
        pBuffer2++;
    }

    return PASSED;
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

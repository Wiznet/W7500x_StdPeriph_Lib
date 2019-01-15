/**
 ******************************************************************************
 * @file    retarget.c
 * @author  WIZnet
 * @brief   Using for printf function
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

#include <stdio.h>
#include "w7500x_uart.h"
#include "main.h"

#if defined (USING_UART0)
#define UART_SEND_BYTE(ch)  UartPutc(UART0, ch)
#define UART_RECV_BYTE()    UartGetc(UART0)
#elif defined (USING_UART1)
#define UART_SEND_BYTE(ch)  UartPutc(UART1, ch)
#define UART_RECV_BYTE()    UartGetc(UART1)
#elif defined (USING_UART2)
#define UART_SEND_BYTE(ch)  S_UartPutc(ch)
#define UART_RECV_BYTE()    S_UartGetc()
#endif

uint8_t UartPutc(UART_TypeDef* UARTx, uint8_t ch);
void UartPuts(UART_TypeDef* UARTx, uint8_t *str);
uint8_t UartGetc(UART_TypeDef* UARTx);
uint8_t S_UartPutc(uint8_t ch);
void S_UartPuts(uint8_t *str);
uint8_t S_UartGetc(void);

#if defined ( __CC_ARM   )
/******************************************************************************/
/* Retarget functions for ARM DS-5 Professional / Keil MDK                    */
/******************************************************************************/
#include <time.h>
#include <rt_misc.h>
#pragma import(__use_no_semihosting_swi)

struct __FILE {int handle; /* Add whatever you need here */};
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f) {
    return (UART_SEND_BYTE(ch));
}

int fgetc(FILE *f) {
    return (UART_SEND_BYTE(UART_RECV_BYTE()));
}

int ferror(FILE *f) {
    /* Your implementation of ferror */
    return EOF;
}

void _ttywrch(int ch) {
    UART_SEND_BYTE(ch);
}

void _sys_exit(int return_code) {
    label: goto label; /* endless loop */
}

#elif defined (__GNUC__)
/******************************************************************************/
/* Retarget functions for GNU Tools for ARM Embedded Processors               */
/******************************************************************************/
#include <sys/stat.h>

__attribute__ ((used)) int _write(int fd, char *ptr, int len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        UART_SEND_BYTE(ptr[i]);  // call character output function
    }
    return len;
}
#else //using TOOLCHAIN_IAR

int putchar(int ch)
{
    return (UART_SEND_BYTE(ch));
}

int getchar(void)
{
    return (UART_SEND_BYTE(UART_RECV_BYTE()));
}

#endif

uint8_t UartPutc(UART_TypeDef* UARTx, uint8_t ch)
{
    UART_SendData(UARTx, ch);

    while (UARTx->FR & UART_FR_BUSY)
        ;

    return (ch);
}

void UartPuts(UART_TypeDef* UARTx, uint8_t *str)
{
    uint8_t ch;

    do {
        ch = *str;
        if (ch != (uint8_t) 0x0) {
            UartPutc(UARTx, ch);
        }
        *str++;
    } while (ch != 0);
}

uint8_t UartGetc(UART_TypeDef* UARTx)
{
    while (UARTx->FR & UART_FR_RXFE)
        ;

    return (UARTx->DR & 0xFF);
}

uint8_t S_UartPutc(uint8_t ch)
{
    S_UART_SendData(ch);

    return (ch);
}

void S_UartPuts(uint8_t *str)
{
    uint8_t ch;

    do {
        ch = *str;
        if (ch != (uint8_t) 0x0) {
            S_UART_SendData(ch);
        }
        *str++;
    } while (ch != 0);
}

uint8_t S_UartGetc(void)
{
    while ((UART2->SR & S_UART_FLAG_RXF) == 0)
        ;
    return (uint8_t) S_UART_ReceiveData();
}

/******************** (C) COPYRIGHT WIZnet *****END OF FILE********************/

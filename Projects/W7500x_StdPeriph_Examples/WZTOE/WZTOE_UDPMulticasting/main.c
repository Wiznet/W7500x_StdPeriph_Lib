/**
 ******************************************************************************
 * @file    WZTOE/WZTOE_Loopback/main.c
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
#include "wizchip_conf.h"
#include "loopback.h"

/** @addtogroup W7500x_StdPeriph_Examples
 * @{
 */

/** @addtogroup WZTOE_Loopback
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define test_buf_SIZE 2048

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
uint8_t test_buf[test_buf_SIZE];

/* Private function prototypes -----------------------------------------------*/
static void UART_Config(void);
static void Network_Config(void);
void delay(__IO uint32_t milliseconds);
void TimingDelay_Decrement(void);
int32_t loopback_multicast(uint8_t sn, uint8_t* buf, uint16_t port);
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
int main(void)
{
    SystemInit();

    /* SysTick_Config */
    SysTick_Config((GetSystemClock() / 1000));

    /* Set WZ_100US Register */
    setTIC100US((GetSystemClock() / 10000));

    UART_Config();

    printf("W7500x Standard Peripheral Library version : %d.%d.%d\r\n", __W7500X_STDPERIPH_VERSION_MAIN, __W7500X_STDPERIPH_VERSION_SUB1, __W7500X_STDPERIPH_VERSION_SUB2);

    printf("SourceClock : %d\r\n", (int) GetSourceClock());
    printf("SystemClock : %d\r\n", (int) GetSystemClock());

    /* Initialize PHY */
#ifdef W7500
    printf("PHY Init : %s\r\n", PHY_Init(GPIOB, GPIO_Pin_15, GPIO_Pin_14) == SET ? "Success" : "Fail");
#elif defined (W7500P)
    printf("PHY Init : %s\r\n", PHY_Init(GPIOB, GPIO_Pin_14, GPIO_Pin_15) == SET ? "Success" : "Fail");
#endif

    /* Check Link */
    printf("Link is ");
    while (!PHY_GetLinkStatus()) ;
    printf("OK\n\r");
	
    /* Network information setting */
    Network_Config();

    printf("System Loop Start\r\n");


    while (1) {
        loopback_multicast(0, test_buf, 1900);
    }
	
	return 0;
}

/**
 * @brief  function for UDP multicasting test. If w7500 receive the "end" data, it sent the multicast leave message and isn't connect multicast group
 * @param  sn: Socket Number.
 * @param  buf: Data repository memory.
 * @param  port: source port of udp.
 * @retval None
 */
int32_t loopback_multicast(uint8_t sn, uint8_t* buf, uint16_t port)
{
	int32_t  ret;
	uint16_t size, sentsize;
	uint16_t port_check=0;
	uint8_t mcastmacv4[6] = {0x01,0x00,0x5E,0x01,0x02,0x03};
	uint8_t udp_multi_dest_ip[4] = {235,255,255,250};
	uint16_t udp_destport;
	
switch(getSn_SR(sn))
{
	case SOCK_CLOSED:

		setSn_DPORT(sn, port);
		setSn_DHAR( sn, mcastmacv4);
		setSn_DIPR(sn,udp_multi_dest_ip);
#ifdef _LOOPBACK_DEBUG_
		printf("%d:Multicast Test UDP, Set MAC(DHAR)\r\n",sn);

		printf("%d:Dest Group IP - %d.%d.%d.%d : %d\r\n",sn, udp_multi_dest_ip[0], udp_multi_dest_ip[1], udp_multi_dest_ip[2], udp_multi_dest_ip[3], port_check);
		printf("%d:Dest Group MAC - %x:%x:%x:%x:%x:%x\r\n",sn, mcastmacv4[0], mcastmacv4[1], mcastmacv4[2], mcastmacv4[3], mcastmacv4[4], mcastmacv4[5]);

		printf("%d:Opened, Test UDP, port [%d]\r\n", sn, port);
		printf("IGMPv1 Multicast Test UDP start\r\n");
#endif
		if((ret = socket(sn, Sn_MR_UDP, port, SF_MULTI_ENABLE|SF_IGMP_VER2)) != sn)
			return ret;
#ifdef _LOOPBACK_DEBUG_
		printf("%d: SN_MR: 0x%02x\r\n", sn, getSn_MR(sn));
#endif								
	   break;
	case SOCK_UDP:


		if((size = getSn_RX_RSR(sn)) > 0)
		{
			if(size > test_buf_SIZE) size = test_buf_SIZE;
			memset(test_buf, 0, test_buf_SIZE);
			ret = recvfrom(sn, test_buf, size, udp_multi_dest_ip, (uint16_t*)&udp_destport);
			if(ret <= 0)
			{
				printf("%d: recvfrom error. %ld\r\n",sn, ret);
				return ret;
			}
#ifdef _LOOPBACK_DEBUG_
			printf("%d:recv : %s\t",sn, test_buf);
			printf("%d:peer - %d.%d.%d.%d : %d\r\n",sn, udp_multi_dest_ip[0], udp_multi_dest_ip[1], udp_multi_dest_ip[2], udp_multi_dest_ip[3], udp_destport);
#endif
			if(strstr( test_buf, "end" ))
			{
				close(sn);
				printf("%d: SN_MR: 0x%02x\r\n", sn, getSn_MR(sn));
				
				return 2;
			}
			size = (uint16_t) ret;
			sentsize = 0;
			while(sentsize != size)
			{

				ret = sendto(sn, test_buf+sentsize, size-sentsize, udp_multi_dest_ip, udp_destport);
#ifdef _LOOPBACK_DEBUG_
				printf("multicast sendto %d\r\n", ret);
#endif
				if(ret < 0)
				{
					printf("%d: sendto error. %ld\r\n",sn, ret);
					return ret;
				}
				sentsize += ret; // Don't care SOCKERR_BUSY, because it is zero.
			}
			
		}
	break;
	}
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
 * @brief  Configures the Network Information.
 * @note
 * @param  None
 * @retval None
 */
static void Network_Config(void)
{
    wiz_NetInfo gWIZNETINFO;

    uint8_t mac_addr[6] = { 0x00, 0x08, 0xDC, 0x01, 0x02, 0x03 };
    uint8_t ip_addr[4] = { 192, 168, 11, 100 };
    uint8_t gw_addr[4] = { 192, 168, 11, 1 };
    uint8_t sub_addr[4] = { 255, 255, 255, 0 };
    uint8_t dns_addr[4] = { 8, 8, 8, 8 };

    memcpy(gWIZNETINFO.mac, mac_addr, 6);
    memcpy(gWIZNETINFO.ip, ip_addr, 4);
    memcpy(gWIZNETINFO.gw, gw_addr, 4);
    memcpy(gWIZNETINFO.sn, sub_addr, 4);
    memcpy(gWIZNETINFO.dns, dns_addr, 4);

    ctlnetwork(CN_SET_NETINFO, (void*) &gWIZNETINFO);

    printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\r\n", gWIZNETINFO.mac[0], gWIZNETINFO.mac[1], gWIZNETINFO.mac[2], gWIZNETINFO.mac[3], gWIZNETINFO.mac[4], gWIZNETINFO.mac[5]);
    printf("IP: %d.%d.%d.%d\r\n", gWIZNETINFO.ip[0], gWIZNETINFO.ip[1], gWIZNETINFO.ip[2], gWIZNETINFO.ip[3]);
    printf("GW: %d.%d.%d.%d\r\n", gWIZNETINFO.gw[0], gWIZNETINFO.gw[1], gWIZNETINFO.gw[2], gWIZNETINFO.gw[3]);
    printf("SN: %d.%d.%d.%d\r\n", gWIZNETINFO.sn[0], gWIZNETINFO.sn[1], gWIZNETINFO.sn[2], gWIZNETINFO.sn[3]);
    printf("DNS: %d.%d.%d.%d\r\n", gWIZNETINFO.dns[0], gWIZNETINFO.dns[1], gWIZNETINFO.dns[2], gWIZNETINFO.dns[3]);
}

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in milliseconds.
 * @retval None
 */
void delay(__IO uint32_t milliseconds)
{
    TimingDelay = milliseconds;

    while (TimingDelay != 0)
        ;
}

/**
 * @brief  Decrements the TimingDelay variable.
 * @param  None
 * @retval None
 */
void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00) {
        TimingDelay--;
    }
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

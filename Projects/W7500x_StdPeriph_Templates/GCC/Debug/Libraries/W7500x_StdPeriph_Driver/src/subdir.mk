################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_adc.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_crg.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_dualtimer.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_exti.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_flash.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_gpio.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_miim.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_misc.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_pwm.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_rng.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_rtc.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_ssp.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_uart.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_wdt.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_wztoe.c 

OBJS += \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_adc.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_crg.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_dualtimer.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_exti.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_flash.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_gpio.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_miim.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_misc.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_pwm.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_rng.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_rtc.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_ssp.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_uart.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_wdt.o \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_wztoe.o 

C_DEPS += \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_adc.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_crg.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_dualtimer.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_exti.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_flash.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_gpio.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_miim.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_misc.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_pwm.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_rng.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_rtc.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_ssp.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_uart.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_wdt.d \
./Libraries/W7500x_StdPeriph_Driver/src/w7500x_wztoe.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/W7500x_StdPeriph_Driver/src/w7500x_adc.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_crg.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_crg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_dualtimer.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_dualtimer.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_exti.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_exti.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_flash.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_gpio.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_miim.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_miim.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_misc.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_misc.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_pwm.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_pwm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_rng.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_rng.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_rtc.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_ssp.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_ssp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_uart.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_wdt.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_wdt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/W7500x_StdPeriph_Driver/src/w7500x_wztoe.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/W7500x_StdPeriph_Driver/src/w7500x_wztoe.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



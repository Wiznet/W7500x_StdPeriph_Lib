################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/src/main.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/src/retarget.c \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/src/w7500x_it.c 

OBJS += \
./src/main.o \
./src/retarget.o \
./src/w7500x_it.o 

C_DEPS += \
./src/main.d \
./src/retarget.d \
./src/w7500x_it.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/retarget.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/src/retarget.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/w7500x_it.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/src/w7500x_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



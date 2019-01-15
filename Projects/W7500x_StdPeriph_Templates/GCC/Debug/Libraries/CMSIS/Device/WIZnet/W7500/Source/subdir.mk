################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/CMSIS/Device/WIZnet/W7500/Source/system_w7500x.c 

OBJS += \
./Libraries/CMSIS/Device/WIZnet/W7500/Source/system_w7500x.o 

C_DEPS += \
./Libraries/CMSIS/Device/WIZnet/W7500/Source/system_w7500x.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/CMSIS/Device/WIZnet/W7500/Source/system_w7500x.o: C:/Users/boomw/Downloads/W7500x_StdPeriph_Lib/Libraries/CMSIS/Device/WIZnet/W7500/Source/system_w7500x.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\CMSIS\Device\WIZnet\W7500\Include" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Application\loopback" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Ethernet" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DHCP" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\ioLibrary\Internet\DNS" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\startup" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\Libraries\W7500x_StdPeriph_Driver\inc" -I"C:\Users\boomw\Downloads\W7500x_StdPeriph_Lib\src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



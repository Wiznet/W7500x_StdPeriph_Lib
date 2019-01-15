################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
C:/Users/boomw/Downloads/W7500x_Platform_Firmware-master/W7500x_Platform_Firmware-master/Libraries/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_w7500x.S 

OBJS += \
./Libraries/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_w7500x.o 

S_UPPER_DEPS += \
./Libraries/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_w7500x.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_w7500x.o: C:/Users/boomw/Downloads/W7500x_Platform_Firmware-master/W7500x_Platform_Firmware-master/Libraries/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_w7500x.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -march=armv6-m -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



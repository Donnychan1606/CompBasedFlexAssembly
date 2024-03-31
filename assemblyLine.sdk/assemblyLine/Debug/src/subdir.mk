################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/error_handling.c \
../src/freertos_tcp_perf_client.c \
../src/i2c_access.c \
../src/iic_phyreset.c \
../src/key.c \
../src/limit_switch.c \
../src/main.c \
../src/message_center.c \
../src/platform.c \
../src/platform_mb.c \
../src/platform_ppc.c \
../src/platform_zynqmp.c \
../src/robotic_arm.c \
../src/sfp.c \
../src/si5324.c \
../src/state_machine.c \
../src/stepper_motor.c \
../src/three_axes_platform.c 

OBJS += \
./src/error_handling.o \
./src/freertos_tcp_perf_client.o \
./src/i2c_access.o \
./src/iic_phyreset.o \
./src/key.o \
./src/limit_switch.o \
./src/main.o \
./src/message_center.o \
./src/platform.o \
./src/platform_mb.o \
./src/platform_ppc.o \
./src/platform_zynqmp.o \
./src/robotic_arm.o \
./src/sfp.o \
./src/si5324.o \
./src/state_machine.o \
./src/stepper_motor.o \
./src/three_axes_platform.o 

C_DEPS += \
./src/error_handling.d \
./src/freertos_tcp_perf_client.d \
./src/i2c_access.d \
./src/iic_phyreset.d \
./src/key.d \
./src/limit_switch.d \
./src/main.d \
./src/message_center.d \
./src/platform.d \
./src/platform_mb.d \
./src/platform_ppc.d \
./src/platform_zynqmp.d \
./src/robotic_arm.d \
./src/sfp.d \
./src/si5324.d \
./src/state_machine.d \
./src/stepper_motor.d \
./src/three_axes_platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../assemblyLine_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



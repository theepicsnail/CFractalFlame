################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libconfig-1.4.9/tinytest/tinytest.o 

C_SRCS += \
../libconfig-1.4.9/tinytest/tinytest.c 

OBJS += \
./libconfig-1.4.9/tinytest/tinytest.o 

C_DEPS += \
./libconfig-1.4.9/tinytest/tinytest.d 


# Each subdirectory must supply rules for building sources it contributes
libconfig-1.4.9/tinytest/%.o: ../libconfig-1.4.9/tinytest/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



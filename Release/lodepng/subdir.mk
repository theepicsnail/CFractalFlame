################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lodepng/lodepng.cpp 

OBJS += \
./lodepng/lodepng.o 

CPP_DEPS += \
./lodepng/lodepng.d 


# Each subdirectory must supply rules for building sources it contributes
lodepng/%.o: ../lodepng/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DRELEASE -UDEBUG -I/home/snail/workspace/FractalFlame/lodepng -I/home/snail/workspace/FractalFlame/libconfig-1.4.9/lib -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



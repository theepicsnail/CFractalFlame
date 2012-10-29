################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Config.cpp \
../Image.cpp \
../Renderer.cpp \
../Util.cpp \
../main.cpp 

OBJS += \
./Config.o \
./Image.o \
./Renderer.o \
./Util.o \
./main.o 

CPP_DEPS += \
./Config.d \
./Image.d \
./Renderer.d \
./Util.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -lpthread -DDEBUG -URELEASE -I/home/snail/workspace/FractalFlame/lodepng -I/home/snail/workspace/FractalFlame/libconfig-1.4.9/lib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libconfig-1.4.9/lib/libconfig___la-grammar.o \
../libconfig-1.4.9/lib/libconfig___la-libconfig.o \
../libconfig-1.4.9/lib/libconfig___la-libconfigcpp.o \
../libconfig-1.4.9/lib/libconfig___la-scanctx.o \
../libconfig-1.4.9/lib/libconfig___la-scanner.o \
../libconfig-1.4.9/lib/libconfig___la-strbuf.o \
../libconfig-1.4.9/lib/libconfig_la-grammar.o \
../libconfig-1.4.9/lib/libconfig_la-libconfig.o \
../libconfig-1.4.9/lib/libconfig_la-scanctx.o \
../libconfig-1.4.9/lib/libconfig_la-scanner.o \
../libconfig-1.4.9/lib/libconfig_la-strbuf.o 

C_SRCS += \
../libconfig-1.4.9/lib/grammar.c \
../libconfig-1.4.9/lib/libconfig.c \
../libconfig-1.4.9/lib/scanctx.c \
../libconfig-1.4.9/lib/scanner.c \
../libconfig-1.4.9/lib/strbuf.c 

C++_SRCS += \
../libconfig-1.4.9/lib/libconfigcpp.c++ 

CC_SRCS += \
../libconfig-1.4.9/lib/libconfigcpp.cc 

OBJS += \
./libconfig-1.4.9/lib/grammar.o \
./libconfig-1.4.9/lib/libconfig.o \
./libconfig-1.4.9/lib/libconfigcpp.o \
./libconfig-1.4.9/lib/scanctx.o \
./libconfig-1.4.9/lib/scanner.o \
./libconfig-1.4.9/lib/strbuf.o 

C++_DEPS += \
./libconfig-1.4.9/lib/libconfigcpp.d 

C_DEPS += \
./libconfig-1.4.9/lib/grammar.d \
./libconfig-1.4.9/lib/libconfig.d \
./libconfig-1.4.9/lib/scanctx.d \
./libconfig-1.4.9/lib/scanner.d \
./libconfig-1.4.9/lib/strbuf.d 

CC_DEPS += \
./libconfig-1.4.9/lib/libconfigcpp.d 


# Each subdirectory must supply rules for building sources it contributes
libconfig-1.4.9/lib/%.o: ../libconfig-1.4.9/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

libconfig-1.4.9/lib/%.o: ../libconfig-1.4.9/lib/%.c++
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -URELEASE -I/home/snail/workspace/FractalFlame/lodepng -I/home/snail/workspace/FractalFlame/libconfig-1.4.9/lib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

libconfig-1.4.9/lib/%.o: ../libconfig-1.4.9/lib/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -URELEASE -I/home/snail/workspace/FractalFlame/lodepng -I/home/snail/workspace/FractalFlame/libconfig-1.4.9/lib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



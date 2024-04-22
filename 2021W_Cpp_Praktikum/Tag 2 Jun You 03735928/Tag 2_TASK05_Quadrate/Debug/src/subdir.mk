################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/20210930_TASK14_1.16.8_Quadrate.cpp \
../src/square.cpp 

OBJS += \
./src/20210930_TASK14_1.16.8_Quadrate.o \
./src/square.o 

CPP_DEPS += \
./src/20210930_TASK14_1.16.8_Quadrate.d \
./src/square.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



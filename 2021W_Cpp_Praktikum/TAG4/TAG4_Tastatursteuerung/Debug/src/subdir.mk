################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/20211004_TAG4_Tastatur.cpp \
../src/InterfaceSIM.cpp \
../src/KeyboardControl.cpp \
../src/PIDController.cpp 

OBJS += \
./src/20211004_TAG4_Tastatur.o \
./src/InterfaceSIM.o \
./src/KeyboardControl.o \
./src/PIDController.o 

CPP_DEPS += \
./src/20211004_TAG4_Tastatur.d \
./src/InterfaceSIM.d \
./src/KeyboardControl.d \
./src/PIDController.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



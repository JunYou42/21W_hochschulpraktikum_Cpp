################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/20210930_TASK13_1.16_Fahrzeug.cpp \
../src/Vehicle.cpp 

OBJS += \
./src/20210930_TASK13_1.16_Fahrzeug.o \
./src/Vehicle.o 

CPP_DEPS += \
./src/20210930_TASK13_1.16_Fahrzeug.d \
./src/Vehicle.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



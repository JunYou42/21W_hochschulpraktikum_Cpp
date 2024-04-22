################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/20210929_TASK12_Erweiterte_Datumklasse.cpp \
../src/Date.cpp 

OBJS += \
./src/20210929_TASK12_Erweiterte_Datumklasse.o \
./src/Date.o 

CPP_DEPS += \
./src/20210929_TASK12_Erweiterte_Datumklasse.d \
./src/Date.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



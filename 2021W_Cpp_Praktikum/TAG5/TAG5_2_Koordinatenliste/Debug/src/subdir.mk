################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/20211005_TAG5_Koordinatenliste.cpp \
../src/Maneuver.cpp 

OBJS += \
./src/20211005_TAG5_Koordinatenliste.o \
./src/Maneuver.o 

CPP_DEPS += \
./src/20211005_TAG5_Koordinatenliste.d \
./src/Maneuver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/20210930_TASK16_1.17.6\ Virtuelle\ Methoden.cpp \
../src/Person.cpp \
../src/Student.cpp 

OBJS += \
./src/20210930_TASK16_1.17.6\ Virtuelle\ Methoden.o \
./src/Person.o \
./src/Student.o 

CPP_DEPS += \
./src/20210930_TASK16_1.17.6\ Virtuelle\ Methoden.d \
./src/Person.d \
./src/Student.d 


# Each subdirectory must supply rules for building sources it contributes
src/20210930_TASK16_1.17.6\ Virtuelle\ Methoden.o: ../src/20210930_TASK16_1.17.6\ Virtuelle\ Methoden.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/20210930_TASK16_1.17.6 Virtuelle Methoden.d" -MT"src/20210930_TASK16_1.17.6\ Virtuelle\ Methoden.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



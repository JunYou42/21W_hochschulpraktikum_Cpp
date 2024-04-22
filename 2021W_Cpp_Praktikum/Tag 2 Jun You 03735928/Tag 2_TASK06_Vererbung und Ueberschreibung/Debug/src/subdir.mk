################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/20210930_TASK15_1.17.3_Vererbung\ und\ Ueberschreibung.cpp \
../src/Person.cpp \
../src/Student.cpp 

OBJS += \
./src/20210930_TASK15_1.17.3_Vererbung\ und\ Ueberschreibung.o \
./src/Person.o \
./src/Student.o 

CPP_DEPS += \
./src/20210930_TASK15_1.17.3_Vererbung\ und\ Ueberschreibung.d \
./src/Person.d \
./src/Student.d 


# Each subdirectory must supply rules for building sources it contributes
src/20210930_TASK15_1.17.3_Vererbung\ und\ Ueberschreibung.o: ../src/20210930_TASK15_1.17.3_Vererbung\ und\ Ueberschreibung.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/20210930_TASK15_1.17.3_Vererbung und Ueberschreibung.d" -MT"src/20210930_TASK15_1.17.3_Vererbung\ und\ Ueberschreibung.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



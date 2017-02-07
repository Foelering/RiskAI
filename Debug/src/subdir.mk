################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HumanPlayer.cpp \
../src/Land.cpp \
../src/Player.cpp \
../src/RisikoAI.cpp 

OBJS += \
./src/HumanPlayer.o \
./src/Land.o \
./src/Player.o \
./src/RisikoAI.o 

CPP_DEPS += \
./src/HumanPlayer.d \
./src/Land.d \
./src/Player.d \
./src/RisikoAI.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/auto.c \
../src/color.c \
../src/fecha.c \
../src/main.c \
../src/marca.c \
../src/servicio.c \
../src/trabajo.c 

OBJS += \
./src/auto.o \
./src/color.o \
./src/fecha.o \
./src/main.o \
./src/marca.o \
./src/servicio.o \
./src/trabajo.o 

C_DEPS += \
./src/auto.d \
./src/color.d \
./src/fecha.d \
./src/main.d \
./src/marca.d \
./src/servicio.d \
./src/trabajo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



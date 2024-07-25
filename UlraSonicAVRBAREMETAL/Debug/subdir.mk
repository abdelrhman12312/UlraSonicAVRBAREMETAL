################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../PWM.c \
../Ultrasonic.c \
../gpio.c \
../icu.c \
../lcd.c \
../lm35_sensor.c \
../main.c \
../motordriver.c 

OBJS += \
./ADC.o \
./PWM.o \
./Ultrasonic.o \
./gpio.o \
./icu.o \
./lcd.o \
./lm35_sensor.o \
./main.o \
./motordriver.o 

C_DEPS += \
./ADC.d \
./PWM.d \
./Ultrasonic.d \
./gpio.d \
./icu.d \
./lcd.d \
./lm35_sensor.d \
./main.d \
./motordriver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



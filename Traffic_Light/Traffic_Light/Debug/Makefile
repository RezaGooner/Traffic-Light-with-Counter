################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/ASF/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/ASF/common/utils/make/ \
../src/ASF/mega/ \
../src/ASF/mega/boards/ \
../src/ASF/mega/boards/stk600/ \
../src/ASF/mega/boards/stk600/rcx_x/ \
../src/ASF/mega/utils/ \
../src/ASF/mega/utils/assembler/ \
../src/ASF/mega/utils/preprocessor/ \
../src/config/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/ASF/mega/boards/stk600/rcx_x/init.c \
../src/main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
src/ASF/mega/boards/stk600/rcx_x/init.o \
src/main.o

OBJS_AS_ARGS +=  \
src/ASF/mega/boards/stk600/rcx_x/init.o \
src/main.o

C_DEPS +=  \
src/ASF/mega/boards/stk600/rcx_x/init.d \
src/main.d

C_DEPS_AS_ARGS +=  \
src/ASF/mega/boards/stk600/rcx_x/init.d \
src/main.d

OUTPUT_FILE_PATH +=Traffic_Light.elf

OUTPUT_FILE_PATH_AS_ARGS +=Traffic_Light.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
src/ASF/mega/boards/stk600/rcx_x/init.o: ../src/ASF/mega/boards/stk600/rcx_x/init.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=STK600_MEGA  -I"C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\Packs\atmel\ATmega_DFP\1.2.209\include" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega32 -B "C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega32" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/main.o: ../src/main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=STK600_MEGA  -I"C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\Packs\atmel\ATmega_DFP\1.2.209\include" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils/preprocessor" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega32 -B "C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega32" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Traffic_Light.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega32" -Wl,--relax  
	@echo Finished building target: $@
	"C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Traffic_Light.elf" "Traffic_Light.hex"
	"C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Traffic_Light.elf" "Traffic_Light.eep" || exit 0
	"C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Traffic_Light.elf" > "Traffic_Light.lss"
	"C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Traffic_Light.elf" "Traffic_Light.srec"
	"C:\Apps\Atmel_Studio_7.0.1931_Downloadly.ir\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Traffic_Light.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Traffic_Light.elf" "Traffic_Light.a" "Traffic_Light.hex" "Traffic_Light.lss" "Traffic_Light.eep" "Traffic_Light.map" "Traffic_Light.srec" "Traffic_Light.usersignatures"
	
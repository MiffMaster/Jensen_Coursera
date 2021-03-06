#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Basic makefile for multi target build
#
# Use: make [Build Target] PLATOFRM=[Override] COURSE1=[Overide] \
#                          VERBOSE=[Override]
#
# Build Targets:
#      <FILE>.i - Preprocessed output file
#      <FILE>.o - Builds the <FILE>.o object file
#      <FILE>.asm - Assembly output files
#      build - Builds and links all source files
#      compile-all - Compile without linking
#      clean - Removes all generated files
#
# Overrides (first option is default):
# PLATFORM=HOST - Builds for testing on the host machine
#          MSP432 - Build for the embedded target device
#
# COURSE1=FLASE - Outputs c1m1 deliberable
#         TRUE - Outputs c1m4 deliverable (Course1 final assignment)
#
# VERBOSE=FLASE - Dissable debug output
#         TRUE - Enable debug output
#
#------------------------------------------------------------------------------

PROJECT = c1m4

# Platform Overrides - Defaults to HOST
# If anything other than MSP432, reset to HOST
ifndef PLATFORM
	ifneq ($(PLATFORN),MSP432)
		override PLATFORM = HOST
	endif
endif

# Enable debug output
ifndef VERBOSE
	override VERBOSE = FALSE
endif

# Switch to Coures1 deliverable
ifndef COURSE1
	override COURSE1 = FALSE
endif

include sources.mk
# Pattern matche *.s files in SOURCES and assigns *.o to OBJECTS
OBJECTS = $(SOURCES:.c=.o)

# Platform independent options
LDFLAGS = -Wl,-Map=$(PROJECT).map
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -D$(PLATFORM) $(INCLUDES)

# Compiler flags and defines for MSP432
ifeq ($(PLATFORM),MSP432)
	LDFLAGS := $(LDFLAGS),-T,./msp432p401r.lds
	CFLAGS += -mcpu=cortex-m4 \
	          -march=armv7e-m \
	          -mthumb \
	          -mfpu=fpv4-sp-d16 \
	          -mfloat-abi=hard \
	          --specs=nosys.specs
          
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump

# Compiler flags and defines for HOST
else ifeq ($(PLATFORM),HOST)
	CC = gcc
	SIZE = size
	OBJDUMP = objdump
endif

ifeq ($(COURSE1),TRUE) 
	CPPFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE),TRUE)
	CPPFLAGS += -DVERBOSE
endif

# Build targets
$(PROJECT).asm: $(PROJECT).out
	$(OBJDUMP) -D $(PROJECT).out > $@
	
%.i: %.c
	$(CC) -E $< $(CPPFLAGS) $(CFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

%.o: %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@
	
.PHONY: compile-all
compile-all: $(OBJECTS)

.PHONY: build
build: $(PROJECT).out
	$(SIZE) $(PROJECT).out

$(PROJECT).out : $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f *.asm $(PROJECT).out $(PROJECT).map
	rm -f src/*.i src/*.asm src/*.o


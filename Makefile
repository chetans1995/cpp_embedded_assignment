CC=C:\avr\avr-gcc-15.2.0-x64-windows\bin\avr-g++
LD=C:\avr\avr-gcc-15.2.0-x64-windows\bin\avr-ld
OBJCOPY="C:\avr\avr-gcc-15.2.0-x64-windows\bin\avr-objcopy"
OBJDUMP="C:\avr\avr-gcc-15.2.0-x64-windows\bin\avr-objdump"
AVRSIZE="C:\avr\avr-gcc-15.2.0-x64-windows\bin\avr-size"
OBJISP="C:\avr\avr-gcc-15.2.0-x64-windows\bin\avrdude"
MCU=atmega328p
PROGRAMMER=arduino
BAUDRATE=115200
CFLAGS=-Wall -Wextra  -Wundef -pedantic \
		-Os  -DF_CPU=16000000UL -mmcu=${MCU} -DBAUD=19200
LDFLAGS=-mmcu=$(MCU)
PORT=\\\\.\\COM4
BIN=CuperAdCcreen
OUT=${BIN}.hex
SOURCES = main.cpp src/millis.cpp src/lcd_driver.cpp

DEBUG?=1

ifeq ($(DEBUG), 1)
	OUTPUTDIR=bin/debug
else
	OUTPUTDIR=bin/release
endif

OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.cpp=.o))

all: $(OUTPUTDIR)  $(OUT) 

$(OBJS): Makefile

$(OUTPUTDIR)/%.o:%.cpp
	$(CC) $(CFLAGS) -MD -o $@ -c $<

%.lss: %.elf
	$(OBJDUMP) -h -S -s $< > $@

%.elf: $(OBJS)
	$(CC) -Wl,-Map=$(@:.elf=.map) $(LDFLAGS) -o $@ $^
	$(AVRSIZE) $@


$(OBJS):$(SOURCES)

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .fuse -R .lock -R .user_signatures -R .comment $< $@

isp: ${BIN}.hex
	$(OBJISP) -F -V -c $(PROGRAMMER) -p ${MCU} -P ${PORT} -b $(BAUDRATE) -U flash:w:$<

clean:
	del "$(OUT)"  *.map *.P *.d

$(OUTPUTDIR): 
	@mkdir "$(OUTPUTDIR)"
	@mkdir "bin"
	@mkdir "bin/debug"
	@mkdir "bin/debug/src"
		   	
.PHONY: clean dirs
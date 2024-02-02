#@copyright: Aly Mustafa Enaya
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name =Unit3_lab4_cortexM4

all: $(project_name).bin
	@echo "*** Build is Done ***"
	
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script_cortex_m4.ld  $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf
	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean-all:
	rm *.o *.elf *.bin *.map

clean:
	rm *.elf *.bin *.map
	
	

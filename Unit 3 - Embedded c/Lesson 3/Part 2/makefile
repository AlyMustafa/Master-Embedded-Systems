#@copyright: Aly Mustafa Enaya
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)

project_name =learn_in_depth_cortex_M3
all: $(project_name).bin
	#echo "***Build is Done***"
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@
	
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script_cortex_m3.ld  $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map
	
#startup.o: startup.s
	#$(CC)as.exe $(CFLAGS) $< -o $@
	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean-all:
	rm *.o *.elf *.bin *.map

clean:
	rm *.elf *.bin *.map
	

#@copyright: Aly Mustafa Enaya
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)

project_name =learn-in-depth
#all: $(project_name).bin
	#@echo "***Build is Done***"
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@
	
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerScript.ld  $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map
	
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean-all:
	rm *.o *.elf *.bin *.map

clean:
	rm *.elf *.bin *.map
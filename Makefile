

CC=cc
DEBUG=-g -O0
PRODUCTION=-s -Os
CFLAGS=-std=gnu99 -mtune=i386 -m32 -c $(PRODUCTION) -ffreestanding -nostdlib -Wall
ASM=as
AFLAGS=--32
LINKER = ld
LFLAGS = -T linker.ld -Map kernel.map --gc-sections --oformat elf32-i386 -melf_i386 -o $(OUTPUT)
EMULATOR=qemu-system-i386
EFLAGS=-kernel $(OUTPUT) -net none -s

# Output binary
OUTPUT=kernel.bin

OBJS=src/console.o  \
     src/boot.o     \
     src/kernel.o   \



$(OUTPUT): $(OBJS)
			$(LINKER) $(LFLAGS) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) $*.c -o $*.o

.S.o:
			$(CC) $(CFLAGS) $*.S -o $*.o

clean:
			rm -f -R $(OBJS) $(OUTPUT)

qemu: $(OUTPUT)
			$(EMULATOR) $(EFLAGS)

AS = nasm
CC = gcc
LD = ld
GRUB = grub-mkrescue

CFLAGS = -m32 -ffreestanding -nostdlib -Wall -Wextra
LDFLAGS = -m elf_i386 -T linker.ld -nostdlib

OBJS = boot.o kernel.o

all: os.iso

boot.o: boot.asm
	$(AS) -f elf32 $< -o $@

kernel.o: kernel.c
	$(CC) $(CFLAGS) -c $< -o $@

os.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

os.iso: os.bin
	mkdir -p isodir/boot/grub
	cp os.bin isodir/boot/
	echo 'menuentry "HelloOS" { multiboot /boot/os.bin }' > isodir/boot/grub/grub.cfg
	$(GRUB) -o $@ isodir

clean:
	rm -f *.o os.bin os.iso
	rm -rf isodir

run:
	qemu-system-i386 -cdrom os.iso

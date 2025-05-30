CC = i686-elf-gcc
LD = i686-elf-ld
CFLAGS = -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -nostdlib

all: kernel.bin

kernel.bin: kernel.c linker.ld
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o
	$(LD) $(LDFLAGS) kernel.o -o kernel.bin
	nasm hello.asm -f bin -o hello.bin

iso: kernel.bin
	mkdir -p iso/boot/grub
	mkdir -p iso/boot/grub2

	cp kernel.bin iso/boot/
	cp hello.bin iso/boot/
	cp boot/grub/grub.cfg iso/boot/grub/
	cp boot/grub/grub.cfg iso/boot/grub2/

	grub-mkrescue /usr/lib/grub/i386-pc  -o hello.iso iso

clean:
	rm -rf *.o *.bin iso hello.iso
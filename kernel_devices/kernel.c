// kernel.c - Main kernel code
void kernel_main(void) {
    volatile char *vga = (volatile char*)0xB8000;
    const char *msg = "Hello World from GRUB2!";
    
    for(int i = 0; msg[i]; i++) {
        vga[i*2] = msg[i];       // Character
        vga[i*2 + 1] = 0x0F;     // White on black
    }
    
    while(1); // Halt
}

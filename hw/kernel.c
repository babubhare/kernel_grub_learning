// kernel.c
void kernel_main(void) {
    //clear_screen();
    // const char *str = "Hello, World!";
    // char *video = (char*) 0xb8000;
    // for (int i = 0; str[i] != '\0'; i++) {
    //     video[i * 2] = str[i];
    //     video[i * 2 + 1] = 0x07; // Light grey on black
    // }

    char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]='0x0F';
		i++;
	};

    
}

void k_clear_screen() // clear the entire text screen
{
	
};
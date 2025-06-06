#include "stdarg.h"
#define ATAPI_SECTOR_SIZE 2048

void printf(char *,...); 				//Our printf function
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.
unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, unsigned char _data);
unsigned short inportw(unsigned short _port);
void outportw(unsigned short _port, unsigned short _data);
unsigned long inportl(unsigned short _port);
void outportl(unsigned short _port, unsigned long _data);
void kernel_main();

void sleep(int ms);
void init_acpi();
void poweroff();

// MEMORY
void *malloc(unsigned long size);
void *memset(void *str, int c, int n);
int memcmp( char *str1, char *str2, int n);
void *malloc_align(unsigned long size,unsigned long tag);

// BLOCKDEVICE
//void init_blockdevice();
//void introduceDevice(unsigned char type,unsigned long pointertodevice,unsigned long readsector,unsigned long writesector,unsigned long eject,unsigned long framesize,unsigned char* name);
//void dirdev();

// STRING
void printstring(char* msg);
void putc(char a);
void init_video();
void hexdump(unsigned long msg);
void drawcharraw(unsigned char c, int offsetX, int offsetY, int fgcolor, int bgcolor);
unsigned char getch();

#define VK_UP 0xCB
#define VK_LEFT 0xCC
#define VK_RIGHT 0xCD
#define VK_DOWN 0xCE

typedef struct{
	int mouse_x;
	int mouse_y;
	int mouse_z;
	int mousePressed;
	int keyPressed;
}InputStatus;
InputStatus getInputStatus();

// VIDEO
int init_graph_vga(int width, int height,int chain4);
void cls();
void putpixel(int x,int y, int color);
char getpixel(int x,int y);
int isGraphicsMode();
void addController(unsigned char drawable,unsigned long drawablefunc,unsigned short x,unsigned short y,unsigned short w,unsigned short h,unsigned long value,unsigned long onSelected,unsigned long onFocus,unsigned char controller);
void draw();
unsigned long show();
void message(char *message);
char confirm(char *message);
char *browseDIR(char *path);
char *browse();
void freeGui();

// GDT
void init_gdt();

// IDT
void init_idt();
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void setErrorInt(unsigned char num,unsigned long base);
void setNormalInt(unsigned char num,unsigned long base);

// TIMER MOD
void init_timer();
int getTicks();
void resetTicks();

// PS2
void init_ps2();

// PCI
void init_pci();
unsigned long getBARaddress(int bus,int slot,int function,int barNO);
void init_xhci(unsigned long bus,unsigned long slot,unsigned long function);
void dumpPCI(int bus,int slot,int function);
void memdump(unsigned long location);

// SERIAL
void init_serial();

// IDE
void init_ide(unsigned short BAR);
void init_ide2();
void ahci_init(int bus,int slot,int function);
void uhci_init(int bus,int slot,int function);


typedef struct{

	//
	// Blockdevice settings
	//
	
	unsigned long readRawSector;
	unsigned long writeRawSector;
	unsigned long reinitialise;
	unsigned long eject;
	
	//
	// Filesystem settings
	//
	
	unsigned long dir;
	unsigned long readFile;
	unsigned long writeFile;
	unsigned long existsFile;
	unsigned long newFile;
	unsigned long deleteFile;
	unsigned long renameFile;
	unsigned long copyfile;
	
	//
	// Misc
	//
	
	unsigned char readonly;
	
	//
	// Advanced
	//
	
	unsigned long arg1;	// LINK TO DATAPOINTER
	unsigned long arg2;	// OFFSET DISK
	unsigned long arg3;
	unsigned long arg4;
	unsigned long arg5;	// SIZEOF SECTOR
	unsigned long arg6;
	unsigned long arg7;
	unsigned long arg8;
	unsigned long arg9;
}Device;

Device *getNextFreeDevice();
char* dir(char* path);
char fexists(unsigned char* path);
int fread(char* path,unsigned char* buffer);
int getDeviceCount();
int iself(unsigned char* buffer);
unsigned long loadelf(void * buffer);
void detectFilesystemsOnMBR(Device* dev);
void initialiseExt2(Device* device);
void initialiseFAT(Device* device);

int pow(int base,int exp);

typedef struct{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
}Register;

typedef struct{
	unsigned long bar1;
	unsigned long bar2;
	unsigned long bar3;
	unsigned long bar4;
}TRB;

typedef struct{
	unsigned char drivertype; // 1,2,3
	unsigned char portnumber;
	unsigned long localring;
	unsigned long localringoffset;
	
	int assignedSloth;
	
	unsigned char class;
	unsigned char subclass;
	unsigned char protocol;
	
	unsigned long sendMessage;
}USB_DEVICE;
void init_xhci_hid(USB_DEVICE* device);
unsigned long xhci_get_keyboard();
unsigned char get_xhci_hid_keyboard_input(USB_DEVICE* device,unsigned char wait);
//void dirdev();

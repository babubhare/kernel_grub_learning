; boot.asm - Multiboot-compliant entry point
section .multiboot
align 4
    dd 0x1BADB002        ; Magic number
    dd 0x00000003        ; Flags: ALIGN + MEMINFO
    dd -(0x1BADB002 + 3) ; Checksum

section .text
global _start
extern kernel_main

_start:
    cli
    mov esp, stack_top
    call kernel_main
    hlt

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

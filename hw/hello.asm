global start

section .text
bits 32

start:
    mov word [0xb8000], 0x0748 ; H
    mov word [0xb8002], 0x0765 ; e
    mov word [0xb8004], 0x076c ; l
    mov word [0xb8006], 0x076c ; l
    mov word [0xb8008], 0x076f ; o
    mov word [0xb800a], 0x0720 ;
    mov word [0xb800c], 0x0757 ; W
    mov word [0xb800e], 0x076f ; o
    mov word [0xb8010], 0x0772 ; r
    mov word [0xb8012], 0x076c ; l
    mov word [0xb8014], 0x0764 ; d
    mov word [0xb8016], 0x0721 ; !
    hlt ; Halt CPU
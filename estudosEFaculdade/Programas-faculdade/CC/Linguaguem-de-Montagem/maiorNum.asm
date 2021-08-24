section .data
    x dd 50 ; define double world aguenta - 4 bytes
        ;db - define byte - 1 byte
        ;dw define word - 2 bytes
        ;dq - define quad word - 4 bytes
        ;dt - define ten word  - 10 bytes
    y dd 90
    msg1 db 'X maior que Y'
    tamMsg1 equ $ - msg1
    msg2 db 'Y maior que x'
    tamMsg2 equ $ - msg2
;enddata
section .text
    global _start
        _start:
           mov eax, DWORD [x]
           mov ebx, DWORD [y]
           cmp eax, ebx ; comparação
            jge maior            ;(je =) (jg >) (jge >=) (jl <) (jle <=) (jne !=)
                mov edx, tamMsg2
                mov ecx, msg2
            
            jmp final
        maior: ;metodo
            mov edx, tamMsg1
            mov ecx, msg1        
        final:
            mov ebx, 1
            mov eax, 4
            int 0x80
            mov eax, 1
            int 0x80
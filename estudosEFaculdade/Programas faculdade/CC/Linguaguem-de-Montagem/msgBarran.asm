;seção de declaração das variaveis
section .data
    msg db 'Olá mundo, sem \n'    
    tamMsg equ $ - msg
    msg2 db  'Olá mundo com o \n', 10
    tamMsg2 equ $ - msg2

;endData

section .text
    global _start
        _start:
            mov ecx, msg
            mov edx, tamMsg
            call func_Imprime_Tela
           
            mov ecx, msg2
            mov edx, tamMsg2
            call func_Imprime_Tela 
           ;exit
            mov eax, 1
            mov ebx, 5
            int 0x80
;endText
func_Imprime_Tela:
    mov eax, 4; define para impressão
    mov ebx, 0 ; no caso para tela
    int 0x80
    ret
;endFunc_Imprime_Tela        
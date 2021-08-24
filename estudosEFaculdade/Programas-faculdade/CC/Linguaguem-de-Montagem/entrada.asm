;programa para a entrada de dados
;constantes
SYS_EXIT equ 1
RET_EXIT equ 5
SYS_READ equ 3 ;serviço de leitura
SYS_WRITE equ 4 ; serviço de escrita ou impreção
STD_IN    equ 0 ;parametro de saida
STD_OUT   equ 1
MAX_IN    equ 25
;criação das variaveis
section .data
    msg db 'Entre com seu nome: ' , 0xA, 0xD
    tamMsg equ $ - msg
    msgBemVindo db 'Seja bem vindo, '
    tamMsgBemVindo equ $ - msgBemVindo
;enddata
;declaração  de inicialização de informação vao ser usadas a inda
section .bss
    nome resb 2
;endbss
section .text
    global _start
    _start:
    ; ax(acumulador  para operações numericas) bx( acumulador de registro base) cx(registro de conta com operações string) dx(registro de dados)
    ;saida de dados 
        mov eax, SYS_WRITE
        mov ebx, STD_OUT;tela do computador
        mov ecx, msg
        mov edx, tamMsg
        int 0x80
        ;entrada de dados
        
        mov eax, SYS_READ ; seta para o serviço de leitura do teclado
        mov ebx, STD_IN ; referencia ao teclado
        mov ecx, nome
        mov edx, MAX_IN ; tamanho da string ou seja dos caracteres validos
        int 0x80
        ;imprime o nome  na tela
        mov eax, SYS_WRITE
        mov ebx, STD_OUT
        mov ecx, msgBemVindo
        mov edx, tamMsgBemVindo
        int 0x80
        mov eax, SYS_WRITE
        mov ebx, STD_OUT
        mov ecx, nome
        mov edx, MAX_IN
        int 0x80 


    exit:
        mov eax, SYS_EXIT;função exit em c
        mov ebx, RET_EXIT ; correspondente a xor ebx, ebx
        int 0x80
        
;endtext
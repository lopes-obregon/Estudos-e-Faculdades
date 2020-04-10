section .data
    tit db '|Calculadora|', 10 ; cada 10 é um salto de linha e 0 dizendo que esta finalizando a string
    tamTit equ $ - tit
    traco db '-------------',10
    tamTraco equ $ - traco
    ;mesangems de opção
        obValor db 'valor 1: ', 10
        tamObValor  equ $ - obValor
        obValor2 db 'valor 2: ', 10
        tamObValor2 equ $ - obValor2
        msgOpc db 'Deseja Realizar?', 10
        tamMsgOpc equ $ - msgOpc
        msgErro db 'opção invalida!', 10
        tamMsgErro equ $ - msgErro

    ;end_mensaguem
    ;opções
        op1 db  '1 - adicionar ', 0
        tamOp1 equ $ - op1
        op2 db  '2- subtrair ', 0
        tamOp2 equ $ - op2
        op3 db '3- multiplicar ', 0
        tamOp3 equ $ - op3
        op4 db '4- dividir', 10
        tamOp4 equ $ - op4
    ;endOpções
    msgResultado db 'Resultado é: ',10
    tamMsgResultado equ $ - msgResultado

;enddata
;variaveis que podem ser trocadas de valor
section .bss
    opc     resb 2
    num1    resb 10
    num2    resb 10
    result  resb 10
    buffer: resb 10
;end bss
section .text
    global _start
        _start:
        ;;start calculadora
            mov eax, 4
            mov ebx, 1
            mov ecx, traco
            mov edx, tamTraco
            int 0x80
            
            mov eax, 4
            mov ebx, 1
            mov ecx, tit
            mov edx, tamTit
            int 0x80

            mov eax, 4
            mov ebx, 1
            mov ecx, traco
            mov edx,tamTraco
            int 0x80

            mov eax, 4
            mov ebx, 1
            mov ecx, obValor
            mov edx, tamObValor
            int 0x80

            mov eax, 4
            mov ebx, 1
            mov ecx, obValor2
            mov edx, tamObValor2

            ;opções
        ;end calculadora
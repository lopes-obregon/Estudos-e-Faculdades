global question
;eax é a saida para o c
segment .text
    question:
        mov ebx, edi ; edi por onde recebe o valor
        jmp _testar
        ret ; para poder retornar

_testar:
    cmp ebx, 0
    je _par
    jl _impar
    sub ebx, 2 ;subtraia
    jmp _testar
_par:
    mov eax, 1
    ret
_impar:
    mov eax, 0
    ret
;endText
;função de salto
;jump -> jmp incondicional
;saltos condicionais
;cmp a,b
;je  a ==  b
;jne a != b
;jg a > b
;jge a >= b
;jl a < b
; jle a <= b 
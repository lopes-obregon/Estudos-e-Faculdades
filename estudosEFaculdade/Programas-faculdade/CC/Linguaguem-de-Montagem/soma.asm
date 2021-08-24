;programa que pega o valor da variavel e acresenta mais um
section .data
    v1 dw '100'
section .bss
    buffer: resb 10
;enddata

section .text
    global _start
        _start:
            call converter_valor    
            mov ecx, v1
            call mostrar_valor ; call chama a função
           
        _final:
            mov eax, 1
            mov ebx, 0
            int 0x80
;incrementa com +1
converter_valor:
    lea esi, [v1]
    mov ecx, 3
    call string_to_int
    add eax, 1 ;add adiciona o elemento a variavel
    ret ; retorna para o start
mostrar_valor:
    lea esi, [buffer]
    call int_to_string ; chama a string
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, 10
    int 0x80
    ret
;converte uma string para inteiro
; esi(ponteiro da string que precisa converter) ecx(sera o numero de digitios que essa string tem)
;saida: eax com o valor
string_to_int:
    xor ebx, ebx
    .prox_digito:
        movzx eax, byte[esi]
        inc esi
        sub al, '0'
        imul ebx, 10 ; multiplica ebx em 10
        add ebx, eax ; ebx = ebx*10 +eax
        loop .prox_digito ;while( -- ecx)
        mov eax, ebx
        ret
;converter inteiro para string
;entrada eax esi(ponteirto para onde vai amarzenar a string resultante)
; saida eax
int_to_string:
    add esi, 9
    mov byte [esi], 0
    mov ebx, 10
    .prox_digito:
        xor edx, edx ;para limpar o edx
        div ebx
        add dl , '0'
        dec esi
        mov [esi], dl
        test eax, eax ; testamos se contem
        jnz .prox_digito ;saltamos para proximo digito jnz(pule até ser zero) até eax ser == 0
        mov eax, esi
        ret
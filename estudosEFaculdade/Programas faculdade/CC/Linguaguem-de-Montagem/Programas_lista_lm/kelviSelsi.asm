;programa que converte os graus de celsius para kelvin
section .data
    celsius dw 25, 80, 115, 15
    kelvin dw 0, 0, 0, 0

section .text
    global _start
        _start:
           lea rbx, [celsius]
            mov rcx, 4
            xor rcx, rcx ; limpando os dados do rcx
            loop4:
                xor rax, rax
                mov ax, [rbx + rcx]; ax = celcius[rcx]
                add ax, 273
                ;salvando na pilha
                push rbx
                call troca_valor
                push rcx
                ; pega os valores salvos da pilha e devolve pro regirstrador
                pop rcx
                pop rbx
                add rcx, 2 ; adiciona dois porque estamos andando em dois bytes
                cmp rcx, 8; compara rcx com oito pq é o numero maximo de bytes ou seja o tamanho maximo dos bytes
                jl loop4
            exit:
                mov eax, 1
                mov ebx, 0
                int 0x80
; salva o valor convertido para o vetor em questão
troca_valor:
    lea rbx, [kelvin]; lendo para rbx o endereço da variavel kelvin
    mov [rbx + rcx], ax ; jogando para kelvin[rcx] = ax
    int 0x80
    ret
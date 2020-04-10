;inverter a sequencia  da primeira tabela. adicionar 12 na segunda tabela e copiar  a mesma (depois da soma)
section .data 
    table dw 36, 255, 78, 118, 250, 28
    ;table db 24, FF, 4E, 76, FA, 1C em exa
    ;table dw 28, 250, 118, 78, 255, 36 
    table2 dw 172, 41, 62, 18, 224, 169
    ;table2 db AC, 29, 3E, 12, E0, A9 hexa
   aux_table times 6 dw 0
;endSection
section .text
    global _start
        _start:
        ;segunda tabela salva na pilha e adicona 12 nela 
            lea rbx, [table2]  
            mov rcx, 6
            xor rcx, rcx     
            loop4:
                xor rax, rax; limpa o rax para não pegar sujeira
                mov ax, [rbx + rcx] ; ax = table2[rcx]
                add ax, 12 ; adiciona 12 no ax
                ;movendo o valor de volta pra table 2
                push rax
                push rcx
                push rbx
                mov [rbx + rcx], ax
                add rcx, 2; 1 byte que seria 8 bits porque estamos utilizando o tipo db
                cmp rcx,12; no caso os byte
                jl loop4
                lea rbx, [table]
                mov rcx, 6
                mov rax, 0
                add rcx, 4
                ;troca o valor da variavel
               inverter_valor:
                    mov ax, [rbx + rcx]; rsi = table[rcx]
                    push rcx
                    push rbx
                    push ax
                    mov rax, 10
                    sub rax, rcx
                    mov rcx, rax
                    lea rbx, [aux_table]
                    pop ax; carregando o ultimo valor lido
                    mov [rbx + rcx], ax; aux_table[rcx] = ax
                    pop rbx
                    pop rcx
                    sub rcx, 2
                cmp rcx,0
                jge inverter_valor
                xor ax,ax
                xor rbx, rbx
                xor rcx, rcx
                ;troca de valores de aux para table
                lea rbx, [aux_table]
                mov rcx, 6
                xor rcx, rcx
                troca_valor_invertido:
                    mov ax, [rbx + rcx]
                    push rbx
                    lea rbx, [table]
                    mov [rbx + rcx], ax;table[rcx] = ax
                    pop rbx
                    add rcx, 2
                cmp rcx,12
                jl troca_valor_invertido
        ;fim do procedimento
            exit:
                mov eax, 1
                mov ebx, 0
                int 0x80
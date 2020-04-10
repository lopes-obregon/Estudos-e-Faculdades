section .data
    fmtDec db "%d", 10,0
    fmtStr db  "%s", 10, 0
    msgResult db "Resultado: ", 10, 0
   celsius dw 25, 80, 115, 15
   kelvin times 4 dw 0
    extern printf
   section .text
        global _start
            _start:
            lea rbx, [celsius]
            mov rcx, 4
            push rbp
            mov rdi, fmtStr
            mov rsi, msgResult
            pop rbp
            xor rcx, rcx; indice que seja paraceido com o i das linguaguem de alto nilvel
            loop4:
                xor rax, rax; zera para evitar pegar lixo
                mov ax, [rbx+rcx] ; ax = celsius [rcx] rcx no indice
                add ax, 273
                ;salvando na pilha
                push rax
                push rbx
                push rcx
                ;endPilha
                mov rdi, fmtDec
                mov rsi, rax
                call printf
                ;apagando do topo da pilha
                pop rcx
                pop rbx
                pop rax
                add rcx, 2; indice dois porque está acessando de dois em dois bytes
                cmp rcx ,8
                jl loop4
            mov rax, 1
            mov rbx, 0
            int 0x80
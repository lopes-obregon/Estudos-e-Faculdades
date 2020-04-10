section .data
    filename db 'hello.txt',0
    write_file db 'Hello World',10
    tamWrite_file equ $ - write_file
    msg_done db "arquivo gravado com sucesso", 10, 0
    tamMsg_done equ $ - msg_done
;endData

section .bss
    fd resb 1
    bret resb 1
    buffleitura resb 2
    tam resb 2
    info resb 2
;endBss

section .text
    global _start
        _start:
            ;cria o arquivo
           call creat_file 
            mov [fd], eax
            ;escreve no arquivo
            call write_in_file
            ;msg de sucesso de gravação
            mov ecx, msg_done
            mov edx, tamMsg_done
            call print
            ;abrindo para a leitura
            call open_file_read
            mov [fd], eax
            ;ler do arquivo
           call read_file
           ;fechando o arquivo
            call close_file
            ;imprimindo a informação
            mov ecx, info
            mov edx, tamMsg_done
            call print
            exit:
                mov eax, 1
                mov ebx, 0
                int 80h
;endText
;metodo que cria o arquivo
creat_file:
    mov eax, 8 ; cria o arquivo segundo a system call
    mov ebx, filename
    mov ecx, 0777
    int 0x80
    ret  
;end Creat_file
close_file:
    mov eax,6 ; fecha o arquivo segundo a sustem call
    mov ebx, [fd]
    int 0x80
    ret
;escrevendo no arquivo
 write_in_file:
    mov edx, tamWrite_file
    mov ecx, write_file
    mov ebx, [fd]
    mov eax, 4
    int 0x80
    ret
print:
    mov eax, 4
    mov ebx, 1
    int 0x80
    ret
    
    
    ;abrindo o arquivo para a leitura
open_file_read:
    mov eax , 5 ; abrindo o arquivo
    mov ebx, filename; indicando qual arquivo abrir
    mov ecx, 0 ; para acessar somenta a leitura
    mov edx, 0777
    int 0x80
    ret
    
    ; ler do arquivo
read_file:
    mov eax, 3
    mov ebx, [fd]
    mov ecx, info
    mov edx, tamWrite_file
    int 0x80
    ret
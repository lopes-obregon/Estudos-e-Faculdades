;programa que escreve hello world em um arquivo txt
section .data
    nomeArquivo db 'teste.txt',0
    file db 0 ;definindo um descritor
    msgErro db 'Erro na abertura do arquivo',10,13
    tamMsgErro equ $ - msgErro
;endData
section .text
    global _start
        _start:
            ;file = open(nomeArquivo, Read,0)
          mov eax, 5 ;seta para o serviço de  abrir arquivo
          mov ebx, nomeArquivo
          mov ecx, 2 ; oque vai escrever no arquivo
          mov edx, 0
          int 0x80
          cmp eax, -1
          je deuErrado;salta para  o metodo deuErrado se eax == -1
          mov [file], eax ;salva em uma variável file(existe outras maneiras)
          deuErrado:
            mov eax, 4
            mov ebx, 1
            mov ecx, msgErro
            mov edx, tamMsgErro
            int 0x80

            ;exit(1)
            mov eax,1
            mov ebx, 0 
            int 0x80
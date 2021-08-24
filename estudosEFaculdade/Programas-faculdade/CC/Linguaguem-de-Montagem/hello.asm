section .data ; variaveis
    hello db 'Hello World!', 10, 13 ;definindo uma string "hello World \n";
    tamanhoString equ $ - hello ;constante com  o tamanho da string hello
;enddata
section .text: ;segmento ou seção de codigo seria main ou manos a main em c;
    global _start ;difine o inicio do código ou a label start;
    _start: ; inicio ou a label
    mov eax, 4 ;seta para o modo de impressão
    mov ebx, 1 ;seta para a impressão para a tela do computador
    mov ecx, hello ;indica que irá imprimir o conteudo de hello
    mov edx, tamanhoString ; define o numero de carateres a serem imprimidos apartir do inicio de hello
    int 0x80 ; realiza a interrupção
    mov eax, 1 ; seta o serviço 1 ou a função exit
    mov ebx, 0 ; passa o parâmetro 0 (exit(0) em c)
    int 0x80 ; endereço kernel
;endtext
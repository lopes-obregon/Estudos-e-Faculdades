#include <stdio.h>
#include <stdlib.h>
typedef struct{
   char nome_peca[30];
   int num_peca;
   float preco;
   int quantia;
   int pedido;
}Estoque;
typedef struct{
    char rua[25];
    char cidade[20];
    char estado[2];
    char cep[8];
}Endereco;
typedef struct{
    char nome[15];
    char sobrenome[15];
    Endereco end_resid;
}Aluno;
int main()
{
    printf("Hello world!\n");
    return 0;
}

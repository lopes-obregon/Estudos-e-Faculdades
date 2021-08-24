//programa que le  um nome e impreime as 4 letras do nome
#include <stdio.h>

int main(){
    char nome[10];
    int i;
    printf("Informe o seu nome: ");
    scanf("%s", nome);
    printf("As 4 letras do seu nome é\n");
    for( i = 0; i < 4; i++){
        printf("%c", nome[i]);
    }
    printf("\n");
    return 0;
}
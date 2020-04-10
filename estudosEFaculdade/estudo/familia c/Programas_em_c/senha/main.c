#include <stdio.h>
#include <stdlib.h>
void verifica_senha(int a, int b, int c);
int main()
{
    int a,b,c;
    printf("Informe a senha: \n");
    scanf("%d %d %d",&a, &b, &c);
    verifica_senha(a,b,c);

    return 0;
}
//função que verifica a senha
void verifica_senha(int a, int b, int c){
    if(a == 2 && b == 3 && c  == 4){
        printf("Senha correta \n");
    }else{
        printf("Senha errada");
    }
}

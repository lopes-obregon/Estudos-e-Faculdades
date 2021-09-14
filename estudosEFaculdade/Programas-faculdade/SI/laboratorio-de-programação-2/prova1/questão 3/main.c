#include<stdio.h>
//protótipos
int somaPorValor(int n , int soma);
void somaPorReferencia(int *n, int *soma);
//main
int main(int argc, char const *argv[])
{
    int n, soma = 0;
    scanf("%d", &n);
    //passagem por valor
    printf("A soma dos %d primeiros numeros e: %d\n", n, somaPorValor(n, soma));
    somaPorReferencia(&n, &soma);
    printf("A soma dos %d primeiros numeros e: %d\n", n, soma);
    return 0;
}
//passagem por valor
int somaPorValor(int n , int soma){
    while(n > 0){
        soma = soma + n;
        n -= 1;
    }
    return soma;
    
}
void somaPorReferencia(int *n, int *soma){
    while ( *n > 0)
    {
       *soma = *soma + *n;
       *n -= 1;
    }
    
}
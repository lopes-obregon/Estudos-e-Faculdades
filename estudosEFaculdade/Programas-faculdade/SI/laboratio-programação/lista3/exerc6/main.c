//programa que converte Fahrenheits em  celsius
#include <stdio.h>
int main(){
    float tc = 0, tf = 0;
    printf("Informe a temperatuda em Fahrenheits: ");
    scanf("%f", &tf);
    tc = (tf - 32)/1.8;
    printf("Temperatura em Celsius eh:%.2f°\n", tc);
    return 0;
}
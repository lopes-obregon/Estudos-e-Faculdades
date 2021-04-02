//programa que calcula quantos elementos para produzir um latão
#include <stdio.h>
int main(){
    float cobre = 0, zinco = 0, kiloLatao = 0;
    printf("%s: ","Informe a quantidade de kilos para calcular");
    scanf("%f", &kiloLatao);
    //somando as partes se dá 10 po isso divide ele em dez partes
    kiloLatao = kiloLatao/10;
    //sete partes de cobre multiplica para obter o resultado
    cobre = kiloLatao * 7;
    //três partes de zinco restante para enterar os dez partes divididas;
    zinco = kiloLatao * 3;
    //se obtem o latão divido em 10 partes
    printf("Sao necessario %.1f Quilos de cobre e %.1f Quilos de zinco\n", cobre, zinco);
    return 0;
}
//programa que calcula uma diaria e retorna o valor pago da diaria
#include <stdio.h>
#define DIARIA 20.00;
int main(){
    //variavel curta  para armezar dias trabalhando não negativos
    unsigned short int diaTrabalahdo = 0;
    float total = 0; 
    printf("informe os dias trabalhados: ");
    scanf("%d", &diaTrabalahdo);
    total = diaTrabalahdo * DIARIA
    printf("valor pago sem desconto:%.2f\n valor pago com desconto: %.2f\n", total, total -(total * 0.08));
    return 0;
}
/*Programa que mosta que 1-se ano for bissexto ou 0 para não*/
#include <stdio.h>
int main(){
    //ano não é negativo com range de 0 até 65.535
    unsigned short int ano;
    printf("Informe o ano que deseja descobrir: ");
    scanf("%d", &ano);
    printf("O ano %d  eh %d\n", ano, ((ano % 4 == 0 && ano % 100 != 0 ) || (ano % 400 == 0) ));
    return 0;
}
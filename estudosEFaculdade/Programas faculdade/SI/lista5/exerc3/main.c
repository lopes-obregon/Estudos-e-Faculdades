#include <stdio.h>

/*Calcula a quantidade de kilometros/litro*/
int main(){
    unsigned short int carroA, carroB, carroC;
    printf("Informe o km rodado dos carros: ");
    scanf("%d%d%d", &carroA, &carroB, &carroC);
    carroA /=12;
    carroB /= 9;
    carroC /= 8;
    printf("Consumo de combustivel dos carros é\n A:%d\nB:%d\nC:%d\n", carroA, carroB, carroC);
    return 0;
}
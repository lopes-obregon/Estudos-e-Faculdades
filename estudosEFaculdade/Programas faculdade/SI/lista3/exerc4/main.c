//programa que calcula e imprime o sorteio
#include <stdio.h>
int main(){
    float premio = 780000;
    float ponto1 = 0, ponto2 = 0, ponto3 = 0;
    printf("Informe os pontos: ");
    scanf("%f%f%f",&ponto1, &ponto2, &ponto3);
    ponto1 =  (premio)/(ponto1 + ponto2 + ponto3);
    ponto2  = ponto1;
    ponto3 = ponto1;
    printf("Premio do 1:%.2f  2:%.2f  3:%.2f   \n", ponto1, ponto2, ponto3
     );
    return 0;
}
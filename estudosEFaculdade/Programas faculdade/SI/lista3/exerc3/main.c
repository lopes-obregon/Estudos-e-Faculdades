#include <stdio.h>
//programa que calcula volume do cilindro
int main(){
    float vol = 0, raio, altura;
    printf("informe o raio e altura: ");
    scanf("%f%f",&raio, &altura);
    vol = 3.141592 * raio * raio * altura;
    printf("Volume do cilindro eh: %f", vol);
    return 0;
}
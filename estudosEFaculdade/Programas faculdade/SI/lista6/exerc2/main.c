/*programa que inverte um numero*/
#include<stdio.h>

int main(){
    int numero, invertido = 0;
    printf("Informe o numero que deseja inverter: ");
    scanf("%d", &numero);

//     invertido = 0
// resto de 23 por 10 == 3
// invertido = 10 * inv + 3 == 3
// dividimos 23 por 10 == 2
// repetimos:
// inv = 10 * inv + 2 % 10 == 10 * 3 + 2 == 32
    while (numero > 0)
    {
        /* code */
        invertido  = 10 * invertido + numero % 10;
        numero /= 10;
    }
    printf("invertido : %d\n", invertido);
    return 0;
}
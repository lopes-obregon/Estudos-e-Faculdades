#include <stdio.h>
#include <stdint.h>
/*programa que retorna qual semana é*/
int main(){
    int dia;
    printf("Informe o dia ");
    scanf("%d", &dia);
    switch (dia)
    {
    case 1:
        printf("Segunda");
        break;
    
    case 2:
    printf("Terça");
    break;
    case 3:
        printf("Quarta");
        break;
    case 4:
        printf("Quinta");
        break;
    case 5:
        printf("Sexta");
        break;
    case 6:
        printf("Sabado");
        break;
    default:
        printf("Domingo");
        break;
    }
    return 0;   
}
    
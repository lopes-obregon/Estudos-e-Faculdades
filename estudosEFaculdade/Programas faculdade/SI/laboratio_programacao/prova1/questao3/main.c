/*Faça um programa que receba o salário inicial de 
um funcionário, calcule e mostre o novo salário, acrescido de bonificação e de auxílio escola.*/
#include <stdio.h>

int main(){
    float salarioInicial, bonus, salarioFinal;
    printf("Informe o salario inicial R$:");
    scanf("%f", &salarioInicial);
    //bonificação
    if(salarioInicial <= 500)
        bonus = (float)((salarioInicial/100)*5);
    else if(salarioInicial > 500 && salarioInicial <= 1200)
        bonus = (float)((salarioInicial/100)*12);
    else
        printf("Sem Bonus");
    //bonificação de escola
    if(salarioInicial <= 600)
        bonus += 150;
    else
        bonus += 100;
    
    salarioFinal = salarioInicial + bonus;
    printf("Salario final R$:%.2f\n", salarioFinal);
    return 0;
}
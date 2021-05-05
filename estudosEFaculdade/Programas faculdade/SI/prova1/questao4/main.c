/*Uma agência bancária possui dois tipos de investimentos, conforme o quadro a seguir. 
Faça um programa que receba o tipo de investimento e seu valor, calcule e mostre 
o valor corrigido após um mês de investimento, de acordo com o tipo de investimento.*/
#include <stdio.h>

int main(){
    unsigned short int op;
    float valor;
    printf("Informe o tipo de investimento\n 1-Poupança\t2-fundos de renda fixa\nop:");
    scanf("%hd", &op);
    printf("Informe a quantidade a investir R$:");
    scanf("%f", &valor);
    if(op == 1)
        valor +=(float)(valor/100)*3;
    else
         valor +=(float)(valor/100)*4;

    printf("Rendimento do mes R$:%.2f\n", valor);
    return 0;
}
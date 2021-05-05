/*Partes para fazer:
*receber salario minimo
*o numero de  horas trabalhadas
*o número de dependentes do funcionário
*quantidade de horas extras trabalhadas.
**/
#include <stdio.h>

int main(){
    float salarioMinimo, valorHora, salarioMes, valorDependente, valorHoraExtra, salarioBrutoMes, salarioLiquido;
    unsigned short int horaTrabalhada;
    unsigned short int dependentes;
    unsigned short int horasTrabalhadasExtra;

    printf("Informe o salario minimo R$ ");
    scanf("%d", &salarioMinimo);
    printf("Informe horas trabalhadas:  ");
    scanf("%d", &horaTrabalhada);
    printf("Informe o numero de dependentes ");
    scanf("%d", &dependentes);
    printf("Informe a quantidade de horas extra trabalhadas ");
    scanf("%d", &horasTrabalhadasExtra);
    //O valor da hora trabalhada é igual a 1/5 do salário mínimo.
    valorHora = salarioMinimo/5;
    //O salário do mês é igual ao número de horas trabalhadas  multiplicado pelo valor da hora trabalhada.
    salarioMes = salarioMinimo * valorHora;
    //Para cada dependente, acrescente R$ 32,00.
    valorDependente = 32 * dependentes;
    //Para cada hora extra trabalhada, calcular o valor da hora trabalhada acrescida de 50%.
    valorHoraExtra = (horasTrabalhadasExtra) * (valorHora/2);
    //salario mes bruto
    salarioBrutoMes = (float)(salarioMes + valorDependente + valorHoraExtra);
   //desconto do IRPF
    if(salarioBrutoMes  < 200.0){
        printf("Insento de imposto IRPF\n");
    }else{
        if(salarioBrutoMes >= 200.0 || salarioBrutoMes <= 500){
            salarioLiquido = (float)(salarioBrutoMes - ((salarioBrutoMes/100)*10));
        }else{
            if(salarioBrutoMes > 500){
                salarioLiquido = (float)(salarioBrutoMes - ((salarioBrutoMes/100)*20));
            }
        }
    }
    //salario liquido com gratificação
    //usando a variavel salario mes para reaproveitar o espaço ja usado
    if(salarioLiquido <= 350){
        salarioMes = salarioLiquido + 100;
    }else{
        salarioMes = salarioLiquido + 50;
    }

    printf("Salario a receber R$:%.2f\n", salarioMes);
    return 0;
}
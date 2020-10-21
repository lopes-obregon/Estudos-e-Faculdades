#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//programa que calcula a nraiz
//prototipos das funções
void func_calc_fatora(double p, int n);
//funão principal
int main()
{
    double p;
    int n;
    printf("Entre com o valor de P!\n");
    scanf("%lf",&p);
    printf("Informe o N!\n");
    scanf("%d",  &n);
    func_calc_fatora(p,n);
    return 0;
}
//função que calcula a fatoração
void func_calc_fatora(double p, int n){
    //derivada de x^n é n*x^n-1

    double xn = 1;
    double xn_mais_um;
    int n1 = n-1;
    int conta_interacoes = 1; // variavel que conta a quantidade de interações
    double aux[2];
    aux[0] = 1;
    if(p == 0){
        xn = 1;
    }else{
        while(aux[0] != aux[1]){
            xn_mais_um =(1.0/n)*(((n1)*xn) + (p/pow(xn,n1)));
            aux[0] = aux[1];
            aux[1] = xn_mais_um;
            xn = xn_mais_um;
            conta_interacoes +=1;

        }
    }
    printf("O numero de interações %d, o valor da raiz %.9lf\n",conta_interacoes,xn);
}
/*Se você é salvo por Jesus, você é vitorioso! Nos dias bons e nos dias ruins, você tem Jesus do seu lado, lhe ajudando e fortalecendo. Por isso, não desista! Você pode vencer os obstáculos e viver uma vida vitoriosa, centrada em Jesus. Ele é sua força em todo tempo*/

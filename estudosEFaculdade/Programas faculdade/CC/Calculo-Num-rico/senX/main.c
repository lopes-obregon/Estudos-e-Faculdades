#include <stdio.h>
#include <math.h>
/*entrada x: com o valor da quantidade de expressão*/
/*palavra do dia:
*Sexta, 22 de Março de 2019
*Você estaria pronto para se encontrar cara a cara com Deus amanhã? A Bíblia diz que,
*se você se arrepende de seus pecados e dedica sua vida a seguir Jesus,
*não há razão para ter medo! Na hora de prestar contas,
*Jesus purifica todos que foram fiéis a ele. Por isso, conserta-se com Deus hoje, enquanto ainda tem tempo.
*Viva para Jesus e receba a esperança do Céu!*/
/*constantes*/
#define PI 3.141592654
/*declarações das funções*/
long int fatorial(long int n);
long double senx(long double x, int inicio, int fim, long double valor,   int index);
int main(){
    long double angolo;
    int quanTermo;
    double angoloD;
    printf("Informe o angolo: ");
    scanf("%lf",&angoloD);
    printf("informe a quantidade de termos: ");
    scanf("%d",&quanTermo);
    /*resultado da operação*/
    angolo = angoloD;
    angolo = (angolo * PI)/180; /*converte em radianos*/
    printf("Resultado : %Lf\n", senx(angolo, 1, quanTermo, angolo, 3));
    return 0;
}
/*função que calcula o fatorial*/
long int fatorial(long int n){
    if(n == 1){
        return 1;
    }else{
        return n * fatorial(n - 1);
    }
}
/*função que calcula o */
long double senx(long double x, int inicio, int fim, long double valor,   int index){
    if(fim == 0 || inicio == fim){
        return valor;
    }else{
        if(inicio % 2 == 0){
            valor += (pow(x, index)/fatorial(index));
             return senx(x, inicio + 1, fim, valor, index + 2);

        }else{
            valor -= pow(x, index)/fatorial(index);
             return senx(x, inicio + 1, fim, valor, index + 2);
        }
    }



    /*if(fim == 0){
        return x;
    }else{
        if(inicio == fim){
            return valor;
        }else{
            if(inicio % 2 != 0){
                valor -= (pow(x, index)/fatorial(index));
                return senx(x, inicio + 1, fim, valor, index + 2);
            }else{
                valor +=(pow(x,index)/fatorial(index));
                return senx(x, inicio + 1, fim, valor, index + 2);
            }
        }
    }*/
}

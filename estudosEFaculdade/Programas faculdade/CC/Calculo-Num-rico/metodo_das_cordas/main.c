#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 2.7182818284590452354
void calculaFx5c(double a, double b, double *f, double *f2);
double encontraPivo(double *vet, double *vetb, double a, double b);
double func5c(double x);
double funcModulo(double *vet);
void func5cMain(double pivo, double *xn, double a, double b, double pivoa, double pivob, double modulo, double erro);
void func5cMain(double pivo, double *xn, double a, double b, double pivoa, double pivob, double modulo, double erro);
void calculaFx5b(double a, double b, double *f, double *f2);
double func5b(double x);
int main()
{
    double  erro, intervaloa, intervalob, pivoa, modulo, pivob, pivo;
    double f[2];
    double f2[2];
    double xn[2];
    printf("Informe o erro!\n");
    scanf("%lf", &erro);
    printf("Informe os intervalos!\n");
    scanf("%lf %lf", &intervaloa, &intervalob);
    calculaFx5c(intervaloa, intervalob, f, f2);
    pivo = encontraPivo(f, f2, intervaloa, intervalob);
    func5cMain(pivo, xn, intervaloa, intervalob, pivoa, pivob, modulo, erro);
    return 0;
}
//função que calcula as funções
void calculaFx5c(double a, double b, double *f, double *f2){
    f[0] = 2*cos(a) - pow(e,a);
    f[1] = 2*cos(b) - pow(e,b);
    f2[0] = -2*cos(a)-pow(e,a);
    f2[0] = -2*cos(b)-pow(e,b);
}
//função que encontra o pivo
double encontraPivo(double *vet, double *vetb, double a, double b){
    double aux;
    for(int i = 0; i < 2; i++){
        if(vet[i]*vetb[i] > 0){
            // esse é o pivo
            if(i == 0){
                aux = a;
            }else{
                aux = b;
            }
        }
    }
    return aux;
}
// função para ser armazenada no xn
double func5c(double x){
    return 2*cos(x) - pow(e,x);
}
//função para retornar o valor em módulo
double funcModulo(double *vet){
    double aux;

    aux = vet[1] - vet[0];
    if(aux < 0){
        aux = aux * -1;
    }
    return aux;
}
//funcção 5cmain
void func5cMain(double pivo, double *xn, double a, double b, double pivoa, double pivob, double modulo, double erro){
     xn[0] = pivo;
    pivoa = a;
    pivob = b;

    do{
        xn[1] = (pivoa*func5c(pivob) - pivob*func5c(pivoa))/(func5c(pivob) - func5c(pivoa));
        modulo = funcModulo(xn);
        xn[0] = xn[1];
        //parte da troca de valores no caso onde se mantem  o fixo
        if(pivo == a){
            pivoa = a;
        }else{
            if(pivo == b){
                pivob = b;
            }
        }
    }while(modulo > erro);
}
//funções da cinco b
void func5bMain(double pivo, double *xn, double a, double b, double pivoa, double pivob, double modulo, double erro){
    double intervaloa, intervalob;
    double f[2];
    double f2[2];
    printf("Digite o valor do intervalo para a nova função a ser calculada\n");
    scanf("%lf %lf", &intervaloa, &intervalob);
    printf("Informe os intervalos!\n");
    scanf("%lf %lf", &intervaloa, &intervalob);
    calculaFx5b(intervaloa, intervalob, f, f2);
    pivo = encontraPivo(f, f2, intervaloa, intervalob);
    xn[0] = pivo;
    pivoa = intervaloa;
    pivob = intervalob;
        do{
            xn[1] = (pivoa*func5b(pivob) - pivob*func5b(pivoa))/(func5b(pivob) - func5b(pivoa));
            modulo = funcModulo(xn);
            xn[0] = xn[1];
            //parte da troca de valores no caso onde se mantem  o fixo
            if(pivo == intervaloa){
                pivoa = intervaloa;
            }else{
                if(pivo == intervalob){
                    pivob = intervalob;
                }
            }
        }while(modulo > erro);
        printf("resultado: ",xn[1]);
}
//calculaFx5b
void calculaFx5b(double a, double b, double *f, double *f2){
    f[0] = a*pow(e,a) -1.2;
    f[1] = b*pow(e,b) -1.2;
    f2[0] = pow(e,a)*a+2*pow(e,a);
    f2[1] = pow(e,b)*b+2*pow(e,b);
}
double func5b(double x){
    return x*pow(e,x)-1.2;
}

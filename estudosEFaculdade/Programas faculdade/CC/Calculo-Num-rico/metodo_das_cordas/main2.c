#include <stdio.h>
#include <math.h>
#define e 2.7182818284590452354
void calculaFx5c(double a, double b, double *f, double *f2);
double encontraPivo(double *vet, double *vetb, double a, double b);
double func5c(double x);
double funcModulo(double *vet);
void func5cMain(double pivo, double *xn, double a, double b, double pivoa, double pivob, double modulo, double erro);

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
    f[0] = (a * pow(e, a)) - a - 3;
    f[1] = (b * pow(e, b)) - b - 3;
    f2[0] = pow(e, a) * (a + 2);
    f2[1] = pow(e, b) * (b + 2);
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
double func5c(double x) {
    return ((x * pow(e, x)) - x - 3);
}
//função para retornar o valor em módulo
double funcModulo(double *vet){
    double aux;

    aux = fabs(vet[1] - vet[0]);

    return aux;
}
//funcção 5cmain
void func5cMain(double pivo, double *xn, double a, double b, double pivoa, double pivob, double modulo, double erro){
    xn[0] = pivo;
    int n = 0;
    pivoa = a;
    pivob = b;

    do{
        xn[1] = (pivoa*func5c(pivob) - pivob*func5c(pivoa))/(func5c(pivob) - func5c(pivoa));
        modulo = funcModulo(xn);
        xn[0] = xn[1];
        printf("\nn = %d:\n a = %.6lf b = %.6lf\n x(%d) = %.6lf\n erro = %.6lf\n", n, pivoa, pivob, n, xn[0], modulo);
        //parte da troca de valores no caso onde se mantem  o fixo
        if(pivo == a){
            pivoa = xn[0];
        }else{
            if(pivo == b){
                pivob = xn[0];
            }
        }
        n++;
    }while(modulo > erro);
}

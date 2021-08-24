#include <stdio.h>
#include <math.h>
#include <time.h>
//entrada x: com o valor da quantidade de expressão
/*palavra do dia: 
Sexta, 22 de Março de 2019

Você estaria pronto para se encontrar cara a cara com Deus amanhã? A Bíblia diz que, 
se você se arrepende de seus pecados e dedica sua vida a seguir Jesus, 
não há razão para ter medo! Na hora de prestar contas, 
Jesus purifica todos que foram fiéis a ele. Por isso, conserta-se com Deus hoje, enquanto ainda tem tempo.
Viva para Jesus e receba a esperança do Céu!*/
//constantes
#define PI 3.141592654
//declarações das funções
long int fatorial(int x);
long double cosx(long double x, int quantidadeDeTermos);
int main(){
    clock_t t0, tf;
    double tempo_gasto;
    t0 = clock();
    long double angolo;
    int quanTermo;
    printf("Informe o angolo: ");
    scanf("%Lf",&angolo);
    printf("informe a quantidade de termos: ");
    scanf("%d",&quanTermo);
    //resultado da operação
    angolo = (angolo * PI)/180; //converte em radianos
    printf("Resultado : %Lf\n", cosx(angolo,quanTermo));
    tf = clock();
    tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %lf s\n",tempo_gasto);
    return 0;
}
//função que calcula o fatorial
long int fatorial(int n){
    long int fatorial = 1;
    while(n > 1){
      fatorial *= n;
      n = n - 1;
    }
    return fatorial;

}
//função que calcula o seno
long double cosx(long double x, int quantidadeDeTermos){
    long double valoresDex = 0;
    for(int  i = 0; i <= quantidadeDeTermos; i++){
       if (i % 2  == 0) {
           valoresDex += pow(x, (i*2)) / fatorial(i*2);
       }else{
           valoresDex -= pow(x, (i*2)) / fatorial(i*2);
       }
       
   }

   return valoresDex;
}
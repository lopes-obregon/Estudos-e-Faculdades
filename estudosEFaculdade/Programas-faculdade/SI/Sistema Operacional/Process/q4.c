#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//variavel global
int maximo = 0;
int minimo = 0;
int medio = 0;
pthread_t thread1, thread2, thread3;
int size_vector;
void *threadFunctionMedio(void *arg){
   int *vet = (int *)arg;
   int i;
   int soma = 0;
   for(i = 0; i < size_vector; i++)
        soma+= vet[i];
    medio = soma/size_vector;
}
void *threadFunctionMinimo(void *arg){
   int *vet = (int *)arg;
   int i;
   minimo = vet[0];//primeiro elemento do vetor
   for(i = 0; i < size_vector; i++){
       if(vet[i] < minimo){
           minimo = vet[i];
       }
   }
}
void *threadFunctionMaximo(void *arg){
   int *vet = (int *)arg;
   int i;
   maximo = vet[0];//primeiro elemento do vetor
   for(i = 0; i < size_vector; i++){
       if(vet[i] > maximo){
           maximo = vet[i];
       }
   }
}
//main
int main(int argc, char const *argv[])
{
    int i;
    int *vector;
    vector = (int *)malloc(sizeof(int)*(argc -1));
   //converter para inteiros
   size_vector = argc - 1;
    for(i = 1; i < argc; i++){
        vector[i-1] = atoi(argv[i]);
    }
    pthread_create(&thread1, NULL, threadFunctionMedio, vector);
    pthread_create(&thread2, NULL, threadFunctionMinimo, vector);
    pthread_create(&thread3, NULL, threadFunctionMaximo, vector);        
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    printf("Valor medio eh: %d\n", medio);
    printf("Valor minimo eh: %d\n", minimo);
    printf("Valor maximo eh: %d\n", maximo);
    return 0;
}

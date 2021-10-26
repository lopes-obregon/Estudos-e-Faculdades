#include<stdio.h>
void eh_heap(int *vetor, int n);
//main
int main(int argc, char const *argv[])
{
    int v[] = {95, 60, 78, 100, 28, 66, 70, 33};
    int tamanho = 8;
    eh_heap(v, tamanho);
    return 0;
}
//verifica se o vetor eh heap
//n sendo o tamango do vetor;
void eh_heap(int *vetor, int n){
    int i, count;
    count = 0;
    for(i = 0; i < n; i++){
        if(i > 0){
            if(vetor[i] <=vetor[(i-1)/2]){
                //só é heap se satisfaz essa operação
                count++;
            }

        }
    }

    //se todos os elementos estiverem certo então ele é heap
    if(count == n -1){
        puts("eh heap");
    }else{
        puts("vetor não eh heap");
    }
}
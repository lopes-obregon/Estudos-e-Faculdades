#include <stdio.h>
/*programa que ordena em rodem decrescente*/
void decresente(int *v){
    int tmp;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(v[j] < v[j+1]){
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}
//imprime o vetor
void printVet(int *v){
    for(int i = 0; i < 4; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main(){
    int vet[4];
    for(int i = 0; i < 4; i++){
        scanf("%d", &vet[i]);
    }
    decresente(vet);
    printVet(vet);
    return 0;


}
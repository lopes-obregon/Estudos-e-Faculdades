#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
//procedimento que imprime os elementos apenas para conferir os valores
void printVector(uint32_t *vector, int vectorSize){
    for(int i = 0; i < vectorSize; i++)
        printf("%d\n", vector[i]);
}
//procedimento que troca
void troca(uint32_t *vector, int index){
    uint32_t aux = vector[index];
    vector[index] = vector[index + 1];
    vector[index + 1] = aux;
}
//procedimento de  insertion-sort
void insertion_sort(FILE *file, char *argv[]){
    int32_t *vector; // vetor que recebe os elementos
    int Nelemento = 0;//variavel que recebe a quantidade de elementos
    clock_t end, start;
    bool estaOrdenado = true;
    int32_t prov, valor;
    int j; 
    //conta os elementos
    fseek(file, 0, SEEK_END);
    Nelemento = ftell(file);
    Nelemento = Nelemento/sizeof(int32_t);
    fseek(file, 0, SEEK_SET);
    //aloca o vetor
    vector = (int32_t *) malloc(Nelemento * sizeof(int32_t));
    //le os elementos do vetor
    fread(&vector[0], sizeof(int32_t), Nelemento, file);
    printVector(vector, Nelemento);
    start = clock();
    for(int i = 1; i < Nelemento; i++){
        prov =  valor = vector[i];
        j = i-1;
        while(j >= 0 && valor < vector[j]){
            vector[j+ 1] = vector[j];
            j = j - 1;

        }
        vector[j + 1] = prov;
    } 
    end = clock();
    printf("Depois!\n");
    printVector(vector, Nelemento);
    fclose(file);
    file = fopen(argv[3], "wb");
    if(file == NULL){
        printf("Problema na abertura do arquivo\n");
    }else{
        fwrite(vector, sizeof(int32_t), Nelemento, file);
        fclose(file);
    }
    printf("tempo gasto: %.3f ms\n\n", 1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    //libera a memoria alocada
    free(vector);
}
//procedimento bubble sort melhorado
void bubble_sortMelhorado(FILE *file, char *argv[]){
    int32_t *vector; // vetor que recebe os elementos
    int Nelemento = 0;//variavel que recebe a quantidade de elementos
    clock_t end, start;
    bool estaOrdenado = true;
    //conta os elementos
    fseek(file, 0, SEEK_END);
    Nelemento = ftell(file);
    Nelemento = Nelemento/sizeof(int32_t);
    fseek(file, 0, SEEK_SET);
    //aloca o vetor
    vector = (int32_t *) malloc(Nelemento * sizeof(int32_t));
    //le os elementos do vetor
    fread(&vector[0], sizeof(int32_t), Nelemento, file);
    printf("Antes\n");
    printVector(vector, Nelemento);
    start = clock();
    for(int i = 0; i < Nelemento; i++){
        estaOrdenado = true;
        for(int j = 0; j < Nelemento- i - 1; j++){
            if(vector[j] > vector[j+1]){
                troca(vector, j);
                estaOrdenado = false;
            }
        }
        //se estiver ordenado para de executar.
        if(estaOrdenado){
            break;
        }
    }
    end = clock();
    printf("Depois!\n");
    printVector(vector, Nelemento);
    fclose(file);
    file = fopen(argv[3], "wb");
    if(file == NULL){
        printf("Problema na abertura do arquivo\n");
    }else{
        fwrite(vector, sizeof(int32_t), Nelemento, file);
        fclose(file);
    }
    printf("tempo gasto: %.3f ms\n\n", 1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    //libera a memoria alocada
    free(vector);
}
void bubble_sort(FILE *file, char *argv[]){
    int32_t *vector; // vetor que recebe os elementos
    int Nelemento = 0;//variavel que recebe a quantidade de elementos
    clock_t end, start;
    
    //conta os elementos
    fseek(file, 0, SEEK_END);
    Nelemento = ftell(file);
    Nelemento = Nelemento/sizeof(int32_t);
    fseek(file, 0, SEEK_SET);
    //aloca o vetor
    vector = (int32_t *) malloc(Nelemento * sizeof(int32_t));
    //le os elementos do vetor
    fread(&vector[0], sizeof(int32_t), Nelemento, file);
    printf("Antes\n");
    printVector(vector, Nelemento);
    start = clock();
    for(int i = 0; i < Nelemento; i++){
        for(int j = 0; j < Nelemento-1; j++){
            if(vector[j] > vector[j+1]){
                troca(vector, j);
            }
        }
    }
    end = clock();
    printf("Depois!\n");
    printVector(vector, Nelemento);
    fclose(file);
    file = fopen(argv[3], "wb");
    if(file == NULL){
        printf("Problema na abertura do arquivo\n");
    }else{
        fwrite(vector, sizeof(int32_t), Nelemento, file);
        fclose(file);
    }
    printf("tempo gasto: %.3f ms\n\n", 1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    //libera a memoria alocada
    free(vector);
}
int main(int argc, char *argv[])
{
    //se tem 3 entradas então executa
    if(argc == 4){
        //leitura do arquivo 
        FILE *file = fopen(argv[2], "rb");
        if(file == NULL){
            printf("Problema na abertura do arquivo\n");
            return 0;
        }else{
 //se na posição 1  igual a 1 então chama a ordenação Bubble-sort original
            if(atoi(argv[1]) == 1 ){
                printf("arquivo : %s\n", argv[2]);
                bubble_sort(file, argv);
            }else{
                if(atoi(argv[1]) == 2 ){
                    bubble_sortMelhorado(file, argv);
                }else{
                    if(atoi(argv[1]) == 3 ){
                        insertion_sort(file, argv);
                    }else{
                        if(atoi(argv[1]) == 4 ){

                        }else{
                            if(atoi(argv[1]) == 5 ){

                            }else{
                                if(atoi(argv[1]) == 6 ){

                                }else{
                                    if(atoi(argv[1]) == 7 ){

                                    }else{
                                        if(atoi(argv[1]) == 8 ){

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else{
        printf("Desculpe mas são permetidos apenas 3 argumentos!");
    }
    return 0;
}

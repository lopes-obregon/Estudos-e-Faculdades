#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

//procedimento que imprime os elementos apenas para conferir os valores
void printVector(int32_t *vector, int vectorSize){
    for(int i = 0; i < vectorSize; i++)
        printf("%d\n", vector[i]);
}
//procedimento que troca
void troca(uint32_t *vector, int index){
    uint32_t aux = vector[index];
    vector[index] = vector[index + 1];
    vector[index + 1] = aux;
}
void constroiHeap(int32_t m, int32_t *vector){
    int32_t aux;
    for(int32_t i = 1; i < m; i++){
        int f = i+1;
        while(f > 1 && vector[f/2]  < vector[f]){
            aux = vector[f/2];
            vector[f/2] = vector[f];
            vector[f] = aux;
            f /=2;
        }
    }
}
void peneira(int32_t m, int32_t *vector){
    int f = 2;
    int32_t aux;
    while(f <= m){
        if(f < m && vector[f] < vector[f+1]){
            f++;
        }
        if(vector[f/2] >= vector[f]){
            break;
        }
        aux = vector[f/2];
        vector[f/2] = vector[f];
        vector[f] = aux;
        f*=2;
    }
}
void heapSort(int32_t n, int32_t *vector){
    int32_t aux;
    constroiHeap(n, vector);
    for(int i = n; i >= 2; i--){
        aux = vector[1];
        vector[1] = vector[i];
        vector[i] = aux;
        peneira(i-1, vector);
    }
}
void heapMenu(FILE *file, char *argv[]){
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
    heapSort(Nelemento, vector);
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
int32_t particionaM3(int32_t *vector, int32_t inicio, int32_t fim){
    int32_t meio = floor((inicio + fim)/2);
    int32_t a = vector[inicio];
    int32_t b = vector[meio];
    int32_t c = vector[fim];
    int32_t indicieMedia, aux, i=inicio, pivo;
    //abaixo verifica qual é a media
    if(a < b){
        if(b < c){
            indicieMedia = meio;
        }else{
            if(a < c){
                indicieMedia = fim;
            }else{
                indicieMedia = inicio;
            }
        }
    }else{
        if(c < b){
            indicieMedia = meio;
        }else{
            if(c < a){
                indicieMedia = fim;
            }else{
                indicieMedia = inicio;
            }
        }
    }
    aux = vector[indicieMedia];
    vector[indicieMedia] = vector[fim];
    vector[fim] = aux;
    pivo = vector[fim];
    for(int32_t j = inicio; j < fim; j++){
        if(vector[j] < pivo ){
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
        }
    }
    aux = vector[i];
    vector[i] = vector[fim];
    vector[fim] = aux;
    return i;
}
void quickSortM(int32_t *vector, int32_t inicio, int32_t fim){
    int indice; // indice do pico
    if(inicio < fim){
        indice = particionaM3(vector, inicio, fim);
        quickSortM(vector, inicio, indice - 1);
        quickSortM(vector, indice +1, fim);
    }
}
//quick media de 3 menu
void quickSortM3Menu(FILE *file,char  *argv[]){
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
    quickSortM(vector, 0, Nelemento -1);
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
//particiona aleatorio
int particionaAle(int32_t *vector, int32_t inicio, int32_t fim){
    int32_t i = inicio, aux,indexPivo, pivo;
    int k;
    double valor;
    valor = (double) rand()/((double) RAND_MAX +1);
    k = valor * (fim - inicio +1 );
    indexPivo = inicio + k;
    //troca colocando o valor no ultimo
    aux = vector[indexPivo];
    vector[indexPivo] = vector[fim];
    vector[fim] = aux;
    //pivo elemento final
    pivo = vector[fim];
    for(int32_t j = inicio; j < fim; j++){
        if(vector[j] < pivo){
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
        }
    }
    aux = vector[i];
    vector[i] = vector[fim];
    vector[fim] = aux;
    return i;
}
//quicksort pivo aleatorio
void quickSortAle(int32_t *vector, int32_t inicio, int32_t fim){
    int indice; // indice do pico
    if(inicio < fim){
        indice = particionaAle(vector, inicio, fim);
        quickSortAle(vector, inicio, indice - 1);
        quickSortAle(vector, indice +1, fim);
    }
}
void quickSortAleMenu(FILE *file, char *argv[]){
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
    quickSortAle(vector, 0, Nelemento -1);
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
//proceddimento que particiona 
int particiona(int32_t *vector, int32_t inicio, int32_t fim){
    int32_t pivo = vector[fim];
    int32_t i = inicio, aux;
    for(int32_t j = inicio; j < fim; j++){
        if(vector[j] < pivo ){
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
        }
    }
    aux = vector[i];
    vector[i] = vector[fim];
    vector[fim] = aux;
    return i;
}
//procedimento quicksort com pivo sendo o ultimo elmento
void quickSort(int32_t *vector, int32_t inicio, int32_t fim){
    int indice; // indice do pico
    if(inicio < fim){
        indice = particiona(vector, inicio, fim);
        quickSort(vector, inicio, indice - 1);
        quickSort(vector, indice +1, fim);
    }
    
 }
 //procedimento quickmenu
 void quickSortMenu(FILE *file,char  *argv[]){
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
    quickSort(vector, 0, Nelemento -1);
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
//procedimento intercalar
void intercalar(int32_t *vector, int32_t esq, int32_t centro,  int32_t dir){
     int32_t *E = NULL, *D = NULL, Tam1 = centro - esq + 1, Tam2 = dir - centro;
     int i, j, k;

    E = malloc(Tam1*sizeof(int32_t));
    D = malloc(Tam2*sizeof(int32_t));

    /* copiar a primeira parte na esquerda e segunda parte na direita */
    for(i = 0; i < Tam1; i++)
        E[i] = vector[esq + i];

    for(j = 0; j < Tam2; j++)
        D[j] = vector[centro + j + 1];

    i = 0;
    j = 0;
    k = esq;

    while(i < Tam1 && j < Tam2){
        if(E[i] <= D[j]){
            vector[k] = E[i];
            i++;
        } else{
            vector[k] = D[j];
            j++;
        }
        k++;
    }

    while(i < Tam1){
        vector[k] = E[i];
        i++;
        k++;
    }

    while(j < Tam2){
        vector[k] = D[j];
        j++;
        k++;
    }
}
//procedimento mergesort
void mergesort(int32_t esq,  int32_t dir, int32_t *vector){
    int centro;
    //dir representa a ultima posição
    // esquerdo representa a primeira posição
    if(dir - esq > 1){
        centro = floor((esq + dir) /2);
        mergesort(esq, centro, vector);
        mergesort(centro + 1, dir, vector);
        intercalar(vector, esq, centro, dir);

    }
} 

//procedimento  mergesort leitura do arquivo e etc...
void mergesortMenu(FILE *file, char *argv[]){
     //se esquerdo menor que dirito então centro recebe piso de esquerdo mais direito dividido por 2
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
    //margesort
    mergesort(0, Nelemento-1, vector);
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
                            mergesortMenu(file, argv);
                        }else{
                            if(atoi(argv[1]) == 5 ){
                                quickSortMenu(file, argv);
                            }else{
                                if(atoi(argv[1]) == 6 ){
                                    quickSortAleMenu(file, argv);
                                }else{
                                    if(atoi(argv[1]) == 7 ){
                                       quickSortM3Menu(file, argv);
                                    }else{
                                        if(atoi(argv[1]) == 8 ){
                                            heapMenu(file, argv);
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

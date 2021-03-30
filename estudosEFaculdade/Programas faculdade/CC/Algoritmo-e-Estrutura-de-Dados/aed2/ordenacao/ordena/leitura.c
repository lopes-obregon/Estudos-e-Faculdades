#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main( int argc, char *argv[]){
    int Nelemento;
    int32_t *vector;
    FILE *file = fopen(argv[1], "rb");

    if(file == NULL){
        printf("Erro na abertura do arquivo!");
    }else{
         //conta os elementos
        fseek(file, 0, SEEK_END);
        Nelemento = ftell(file);
        Nelemento = Nelemento/sizeof(int32_t);
        fseek(file, 0, SEEK_SET);
        //aloca o vetor
        vector = (int32_t *) malloc(Nelemento * sizeof(int32_t));
        //le os elementos do vetor
        fread(&vector[0], sizeof(int32_t), Nelemento, file);
        for(int i  = 0; i < Nelemento; i++){
            printf("%d\n", vector[i]);
        }
        printf("\n\n");
    }
    
    
    return 0;
}
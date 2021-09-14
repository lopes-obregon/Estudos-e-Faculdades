/*lê do arquivo desconhecido de texto e depois verifica se é
multiplo de 2 ou de 3*/
#include <stdio.h>
//protótipos
void verificaDadoESalva(FILE *file2, FILE *file3, int valor);
//main
int main(int argc, char const *argv[])
{
    FILE *file_input;
    FILE *file_mult2;
    FILE *file_mult3;
    int valor_lido_do_arquivo;
    file_input = fopen("entrada.txt", "r");
    if(file_input == NULL){
        printf("Error na abertura de arquivo\n");
    }else{
        file_mult2 = fopen("mult_2.txt", "w");
        file_mult3 = fopen("mult_3.txt", "w");
        if((file_mult3 == NULL) ||(file_mult2 == NULL) ){
            printf("ERROR\n");
        }else{
            /*//primeira leitura
            fscanf(file_input, "%d", &valor_lido_do_arquivo);
            //verifica e guarda no arquivo
            verificaDadoESalva(file_mult2, file_mult3, valor_lido_do_arquivo);*/
            while(!feof(file_input)){
                fscanf(file_input, "%d", &valor_lido_do_arquivo);
                verificaDadoESalva(file_mult2, file_mult3, valor_lido_do_arquivo);

            }

        }
        fclose(file_mult2);
        fclose(file_mult3);
    }
    fclose(file_input);
    return 0;
}

//verifica o dado e salva no arquivo corespondente
void verificaDadoESalva(FILE *file2, FILE *file3, int valor){
    
    //verifica se o numéro é multiplo de 2 e 3
    printf("valor %d\n", valor);
    if((valor % 2 == 0) && (valor % 3 == 0) ){
        //é multiplo de 2 e 3
        printf("multiplo de 2 e 3  o valor %d\n", valor);
        fprintf(file2, "%d ", valor);
        fprintf(file3, "%d ", valor);
    }else if(valor % 2 == 0){
        //é multiplo de 2
        printf("multiplo de 2 o valor %d\n", valor);
        fprintf(file2, "%d ", valor);
    }else if(valor % 3 == 0){
        //é multiplo de 3
        printf("multiplo de 3 o valor %d\n", valor);
        fprintf(file3, "%d ", valor);
    }
}

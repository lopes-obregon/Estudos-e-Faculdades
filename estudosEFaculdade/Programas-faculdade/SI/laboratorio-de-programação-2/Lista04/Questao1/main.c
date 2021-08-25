#include <stdio.h>
#include <stdlib.h>
//programa que lê dois inteiros e salva no arquivo
/*int main()
{
    FILE *file;
    int a, b;
    file = fopen("entrada.txt", "w");
    if(file == NULL){
        printf("Error ao criar o arquivo!\n");
    }else{
        printf("Digite dois inteiros: ");
        scanf("%d%d",&a, &b);
        fprintf(file, "%d ", a);
        fprintf(file, "%d ", b);
        fclose(file);
    }
    return 0;
}*/
//questão 2
/*int main()
{
    FILE *file;
    int aux, i;
    int *vet;
    file = fopen("entrada.txt", "r");
    if(file == NULL){
        printf("Error ao criar o arquivo!\n");
    }else{
        i  = 0;
        vet = (int *) malloc (sizeof(int)* 2);
        while(!feof(file)){
            fscanf(file, "%d", &aux);
            vet[i] = aux;
            i++;
        }
        fclose(file);
        aux = 0;
        for(i = 0; i < 2; i++){
            aux += *(vet + i);
        }
        file = fopen("saida.txt", "w");
        if(file == NULL){
            printf("Erro ao criar o arquivo!\n");
        }else{
            fprintf(file, "%d", aux);
        }
        fclose(file);
    }
    return 0;
}*/
//ler pares de números
int main(){
    FILE *file;
    FILE *file_exit;
    int aux, soma_de_cada_par, par, primeira_leitura;
    file = fopen("entrada.txt", "r");
    file_exit = fopen("saida.txt", "w");
    if((file == NULL) && (file_exit == NULL)){
        printf("Error ao ler o arquivo!\n");
    }else{
        fscanf(file, "%d", &aux);
        soma_de_cada_par = aux;
        par = 1;
        primeira_leitura = 1;
        while(!feof(file)){
            fscanf(file, "%d", &aux);
            soma_de_cada_par += aux;
            if(primeira_leitura == 1){
                 fprintf(file_exit, "%d ", soma_de_cada_par);
                par = 1;// fez primeira leitura de um par
                soma_de_cada_par = 0;
                primeira_leitura = 0;
            }else if(par == 2){
                fprintf(file_exit, "%d ", soma_de_cada_par);
                par = 1;// fez primeira leitura de um par
                soma_de_cada_par = 0;
            }else{
                par++;
            }
        }
        fclose(file);
        fclose(file_exit);


    }
    return 0;
}


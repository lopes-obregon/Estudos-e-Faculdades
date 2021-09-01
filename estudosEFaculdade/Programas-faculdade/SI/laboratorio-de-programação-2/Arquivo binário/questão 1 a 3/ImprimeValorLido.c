#include<stdio.h>
int main(int argc, char const *argv[])
{
    int valor_lido;
    FILE *file;
    file = fopen("saida.dat", "rb");
    if(file == NULL){
        printf("ERROR");
    }else{
        //ponteiro para o inicio do arquivo
        fseek(file, sizeof(int), SEEK_SET);
        fread(&valor_lido, sizeof(int), 1, file);
        printf("Valor lido eh: %d\n", valor_lido);
    }
    return 0;
}

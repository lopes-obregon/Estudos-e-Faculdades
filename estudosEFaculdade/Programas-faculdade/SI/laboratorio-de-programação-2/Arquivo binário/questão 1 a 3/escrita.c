#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b;
    FILE *file;
    //arquivo para escrita
    file = fopen("entrada.dat", "wb");
    if(file == NULL){
        printf("Error ao gerar o arquivo");
    }else{
        printf("Digite dois numeros: ");
        scanf("%d%d", &a, &b);
        //ponteiro para inicio do arquivo
        fseek(file,sizeof(int), SEEK_SET);
        fwrite(&a, sizeof(int), 1, file);
        fwrite(&b, sizeof(int), 1, file);
        
    }
    fclose(file);
    return 0;
}

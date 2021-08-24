//programa que le 3 string  e substitu pela ocorrencia
#include <stdio.h>
#include <string.h>
#define TAMANHO 10
//prototipo
int encontra_ocorrencia(char *s, char *ocorrencia, int index, int index_ocorrencia, int index_o);
int main(){
    char s1[TAMANHO], s2[TAMANHO], s3[TAMANHO];
    int index_final, i, index_inicial;
    printf("Informe uma  palavra: ");
    scanf("%s", s1);
    printf("Informe duas ocorrencia para a  palavra %s que queira mudar e a outra para a que desejar: ", s1);
    scanf("%s%s", s2, s3);
    /*for ( i = 0; i < strlen(s3); i++)
    {
        s1[i] = s3[i];
    }*/
    index_final = encontra_ocorrencia(s1, s2, 0, 0, 0);
    index_inicial = index_final - strlen(s2);
    index_inicial++;
    for ( i = index_inicial; i <= index_final; i++)
    {
        s1[i] = s3[i - strlen(s3)];
    }
    
    printf("%s\n", s1);
    return 0;
}

//retorna o indicie inicial
int encontra_ocorrencia(char *s, char *ocorrencia, int index, int index_ocorrencia, int index_o){
    //chegou final da frase
    if(index == strlen(s)){
        return index_ocorrencia;
    }else if(s[index] == ocorrencia[index_o]){
        return encontra_ocorrencia(s, ocorrencia, index + 1, index, index_o + 1);
        
    }else{
        return  encontra_ocorrencia(s, ocorrencia, index + 1, index_ocorrencia, index_o);
    }
    
}
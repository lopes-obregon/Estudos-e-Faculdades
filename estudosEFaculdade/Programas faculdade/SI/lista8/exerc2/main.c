//programa que le duas string e n inteiro e copia os n primeiros inteiros de s1 para s2
#include <stdio.h>
#include <string.h>
#define TAMANHO 10
void clear_string(char *s);
int main(){
    //char s1[TAMANHO] = "abacaxi", s2[TAMANHO] = "cereja";
    char s1[TAMANHO], s2[TAMANHO];
    int n , i;
    clear_string(s1);
    clear_string(s2);
    printf("Informe duas palavras: ");
    scanf("%s%s", s1, s2);
    printf("Informe um valor de concatenação: ");
    scanf("%d", &n);
    //removendo o lixo
    s1[strlen(s1)] = '\0';
    s2[strlen(s2)] = '\0';
    for(i = 0; i < n; i++){
            //sempre adiciona na ultima posição
            s2[strlen(s2)] = s1[i];
        

    }

    printf("Palavra final é %s\n", s2);
    return 0;
}
//limpa a string
void clear_string(char *s){
    int i;
    for(i = 0; i < TAMANHO; i++){
        s[i] = '\0';
    }
}
//programa que le 4 palavras e imprime em ordem crescente
#include<stdio.h>
#include <string.h>
#define TAMANHO 10
//prototipos das funções
void clear_string(char *s);
 void print_string(char *s1, char *s2, char *s3, char *s4);
int main(){
    char s1[TAMANHO], s2[TAMANHO], s3[TAMANHO], s4[TAMANHO];
    clear_string(s1);
    clear_string(s2);
    clear_string(s3);
    clear_string(s4);
    printf("Informe 4 palavras obs(separe por espaço EX palavra1 palavra2: ");
    scanf("%s%s%s%s",s1, s2, s3, s4);
    print_string(s1, s2, s3, s4);
    return 0;
}
//imprime as strings
void print_string(char *s1, char *s2, char *s3, char *s4){
    //verifica a  primeira palavra
    //variavel flag para sair do laço para evitar percurso desnecessario
    int i;
    unsigned flag = 0;
    for ( i = 97; i < 122; i++){
        if(s1[0] == (char) i){
            printf("%s\n", s1);
            flag ++;
        }else if(s2[0] == (char) i){
            printf("%s\n", s2);
            flag++;
        }else if(s3[0] == (char) i){
            printf("%s\n", s3);
            flag++;
        }else if (s4[0] == (char) i){
            printf("%s\n", s4);
            flag++;
        }
        if(flag == 4){
            break;
        }
    }
    
}
//limpa a string
void clear_string(char *s){
    int i;
    for ( i = 0; i < TAMANHO; i++)
    {
        s[i] = '\0';
    }
    
}
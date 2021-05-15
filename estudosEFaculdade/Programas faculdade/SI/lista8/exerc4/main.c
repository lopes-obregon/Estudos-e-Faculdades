//programa que calcula a quantidade de vogais de uma frase
#include <stdio.h>
#include <string.h>
#define TAMANHO 25
int main(){
    char frase[TAMANHO];
    unsigned flag_a, flag_e, flag_i, flag_o, flag_u;
    int i;
    flag_a =  flag_e =  flag_i =  flag_o = flag_u = 0;
    printf("Informe a fase: ");
    scanf("%[^\n]", frase);
    //converte em minuscola
    for ( i = 0; i < strlen(frase); i++){
        if(frase[i] == 'a' || frase[i] == 'A'){
            flag_a++;
        }else if(frase[i] == 'e' || frase[i] == 'E'){
            flag_e++;
        }else if (frase[i] == 'i' || frase[i] == 'I')
        {
            flag_i++;
        }else if (frase[i] == 'o' || frase[i] == 'O' )
        {
            flag_o++;
        }else if (frase[i] == 'u' || frase[i] == 'U' )
        {
            flag_u++;
        }
        
        
        
    }
    printf("Sua frase(%s) tem %d A, %d E, %d I, %d, O %d U\n", frase, flag_a, flag_e, flag_i, flag_o, flag_u);
    return 0;
}
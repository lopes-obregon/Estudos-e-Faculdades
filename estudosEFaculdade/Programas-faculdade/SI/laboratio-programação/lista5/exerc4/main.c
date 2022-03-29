#include <stdio.h>
/*programa que calcula a media e retorna o conceito*/

int main(){
   float notaT, notaA, notaE, media;
   char conceito[] = "ABCDE";
    printf("Informe a nota:");
    scanf("%f%f%f", &notaT, &notaA, &notaE);
    notaT *= 2, notaA *= 3, notaE *= 5;
    media = (notaT + notaA + notaE)/10;
    if(media >= 8.0){
        printf("%c", conceito[0]);
    }else{
        if(media >= 7.0 && media <= 8.0){
            printf("%c", conceito[1]);
        }else{
            if(media >= 6.0 && media <= 7.0){
                printf("%c", conceito[2]);
            }else{
                if(media >= 5.0 && media <= 6.0){
                    printf("%c", conceito[3]);
                }else{
                    printf("%c", conceito[4]);
                }
            }
        }
    }
    printf("\n");

    return 0;
}
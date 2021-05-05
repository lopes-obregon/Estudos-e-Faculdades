#include <stdio.h>

/*verifica a coordenada em qual quadrante se localiza*/

int main(){
    signed int x, y;
    printf("Informe a coordenada para verificar qual quadrante se localiza: ");
    scanf("%d%d", &x, &y);
    if(x >= 0 && y >= 0){
        printf("Primeiro quadrande\n");
    }else{
        if(x < 0 && y >= 0){
            printf("Segundo quadrante\n");
        }else{
            if(x < 0 && y < 0){
                printf("Terceiro quadrante\n");
            }else{
                printf("quarto quadrante\n");
            }
        }
    }
    return 0;
}
/**recebe
*preço
*codigo de origem
**mostra
mostra a procedencia*/

#include <stdio.h>

int main(){
    float preco;
    unsigned short int codigo;
    printf("Informe o preço do produto R$ ");
    scanf("%f", &preco);
    printf("Informe o codigo do produto: ");
    scanf("%hd", &codigo);
    if(codigo == 1){
        printf("Sul\n");
    }else{
        if(codigo == 2){
            printf("Norte\n");   
        }else{
            if(codigo == 3){
                printf("Oeste\n");
            }else{
                if(codigo == 5 || codigo == 6){
                    printf("Nordeste\n");
                }else{
                    if(codigo == 7 || codigo == 8 || codigo == 9){
                        printf("Sudeste\n");
                    }else{
                        if(codigo >=10 && codigo <= 20){
                            printf("Centro-oeste\n");
                        }else{
                            if(codigo >= 21 && codigo <= 30){
                                printf("Nordeste\n");
                            }else{
                                printf("Procedencia não encontrada\n");
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
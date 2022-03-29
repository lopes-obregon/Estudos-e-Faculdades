//programa que calcula a soma dos inteiros entre c e b que são divisivel por a

#include <stdio.h>

int main(){
    /*variaveis
    *a sendo o fator comparador
    *b e c sendo os valores de intervalo
    *aux sendo a variavel auxiliar*/
    int a, b, c, i, aux = 0;
    printf("Entre com os numeros para calcular: ");
    scanf("%d%d%d", &a, &b, &c);
    if(a > 1){
        //calcula
        if(b < c){
            //c sendo maior que b
            for(i = b ; i <= c; i++){
                if(i % a == 0){
                    //divisivel por a
                    aux += i;
                }
            }
            printf("Valor da soma do intervalor [%d, %d] : %d\n",b, c, aux);
        }else if(b > c){
            //c sendo menor que b
            for(i = c ; i <= b; i++){
                if(i %a == 0){
                    aux += i;
                }
            }
            printf("Valor da soma do intervalor [%d, %d] : %d",c, b, aux);
        }
        
    }else{
        printf("Inpossivel calcular\n");
    }
    return 0;
}
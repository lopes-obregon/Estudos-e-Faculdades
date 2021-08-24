#include <stdio.h>
#include <stdlib.h>
//variaveis globais
int linha, coluna;
//protótipo das funções
void func_scanf_x_n(float *x);
float calcula_linha(float *vet, float *x, float divisor, int indicie);
float entrada_dados_mat();
float cal_parada(float *v, float *x);
float encontra_maior(float *vetMod, float *x);
float mod(float x1, float x2);
void troca_valor_vets(float *x, float *v);
void print_vet(float *vet);
int main(){
    float divisor, valor;
    float erro, verifica;
    printf("informe o tamanho do seu sistema linear sendo a quantidade de equaçoes e a quantidade de incógnitas: ");
    scanf("%d %d", &linha, &coluna);
    printf("Informe o erro: ");
    scanf("%f",&erro);
    float matriz[linha][coluna+1];
    float x_de_n[coluna];
    float vet[coluna];
    //func_preen_mat(matriz);
    for(int i = 0; i < linha; i++){
        printf("informe a %d equação.\n", i+1);
        for(int j = 0; j < coluna+1; j ++){
            if(j != coluna){
                printf("Informe a %d incognita.\n", j+1);
                matriz[i][j] = entrada_dados_mat();
            }else{
                printf("informe o termo independente %d: ", i+1);
                matriz[i][j] = entrada_dados_mat();

            }
        }

    }
    //func_cal_matriz(matriz);
    func_scanf_x_n(x_de_n);
    float aux[linha];
    do{
        for(int i = 0; i < linha; i++){
           int k = 1;//varial para controlar o indicie do vetor
            for(int j = 0; j < coluna + 1; j++){//mais 1 porque o incremento foi feito na matriz assim segue na linha 13;
                if(i == j){
                    divisor = matriz[i][j];
                }else{
                    if(j != coluna ){
                        valor = matriz[i][j];
                        valor *= -1;
                        vet[k] = valor;
                        k +=1;
                    }else{
                        if(j == coluna){
                            vet[0] = matriz[i][j];//vet é o vetor da linha
                        }
                    }
                }
            }
            aux[i] = calcula_linha(vet,x_de_n,divisor,i);
        }
        verifica = cal_parada(aux, x_de_n);
        troca_valor_vets(x_de_n,aux);
    }while(verifica > erro);
    printf("Solução do sistema é : \n");
    print_vet(x_de_n);
    return 0;
}
//função que imprime o vetor solução
void print_vet(float *vet){
    for(int i = 0; i < linha; i++){
        printf("%f\n",vet[i]);
    }
}
//função que troca o valor para que posssa calcular tudo novamente
void troca_valor_vets(float *x, float *v){
    for(int i = 0; i < linha; i++){
        x[i] = v[i];
    }
}
//função que calcula o erro
float cal_parada(float *v, float *x){
    //parada
    float vet_modulo[linha];
    float maiorDivisao;
    float valor1, valor2;
    for(int i = 0; i < linha; i++){
        valor1 = v[i];
        valor2 = x[i];
        vet_modulo[i] = mod(valor1, valor2);
    }
    //parte que pega o maior
    return maiorDivisao = encontra_maior(vet_modulo,v);//vetor v que tem a referencia de aux
}
//função que encontra o maior para dividir
float encontra_maior(float *vetMod, float *x){
    float maior1 = 0,maior2 = 0, aux;
    for(int i = 0; i < linha; i++){
        if(maior1 < vetMod[i]){
            maior1 = vetMod[i];
            if(maior1 < 0){
                maior1 *=-1;
            }
        }
        aux = x[i];
        if(aux < 0){
            aux *= -1;
        }
        if(maior2 < aux){
            maior2 = aux;
            if(maior2  < 0){
                maior2 *=-1;
            }
        }
    }
    return maior1/maior2;
}
//função módulo
float mod(float x1, float x2){
    float valor;
    valor = x1 - x2;
    if(valor < 0){
        valor *=-1;
    }
    return valor;
}
//calcula o x^n
float calcula_linha(float *vet, float *x, float divisor, int indicie){
    float valor,resto;
    //valor = valor + resto*x[i];
    for(int i = 0; i < linha; i++){
        if( i !=0){
            resto = vet[i]/divisor;
            if(indicie == linha-1){
                valor = valor + resto*x[i-1];
            }else{
                if(i  != indicie){
                    valor = valor + resto*x[i];
                }else{
                    valor = valor + resto*x[i-1];
                }

            }

        }else{
            valor = vet[i]/divisor;
        }
    }
    return valor;
}
//função que entra os dados da matriz
float entrada_dados_mat(){
float valor;
    scanf("%f",&valor);
    return valor;
}
//função que preenche a variavel
void func_scanf_x_n(float *x){
    float valor;
    printf("Insira os valores de X^0.\n");
    for(int i = 0; i < linha; i++){
        scanf("%f",&valor);
        x[i] = valor;
    }
}
/*
O dia do Senhor, porém, virá como ladrão. Os céus desaparecerão com um grande estrondo, os elementos serão desfeitos pelo calor,
e a terra, e tudo o que nela há, será desnudada.
2 Pedro 3:10
*/

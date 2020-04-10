#include<stdio.h>
#include<stdlib.h>
//variaveis globais
int linha,coluna;
//protótipos das funções
float entra_dados(int col);
float entrada_dados_independente(float mat[linha][coluna],int i);
void print_mat(float mat[linha][coluna]);
void calc_mat(float mat[linha][coluna]);
float func_abs(float mat[linha][coluna], int i, int passocoluna);
void troca_linha(float mat[linha][coluna], int coltrav);
void func_copy_mat(float mat[linha][coluna], float auxmat[linha][coluna]);
void cal_mat(float mat[linha][coluna]);
float func_multiplicador(float mat[linha][coluna],int i, int j, int linhatravada, float ai);
float func_copy_mat_vet_(float *vet, float *vetb, float mat[linha][coluna], int lin);
float func_copy_mat_vet2(float mat[linha][coluna], float *vet, float *vetb, int lin, int clin);
float func_multiplicador2(float mat[linha][coluna],int i, int j, int linhatravada, float ai);
float func_solucao_sistema(float mat[linha][coluna]);
float func_classifica_sistema(float mat[linha][coluna]);
//função principal
int main(int argc, char const *argv[]){
    printf("Informe o tamanho da matriz(linha e coluna): ");
    scanf("%d %d",&linha, &coluna);
    coluna +=1;
    float matriz[linha][coluna];
    for(int i = 0; i < linha; i++){
        printf("Informe os valores  da %dº linha \n",i+1);
        for(int j = 0; j < coluna-1; j++){
            matriz[i][j] = entra_dados(j);
        }
         entrada_dados_independente(matriz,i);
    }
    printf("sua matriz é: \n");
    print_mat(matriz);
    printf("\n");
    cal_mat(matriz);
    printf("\n");
    print_mat(matriz);
    func_solucao_sistema(matriz);
    return 0;
}
//função que entra os dados
float entra_dados(int col){
    float valor;
    printf("informe o valor da %dº coluna \n",col+1);
    scanf("%f",&valor);
    return valor ;
}
//entrada dos valores dos termos independentes
//linha vai ser andada as colunas vão ser pré definida ou seja as ultimas para ser uma matriz aumentada
float entrada_dados_independente(float mat[linha][coluna], int i){
    float valor;
    printf("informe o %dº termo independente: \n",i+1);
    scanf("%f", &valor);

    mat[i][coluna-1] = valor;

}
//função que imprime a matriz
void print_mat(float mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++)
        {
            if(j == (coluna -1)){
                printf("| %.2f",mat[i][j]);
            }else{
                printf("%.2f ",mat[i][j]);
            }
        }
        printf("\n");

    }

}
//função que verifica qual é maior em modulo da linha correspondente
void cal_mat(float mat[linha][coluna]){
    int travalin = 1, passcol = 0, contalinha = 0;
    float multiplicador, resultado, aij;
    float vet[coluna];
    float vetb [coluna];
    int contador = 0;
    troca_linha(mat,passcol);
    print_mat(mat);
    //multiplicador deve pegar o valor referente aos seus passos
    //deve andar sempre na diagonal

    for(int i = 0; i < linha - 1; i++){
        //parte que copia para preparar para calcular
        func_copy_mat_vet_(vet,vetb,mat,travalin);
        for(int j = 0; j < coluna; j++){
            if(i == j){
                aij = mat[0][0];
            }
            multiplicador = func_multiplicador(mat, i, j, travalin, aij);
            if(multiplicador != 0){
                //parte que calcula e joga os valores aqui
                resultado = (multiplicador * vet[j]) + vetb[j];
                mat[i+1][j] = resultado;
            }
        }
        travalin +=1;
    }
    printf("\n");
    print_mat(mat);
    printf("\n");
    //tudo isso deve ser executando quando minha matriz for maior ou igual que três
    if(linha > 2){
        do{
            passcol += 1;
            troca_linha(mat,passcol);
            print_mat(mat);
            printf("\n");
            contalinha += 1;
            multiplicador = 0;
            aij = 0;
            if(travalin == linha){
                travalin = (travalin + contalinha) - linha;//soma um para dar um numero maior depois subtrai assim co
            }
            for(int i = 0; i < linha; i++){
                //parte que copia para preparar para calcular
                    if(i >= travalin){
                        func_copy_mat_vet2(mat,vet,vetb,i,contalinha);
                        for(int j = 0; j < coluna; j++){
                            //parte do pivo
                            if(j == contalinha){
                                aij = vet[j];
                            }
                            if(aij != 0){
                            multiplicador = func_multiplicador2(mat,i,j,travalin,aij);
                            }
                            if(multiplicador != 0){
                                //parte que calcula e joga os valores aqui
                                resultado = (multiplicador * vet[j]) + vetb[j];
                                mat[i+1][j] = resultado;
                            }
                        }
                    multiplicador = 0;
                    aij = 0;
                    travalin +=1;
                }
            }
            contador +=1;
        }while(linha - 2 != contador);
    }

}
//função que calcula o valor em modulo;
float func_abs(float mat[linha][coluna], int i, int passocoluna){
    float valor;
    valor = mat[i][passocoluna];
    if (valor < 0) {
        valor = valor * -1;
    }
    return valor;
}
//função que troca a linha
void troca_linha(float mat[linha][coluna], int coltrav){
    int linhaAserTrocada;
    int lintroca;
    float maior = 0;
    float matb[linha][coluna];

    //verificar a coluna
    //primeiro percorrer a matriz
    for(int i = 0; i < linha; i++){
        //trava a coluna
        if(coltrav < 1 ){
            if (func_abs(mat,i,coltrav) > maior) {
                maior = mat[i][coltrav];
                lintroca = i;
            }

        }else{
            if((func_abs(mat,i,coltrav) > maior || func_abs(mat,i+1,coltrav) > func_abs(mat,i,coltrav)) && (i>= coltrav)){
                if(i >= coltrav){
                    maior = mat[i][coltrav];
                    lintroca = i;
                }
            }
        }
    }

    //realizar a troca da linha

    //achar o menor
    //temos que percorrer para achar o menor valor para trocar a linha
    maior = 999999;
    for(int i = 0; i < linha; i++){
        if(func_abs(mat,i,coltrav) < maior){
            maior = mat[i][coltrav];
            linhaAserTrocada = i;
        }
    }
    //copia os valores para a matriz b para que possa realizar os calculos da troca de linhas
    func_copy_mat(mat,matb);
    for(int i = 0; i < coluna; i++){
        mat[linhaAserTrocada][i] = matb[lintroca][i];
        mat[lintroca][i] = matb[linhaAserTrocada][i];
    }

}
//função que copia
void func_copy_mat(float mat[linha][coluna], float auxmat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++)
        {
            auxmat[i][j] = mat[i][j];
        }

    }

}
//função que retorna o malor do Mij
float func_multiplicador(float mat[linha][coluna],int i, int j, int linhatravada, float ai){
    float menosaij, Mij;
    //para calcular uma vez
    if((linhatravada*1) - linhatravada == j ){
        menosaij = mat[i+1][j];
        menosaij = menosaij * -1;
        Mij = menosaij / ai;
    }
    return Mij;
}
//função que joga o valor dentro do vetor
float func_copy_mat_vet_(float *vet, float *vetb,float mat[linha][coluna], int lin){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if((lin * 1) - lin == i){//copiei a primeira
                vet[j] = mat[i][j];
            }
        }
    }
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
                if(lin >= i){
                vetb[j] = mat[i][j];
                }
            }
        }
}
//função que copia para mais de 3linhas
float func_copy_mat_vet2(float mat[linha][coluna], float *vet, float *vetb, int lin, int clin){
    //clin a variavel que conta qual linha que esta fazendo a conta;
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(i == clin){
                vet[j] = mat[i][j];
            }
        }
    }
    //parte que pega o restante para calcular
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(i == lin+1){
                vetb[j] = mat[i][j];
            }
        }
    }
}
//função que retorna o multiplicador 2
float func_multiplicador2(float mat[linha][coluna],int i, int j, int linhatravada, float ai){
    float menosaij, Mij;
    if(j == linhatravada && linhatravada < 2 ){
        menosaij = mat[i+1][j];
        menosaij = menosaij * -1;
        Mij = menosaij /ai;
    }else{
        if(linhatravada >=2 && j <=linhatravada){
            menosaij = mat[i+1][j];
            menosaij = menosaij * -1;
            Mij = menosaij /ai;

        }

    }
    return Mij;
}
//função que acha a solução do sistema
float func_solucao_sistema(float mat[linha][coluna]){
    float dividendo,divisor, sinal;
    int k = linha - 1; //indice que guarda os valores
    float vet[linha];
    //if(func_classifica_sistema(mat) == 0){
    for(int i = linha; i > 0; i--){
        for(int j = 0; j < coluna; j++){
            if((i-1) == j){
                divisor = mat[i-1][j];
            }
            if(j == coluna -1){
                dividendo += mat[i-1][j];
                vet[k] = dividendo/divisor;// k == 1, k == 0
            }
            if(i == linha ){
                vet[k]=  dividendo / divisor;// k == 2
            }
            if(i < linha && j == i ){
                sinal = mat[i-1][j];
                sinal *= -1;
                sinal = sinal * vet[j];// j referente ao ultimos valores guardados
                dividendo += sinal;
            }else{
                if(j > i && j < coluna-1){
                    sinal = mat[i-1][j];
                    sinal *= -1;
                    sinal = sinal * vet[j];
                    dividendo += sinal;
                }
            }
        }
        dividendo = 0;
        k = k -1 ;
    }
    printf("Solução do sistema é: \n");
    for(int i = 0; i < linha; i++){
        printf("%.9f\n",vet[i]);
    }
}
//função que classifica o sistema
float func_classifica_sistema(float mat[linha][coluna]){
    float aux = 0;//0 - false 1 - true
    int i = linha;
        for(int j = 0 ; j < coluna; j++){
            if(j == coluna - 2){
                aux = mat[i][j];
                if(aux == 0 && mat[i][j+1] != 0){
                    printf("Sistema imposivel!\n");
                    aux = 1;
                }else{
                    if(aux == mat[i][j+1]){
                         printf("Sistema Possivel e Determinado!\n");
                        aux  = 0;
                    }else{
                        if(aux != mat[i][j+1]){
                            printf("Sistema Posivel e inderteminado!\n");
                            aux = 1;
                        }
                    }

                }

            }

        }


    return aux;

}
//frase do dia
/*
"Mas eu digo a vocês que estão me ouvindo: Amem os seus inimigos, façam o bem aos que os odeiam.
Lucas 6:27
*/

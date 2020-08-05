#include <stdio.h>
#include <stdlib.h>
//função global
int linha, coluna;
//procedimentos
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
int troca_linha(float mat[linha][coluna], int passcol, int vezesTrocadaLinha){
    float menor = 99999;
    int linhaAserTrocada;
    int lintroca, aux;
    float maior = 0;
    float matb[linha][coluna];
    aux = 1;
    linhaAserTrocada = 1;
    //verificar a colina
    for(int i = 0; i < linha; i++){
            if((i == passcol)){
                maior = mat[i][passcol];
            }else{
                menor = mat[i][passcol];
                if(maior < menor){
                        //pode aver troca
                    linhaAserTrocada = 0;
                }
            }

        }

    maior = -99999;
    menor = 99999;
    if(linhaAserTrocada == 0){
            //primeiro percorrer a matriz
        for(int i = 0; i < linha; i++){
            //trava a coluna
            if ((func_abs(mat,i,passcol) > maior) && (i >= passcol)) {
                maior = mat[i][passcol];
                lintroca = i;
                aux = 0;
            }

        }
        //realizar a troca da linha

        //achar o menor
        //temos que percorrer para achar o menor valor para trocar a linha
        for(int i = 0; i < linha; i++)
        {
            if (func_abs(mat,i,passcol) < menor && i >= passcol) {
                linhaAserTrocada = i;
                menor = mat[i][passcol];
            }

        }
        //copia os valores para a matriz b para que possa realizar os calculos da troca de linhas
        func_copy_mat(mat,matb);
        //parte que troca

        for(int i = 0; i < coluna; i++){
            mat[linhaAserTrocada][i] = matb[lintroca][i];
            mat[lintroca][i] = matb[linhaAserTrocada][i];
        }
    }

    if(aux == 0){
        vezesTrocadaLinha += 1;
    }
    return vezesTrocadaLinha;
}

//imprime matriz
void printMat(float mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(j + 1 != coluna){
                printf("%.2f ", mat[i][j]);
            }else{
                printf("%.2f\n", mat[i][j]);
            }
        }
    }
}
//função que calcula o determinante
float calcDet(float mat[linha][coluna], int vezesTrocadas){
    float aux = 1;
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(i == j){
                aux = aux*mat[i][j];
            }
        }
    }
    //vezes trocada é impar
    while(vezesTrocadas > 0){
        aux *= -1;
        vezesTrocadas --;
    }
    return aux;
}
//passa o valor da linha para um vetor
void copyMatToVector(float mat[linha][coluna], float *vet, int linhaTravada){
    for(int i = 0; i < coluna; i++){
        vet[i] = mat[linhaTravada][i];
    }
}
//acha multiplicador
float achaMult(float mat[linha][coluna],int i, int j){
    if(i > j){
        return mat[i][j];
    }else{
        return achaMult(mat, i + 1, j);
    }
}
//função que acha o pivo
float achaPivo(float mat[linha][coluna], int i, int j){
    if(i == j){
        //achou o pivo
        return mat[i][j];
    }else{
        return achaPivo(mat, i, j+1);
    }
}
//função que calcula a matriz
void calMat(float mat[linha][coluna]){
   float pivo, mult, vetLinha[coluna];
   int calculo, trocouLinha, vezesCalculada; //variavel que conta a interação do calculo para tracar linha ou coluna
   calculo = trocouLinha = 0;
   vezesCalculada = 1;
   do{
        trocouLinha  = troca_linha(mat,calculo, trocouLinha);
        printMat(mat);
        printf("\n");
        pivo = achaPivo(mat, calculo, calculo);
        copyMatToVector(mat, vetLinha, calculo);
        for(int i = 0; i < linha; i++){
            mult = achaMult(mat, i, calculo);
            mult = -1*(mult/pivo);
            for(int j = 0; j < linha; j++){
                if(i > calculo ){
                    mat[i][j] = mult*vetLinha[j] + mat[i][j];
                }
            }
        }

        calculo += 1;
        vezesCalculada +=1;
   }while(vezesCalculada < linha);
   printMat(mat);
   printf("\n");
    printf("Determinante da matriz é: %.2f\n", calcDet(mat, trocouLinha));
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

//insere valores na matriz
void insere(float mat[linha][coluna]){
    printf("Informe o elemento da matriz\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("a%d%d: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
}
//main
int main()
{
    printf("Informe a Dimenção da sua matriz: ");
    scanf("%d %d", &linha, &coluna);
    float matriz[linha][coluna];
    insere(matriz);
    printf("Sua matriz é!\n");
    printMat(matriz);
    printf("\n");
    calMat(matriz);

    return 0;
}

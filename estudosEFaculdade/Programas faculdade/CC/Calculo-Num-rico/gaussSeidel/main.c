#include <stdio.h>
#include <stdlib.h>
//variavel global
//n representa as linhas e m representa as colunas
int n, m;
//procedimentos
void contTrocaLinha(float mat[n][m], float matB[n][m],int lMenor, int lMaior){
    float aux;
    for(int i = 0; i < m; i++){
        aux = mat[lMenor][i];
        mat[lMenor][i] = matB[lMaior][i];
        mat[lMaior][i] = aux;
    }
}
//função que verifica a linha
int verificaLinha(float mat[n][m], float value, int coluna){
    int linhaRetorno;
    for (int i = 0 ; i < n ; i++){
        if(value < mat[i][coluna]){
            linhaRetorno = i;
        }

    }

    return linhaRetorno;
}
//função que copia a matriz
void copyMat(float mat[n][m], float matB[n][m]){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            matB[i][j] = mat[i][j];

}
//função que troca linha
void trocaLinha(float mat[n][m]){
    float aux, matB[n][m];
    int lAtual, lMaior;
    lAtual = 0, lMaior = 0;
    for (int i = 0 ; i < n ; i++){
            copyMat(mat, matB);
        for(int j = 0; j < m; j++){
            if((i == j) && (j+1 !=m) ){
                //copia matriz

                lAtual = i;
                lMaior = verificaLinha(mat,mat[i][j], j);
                if(lMaior <= n){
                    contTrocaLinha(mat, matB, lAtual, lMaior);
                }
            }
        }
    }
    /*
    for(int i = 0; i < n; i++){
            aux = mat[i][0];
        for(int j = 0; j < n; j++){
            if((aux < mat[j][0]) && (mat[j][0] != 0)  && (aux != 0)){
                lMenor = i;
            }else{
                if((aux > mat[j][0]) && (mat[j][0] != 0) && (aux != 0)){
                    lMaior = i;
                }
            }
        }
    }*/

}
//função que encontra o maior do vetor
float maiorC(float *vet, float maior,int index ){
    if(index == n){
        return maior;
    }else{
        if(maior < vet[index]){
            maior = vet[index];
            return maiorC(vet, maior, index + 1);
        }else{
            return maiorC(vet, maior, index + 1);
        }
    }
}
//função que realiza o critério das linhas
int  criterioLinhas(float mat[n][m]){
    float vet[n], aux, div;
    aux = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            if(i == j){
                div = mat[i][j];
            }else{
                aux += mat[i][j];
            }
        }
        vet[i] = aux/div;
        aux = 0;
    }
    aux = maiorC(vet, -999999,0);
    if(aux > 1){
        //faz uma troca de linha
        printf("Sistema não tem convergencia garantida\n");
        trocaLinha(mat);
        printf("Sistema com a linha trocada!\n");
        printMat(mat);
        return 1;
    }else{
        printf("Convergencia garantida!\n");
        return 3;
    }
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
//função que encontra o maior para dividir
float encontra_maior(float *vetMod, float *x){
    float maior1 = 0,maior2 = 0, aux;
    for(int i = 0; i < n; i++){
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
//função que calcula o erro
float cal_parada(float *v, float *x){
    //parada
    float vet_modulo[n];
    float maiorDivisao;
    float valor1, valor2;
    for(int i = 0; i < n; i++){
        valor1 = v[i];
        valor2 = x[i];
        vet_modulo[i] = mod(valor1, valor2);
    }
    //parte que pega o maior
    return maiorDivisao = encontra_maior(vet_modulo,v);//vetor v que tem a referencia de aux
}


//imprime vetor xn
void printVet(float *vet){
    for(int i = 0; i < n; i++){
        printf("|%f|\n", vet[i]);
    }

}
//copia o vetor
void copyVet(float *v1, float *v2){
    for(int i = 0; i < n; i++){
        v2[i] = v1[i];
    }
}
//calcula a matriz
void calcMat(float mat[n][m], float erro, float *vetIni){
    float vet[n], aux, div, dr;
    int k = 0;
    copyVet(vetIni, vet);
    do{
            copyVet(vet, vetIni);
            for(int i = 0; i < n; i++){
                aux = mat[i][m -1];
            for(int j = 0;  j < m; j++){
                if(i != j){
                    aux = aux - mat[i][j] * vet[j];
                }else{
                    div = mat[i][j];
                }
            }
            vet[i] = aux/div;
        }
        printf("k = %d\n", k);
        printVet(vet);
        k += 1;
        dr =  cal_parada(vet, vetIni);
        printf("erro: %f\n", dr);
    }while(dr  > erro);
    printf("Portanto  a solução do sistema é: \n");
    for(int i = 0; i < n; i++)
        printf("|%f|\n", vet[i]);

}
//imprime a matriz
void printMat(float mat[n][m]){
 for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(j+ 1 == m){
            printf("| %f",mat[i][j]);
            printf("\n");

        }else{
            printf("%f ", mat[i][j]);
        }
    }
 }

}
//insere dados na matriz
void insere(float mat[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j+1 == m){
                printf("b%d:",i +1);
                scanf("%f", &mat[i][j]);
            }else{
                printf("a%d%d: ", i + 1, j +1);
                scanf("%f", &mat[i][j]);
                printf("\n");
            }
        }
    }

}
//main
int main()
{
    printf("Informe o tamanho da matriz!\n");
    scanf("%d %d", &n, &m);
    m += 1;
    //gera a matriz nova
    float matriz[n][m], x[n], error;
    insere(matriz);
    printf("Sua matriz é!\n");
    printMat(matriz);
    //insere o dado do xn
    printf("informe o resultado inicial da matriz:\n");
    for(int i = 0; i < n; i++){
        printf("[%d]\n", i +1);
        scanf("%f", &x[i]);
        printf("\n");
    }
    printf("Informe o erro: ");
    scanf("%f", &error);
    int aux = 0;
    do{
        aux += criterioLinhas(matriz);
    }while(aux < 2);
    calcMat(matriz, error, x);
    return 0;
}

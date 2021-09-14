#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//protótipos
void collatz(int n);
int main(int argc, char const *argv[])
{
    pid_t pid;
    int i;
    //retrona um inteiro
    pid = fork(); // cria processo filho
    if(pid < 0){
        fprintf(stderr, "Fork failed!\n");
    }else if (pid == 0){
        //child process
        if(atoi(argv[1]) < 0){
            printf("Argumento invalido!\n");
            exit(EXIT_FAILURE);//falha na saida
        }else{
            collatz(atoi(argv[1]));
            exit(EXIT_SUCCESS);//concluido com sucesso
        }

    }else{
        wait(NULL);//ESPERA FILHO EXECUTAR
        
    }
    return 0;
}
void collatz(int n){
    if( n == 1){
        printf("%d\n", n);
        return;
    }
    if(n %2 == 0){
        //n é par
        printf("%d ", n);
        collatz(n/2);
    }else{
        //n é impar
        printf("%d ", n);
        collatz(3*n +1);
    }
}
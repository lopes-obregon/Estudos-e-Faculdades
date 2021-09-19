//processo unico
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *function(void *arg);
int main(int argc, char const *argv[])
{
    pthread_t thread1;
    pid_t pid;
    int n = 1;
    void *pointer_n;
    pointer_n = &n;
    pid = fork();
    if(pid == 0){
        //processo filho 
        fork();
        pthread_create(&thread1, NULL, function, pointer_n);
    }
    fork();
    
    return 0;
}
void *function(void *arg){
    int *thread = (int*)arg;//converte de void para inteiro
    int aux;
    scanf("%d", &aux);
    pthread_exit(NULL);//sai da thread ou finaliza
   
}
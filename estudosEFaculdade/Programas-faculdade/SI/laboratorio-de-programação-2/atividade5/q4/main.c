//programa que realiza o calculo de array e node
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
 struct node_t
{
   int key;
    struct node_t *next;
   
};
typedef struct  node_t node_t;
struct node_head_t
{
    node_t * head;
};
typedef struct node_head_t node_head_t;

void addNode(node_head_t *list, int value);
void changeHead(node_head_t *list, node_t *new_node);
void printList(node_head_t *list);
void clearList(node_head_t *list);
int main(int argc, char const *argv[])
{
    int i, aux;
    node_head_t *list;
    node_t *node;
    list = (node_head_t *)malloc(sizeof(node_head_t));
    list->head = NULL;
    srand(time(NULL));
    printf("Números gerados\n");
    for(i = 0; i < 10; i++){
        aux = rand() % 100;
        printf("%d ", aux);
        addNode(list, aux);
        
    }
    printf("\n");
    printList(list); 
    clearList(list);
    printList(list);
    return 0;
}

void addNode(node_head_t *list, int value){
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->key = value;
    new_node->next = NULL;
    changeHead(list, new_node);
}
void changeHead(node_head_t *list, node_t *new_node){
    node_t *aux;
    node_t *ant;
    if(list->head == NULL){
        new_node->next = list->head;
        list->head = new_node;
    }else{
        //contendo um elemento
        aux = list->head;
        if(aux->next == NULL){
            if( new_node->key > aux->key){
                //elemento da lista menor
                aux->next = new_node;
            }else{
                //novo elemento menor
                new_node->next = aux;
                list->head = new_node;
            }
        }else{
            while(aux != NULL){
                ant = aux;
                aux = aux->next;
                if(ant->key < new_node->key && aux->key > new_node->key){
                    //insere meio
                    ant->next = new_node;
                    new_node->next = aux;
                    break;
                }else if(ant->key > new_node->key){
                    //insere no menor mudando a cabeça
                    new_node->next = ant;
                    list->head = new_node;
                    break;
                }else if(new_node->key > aux->key && aux->next == NULL){
                    aux->next = new_node;
                    break;
                }
            }

        }

    }
    
    
}

void printList(node_head_t *list){
    node_t *node;
    if(list->head == NULL){
        printf("Lista vazia\n");

    }else{
        node = list->head;
        while(node != NULL){
            printf("%d->", node->key);
            node = node->next;
        }
        printf("\n");

    }
}

void clearList(node_head_t *list){
    node_t *node;
    node = list->head;
    node_t *aux;
    while(node != NULL){
        aux = node;
        node = node->next;
        free(aux);
    }
    list->head = node;
}

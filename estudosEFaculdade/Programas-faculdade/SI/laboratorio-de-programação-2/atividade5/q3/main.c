//programa que realiza o calculo de array e node
#include<stdio.h>
#include<stdlib.h>
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
void calcByteList(node_head_t *list);
int main(int argc, char const *argv[])
{
    int i;
    node_head_t *list;
    list = (node_head_t *)malloc(sizeof(node_head_t));
    list->head = NULL;
    for(i = 0; i < 100; i++){
        addNode(list, i);
        
    }
    printList(list);
    calcByteList(list);
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
    new_node->next = list->head;
    list->head = new_node;
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
void calcByteList(node_head_t *list){
    node_t *node;
    node = list->head;
    long int size_node;
    printf("%ld\n", sizeof(node)*100);
    while(node != NULL){

        node = node->next;
    }
}
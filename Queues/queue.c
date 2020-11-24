#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "queue.h"

typedef enum Valuators_enum {
 SP,
 MOODYS,
 FITCH
} Valuators; // Es opcional (pero recomendado) usar esta enum.
struct Marketable_Security_Struct {
    Valuators_enum Valuators;
};

Queue create(){
    Queue queue = malloc(sizeof(struct strQueue));
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
    return queue;
}
int size(Queue q){
    return q->size;
}
int isEmpty(Queue q){
    if(q->first == NULL) return 1;
    return 0;
}
Node peek(Queue q){
    return q->last;
}
void offer(Queue q, char c){
    Node node = malloc(sizeof(struct strNode));
    node->next = NULL;
    node->data = c;    
    if(q->first == NULL && q->last == NULL){
        q->first = node;
        q->last = node;
        q->size++;
    }else if (size(q) == 1){
        q->first->next = node;
        q->last = node;
        q->size++;
    }
    else{
        q->last->next = node;
        q->last = node;
        q->size++;
    }
}
char poll(Queue q){
    char c;
    if(isEmpty(q)){
        return '0';   
    }
    else{
        Node toRemove= q->first->next;
        c = q->first->data;
        q->first = toRemove->next;
        free(q->first);
        q->size--;
        return c;
    }
}
void destroy(Queue q){
    while(isEmpty(q) == 0){
        poll(q);
    }
    free(q);
}

void show(Queue q){
    Node aux = malloc(sizeof(struct strNode));
    aux = q->first;
    int sizeQ = size(q);
    for(int i=0;i<sizeQ;i++){
        if(i == sizeQ-1) printf("[%c]=o\n",aux->data);
        else printf("[%c]=>",aux->data);
        aux = aux->next;
    }
    free(aux);
}
 
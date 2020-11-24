#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

typedef struct strNode* Node;
typedef struct strQueue* Queue;

struct strNode{
    struct strNode *next;
    char data;
};

struct strQueue{
    struct strNode *first, *last;
    int size;
};

Queue create();
int size(Queue);
int isEmpty(Queue);
Node peek(Queue);
void offer(Queue,char);
char poll(Queue);
void destroy(Queue);
void show(Queue);

#endif
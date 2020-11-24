#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void){
    Queue queue = create();
    printf("Q isEmpty: %d\n",isEmpty(queue));
    printf("Q size: %d\n",size(queue));
    offer(queue,'a');
    offer(queue,'b');
    offer(queue,'c');
    offer(queue,'d');
    offer(queue,'e');
    printf("Q isEmpty: %d\n",isEmpty(queue));
    printf("Q size: %d\n",size(queue));
    Node node = peek(queue);
    printf("Peek: %c\n",node->data);
    show(queue);
    poll(queue);
    show(queue);
    destroy(queue);
    printf("%c",queue->first->data);
}
#include <stdio.h>

void swap(int *a, int *b) {
    // Implementa swap aquí, recuerda no usar printf o similares.
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int a = 25;
    int b = 13;
    swap(&a, &b);
    printf("%d %d", a, b);
}
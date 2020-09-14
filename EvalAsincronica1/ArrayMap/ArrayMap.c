#include <stdio.h>
/**
 * Este programa trata de crear una funcion .map(x)
 * donde recorra cada valor del arreglo que se le pasa
 * y en cada valor ejecute la funcion MakeItDouble()
 * 
 */

int arr[3] = {1,2,3};

void ArrayMap(int* target, int size, int (*)(int));
int MakeItDouble(int);

int main(void){
    ArrayMap(arr,3,MakeItDouble);
}
void ArrayMap(int* target, int size, int (*apply)(int)) {
    for(int i=0;i<size;i++,target++){
        *target = apply(*target);
    }
}
int MakeItDouble(int number){
    return number *= 2;
}
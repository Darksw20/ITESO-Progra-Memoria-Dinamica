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
    printf("Hola mundo");
}
void ArrayMap(int* target, int size, int (*DoubleIt)(int)) {

}
int MakeItDouble(int number){

    return 0;
}
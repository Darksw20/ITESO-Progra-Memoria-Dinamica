#include <stdio.h>

/**
 * El objetivo de este programa es pasar un array 2-D a un Vector.
 * 
 * puede haber cualquier cantidad de numeros en cada fila,
 * pero siempre el primer numero indicara cuantos habrá en esa fila
 * 
 */

int array1[4][4] = {
    {1,7},
    {2,4,1},
    {3,4,0,-3},
    {1,123}
};
int array2[4][4] = {
    {1,2},
    {3,1,5,9},
    {0},
    {2,10,10}
};
int** arr = array1;
void* res1;
void* res2;
void FoldMultiArray(int** multiArray, int size, int* result);
void PrintVector(int* result);

int main(void){
    FoldMultiArray(arr,4,res1);
    printf("Caso 1:\nVector resultante: ");
    PrintVector(res1);
    arr = array2;
    FoldMultiArray(arr,4,res2);
    printf("Caso 2:\nVector resultante: ");
    PrintVector(res2);
}

void FoldMultiArray(int** multiArray, int size, int* result) {
    for(int i = 0;i<size;i++){
        int var = arr[i][0];
        int res = 0;
        for(int j=0;j<var;j++){
            res += arr[i][j+1];
        }
        //result.append(res)
    }
}
void PrintVector(int* result){

}
#include <stdio.h>
/**
 * 
 */
// NO modifiquen esta struct, es readonly
struct ComparisonLibrary
{
  int (*Comparers[2])(void*, void*);
  int (*GetComparerId)(char);
};

void GenericSort(void* target[], char types[], int element_count, struct ComparisonLibrary Lib) ;

int main(void){
    printf("Hola mundo");
}



void GenericSort(void* target[], char types[], int element_count, struct ComparisonLibrary Lib) {
}


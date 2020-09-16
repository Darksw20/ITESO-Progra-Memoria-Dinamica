#include <stdio.h>
/**
 * El codigo deberá ordenar los arreglos usando las siguientes reglas:
 * 1.- HyperNodes menor
 * 2.- HyperNodes mayor
 * 3.- MultiThreads menor
 * 4.- MultiThreads mayor
 */
// NO modifiquen esta struct, es readonly
struct ComparisonLibrary
{
  int (*Comparers[2])(void*, void*);
  int (*GetComparerId)(char);
};
char types[] = {'H','M','M','H','M','H'};
int tar[] = {2,5,3,1,2,4};
void* target[] = {
  tar+0,
  tar+1,
  tar+2,
  tar+3,
  tar+4,
  tar+5
};

void GenericSort(void* target[], char types[], int element_count, struct ComparisonLibrary Lib);

int main(void){
  struct ComparisonLibrary Lib;
  for(int i=0;i<=5;i++){
    printf("%c ",*(types+i));
  }
  printf("\n");
  for(int i=0;i<=5;i++){
    int *name = target[i];
    printf("%d ",*name);
  }
  printf("\n");
  printf("-------------------------------------------------\n");
  GenericSort(target,types,6,Lib);
  printf("\n");
  printf("-------------------------------------------------\n");
  for(int i=0;i<=5;i++){
    printf("%c ",*(types+i));
  }
  printf("\n");
  for(int i=0;i<=5;i++){
    int *name = target[i];
    printf("%d ",*name);
  }
  printf("\n");
}

void GenericSort(void* target[], char types[], int element_count, struct ComparisonLibrary Lib) {
  for(int i=0; i<element_count-1; i++){
    for(int j = i +1; j<element_count; j++){
      if(*(types+i)>*(types+j)){
        char temp = *(types+i);
        *(types+i) = *(types+j);
        *(types+j) = temp;
        void* temp1 = target[i];
        target[i] = target[j];
        target[j] = temp1;
      }
    }
  }
  for(int i=0; i<element_count-1; i++){
    for(int j = i +1; j<element_count; j++){
      if(*(types+i) == 'H' && *(types+j) == 'H'){
        if(Lib.Comparers[Lib.GetComparerId('H')](target[i],target[j])>0){
          char temp = *(types+i);
          *(types+i) = *(types+j);
          *(types+j) = temp;
          void* temp1 = target[i];
          target[i] = target[j];
          target[j] = temp1;
        }
      }
      if(*(types+i) == 'M' && *(types+j) == 'M'){
        if(Lib.Comparers[Lib.GetComparerId('M')](target[i],target[j])>0){
          char temp = *(types+i);
          *(types+i) = *(types+j);
          *(types+j) = temp;
          void* temp1 = target[i];
          target[i] = target[j];
          target[j] = temp1;
        }
      }
    }
  }
}

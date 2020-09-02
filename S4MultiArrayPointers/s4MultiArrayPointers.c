#include <stdio.h>

void printDictionary(char** input, int n){
  for(int i=0; i < n; i++){
    for(int j=0; *(input[i]+j) != '\0'; j++){
      printf("%c", *(input[i]+j));
    }
    printf("\n");
  }
}

int main(void){
  char* arry[] = {
     "hola", 
     "estos", 
     "son", 
     "varias lineas", 
     "de texto" 
  };
  printDictionary(arry, 5);
}
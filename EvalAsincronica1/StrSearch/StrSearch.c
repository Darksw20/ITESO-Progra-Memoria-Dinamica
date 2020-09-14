#include <stdio.h>
/**
 * Este programa recibe una cadena y un patron
 * debe regresar el valor del indice donde el codigo se repite
 */
int strsearch(char* input, char* pattern) {
  for(int counter = 0;*input != '\0';input++, counter++){
    if(*pattern == *input){
      char *tempInp = input, *tempPat = pattern;
      while(*pattern == *input && *pattern != '\0'){
        pattern++;
        input++;
      }
      if(*pattern == '\0'){
        return counter;
      }else{
        input = tempInp;
        pattern = tempPat;
      }
    }
  }
  
  return -1;
}

int main(){
    char inp[] = "Hello world";
    char pat[] = "world";
    int res1 = strsearch(inp,pat);
    printf("%d\n",res1);
    printf("----------------------\n");
    char inp2[] = "abcabc";
    char pat2[] = "abc";
    int res2 = strsearch(inp2,pat2);
    printf("%d\n",res2);
    printf("----------------------\n");
    char inp3[] = "abc";
    char pat3[] = "defg";
    int res3 = strsearch(inp3,pat3);
    printf("%d\n",res3);
    printf("----------------------\n");
}

#include "stdio.h"

int strsearch(char* input, char* pattern) {
  int flag = 0, res;
  for(int counter = 0;*input != '\0';input++, counter++){
    if(*pattern == *input){
      char *tempInp = input, *tempPat = pattern;
      while(*pattern == *input && *pattern != '\0'){
        pattern++;
        input++;
      }
      if(*pattern == '\0'){
        res = counter;
        flag = 1;
      }else{
        input = tempInp;
        pattern = tempPat;
      }
    }
  }
  if(flag != 1){
    res = -1;
  }
  return res;
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

#include <stdio.h>
/**
 * 
 */
void errorFormatter(char* target, int length);

int main(void){
    char errors[1000] = "1x10x";
    printf("%s\n",errors);
    errorFormatter(errors,6);
    printf("\n");
    printf("%s\n",errors);
}

void errorFormatter(char* target, int length) {
    int count = 0;
    for(int i=0;i<length;i++){
        if(*(target+i)=='x'){
            count += 2;
        }
    }
    int newArrLenght = length+count;
    for(int i=length;i >= 0;i--){
        if(*(target+i)=='x'){
            *(target+newArrLenght) = '>';
            *(target+newArrLenght-1) = 'E';
            *(target+newArrLenght-2) = '<';
            newArrLenght -= 3;
        }else{
            *(target+newArrLenght) = *(target+i);
            newArrLenght--;
        }
    }
}
#include "stdio.h"

void strrem(char *input, char target){
    while(*input != '\0'){
        if(*input == target){
            char *temp = input;
            while(*input != '\0'){
                *input = *(input + 1);
                input++;
            }
            input = temp;
        }else{
            input++;
        }
    }
}
/*


void strrem(char* input, char target) {
    char* temp = input;
    char* current = input;

    while(*temp != '\0') {
        if(*temp != target){ 
            *current = *temp;
            current++;
        }
        temp++;
    }
    *current = '\0';
}
*/

int main(){
    char hello[] = "Hola mundo";
    strrem(hello,'o');
    printf("%s\n",hello);
}
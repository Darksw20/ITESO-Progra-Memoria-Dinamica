#include <stdio.h>
/**
 * Codigo revisa que dos cadenas sean iguales
 * 
 * 1 si son identicas
 * 0 si no lo son
 * 
 */

int strequ(char* a, char*b);


int main(void){
    char a[] = "Hola";
    char b[] = "Hol";
    int val = strequ(a,b);
    printf("%d", val);
}

int strequ(char* a, char*b) {
    int res = 1;
    while(*a != '\0' || *b != '\0'){
        if(*a != *b){
            res = 0;
        }
        b++;
        a++;
    }
    return res;
}

#include <stdio.h>

struct ChatLog{
  int post_count; //número de elementos a manipular
    //cada uno de ellos es una cadena de caracteres char*
  char** posts;
};

char palabra1[] = {'h', 'o', 'l', 'A', '\0'};
char palabra2[] = {'H', 'o', 'L', 'A', '\0'};
char palabra3[] = {'H', 'o', 'L', 'a', '\0'};
char palabra4[] = {'e', 'S', 't', 'O', ' ', 'e', 'S', ' ', 'a', ' ', 'm', 'U', 'n', 'D', 'O', '\0'};

char* post1[] = {
    palabra1,
    palabra2,
    palabra3
};

char* post2[] = {
    palabra4
};

//struct ChatLog logs = {.post_count = 3, .posts = post1};
struct ChatLog logs = {.post_count = 1, .posts = post2};

void RegularizeChatLog(struct ChatLog* log) {
    int minusculas = 0, mayusculas = 0;
    for (int i = 0; i < (log -> post_count); i++){
        char* palabra = (log -> posts)[i];
        for(int j = 0; palabra[j] != '\0'; j++){
            if (palabra[j] <= 'Z' && palabra[j] >= 'A') 
                mayusculas++;
            else if (palabra[j] <= 'z' && palabra[j] >= 'a')
                minusculas++;
        }
        if (minusculas > mayusculas){
            for(int k = 0; palabra[k] != '\0'; k++){
                if (palabra[k] <= 'Z' && palabra[k] >= 'A'){
                    palabra[k] = palabra[k] + 32;
                }
            }
        }
        else if (minusculas < mayusculas){
            for(int k = 0; palabra[k] != '\0'; k++){
                if (palabra[k] <= 'z' && palabra[k] >= 'a'){
                    palabra[k] = palabra[k] - 32;
                }
            }
        }
        else{
            if (palabra[0] <= 'z' && palabra[0] >= 'a')
                palabra[0] = palabra[0] - 32;
            for(int k = 1; palabra[k] != '\0'; k++){
                if (palabra[k] <= 'Z' && palabra[k] >= 'A'){
                    palabra[k] = palabra[k] + 32;
                }
            }
            for(int p = 0; palabra[p] != '\0'; p++){
                if(palabra[p] == ' '){
                    if (palabra[p+1] <= 'z' && palabra[p+1] >= 'a')
                        palabra[p+1] = palabra[p+1] - 32;
                }
            }
        }
        mayusculas = 0;
        minusculas = 0;
    }
}

int main(){
    
    RegularizeChatLog(&logs);
    return 0;
}

#include <stdio.h>
/**
 * El codigo debe de recibir un post, el post se reescribirá utilizando las siguientes reglas:
 * MAYUS > minus = MAYUS
 * MAYUS < minus = minus
 * MAYUS = miuns = Cap First Letters
 * 
 */
// No modifiques esta struct, es readonly
struct ChatLog{
  int post_count;
  char** posts;
};

void RegularizeChatLog(struct ChatLog* log);


int main(void){
    struct ChatLog posts = {
        
    };
    printf("Hola mundo");
}

void RegularizeChatLog(struct ChatLog* log) {
}
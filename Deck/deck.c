#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* hand = NULL;
char outCondition = 's';

void printDeck(char**);
void initDeck(char**);
void freeDeck(char** deck);

void pull();
void top();
void bottom();
void discard();

//TODO: Pull
//TODO: Top
//TODO: Bottom
//TODO: Discard

int main(void){
    char** deck = (char**) calloc(5,sizeof(char*));
    initDeck(deck);
    while (outCondition != 'e'){
        if(hand == NULL){
            printf("En su deck se encuentran las siguientes cartas:\n");
            printDeck(deck);
            printf("¿Que desea hacer?\n[p]ull para robar una carta\n[e]xit para salir\n");
        }else{
            printf("En su deck se encuentran las siguientes cartas:\n");
            printDeck(deck);
            printf("En su mano se encuentra la siguiente carta <%s>\n",hand);
            printf("¿Que desea hacer?\n[t]op para regresarla a la parte superior\n");
            printf("[b]ottom para regresarla a la parte inferior\n[d]iscard para descartarla\n[e]xit para salir\n");
        }

        printf("¿Desea salir del programa?\ne = exit | s = stay\n");
        scanf("%c",&outCondition);
    }
    freeDeck(deck);
}

void pull(){

}

void top(){

}

void bottom(){

}

void discard(){

}

void initDeck(char** deck){
    char* initialDeck[5] = {"10","J","Q","K","A"};
    for(int i=0;i<5;i++){
        deck[i] = (char*)calloc(2,sizeof(char));
        strcpy(deck[i],initialDeck[i]);
    }
    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        int r1 = rand() % 5;
        int r2 = rand() % 5;
        void* temp = deck[r1];
        deck[r1] = deck[r2];
        deck[r2] = temp;
    }
}

void freeDeck(char** deck){
    for(int i = 0;i < 5;i++)
        free(deck[i]);
    free(deck); 
}

void printDeck(char** deck){
    for(int i=0;i<5;i++){
        printf("[%s]\t",deck[i]);
    }
    printf("\n");
}
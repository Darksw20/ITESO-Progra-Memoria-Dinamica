#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* hand = NULL;
char option = 's';
int cantCards = 5;

void printDeck(char**);
void initDeck(char**);
void freeDeck(char**);

void pull(char**,char*);
void top();
void bottom();
void discard();

//TODO: Save
//TODO: Load
//TODO: SaveText
//DONE: Pull
//DONE: Top
//DONE: Bottom
//DONE: Discard

int main(void){
    char** deck = (char**) calloc(5,sizeof(char*));
    initDeck(deck);
    while (option != 'e'){
        printf("%s",hand);
        if(hand == NULL){
            printf("En su deck se encuentran las siguientes cartas:\n");
            printDeck(deck);
            printf("¿Que desea hacer?\n[p]ull para robar una carta\n[e]xit para salir\n");
            fflush(stdin);
            scanf("%c",&option);
            switch (option){
                case 'p':
                    pull(deck, hand);
                    break;
                case 'e':
                    printf("Gracias por Jugar.\n");
                    break;
                default:
                    printf("Opción no valida. Intente de nuevo\n");
                    break;
            }
        }else{
            printf("En su deck se encuentran las siguientes cartas:\n");
            printDeck(deck);
            printf("En su mano se encuentra la siguiente carta <%s>\n",hand);
            printf("¿Que desea hacer?\n[t]op para regresarla a la parte superior\n");
            printf("[b]ottom para regresarla a la parte inferior\n[d]iscard para descartarla\n[e]xit para salir\n");
            fflush(stdin);
            scanf("%c",&option);
            switch (option){
                case 't':
                    /* code */
                    break;
                case 'b':
                    /* code */
                    break;
                case 'd':
                    /* code */
                    break;
                case 'e':
                    printf("Gracias por Jugar.\n");
                    break;
                default:
                    printf("Opción no valida. Intente de nuevo\n");
                    break;
            }
        }
    }
    freeDeck(deck);
}

void pull(char** deck,char* hand){
    hand = deck[cantCards-1];
    deck[cantCards-1] = NULL;
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
        if(deck[i] != NULL){
            printf("[%s]\t",deck[i]);
        }
    }
    printf("\n");
}
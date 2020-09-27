#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Deck{
    int cantCards;
    char hand;
    char* cards;
};


char option = 's';
int cantCards = 5;

void printDeck(struct Deck*);
void initDeck(struct Deck*);
void freeDeck(struct Deck*);

void pull(struct Deck*);
void top(struct Deck*);
void bottom(struct Deck*);
void discard(struct Deck*);

//DONE: Pull
//DONE: Top
//DONE: Bottom
//DONE: Discard

int main(void){
    struct Deck deck;
    initDeck(&deck);
    while (option != 'e'){
        if(deck.hand == '0'){
            printf("----------------------------------------------------\n");
            printf("En su deck se encuentran las siguientes cartas:\n");
            printDeck(&deck);
            printf("¿Que desea hacer?\n[p]ull para robar una carta\n[e]xit para salir\n");
            fflush(stdin);
            scanf("%c",&option);
            switch (option){
                case 'p':
                    pull(&deck);
                    break;
                case 'e':
                    printf("Gracias por Jugar.\n");
                    break;
                default:
                    printf("Opción no valida. Intente de nuevo\n");
                    break;
            }
        }else{
            printf("----------------------------------------------------\n");
            printf("En su deck se encuentran las siguientes cartas:\n");
            printDeck(&deck);
            if(deck.hand == 'D'){
                printf("En su mano se encuentra la siguiente carta <10>\n");
            }else{
                printf("En su mano se encuentra la siguiente carta <%c>\n",deck.hand);
            }
            printf("¿Que desea hacer?\n[t]op para regresarla a la parte superior\n");
            printf("[b]ottom para regresarla a la parte inferior\n[d]iscard para descartarla\n[e]xit para salir\n");
            fflush(stdin);
            scanf("%c",&option);
            switch (option){
                case 't':
                    top(&deck);
                    break;
                case 'b':
                    bottom(&deck);
                    break;
                case 'd':
                    discard(&deck);
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
    
}

void pull(struct Deck* deck){
    if(deck->hand == '0' && deck->cantCards > 0){
        deck->hand = deck->cards[deck->cantCards-1];
        deck->cards[deck->cantCards-1] = '0';
        deck->cantCards--;
    }else{
        printf("Error: ya tiene carta en mano o no hay mas cartas que robar\n");
    }
}

void top(struct Deck* deck){
    deck->cards[deck->cantCards] = deck->hand;
    deck->hand = '0';
    deck->cantCards++;
}

void bottom(struct Deck* deck){
    for(int i = deck->cantCards;i >= 0 ;i--)
        deck->cards[i+1] = deck->cards[i];
    deck->cards[0] = deck->hand;
    deck->hand = '0';
    deck->cantCards++;
}

void discard(struct Deck* deck){
    if(deck->hand != '0')
        deck->hand = '0';
}

void initDeck(struct Deck* deck){
    char initialDeck[] = {'D','J','Q','K','A'};
    deck->cantCards = 5;
    deck->cards = calloc(5,sizeof(char));
    deck->hand = '0';
 
    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        int r1 = rand() % 5;
        int r2 = rand() % 5;
        char temp = initialDeck[r1];
        initialDeck[r1] = initialDeck[r2];
        initialDeck[r2] = temp;
    }
    for(int i = 0;i < 5;i++){
        deck->cards[i] = initialDeck[i];
    }
}

void printDeck(struct Deck* deck){
    for(int i=0;i<deck->cantCards;i++){
        if(deck->cards[i] == 'D'){
            printf("[10]\t");
        }else{
            printf("[%c]\t",deck->cards[i]);
        }
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "deckLib.h"
#include "deckSerializers.h"

GameState newDeckGame(){
    GameState game = malloc(sizeof(struct DeckGame));
    game->cantCards = 5;
    game->cards = calloc(5,sizeof(char));
    game->hand = '0';
    game->option = 's';
    return game;
}

void initDeck(GameState game){
    char initialDeck[] = {'D','J','Q','K','A'};
    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        int r1 = rand() % 5;
        int r2 = rand() % 5;
        char temp = initialDeck[r1];
        initialDeck[r1] = initialDeck[r2];
        initialDeck[r2] = temp;
    }
    for(int i = 0;i < 5;i++)
        game->cards[i] = initialDeck[i];
}

void playDeckGame(GameState game){
    initDeck(game);
    while (game->option != 'e'){
        if(game->hand == '0'){
            printf("----------------------------------------------------\n");
            printf("En su deck se encuentran las siguientes cartas:\n");
            printDeck(game);
            printf("¿Que desea hacer?\n[p]ull para robar una carta\n[s]ave para guardar\n[l]oad para cargar el juego\n[e]xit para salir\n");
            fflush(stdin);
            scanf("%c",&game->option);
            switch (game->option){
                case 'p':
                    pull(game);
                    break;
                case 's':
                    save(game);
                    printf("¡Juego Guardado!\n");
                    break;
                case 'l':
                    game = load(game);
                    printf("¡Juego Cargado!\n");
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
            printDeck(game);
            if(game->hand == 'D'){
                printf("En su mano se encuentra la siguiente carta <10>\n");
            }else{
                printf("En su mano se encuentra la siguiente carta <%c>\n",game->hand);
            }
            printf("¿Que desea hacer?\n[t]op para regresarla a la parte superior\n");
            printf("[b]ottom para regresarla a la parte inferior\n[d]iscard para descartarla\n[s]ave para guardar\n[l]oad para cargar el juego\n[e]xit para salir\n");
            fflush(stdin);
            scanf("%c",&game->option);
            switch (game->option){
                case 't':
                    top(game);
                    break;
                case 'b':
                    bottom(game);
                    break;
                case 'd':
                    discard(game);
                    break;
                case 's':
                    save(game);
                    printf("¡Juego Guardado!\n");
                    break;
                case 'l':
                    game = load(game);
                    printf("¡Juego Cargado!\n");
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

void endDeckGame(GameState game){
    free(game->cards);
    free(game);
}

void pull(GameState game){
    if(game->hand == '0' && game->cantCards > 0){
        game->hand = game->cards[game->cantCards-1];
        game->cards[game->cantCards-1] = '0';
        game->cantCards--;
    }else{
        printf("Error: ya tiene carta en mano o no hay mas cartas que robar\n");
    }
}

void top(GameState game){
    game->cards[game->cantCards] = game->hand;
    game->hand = '0';
    game->cantCards++;
}

void bottom(GameState game){
    for(int i = game->cantCards;i >= 0 ;i--)
        game->cards[i+1] = game->cards[i];
    game->cards[0] = game->hand;
    game->hand = '0';
    game->cantCards++;
}

void discard(GameState game){
    if(game->hand != '0')
        game->hand = '0';
}

void printDeck(GameState game){
    for(int i=0;i<game->cantCards;i++){
        if(game->cards[i] == 'D'){
            printf("[10]\t");
        }else if(game->cards[i] == '0'){
        }else{
            printf("[%c]\t",game->cards[i]);
        }
    }
    printf("\n");
}

void save(GameState game){
    unsigned char* data;
    data = serializer(game);
    FILE* bin;
    if((bin = fopen("./Data/save_data.bin","wb+")) == NULL){
        printf("Error: En apertura del archivo");
        exit(1);
    }
    fwrite(data,sizeof(char),2,bin);
    rewind(bin);
    fclose(bin);
}

GameState load(GameState game){
    unsigned char data[2];
    FILE* bin;
    if((bin = fopen("./Data/save_data.bin","rb")) == NULL){
        printf("Error: En apertura del archivo");
        exit(1);
    }
    fread(data,sizeof(char),2,bin);
    rewind(bin);
    fclose(bin);
    deserializer(game,data);
    return game;
}
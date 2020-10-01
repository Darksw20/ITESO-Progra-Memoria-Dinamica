#ifndef _DECK_EMULATOR_GUARD_H
#define _DECK_EMULATOR_GUARD_H

struct DeckGame{
    int cantCards;
    char hand;
    char* cards;
    char option;
};

typedef struct DeckGame* GameState;

GameState newDeckGame();
void initDeck(GameState);
void playDeckGame(GameState);
void printDeck(GameState);
void pull(GameState);

void top(GameState);
void bottom(GameState);
void discard(GameState);

void endDeckGame(GameState);


#endif
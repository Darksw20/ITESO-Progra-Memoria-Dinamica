#include <stdio.h>
#include "deckLib.h"

int main(void){
    GameState game = newDeckGame();
    playDeckGame(game);
    endDeckGame(game);
}

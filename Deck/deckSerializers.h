#ifndef _DECK_SERIALIZERS_GUARD_H
#define _DECK_SERIALIZERS_GUARD_H

typedef struct DeckGame* GameState;
typedef char (*FillFuncDeck)(unsigned char*);
typedef void (*FillFuncFile)(char*,char);

char fillDeck1(unsigned char*);
char fillDeck2(unsigned char*);
char fillDeck3(unsigned char*);
char fillDeck4(unsigned char*);
char fillDeck5(unsigned char*);

unsigned char parseBin(char);
void fillFile1(char*,char);
void fillFile2(char*,char);
void fillFile3(char*,char);
void fillFile4(char*,char);
void fillFile5(char*,char);
void fillFileHand(char*,char);

char* serializer(GameState);
void deserializer(GameState,unsigned char*);
char parseHex(int);

#endif
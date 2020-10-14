#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deckLib.h"
#include "deckSerializers.h"

FillFuncDeck fillDeck[5] = {&fillDeck1,&fillDeck2,&fillDeck3,&fillDeck4,&fillDeck5};
FillFuncFile fillFile[6] = {&fillFile1,&fillFile2,&fillFile3,&fillFile4,&fillFile5,&fillFileHand};


char* serializer(GameState game){
    char* val = malloc(sizeof(char)* 2);
    char byteLoad1 = 0x00;
    char byteLoad2 = 0x00;
    val[0] = byteLoad1;
    val[1] = byteLoad2;
    for(int i=0;i<=game->cantCards;i++){
        if(i<game->cantCards){
            fillFile[i](val,game->cards[i]);
        }else if(game->hand == '0'){
            fillFile[4](val,game->cards[i]);
        }else{
            fillFile[5](val,game->hand);
        }
    }
    return val;
}

void deserializer(GameState game,unsigned char* data){
    game->cantCards = 0;
    for(int i = 0;i<5;i++){
        game->cards[i] = 'F';
    }
    for(int i = 0, j = 0;i<5;i++){
        char card = fillDeck[i](data);
        if(card != '0' && i<4){
            game->cards[j] = card;
            game->cantCards++;
            printf("%d %d\n",i,j);
            j++;
        }else if(((data[0]&0x80)>>7) == 0x01 && i == 4){
            game->hand = fillDeck[i](data);
            //game->cantCards++;
        }else if(((data[0]&0x80)>>7) == 0x00 && i == 4){
            game->hand = '0';
            game->cards[j] = card;
            game->cantCards++;
        }
    }
    printf("%d\n",game->cantCards);
    //game->cantCards++;

}

void fillFile1(char* data,char card){
    unsigned char buffer = 0x00; 
    buffer = parseBin(card);
    data[1] = buffer;
}
void fillFile2(char* data,char card){
    unsigned char buffer = 0x00;
    buffer = parseBin(card);
    data[1] = ((data[1]) | (buffer<<3));
}
void fillFile3(char* data,char card){
    unsigned char buffer = 0x00;
    buffer = parseBin(card);
    data[0] = buffer;
}
void fillFile4(char* data,char card){
    unsigned char buffer = 0x00;
    buffer = parseBin(card);
    data[0] = ((data[0]) | (buffer<<3));
}
void fillFile5(char* data,char card){
    unsigned char buffer = 0x00;
    buffer = parseBin(card);
    data[1] = ((data[1]) | (buffer&0x03)<<6);
    data[0] = ((data[0]) | (buffer&0x04)<<4);
    data[0] = (data[0]&0x7F);
}
void fillFileHand(char* data,char card){
    unsigned char buffer = 0x00;
    buffer = parseBin(card);
    data[1] = ((data[1]) | (buffer&0x03)<<6);
    data[0] = ((data[0]) | (buffer&0x04)<<4);
    data[0] = (data[0] | 0x80);
}
char fillDeck1(unsigned char* data){
    return parseHex((data[1]&0x07));
}
char fillDeck2(unsigned char* data){
    return parseHex(((data[1]&0x38)>>3));
}
char fillDeck3(unsigned char* data){
    return parseHex((data[0]&0x07));
}
char fillDeck4(unsigned char* data){
    return parseHex(((data[0]&0x38)>>3));
}
char fillDeck5(unsigned char* data){
    return parseHex(((data[0]&0x40)>>4)|((data[1]&0xC0)>>6));
}
char parseHex(int card){
    char parsedCard;
    switch(card){
        case 0x01:
            parsedCard = 'D';
            break;
        case 0x02:
            parsedCard = 'J';
            break;
        case 0x03:
            parsedCard = 'Q';
            break;
        case 0x04:
            parsedCard = 'K';
            break;
        case 0x05:
            parsedCard = 'A';
            break;
        default:
            parsedCard = '0';
            break;
    }
    return parsedCard;
}
unsigned char parseBin(char card){
    char buffer = 0x00;
    switch(card){
        case 'D':
            buffer = 0x01;
            break;
        case 'J':
            buffer = 0x02;
            break;
        case 'Q':
            buffer = 0x03;
            break;
        case 'K':
            buffer = 0x04;
            break;
        case 'A':
            buffer = 0x05;
            break;
        default:
            buffer = 0x00;
            break;
    }
    return buffer;
}

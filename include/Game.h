#ifndef GAME_H
#define GAME_H
#include "Person.h"
#include <string.h>
struct GAME{//Nesnenin tanımı
    void (*playGame)(struct GAME*,char**,Person*,int,int);
    void (*showScreen)(struct GAME*,Person,double,short,int);
    void (*delete)(struct GAME*);
};
typedef struct GAME* Game;
//Fonksiyonlar
Game new_Game();
void playGame(const Game,char**,Person*,int,int);
void showScreen(const Game,Person,double,short,int);
void delete_Game(const Game);

#endif
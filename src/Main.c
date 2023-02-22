#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "GetFile.h"
#include "Game.h"
int main(){
    GetFile getfile= new_File();
    char** data2;
    data2=getfile->data(getfile,".\\doc\\Kisiler.txt");
    char** data3;
    data3=getfile->data(getfile,".\\doc\\Sayilar.txt");
    int sizeofPerson=getfile->sizeOfFile(getfile,".\\doc\\Kisiler.txt");
    int sizeofNumber=getfile->sizeOfFile(getfile,".\\doc\\Sayilar.txt");
    Person *personArray2=getfile->personArray(getfile,data2);
    getfile->delete(getfile);
    Game game=new_Game();
    game->playGame(game,data3,personArray2,sizeofNumber,sizeofPerson);
    free(personArray2);
    game->delete(game);
}
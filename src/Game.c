#include "Game.h"
Game new_Game(){//Nesnedeki fonksiyonların işaretçilerinin gösterimi
    Game this;
    this=(Game)malloc(sizeof(struct GAME));
    this->playGame=&playGame;
    this->showScreen=&showScreen;
    this->delete=&delete_Game;
};
void gameOver(int turnNumber,double bank){
    system("@cls||clear");//Ekranı temizleme
    printf("\n\n\n");
    int turnNumbersDigit=0;
    int turnNumberBackup=turnNumber;
    int bankBackup=bank;
    int bankBakupDigit=0;
    for(int i=0;i<13;i++){//Aşağıya doğru satır döngüsü.
        printf("\t\t\t\t\t");
        if(i==0||i==1||i==2||i==3|i==6||i==9||i==10||i==11||i==12){//Tamamı # dan oluşan satırlar.
            for(int j=0;j<45;j++){
                printf("#");
            }
        }
        if(i==4){//Tur numarasının yazıldığı satır.
            while(turnNumberBackup!=0){//Tur numarasının basamak sayısını bulan fonksiyon
                turnNumberBackup=turnNumberBackup/ 10;
                turnNumbersDigit++;
            }
            printf("##               Tur: %i",turnNumber);
            for(int k=0;k<21-turnNumbersDigit;k++){
                printf(" ");
            }
            printf("##");
        }
        if(i==5){//Masa bakiyesinin yazıldığı satır.
            while(bankBackup!=0){//Masa bakiyesinin basamak sayısını bulan fonksiyon
                bankBackup/= 10;
                bankBakupDigit++;
            }
            printf("##       MASA BAKIYE: %d TL",(int)bank);
            for(int k=0;k<18-bankBakupDigit;k++){
                printf(" ");
            }
            printf("##");
        }
        if(i==7){//##---## şeklindeki satır.
            printf("##-----------------------------------------##");
        }
        if(i==8){
            printf("##               OYUN BITTI                ##");
        }
        printf("\n");
    }
};
void playGame(const Game game,char** number,Person* person,int sizeofNumber,int sizeofPerson){
    double bank=0;
    int richestPerson=0;
    int turnNumber=1;
    for(int i=0;i<sizeofNumber;i++){//Sayıların döngüsü
        short luckyNumber=(short)atoi(number[i]);
        for(int j=0;j<sizeofPerson;j++){//Kişilerin döngüsü
            if(person[j]->getMoney(person[j])>1000){//1000den fazla parası olmayanlar oyunu oynayamaz
                double playedMoney=person[j]->getMoney(person[j])*person[j]->getRate(person[j]);
                if(person[j]->getNumber(person[j])==luckyNumber){//Numara tahmininin doğruluğunun kontrolü
                    person[j]->setMoney(person[j],person[j]->getMoney(person[j])+playedMoney*9);
                    bank=bank-playedMoney*9;
                }else{
                    bank=bank+playedMoney;               
                    person[j]->setMoney(person[j],person[j]->getMoney(person[j])-playedMoney);
                }
            }
            if(person[j]->getMoney(person[j])>person[richestPerson]->getMoney(person[richestPerson])){//En zengin kişiyi bulma
                richestPerson=j;
            }
        }
        game->showScreen(game,person[richestPerson],bank,luckyNumber,turnNumber);
        turnNumber++;
    }
    gameOver(turnNumber-1,bank);
};
void showScreen(const Game game,Person person,double bank,short luckyNumber,int turnNumber){
    system("@cls||clear");
    printf("\n\n\n");
    int turnNumbersDigit=0;
    int turnNumberBackup=turnNumber;
    int bankBackup=bank;
    int bankBakupDigit=0;
    int personMoneyBackup=person->getMoney(person);
    int personMoneyDigit=0;
    
    for(int i=0;i<13;i++){//Aşağıya doğru satır döngüsü.
        printf("\t\t\t\t\t");    
        if(i==0||i==2||i==3||i==12){//Tamamı # dan oluşan satırlar.
            for(int j=0;j<45;j++){
                printf("#");
            }
        }
        if(i==1){//Şanslı sayının yazıldığı satır.
            if(luckyNumber==10){
                printf("##             SANSLI SAYI: %u             ##",luckyNumber);
            }else{
                printf("##             SANSLI SAYI: %u              ##",luckyNumber);
            }           
        }
        if(i==4){//Tur numarasının yazıldığı satır.
            while(turnNumberBackup!=0){//Tur numarasının basamak sayısını bulan fonksiyon
                turnNumberBackup=turnNumberBackup/ 10;
                turnNumbersDigit++;
            }
            printf("##               Tur: %i",turnNumber);
            for(int k=0;k<21-turnNumbersDigit;k++){
                printf(" ");
            }
            printf("##");
        }
        if(i==5){//Masa bakiyesinin yazıldığı satır.
            while(bankBackup!=0){//Masa bakiyesinin basamak sayısını bulan fonksiyon
                bankBackup/= 10;
                bankBakupDigit++;
            }
            printf("##       MASA BAKIYE: %d TL",(int)bank);
            for(int k=0;k<18-bankBakupDigit;k++){
                printf(" ");
            }
            printf("##");
        }
        if(i==6||i==11){//Başı ve sonu ## olarak biten satırlar.
            printf("##                                         ##");
        }
        if(i==7){//##---## şeklindeki satır.
            printf("##-----------------------------------------##");
        }
        if(i==8){//## En zengin kişinin başlığı
            printf("##             EN ZENGIN KISI              ##");
        }
        if(i==9){//En zengin kişinin yazdırılması.
            printf("##             %s",person->getName(person));
            for(int k=0;k<28-strlen(person->getName(person));k++){
                printf(" ");
            }
            printf("##");
        }
        if(i==10){//En zengin kişinin bakiyesinin yazılması
            printf("##             BAKIYESI: %.0lf",person->getMoney(person));
            while(personMoneyBackup!=0){
                personMoneyBackup/=10;
                personMoneyDigit++;
            }
            for(int k=0;k<18-personMoneyDigit;k++){
                printf(" ");
            }
            printf("##");
        }
        
        printf("\n");
    }
};
void delete_Game(const Game this){
    if(this==NULL) return;
    free(this);
};
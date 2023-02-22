 #ifndef PERSON_H
 #define PERSON_H

 #include "stdio.h"
 #include "stdlib.h"

 struct PERSON//Nesnenin tanımı
 {
    char * name;
    double money;
    double rate;
    short number;
    char* (*getName)(struct PERSON*);
    double (*getMoney)(struct PERSON*);
    double (*getRate)(struct PERSON*);
    short (*getNumber)(struct PERSON*);
    void (*setName)(struct PERSON*,char*);
    void (*setMoney)(struct PERSON*,double);
    void (*setRate)(struct PERSON*,double);
    void (*setNumber)(struct PERSON*,short);
    void (*delete)(struct PERSON*);
 };
 //Fonksiyonlar
 typedef struct PERSON* Person;
 Person new_Person(char*,double,double,short);
 char* getName(const Person);
 double getMoney(const Person);
 double getRate(const Person);
 short getNumber(const Person);
 void setName(const Person,char*);
 void setMoney(const Person,double);
 void setRate(const Person,double);
 void setNumber(const Person,short);
 void delete_Number(const Person);
 
 #endif
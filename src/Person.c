#include "Person.h"


 Person new_Person(char* name,double money,double rate,short number){//Nesnedeki fonksiyonların işaretçilerinin gösterimi
    Person this;
    this= (Person)malloc(sizeof(struct PERSON));
    this->name= name;
    this->money=money;
    this->rate=rate;
    this->number=number;
    this->getName=&getName;
    this->getMoney=&getMoney;
    this->getRate=&getRate;
    this->getNumber=&getNumber;
    this->setName=&setName;
    this->setMoney=&setMoney;
    this->setRate=&setRate;
    this->setNumber=&setNumber;
    this->delete=&delete_Number;
    return this;
 };
 char* getName(const Person this){
     return this->name;
 }
 double getMoney(const Person this){
     return this->money;
 };
 double getRate(const Person this){
     return this->rate;
 };
 short getNumber(const Person this){
     return this->number;
 };
 void setName(const Person this,char* name){
     this->name=name;
 };
 void setMoney(const Person this,double money){
     this->money=money;
 };
 void setRate(const Person this,double rate){
     this->rate=rate;
 };
 void setNumber(const Person this,short number){
     this->number=number;
 };
 void delete_Number(const Person this){
     if(this==NULL) return;
     free(this);
 };
#include "GetFile.h"
#include <stdio.h>
#include <string.h>
GetFile new_File(){//Nesnedeki fonksiyonların işaretçilerinin gösterimi
    GetFile this;
    this=(GetFile)malloc(sizeof(struct GETFILE));
    this->data=&data;
    this->sizeOfFile=&sizeOfFile;
    this->personArray=&personArray;
    this->delete=&delete_GetFile;
};

char** data(const GetFile getFile,char* dataWay){//Veri alan fonksiyon
    FILE * file;
    file= fopen(dataWay,"r");
    int lineNumber=sizeOfFile(getFile,dataWay);

    char ** data2=(char**)malloc(sizeof(char*)*(lineNumber));//String array

    file= fopen(dataWay,"r");
    char * line2 = NULL;
    size_t len2 = 0;
    ssize_t read2;
    int i=0;
    while(read2 = getline(&line2, &len2, file) !=-1){ //Verilerin satır satır okunması        
        data2[i]=strdup(line2);           
        i++;
    }
     fclose(file);
     
    return data2;
}; 
int sizeOfFile(const GetFile getFile,char* dataWay){//Dosyadaki satır sayısının bulunması
    FILE * file;
    file= fopen(dataWay,"r");
    int lineNumber=0;

    if (file == NULL){
        printf("Dosya bulunamadi");
        return 0;
    }else{
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        while((read = getline(&line, &len, file)) != -1){//Verilerin satır satır okunması  
            lineNumber++;
        }
    }
    fclose(file);
    return lineNumber;
};
Person *personArray(const GetFile getFile,char** data){//Verilerin ayrıştırılması
    int sizeOfData2=getFile->sizeOfFile(getFile,".\\doc\\Kisiler.txt");
    Person *personArray2= malloc(sizeOfData2*sizeof(data[0]));
    for(int i=0;i< sizeOfData2;i++){// Verilerin döngüsü.
        char*name;
        double money;
        double rate;
        short number;
        char * checkedLine= malloc(strlen(data[i]));//Satırı bölme işlemi için string
        *checkedLine='\0';//İlk 17 satırdaki saçma hatanın önlenmesi
        for(int j=0,k=0;j<strlen(data[i]);j++){//Satırdaki Harflerin kontrolu
            if(data[i][j]=='#'){//Ayrıma koşulu
                switch (k)
                {
                case 0:
                    name=strdup(checkedLine);
                    break;
                case 1:          
                    money= strtod(checkedLine,NULL);
                    break;
                case 2:
                    rate=strtod(checkedLine,NULL);
                    break;
                }
                *checkedLine='\0';//Kontrol edilen satırı sıfırlıyor 
                k++;
            }else{
                strncat(checkedLine, &data[i][j],1);
            }
        }
        number=(short)atoi(strdup(checkedLine));
        Person person=new_Person(name,money,rate,number);
        personArray2[i]=person;
        free(checkedLine);
    }    
    return personArray2;
};
void delete_GetFile(const GetFile getFile){
    if(getFile==NULL) return;
    free(getFile);
};
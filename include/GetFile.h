#ifndef GETFILE_H
#define GETFILE_H
#include "Person.h"
struct GETFILE//Nesnenin tanımı
{
    char** (*data)(struct GETFILE*,char*); 
    int (*sizeOfFile)(struct GETFILE*,char*);
    Person *(*personArray)(struct GETFILE*,char**);
    void (*delete)(struct GETFILE*);
};
typedef struct GETFILE* GetFile;
//Fonksiyonlar
GetFile new_File();
char** data(const GetFile,char*); 
int sizeOfFile(const GetFile,char*);
Person *personArray(const GetFile,char**);
void delete_GetFile(const GetFile);
#endif
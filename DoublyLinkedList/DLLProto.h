#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
	char *name;
	int PIN,age;
	char sex;
	char *cityAddress,*streetAddress;
	char *mobNo;
}Person;

typedef struct{
	double noMale;
	double noFemale;
}Ratio;

struct DLL{
	Person per;
	struct DLL *right;
	struct DLL *left;
};

typedef struct DLL DLList;

void initPerson(Person *p);

void initList(DLList *dll);

void setPIN(Person *p,DLList *dll);

void getPerson(Person *p,DLList *dll);

void insertFront(DLList *dll,Person p);

void insertEnd(DLList *dll, Person p);

void insertPIN(DLList *dll, Person p, int pin);

DLList* seniorPerson(DLList *dll);

DLList* adult(DLList *dll);

DLList* locatePerson(DLList *dll, char * s);

void displayPerson(Person p);

void listPersons(DLList *dll);

void listSort(DLList *dll);

int noPersons(DLList *dll);

Ratio adultPerson(DLList *dll);

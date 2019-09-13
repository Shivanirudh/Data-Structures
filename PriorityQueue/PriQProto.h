#include<stdio.h>
#include<string.h>

struct emp{
	char name[100];
	int id;
	double salary;
};

typedef struct emp empDetails;

struct priQ{
	empDetails emp[100];
	int left,right;
	int size,capacity;
};

typedef struct priQ priorityQueueADT;

void initialise(priorityQueueADT *P,int max);

void insert(priorityQueueADT *P, empDetails x);

void disp(priorityQueueADT *P,int depth); 

empDetails delete(priorityQueueADT *P);



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[100];
	int visit;
}City;

typedef struct{
	int NoC;
	int ConMat[100][100];
	City data[100];
}cityADT;

void create(cityADT *c);
			
void disp(cityADT *c);

void BFS(cityADT *c);

int connect(cityADT *c,char s[],char d[]);

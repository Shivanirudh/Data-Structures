#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char name[100];
	int visit;
	int cost;
}City;

typedef struct{
	int NoC;
	int AdjMat[100][100];
	City data[100];
	
	int DistMat[100][100];
	char* PredMat[100][100];
	
}cityADT;

void create(cityADT *c);
			
void disp(cityADT *c);

void FW_Algorithm(cityADT *C); 

int displayPath(cityADT *C,char source[],char dest[]); 

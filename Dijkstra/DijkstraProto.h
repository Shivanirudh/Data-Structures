#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char name[100];
	int visit;
	int cost;
	char path[100];
}City;

typedef struct{
	int NoC;
	int ConMat[100][100];
	City data[100];
	int EdgeCost[100][100];
	
}cityADT;

void create(cityADT *c);
			
void disp(cityADT *c);

void Dijkstra_Algorithm(cityADT *C,char source[]); 

char * displayPath(cityADT *C,char source[],char dest[]); 

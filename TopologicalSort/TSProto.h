#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char name[100];
	int visit;
}City;

typedef struct{
	int NoC;
	int AdjMat[100][100];
	City data[100];
	
}cityADT;

void create(cityADT *c);
			
void disp(cityADT *c);

void TopologicalSort(cityADT *C);

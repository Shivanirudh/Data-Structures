#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int arr[100];
	int size;
}numberADT;

void init(numberADT *N);

void insertElements(numberADT *N,int x[100]);

int lsearchElement(numberADT *N,int key);

int bsearchElements(numberADT *N,int key);

void display(numberADT *N);

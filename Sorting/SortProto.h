#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int arr[100];
	int size;
}numberADT;

void init(numberADT *N);

void insertElements(numberADT *N,int x[100]);

void selSort(numberADT *N);

void shellSort(numberADT *N);

void display(numberADT *N);

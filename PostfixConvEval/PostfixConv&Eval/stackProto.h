#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char data[100];
	int top, limit;
}CharStack;

typedef struct{
	int data[100];
	int top, limit;
}IntStack;


int isFull(CharStack S);

int IisFull(IntStack S);

int isEmpty(CharStack S);

int IisEmpty(IntStack S);

void display(CharStack S);

void Idisplay(IntStack S);

void push(CharStack *S,char x);

void Ipush(IntStack *S,int x);

char pop(CharStack *S);

int Ipop(IntStack *S);

void initialise(CharStack *S);

void Iinitialise(IntStack *S);



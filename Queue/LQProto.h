#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
	int front,rear;
	int data[100];
	int capacity,size;
}Queue;

void initialise(Queue *q);

int isFull(Queue *q);

int isEmpty(Queue *q);

void enqueue(Queue *q,int x);

int dequeue(Queue *q);

void display(Queue *q);



#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
	char Job;
	int time;
}Data;

typedef struct{
	int front,rear;
	Data data[100];
	int capacity,size;
	int waitTime;
}Queue;

void initialise(Queue *q){
	q->front=q->rear=-1;
	printf("Enter capacity ");scanf("%d",&q->capacity);
	q->size=0;
	q->waitTime=0;
}

int isFull(Queue *q){
	if((q->rear==q->capacity-1&&q->front==0)||(q->rear==q->front-1))
		return 1;
	else
		return 0;
}
	
int isEmpty(Queue *q){
	if(q->front==-1)
		return 1;
	else
		return 0;
}	

void enqueue(Queue *q,Data x){
	if(isFull(q))
		printf("Queue is full ");
	else{
		if(q->front==-1)
			q->front++;
			
		if(q->rear==q->capacity-1)
			q->rear=0;
		else
			q->rear++;
			
		q->size++;
		q->data[q->rear]=x;
		q->waitTime+=x.time;
	}
}

Data dequeue(Queue *q){
	Data x;
	x.Job='\0';
	x.time=0;
	if(isEmpty(q))
		printf("Queue is empty");
	else{
		x=q->data[q->front];
		q->size--;
		q->waitTime-=x.time;
		if(q->front==q->rear)
			q->front=q->rear=-1;
		else if(q->front==q->capacity-1)
			q->front=0;
		else
			q->front++;
	}
	return x;
}

void display(Queue *q){
	if(isEmpty(q))
		printf("Queue is empty");
	else{
			int i=q->front;
			while(i!=q->rear){
				printf("%c %d; ",q->data[i].Job,q->data[i].time);
				
				if(i==q->capacity-1)
					i=0;
				else
					i++;
			}
			
			printf("%c %d; ",q->data[i].Job,q->data[i].time);	
	}
}

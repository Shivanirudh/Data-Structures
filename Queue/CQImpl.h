#include"LQProto.h"

void initialise(Queue *q){
	q->front=q->rear=-1;
	printf("Enter capacity ");scanf("%d",&q->capacity);
	q->size=0;
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

void enqueue(Queue *q,int x){
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
	}
}

int dequeue(Queue *q){
	int x=0;
	if(isEmpty(q))
		printf("Queue is empty");
	else{
		x=q->data[q->front];
		q->size--;
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
				printf("%d ",q->data[i]);
				
				if(i==q->capacity-1)
					i=0;
				else
					i++;
			}
			
			printf("%d ",q->data[i]);	
	}
}
		
		

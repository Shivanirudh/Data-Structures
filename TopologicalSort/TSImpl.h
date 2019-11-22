#include"TSProto.h"

void create(cityADT *c){
	printf("Enter the number of cities: ");scanf("%d",&c->NoC);
	printf("Enter the cities\n ");
	for(int i=0;i<c->NoC;i++){
		printf("\nCity %d : ",i+1);
		scanf(" %[^\n]",c->data[i].name);
		c->data[i].visit=0;
	}
	printf("Enter Connectivity information:\n ");
	for(int i=0;i<c->NoC;i++){
		for(int j=0;j<c->NoC;j++){
			int opt=0;int cost=0;
		
			printf("\n Enter if connection exists from %s to %s  ",c->data[i].name,c->data[j].name);
			scanf("%d",&opt);
			c->AdjMat[i][j]=opt;
		}
	}
}

void disp(cityADT *c){
	printf("The connections are from:\n");
	for(int i=0;i<c->NoC;i++){
		for(int j=0;j<c->NoC;j++){
			printf("%d ",c->AdjMat[i][j]);
		}
		printf("\n");
	}
}



typedef struct{
	int front,rear;
	int data[100];
	int capacity,size;
}Queue;

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
void TopologicalSort(cityADT *c){
	Queue q;int counter=0;
	initialise(&q);
	char *topSort[100];
	for(int i=0;i<c->NoC;i++)
		topSort[i]=(char*)malloc(sizeof(100));
		
	int indegreeMat[100];
	
	for(int i=0;i<c->NoC;i++){
		indegreeMat[i]=0;
	}
	
	for(int i=0;i<c->NoC;i++)
		for(int j=0;j<c->NoC;j++)
			indegreeMat[j]+=c->AdjMat[i][j];

	
	for(int i=0;i<c->NoC;i++)
		if(indegreeMat[i]==0)
			enqueue(&q,i);
	
	while(!isEmpty(&q)){
		int pos=dequeue(&q);
		strcpy(topSort[counter],c->data[pos].name);
		counter++;
		for(int i=0;i<c->NoC;i++){
			if(c->AdjMat[pos][i]){
				if(--indegreeMat[i]==0)
					enqueue(&q,i);
			}
		}
	}
	if(counter!=c->NoC)
		printf("Graph is cyclic");
	else{
		for(int i=0;i<c->NoC;i++)
			printf(" %s ",topSort[i]);
	}
}
			

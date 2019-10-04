#include"BFSProto.h"

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
			int opt=0;
			printf("\n Is there a connection from %s to %s? 1-Yes 0-No ",c->data[i].name,c->data[j].name);
			scanf("%d",&opt);
			c->ConMat[i][j]=opt;
		}
	}
}
			
void disp(cityADT *c){
	printf("The connections are from:\n");
	for(int i=0;i<c->NoC;i++){
		for(int j=0;j<c->NoC;j++){
			if(c->ConMat[i][j]==1)
				printf(" %s to %s \n",c->data[i].name,c->data[j].name);
		}
	}
}
	
	
typedef struct{
	int front,rear;
	char data[100][100];
	int capacity,size;
}VisitedQueue;

int isFull(VisitedQueue *q){
	if((q->rear==q->capacity-1&&q->front==0)||(q->rear==q->front-1))
		return 1;
	else
		return 0;
}
	
int isEmpty(VisitedQueue *q){
	if(q->front==-1)
		return 1;
	else
		return 0;
}	

void enqueue(VisitedQueue *q,char x[]){
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
		strcpy(q->data[q->rear],x);
	}
}

char* dequeue(VisitedQueue *q){
	char *tmp=NULL;
	
	if(isEmpty(q))
		printf("Queue is empty");
	else{
		tmp=(char*)malloc(sizeof(100));
		strcpy(tmp,q->data[q->front]);
		q->size--;
		if(q->front==q->rear)
			q->front=q->rear=-1;
		else if(q->front==q->capacity-1)
			q->front=0;
		else
			q->front++;
	}
	return tmp;
}


int checkVisit(cityADT *c){
	for(int i=0;i<c->NoC;i++)
		if(c->data[i].visit==0)
			return 1;
	return 0;
}
	
void BFS(cityADT *c){
	VisitedQueue Q;
	Q.front=Q.rear=-1;
	Q.capacity=c->NoC;
	Q.size=0;
	
	int i=0;
	while(checkVisit(c)){
		
		for(int a=0;a<c->NoC;a++)
			if(c->data[a].visit==0){
				i=a;break;
			}
				
		printf("\n %s \n",c->data[i].name);
		c->data[i].visit=1;
		enqueue(&Q,c->data[i].name);
		while(Q.size){
			char *tmp=NULL;
			tmp=(char*)malloc(sizeof(100));
			strcpy(tmp,dequeue(&Q));
			int j=0;
			for(int a=0;a<c->NoC;a++)
				if(!strcmp(tmp,c->data[a].name)){
					j=a;
					break;
				}
			
			for(int a=0;a<c->NoC;a++){
				if(c->ConMat[j][a]){
					if(c->data[a].visit==0){
						printf("\n %s \n",c->data[a].name);
						c->data[a].visit=1;
						enqueue(&Q,c->data[a].name);
					}
				}
			}
		}
	}
}

int connect(cityADT *c,char source[],char dest[]){
	int i,j;
	int flag=0;
	for(int a=0;a<c->NoC;a++){
		if(!strcmp(source,c->data[a].name)){
			i=a;
			break;
		}
	}	
	for(int a=0;a<c->NoC;a++){
		if(!strcmp(dest,c->data[a].name)){
			j=a;
			break;
		}
	}
	if(c->ConMat[i][j])
		flag=1;
	else{
		for(int a=0;a<c->NoC;a++){
			if(c->ConMat[i][a]){
				flag+=connect(c,c->data[a].name,dest);
			}
		}
	}
	return (flag>0)?1:0;
}


	
	
	
	
	

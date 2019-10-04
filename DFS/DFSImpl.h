#include"DFSProto.h"

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
			//c->ConMat[j][i]=opt;
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
	char data[100][100];
	int top, limit;
}Stack;

int isFull(Stack S){
	return ((S.top+1)==S.limit)?1:0;
}

int isEmpty(Stack S){
	return (S.top==-1)?1:0;
}

int size(Stack S){
	return S.top+1;
}

void display(Stack S){
	if(isEmpty(S))
		printf("Stack is empty");
	else{
		for(int i=S.top;i>=0;i--)
			printf("%s\n",S.data[i]);
	}
}

void push(Stack *S,char x[]){
	if(isFull(*S))
		printf("Stack is full");
	else{
		(*S).top++;
		strcpy((*S).data[(*S).top],x);
	}
}

void pop(Stack *S){
	if(!isEmpty(*S))
		(*S).top--;
}

void initialise(Stack *S){
	(*S).top=-1;
	printf("Enter maximum limit ");scanf("%d",&((*S).limit));
}

int checkVisit(cityADT *c){
	for(int i=0;i<c->NoC;i++)
		if(c->data[i].visit==0)
			return 1;
	return 0;
}

void DFS(cityADT *c){
	Stack S;
	initialise(&S);
	int x,tmp;
	
	while(checkVisit(c)){
		for(int a=0;a<c->NoC;a++){
			if(c->data[a].visit==0){
				x=a;
				break;
			}
		}
		
		printf("\n %s \n",c->data[x].name);
		c->data[x].visit=1;
		
		push(&S,c->data[x].name);
		
		while(!isEmpty(S)){
			
			for(int i=0;i<c->NoC;i++){
				if(!strcmp(c->data[i].name,S.data[S.top]))
					tmp=i;	
			}	
			
			int flag=0;
			for(int i=0;i<c->NoC;i++){
				if(c->ConMat[tmp][i]){
					if(c->data[i].visit==0){
						printf("\n %s \n",c->data[i].name);
						c->data[i].visit=1;
						flag++;
						push(&S,c->data[i].name);
						break;
						
					}
				}
			}
			if(!flag)
				pop(&S);
		}
	}
}

int connect(cityADT *c,char source[],char dest[]){
	int i,j;
	int flag=0;
	for(int a=0;a<c->NoC;a++)
		if(!strcmp(source,c->data[a].name)){
			i=a;
			break;
		}
		
	for(int a=0;a<c->NoC;a++)
		if(!strcmp(dest,c->data[a].name)){
			j=a;
			break;
		}
	
	if(c->ConMat[i][j])
		flag=1;
	else{
		for(int a=0;a<c->NoC;a++)
			if(c->ConMat[i][a])
				flag+=connect(c,c->data[a].name,dest);
	}
	
	return (flag>0)?1:0;
}

char* path(cityADT *c,char source[],char dest[]){

	int i=0,j=0;
	
	if(connect(c,source,dest)){
		char *way;
		way=(char*)malloc(sizeof(1000));
		way[0]='\0';
		strcat(way,source);
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
	
		if(c->ConMat[i][j]){
			strcat(way,dest);
			return way;
		}
		else{
			for(int a=0;a<c->NoC;a++)
				if(c->ConMat[i][a])
					if(connect(c,c->data[a].name,dest)){
						strcat(way,path(c,c->data[a].name,dest));
						break;
					}
		}
		
		return way;
	}
	else{
		printf("\n There does not exist a connection from %s to %s\n",source,dest);
		return NULL;
	}
}

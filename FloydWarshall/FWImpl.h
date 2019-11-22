#include"FWProto.h"

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
			if(i==j)
				c->AdjMat[i][j]=0;
			else{
				printf("\n Enter distance of connection from %s to %s  ",c->data[i].name,c->data[j].name);
				scanf("%d",&opt);
				c->AdjMat[i][j]=opt;
			}
		}
	}
	
	//Initialise Distance Matrix
	for(int i=0;i<c->NoC;i++)
		for(int j=0;j<c->NoC;j++)
			c->DistMat[i][j]=c->AdjMat[i][j];
	
	//Initialise Predecessr Matrix  
	for(int i=0;i<c->NoC;i++){
		for(int j=0;j<c->NoC;j++){
			c->PredMat[i][j]=(char*)malloc(sizeof(100));
			c->PredMat[i][j][0]='\0';
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

void displayTables(cityADT *c){
	printf("\nDistance Matrix\n");
	for(int i=0;i<c->NoC;i++){
		for(int j=0;j<c->NoC;j++){
			printf("%d ",c->DistMat[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPredecessor Matrix\n");
	for(int i=0;i<c->NoC;i++){
		for(int j=0;j<c->NoC;j++){
			if(c->PredMat[i][j][0]=='\0')
				printf("0 ");
			else
				printf("%s ",c->PredMat[i][j]);
		}
		printf("\n");
	}
}

void FW_Algorithm(cityADT *c){
	
	//Floyd Warshall Algorithm
	for(int k=0;k<c->NoC;k++){
		for(int i=0;i<c->NoC;i++){
			for(int j=0;j<c->NoC;j++){
				if(c->DistMat[i][j]>c->DistMat[i][k]+c->DistMat[k][j]){
					c->DistMat[i][j]=c->DistMat[i][k]+c->DistMat[k][j];
					strcpy(c->PredMat[i][j],c->data[k].name);
				}
			}
		}
	}
	displayTables(c);
}

int displayPath(cityADT *c,char source[],char dest[]){
	
	int i,j;
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
	int t=0;
	printf("\nPath is %s ",c->data[i].name);
	if(c->PredMat[i][j][0]=='\0'){
		printf("%s",c->data[j].name);
		t+=c->DistMat[i][j];
	}
	else{
		
		t+=displayPath(c,source,c->PredMat[i][j]);
		t+=displayPath(c,c->PredMat[i][j],dest);
	}
	printf("\nCost is %d\n", t);
	return t;
}

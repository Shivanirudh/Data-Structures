#include"DijkstraProto.h"

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
			printf("\n Is there a connection from %s to %s? 1-Yes 0-No ",c->data[i].name,c->data[j].name);
			scanf("%d",&opt);
			c->ConMat[i][j]=opt;
			if(c->ConMat[i][j]){
				printf("Enter cost of travel ");scanf("%d",&cost);
			}
			c->EdgeCost[i][j]=cost;
		}
	}
}
			
void disp(cityADT *c){
	printf("The connections are from:\n");
	for(int i=0;i<c->NoC;i++){
		for(int j=0;j<c->NoC;j++){
			if(c->ConMat[i][j]==1)
				printf(" %s to %s at cost %d \n",c->data[i].name,c->data[j].name,c->EdgeCost[i][j]);
		}
	}
}

int checkVisit(cityADT *c){
	for(int i=0;i<c->NoC;i++)
		if(c->data[i].visit==0)
			return 1;
	return 0;
}

void displayTable(cityADT *c){
	printf("\n\n");
	printf(" Vertex\tVisited\tCost\tPath \n");
	for(int i=0;i<c->NoC;i++){
		printf(" %s%-9d%-10d%-8s \n",c->data[i].name,c->data[i].visit,c->data[i].cost,c->data[i].path);
	}
}

void Dijkstra_Algorithm(cityADT *c,char source[]){
	for(int a=0;a<c->NoC;a++)
		c->data[a].path[0]='\0';
	
	int i,j;
	
	for(int a=0;a<c->NoC;a++){
		if(!strcmp(source,c->data[a].name)){
			i=a;
			break;
		}
	}
	for(int a=0;a<c->NoC;a++){
		if(a==i){
			c->data[a].cost=0;
			c->data[a].visit=0;
		}
		else{
			c->data[a].cost=1000;
			c->data[a].visit=0;
		}
	}
	
	while(checkVisit(c)){
		
		if(c->data[i].visit==0)
			j=i;
		else{
			c->data[j].cost=1000;
			for(int a=0;a<c->NoC;a++){
				if(c->data[a].visit==0){
					if(c->ConMat[j][a]){
						if(c->data[a].cost<c->data[j].cost){
							j=a;
							break;
						}
					}
				}
			}
		}
		printf("\n %s is known \n",c->data[j].name);
		c->data[j].visit=1;
		
		for(int a=0;a<c->NoC;a++){
			if(c->ConMat[j][a]){
				if(c->data[a].visit==0){
					if(c->data[j].cost+c->EdgeCost[j][a]<c->data[a].cost){
						c->data[a].cost=c->data[j].cost+c->EdgeCost[j][a];
						strcpy(c->data[a].path,c->data[j].name);
					}
				}
			}
		}
		displayTable(c);
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

void strrev(char *s){
	char r[100];
	int count=0;
	int begin,end;
	while (s[count] != '\0')
      count++;
 
   end = count - 1;
 
   for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }
 
   r[begin] = '\0';
   strcpy(s,r);
}

char* displayPath(cityADT *c,char source[],char dest[]){
	
	char *way;
	way=(char*)malloc(sizeof(1000));				
	
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
	
	char path[100];
	strcpy(path,c->data[j].path);
	if(connect(c,source,dest)){
		if(c->data[j].path[0]){
			while(strcmp(path,source)){
				strcat(way,path);
				for(int a=0;a<c->NoC;a++){
					if(!strcmp(c->data[a].path,c->data[j].path)){
						strcpy(path,c->data[a].path);
						j=a;
						break;
					}
				}
			}
			strrev(way);
			return way;
		}
		else{
			return NULL;
		}
	}
	else{
		return NULL;
	}
}

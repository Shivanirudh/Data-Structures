#include"HashProto.h"

void initialise(HashADT* hashTable){
	printf("Enter table size: ");scanf("%d",&hashTable->table_size);
	
	for(int i=0;i<hashTable->table_size;i++)
		hashTable->table[i]=NULL;
}

int hashFunction(int x,int table_size){
	return x%table_size;
}
void insert(HashADT* hashTable,int x){
	int pos=hashFunction(x,hashTable->table_size);
	
	if(hashTable->table[pos]==NULL){
		hashTable->table[pos]=(Block*)malloc(sizeof(Block));
		hashTable->table[pos]->data=x;
		hashTable->table[pos]->next=NULL;
	}
	else{
		Block* link=hashTable->table[pos];
		while(link->next)
			link=link->next;
		Block *tmp=(Block*)malloc(sizeof(Block));
		tmp->data=x;
		tmp->next=NULL;
		
		link->next=tmp;
	}
}

void displayChain(Block *link){
	if(link){
		Block* tmp=link;
		while(tmp->next){
			printf(" %d ",tmp->data);
			tmp=tmp->next;
		}
		printf(" %d ",tmp->data);
	}
} 

void displayTable(HashADT *hashTable){
	for(int i=0;i<hashTable->table_size;i++){
		printf("\n%d-- ",i);
		displayChain(hashTable->table[i]);
		printf("\n");
	}
}

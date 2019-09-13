#include"BSTProto.h"

int mystrcmp(char str1[],char str2[]){
	int i=0;
	while(str1[i]&&str2[i]){
		if(str1[i]>str2[i])
			return 1;
		else if(str1[i]<str2[i])
			return -1;
		else
			i++;
		return 0;
	}
}

void displayPlayer(playerInfo pi){
	printf("Name: %s\nRole: %s\n",pi.name,pi.role);
}

playerProfile* findmin(playerProfile *P){  
    if(P==NULL)
    	printf("Tree empty"); 
    while(P->left!=NULL)
    	return findmin(P->left);
    if(P->left==NULL)
    	printf("\n Minimum in the tree = %d",P->pi.name);  
}
/*
void initialise(playerProfile *pp){
	pp=(playerProfile*)malloc(sizeof(playerProfile));
	pp->left=NULL;
	pp->right=NULL;
}*/

playerProfile* insert(playerProfile *P, playerInfo x){
	//displayPlayer(x);
	printf("\nH1\n");
	if(P==NULL){
		printf("\nH0\n");
		P=(playerProfile*)malloc(sizeof(playerProfile));
		P->pi=x;
		P->left=NULL;
		P->right=NULL;
		//displayPlayer(P->pi);
	}
	else if(strcmp(x.name,P->pi.name)<0){
		P->left=insert(P->left,x);
		printf("\nH2\n");
	}
	else if(strcmp(x.name,P->pi.name)>0){ 
		P->right=insert(P->right,x);
		printf("\nH3\n");
	}
	printf("\nH4\n");
	return P;
}

playerProfile* deleteNode(playerProfile *Q, char name[]){
	playerProfile *tmp=NULL;
	if(strcmp(name,Q->pi.name)<0)
		deleteNode(Q->left,name);
	else if(strcmp(name,Q->pi.name)>0) 
		deleteNode(Q->right,name);
	else if(Q->left&&Q->right){
		tmp=findmin(Q->right);
		Q->pi=tmp->pi;
		Q->right=deleteNode(Q->right,Q->pi.name);
	}
	else{
		tmp=Q;
		if(!Q->right) 
			Q=Q->left;
		if(!Q->left)
			Q=Q->right;
		free(tmp);
	}
	return Q;
}


	
void disp(playerProfile *Q,int depth){
	if(Q){
		printf("\nHI1\n");
		for(int i=0;i<depth;i++)
			printf("\t");
		
		displayPlayer(Q->pi);
		printf("\nHI2\n");
		disp(Q->left,depth+1);
		printf("\nHI3\n");
		disp(Q->right,depth+1);
		printf("\nHI4\n");
	}
}

void search(playerProfile *P, char name[]){
	if(P==NULL)
		printf("\nNo such record \n");
	if(!mystrcmp(name,P->pi.name))
		displayPlayer(P->pi);
	if(strcmp(name,P->pi.name)<0)
		search(P->left,name);
	if(strcmp(name,P->pi.name)>0)
		search(P->right,name);
}	

void preorder(playerProfile *P){
	displayPlayer(P->pi);
	if(P->left)
		preorder(P->left);
	if(P->right)
		preorder(P->right);
}

void inorder(playerProfile *P){
	
	if(P->left)
		preorder(P->left);
	displayPlayer(P->pi);
	if(P->right)
		preorder(P->right);
}

void postorder(playerProfile *P){
	if(P->left)
		preorder(P->left);
	if(P->right)
		preorder(P->right);
	displayPlayer(P->pi);
}

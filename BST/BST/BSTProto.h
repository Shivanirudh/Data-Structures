#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[100];
	char role[100];
	double avgRR;
}playerInfo;

struct Play{
	playerInfo pi;
	struct Play* left;
	struct Play* right;
};

typedef struct Play playerProfile;

void initialise(playerProfile *pp);

playerProfile* insert(playerProfile *P, playerInfo x);

playerProfile* deleteNode(playerProfile *Q, char name[]); 
	
void disp(playerProfile *Q,int depth);

void search(playerProfile *P, char name[]); 	

void preorder(playerProfile *P);

void inorder(playerProfile *P);

void postorder(playerProfile *P);

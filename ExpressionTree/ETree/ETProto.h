#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char data[100];
	int top, limit;
}CharStack;

struct node{
	char element;
	struct node* left;
	struct node* right;
};

typedef struct node Tree;


typedef struct
{
 Tree* data[100];
 int top,limit;
}NodeStack;

int NodeisEmpty(NodeStack *S);
int NodeisFull(NodeStack *S);
void Nodepush(NodeStack *S,Tree *t);
Tree* Nodepop(NodeStack *S);
void Nodedisp(NodeStack S);
void Nodesize(NodeStack S);
void initializeNode(NodeStack *S);


typedef struct{
	char *infix;
	char *postfix;
	int value;
	NodeStack NS;
	CharStack CS;
}ExpTADT;


int isFull(CharStack S);

int isEmpty(CharStack S);

void initialise(CharStack *S);

void push(CharStack *S,char x);

char pop(CharStack *S);

void displayTree(Tree *t,int depth);

void ETinitialise(ExpTADT *e);

void ETdisplay(ExpTADT e);

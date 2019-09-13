#include "ETProto.h"

int isFull(CharStack S){
	return ((S.top+1)==S.limit)?1:0;
}

int isEmpty(CharStack S){
	return (S.top==-1)?1:0;
}

void push(CharStack *S,char x){
	if(isFull(*S))
		printf("Stack is full");
	else{
		(*S).top++;
		(*S).data[(*S).top]=x;
	}
}

char pop(CharStack *S){
	if(isEmpty(*S))
		printf("Stack is empty");
	else
		return (*S).data[(*S).top--];
}

void initialise(CharStack *S){
	(*S).top=-1;
	printf("Enter maximum limit ");scanf("%d",&((*S).limit));
}

void displayTree(Tree *t,int depth){
	if(t){
		
		for(int i=0;i<depth;i++)
			printf("\t");
		
		printf("%c\n",t->element);
		
		displayTree(t->left,depth+1);
		displayTree(t->right,depth+1);
	}
}		

void ETinitialise(ExpTADT *e){
	e->infix=(char*)malloc(sizeof(100));
	e->postfix=(char*)malloc(sizeof(100));
	e->value=0;
	initializeNode(&e->NS);
	initialise(&e->CS);
}

void ETdisplay(ExpTADT e){
	printf("\n\nThe infix expression is \n%s\n",e.infix);
	printf("\n\nThe postfix expression is \n%s\n",e.postfix);
	printf("\n\nThe value of the expression is %d\n",e.value);
}

int NodeisEmpty(NodeStack *S)
{
 if(S->top==-1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

int NodeisFull(NodeStack *S)
{
 if(S->top+1==S->limit)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

void Nodepush(NodeStack *S,Tree* t)
{
 
 if(NodeisFull(S)==1)
 {
  printf("Stack is full");
 }
 else
 {
  
  (*S).data[++((*S).top)]=t;
 }
}

Tree* Nodepop(NodeStack *S)
{
 Tree* t;
 if(NodeisEmpty(S)==1)
 { 
  printf("Stack is empty");
 }
 else
 { 
  t=(*S).data[(*S).top];
  ((*S).top)--;
 }
 return t;
}

void Nodedisp(NodeStack S)
{
 int i;
 if(NodeisEmpty(&S)==1)
 {
  printf("The stack is empty");
 }
 else
 {
  printf("The Current Stack is:\n");
  for(i=0;i<=S.top;i++)
  {
   printf("%c ",(S.data[i])->element);
  }
 }
 printf("\n");
}

void size(NodeStack S)
{
 printf("%d\n",S.top+1);
}


void initializeNode(NodeStack *S)
{
 printf("Enter the upper limit of the stack:\t");
 scanf("%d",&((*S).limit));
 (*S).top=-1;
}	

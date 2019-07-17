#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char data[100];
	int capacity;
	int top;
}Stack;

void initialise(Stack *S){
	printf("Enter capacity ");scanf("%d",&((*S).capacity));
	(*S).top=-1;
}

void push(Stack *S,char data){
	if((*S).top==(*S).capacity)
		printf("No space available ");
	else{
		(*S).data[++(*S).top]=data;
	}
}

void pop(Stack *S){
	if((*S).top==-1)
		printf("No element available ");
	else{
		(*S).top--;
	}
}

int main(){
	char exp[50];
	Stack S;initialise(&S);
	
	printf("Enter the expression ");scanf("%s",exp);
	
	for(int i=0;i<S.capacity;i++){
		if(exp[i]=='['||exp[i]=='{'||exp[i]=='(')
			push(&S,exp[i]);
		else if(exp[i]==']'||exp[i]=='}'||exp[i]==')'){
			if(exp[i]==']' && S.data[S.top]=='[')
				pop(&S);
			else if(exp[i]=='}' && S.data[S.top]=='{')
				pop(&S);
			else if(exp[i]==')' && S.data[S.top]=='(')
				pop(&S);
			else
				break;
		}
	}
	
	if(S.top==-1)
		printf("Balanced\n");
	else
		printf("Unbalanced\n");
}
	

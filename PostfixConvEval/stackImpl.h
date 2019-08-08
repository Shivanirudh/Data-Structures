#include"stackProto.h"

int isFull(CharStack S){
	return ((S.top+1)==S.limit)?1:0;
}

int IisFull(IntStack S){
	return ((S.top+1)==S.limit)?1:0;
}

int isEmpty(CharStack S){
	return (S.top==-1)?1:0;
}

int IisEmpty(IntStack S){
	return (S.top==-1)?1:0;
}

void display(CharStack S){
	if(isEmpty(S))
		printf("Stack is empty");
	else{
		for(int i=S.top;i>=0;i--)
			printf("%c\n",S.data[i]);
	}
}

void Idisplay(IntStack S){
	if(IisEmpty(S))
		printf("Stack is empty");
	else{
		for(int i=S.top;i>=0;i--)
			printf("%d\n",S.data[i]);
	}
}

void push(CharStack *S,char x){
	if(isFull(*S))
		printf("Stack is full");
	else{
		(*S).top++;
		(*S).data[(*S).top]=x;
	}
}

void Ipush(IntStack *S,int x){
	if(IisFull(*S))
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

int Ipop(IntStack *S){
	if(IisEmpty(*S))
		printf("Stack is empty");
	else
		
		return (*S).data[(*S).top--];
}

void initialise(CharStack *S){
	(*S).top=-1;
	printf("Enter maximum limit ");scanf("%d",&((*S).limit));
}

void Iinitialise(IntStack *S){
	(*S).top=-1;
	printf("Enter maximum limit ");scanf("%d",&((*S).limit));
}

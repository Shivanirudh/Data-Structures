#include "ETImpl.h"


int isDigit(char ch){
	return (ch>='0'&&ch<='9')?1:0;
}

char* infixToPostfix(char *infix){
	char *postfix=(char*)malloc(sizeof(100));
	CharStack operator;
	operator.top=-1;
	printf("Enter maximum limit ");scanf("%d",&operator.limit);
	
	int i=0,p=0;
	while(infix[i]){
		if(isDigit(infix[i]))
			postfix[p++]=infix[i];
		else{
			switch(infix[i]){
				case '%':
				case '/':
				case '*':
					if(operator.data[operator.top]=='+'||operator.data[operator.top]=='-'||operator.top==-1)
						push(&operator,infix[i]);
					else{
						while(operator.data[operator.top]=='*'){
							char ch=pop(&operator);
							postfix[p++]=ch;
						}
						while(operator.data[operator.top]=='/'){
							char ch=pop(&operator);
							postfix[p++]=ch;
						}
						while(operator.data[operator.top]=='%'){
							char ch=pop(&operator);
							postfix[p++]=ch;
						}
						push(&operator,infix[i]);
					}
					break;
				case '-':
				case '+':
						if(operator.top==-1)
							push(&operator,infix[i]);
						else{	
							while(operator.data[operator.top]=='*'){
								char ch=pop(&operator);
								postfix[p++]=ch;
							}
							while(operator.data[operator.top]=='/'){
								char ch=pop(&operator);
								postfix[p++]=ch;
							}
							while(operator.data[operator.top]=='%'){
								char ch=pop(&operator);
								postfix[p++]=ch;
							}
							while(operator.data[operator.top]=='+'){
								char ch=pop(&operator);
								postfix[p++]=ch;
							}
							
							while(operator.data[operator.top]=='-'){
								char ch=pop(&operator);
								postfix[p++]=ch;
							}
								
							push(&operator,infix[i]);
						}
						break;
			}
		}
		i++;
	}
		
	while(operator.top!=-1){
		char ch=pop(&operator);
		postfix[p++]=ch;				
	}
	postfix[p]='\0';
		
	return postfix;
}

Tree* postfixToET(char *postfix)
{
 NodeStack NS;
 initializeNode(&NS);
 int i=0;
 while(postfix[i])
 {
  if(isDigit(postfix[i]))
  {
   Tree *t=(Tree*)malloc(sizeof(Tree));
   t->element=postfix[i];
   t->right=t->left=NULL;
   Nodepush(&NS,t);
  }
  else 
  {
   Tree *t=(Tree*)malloc(sizeof(Tree));
   t->element=postfix[i];
   t->right=Nodepop(&NS);
   t->left=Nodepop(&NS);
   Nodepush(&NS,t);
  }
  i++;
 }
 return Nodepop(&NS);
}

int Apply(int x,char y,int z){
	switch(y){
		case '/':return x/z;break;
		case '*':return x*z;break;
		case '+':return x+z;break;
		case '-':return x-z;break;
	}
}

int Evaluate(Tree *ET){
	int val=0;
	if(isDigit(ET->element))
		return ET->element-48;
	else{
		int leftop=Evaluate(ET->left);
		int rightop=Evaluate(ET->right);
		val=Apply(leftop,ET->element,rightop);
		return val;
	}
}
void main(){
	ExpTADT expt;
	ETinitialise(&expt);
	
	
	printf("Enter infix expression ");
	scanf("%s",expt.infix);
	
	expt.postfix=infixToPostfix(expt.infix);
	
	Tree *ET=postfixToET(expt.postfix);
	displayTree(ET,0);
	
	expt.value=Evaluate(ET);
	ETdisplay(expt);
	
}
	
/*
Output:
Enter the upper limit of the stack:	100
Enter maximum limit 100
Enter infix expression 4*5-2/1
Enter maximum limit 100
Enter the upper limit of the stack:	100
-
	*
		4
		5
	/
		2
		1


The infix expression is 
4*5-2/1


The postfix expression is 
45*21/-


The value of the expression is 18

*/	

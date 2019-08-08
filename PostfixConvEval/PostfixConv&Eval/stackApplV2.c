#include"stackImpl.h"

int isDigit(char ch){
	return (ch>='0'&&ch<='9')?1:0;
}

char* infixToPostfix(char infix[]){
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
								
int evalPostfix(char* postfix){
	IntStack operand;
	operand.top=-1;
	printf("Enter maximum limit ");scanf("%d",&operand.limit);
	int i=0;
	while(postfix[i]){
		if(isDigit(postfix[i]))
			Ipush(&operand,postfix[i]);
		else{
			int n1,n2;
			n2=Ipop(&operand);n1=Ipop(&operand);
			double result;
			switch(postfix[i]){
				case '+':
					result=n1-48+n2-48;break;
				case '-':
					result=n1-n2;break;
				case '*':
					result=(n1-48)*(n2-48);break;
				case '/':
					result=(n1-48)/(n2-48);break;
				case '%':
					result=(n1-48)%(n2-48);break;
			}
			
			int value=(int)result;
			value+=48;
			Ipush(&operand,value);
			
		}
		i++;
	}
	
	int reqValue=Ipop(&operand);
	reqValue-=48;
	return reqValue;
}
	
	
					
	
void main(){
	char infix[100],*postfix;
	postfix=(char*)malloc(sizeof(100));
	
	printf("Enter infix expression ");
	scanf("%s",infix);
	
	postfix=infixToPostfix(infix);
	
	printf("\n\nThe infix expression is \n%s\n",infix);
	printf("\n\nThe postfix expression is \n%s\n",postfix);
	
	int result;
	result=evalPostfix(postfix);
	printf("\nThe value of the postfix expression is %d\n",result);
}

/*
Output:
Enter infix expression 3-4+5*6/3
Enter maximum limit 100


The infix expression is 
3-4+5*6/3


The postfix expression is 
34-56*3/+
Enter maximum limit 100

The value of the postfix expression is 9
*/

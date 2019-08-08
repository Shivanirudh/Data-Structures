#include"stackImpl.h"

void main(){
	IntStack iS;CharStack cS;
	Iinitialise(&iS);initialise(&cS);

	int opt;char choice='Y';int x;char ch;
	do{
		printf("What operation do you want to perform? 1-push 2-pop 3-display stack:  ");scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter value to be pushed ");scanf("%d",&x);getchar();
				printf("Enter character to be pushed ");scanf("%c",&ch);
				Ipush(&iS,x);push(&cS,ch);break;
			case 2:
				printf("Integer:%d\n",Ipop(&iS));
				printf("Character:%c\n",pop(&cS));break;
			case 3:
				printf("The integer stack is:\n");
				Idisplay(iS);
				printf("The character stack is:\n");
				display(cS);break;
		}
		printf("Do you want to perform another operation?(y/n)");scanf(" %c",&choice);
	}while(choice=='Y'||choice=='y');
}

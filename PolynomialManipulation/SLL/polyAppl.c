#include"polyImpl.h"

void main(){
	polyADT *p1;
	p1=(polyADT*)malloc(sizeof(polyADT));
	p1->tm.exp=p1->tm.coeff=0;
	p1->next=NULL;
	
	polyADT *p2;
	p2=(polyADT*)malloc(sizeof(polyADT));
	p2->tm.exp=p2->tm.coeff=0;
	p2->next=NULL;
	
	printf("\nEnter polynomial 1\n");
	//create(&p1);
	term t;
	int option=0;
	do{
		printf("\nWhere to insert?\n [1] Insert at Front\n [2] Insert at End\n [3] Insert after term\n [0] exit\n Your choice: ");scanf("%d",&option);
		

		if(option==1){
			printf("\nEnter the term's coefficent ");scanf("%f",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			insertFront(p1,t);		
			display(p1);
		}
		else if(option==2){
			printf("\nEnter the term's coefficent ");scanf("%f",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			insertEnd(p1,t);
		}
		else if(option==3){
			int exp;
			printf("\nEnter the term's coefficent ");scanf("%f",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			printf("Enter the exponent after which the term is to be inserted ");scanf("%d",&exp);
			insertAfterTerm(p1,t,exp);
		}
		else if(option!=0)
			printf("Invalid option\n");
		else
			break;
	}while(option);
	
	printf("\nEnter polynomial 2\n");
	//create(&p2);
	do{
		printf("\nWhere to insert? 1-Insert at Front 2-Insert at End 3-Insert after term 0-exit ");scanf("%d",&option);
		

		if(option==1){
			printf("\nEnter the term's coefficent ");scanf("%f",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			insertFront(p2,t);
		}
		else if(option==2){
			printf("\nEnter the term's coefficent ");scanf("%f",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			insertEnd(p2,t);
		}
		else if(option==3){
			int exp;
			printf("\nEnter the term's coefficent ");scanf("%f",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			printf("Enter the exponent after which the term is to be inserted ");scanf("%d",&exp);
			insertAfterTerm(p2,t,exp);
		}
		else if(option!=0)
			printf("Invalid option\n");
		else
			break;
	}while(option);
	
	int opt=0, poly=0;
	
	do{
	
		printf("\nWhat do?\n [1]Add\n [2]Multiply\n ");
		printf("[3]Find degree\n [4]Evaluate\n [5]Display\n [0]Exit\n Your choice: ");scanf("%d",&opt);
		
		if(opt!=1&&opt!=2&&opt!=0){
			printf("\nSelect polynomial ");scanf("%d",&poly);
		}
		
		if(opt==1){
			polyADT *result;
			result=(polyADT*)malloc(sizeof(polyADT));
			result=polyAdd(p1,p2);
			display(p1);
			display(p2);
			display(result);
		}
		else if(opt==2){
			polyADT *result;
			result=(polyADT*)malloc(sizeof(polyADT));
			result=polyMul(p1,p2);
			display(p1);
			display(p2);
			display(result);
		}
		else if(opt==3){
			if(poly==1)
				polyDegree(p1);
			else if(poly==2)
				polyDegree(p2);
			else
				printf("\nInvalid option\n");
		}
		else if(opt==4){
			double result=0;
			if(poly==1){
				result=polyEvaluate(p1);
				printf("\nValue of polynomial is: %lf\n",result);
			} 
			else if(poly==2){
				result=polyEvaluate(p2);
				printf("\nValue of polynomial is: %lf\n",result);
			}
			else
				printf("\nInvalid option\n");
		}
		else if(opt==5){
			if(poly==1)
				display(p1);
			else if(poly==2)
				display(p2);
			else
				printf("\nInvalid option\n");
		}
		else if(opt!=0)
			printf("Invalid option\n");
		else;
		
	}while(opt);
}

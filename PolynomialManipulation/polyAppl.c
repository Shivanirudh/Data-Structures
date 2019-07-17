#include<polyAppl.h>

void main(){
	polyADT p1;initialise(&p1);
	polyADT p2;initialise(&p2);
	
	printf("\nEnter polynomial 1\n");
	create(&p1);
	
	printf("\nEnter polynomial 2\n");
	create(&p2);
	
	int opt=0, poly=0;
	
	do{
	
		printf("\nWhat do? 1-Insert at Front 2-Insert at End 3-Insert after term 4-Add 5-Multiply ");
		printf("6-Find degree 7-Evaluate 8-Display ");scanf("%d",&opt);
		
		if(opt!=4&&opt!=5){
			printf("\nSelect polynomial ");scanf("%d",&poly);
		}
		
		if(opt==1){
			term t;
			printf("\nEnter the term's coefficent ");scanf("%d",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			
			if(poly==1)
				insertFront(p1,t);
			else if(poly==2)
				insertFront(p2,t);
			else;
		}
		else if(opt==2){
			term t;
			printf("\nEnter the term's coefficent ");scanf("%d",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			
			if(poly==1)
				insertEnd(p1,t);
			else if(poly==2)
				insertEnd(p2,t);
			else;
		}
		else if(opt==3){
			term t;
			printf("\nEnter the term's coefficent ");scanf("%d",&t.coeff);
			printf("Enter the term's exponent ");scanf("%d",&t.exp);
			int exp;
			printf("Enter the exponent after which the term is to be inserted ");scanf("%d",&exp);
			
			if(poly==1)
				insertAfterTerm(poly1,t,exp);
			else if(poly==2)
				insertAfterTerm(poly2,t,exp);
			else;		
		}
		else if(opt==4){
			display(polyAdd(p1,p2));
		}
		else if(opt==5){
			display(polyMul(p1,p2));
		}
		else if(opt==6){
			if(poly==1)
				polyDegree(p1);
			else if(poly==2)
				polyDegree(p2);
			else;
		}
		else if(opt==7){
			if(poly==1)
				printf("Value is %d\n",polyEvaluate(p1));
			else if(poly==2)
				printf("Value is %d\n",polyEvaluate(p2));
			else;
		}
		else if(opt==8){
			if(poly==1)
				display(p1);
			else if(poly==2)
				display(p2);
			else;
		}
		else if(opt!=0)
			printf("Invalid option\n");
		else;
		}
	}while(opt);
}

#include"polyProto.h"

void initialise(polyADT *p){
	p=(polyADT*)malloc(sizeof(polyADT));
	p->tm.exp=p->tm.coeff=0;
	p->next=NULL;
}

void insertFront(polyADT *p,term t){//1. Input a polynomial through insertion at the front
	polyADT *tmp;
	tmp=(polyADT*)malloc(sizeof(polyADT));	
	
	if(!tmp)
		printf("No space allotted");
	else{
		tmp->tm=t;
		tmp->next=p->next;
		p->next=tmp;
	}
}

void insertEnd(polyADT *p,term t){//2. Input a polynomial through insertion at the end
	polyADT *tmp;
	tmp=(polyADT*)malloc(sizeof(polyADT));	
	
	polyADT *end=p;
	while(end->next!=NULL)end=end->next;
	
	if(!tmp)
		printf("No space allotted ");
	else{
		tmp->tm=t;
		tmp->next=end->next;
		end->next=tmp;
	}
}

void insertAfterTerm(polyADT *p, term t, int exp){//3. Input a polynomial after a term
	polyADT* tmp;
	tmp=(polyADT*)malloc(sizeof(polyADT));	
	
	polyADT *end=p;
	int flag=0;
	while(end->tm.exp != exp&&end->next!=NULL){
		if(end->tm.exp == exp){
			flag=1;break;
		}
		end=end->next;
	}
		
	
	if(!tmp)
		printf("No space allotted");
	else{	
		if(!flag)
			printf("Term not found\n");
		else{
			tmp->tm=t;
			tmp->next=end->next;
			end->next=tmp;
		}
	}
}	

void create(polyADT *p){
	term t;
	int opt=0;
	do{
		printf("\nWhere to insert? 1-Insert at Front 2-Insert at End 3-Insert after term 0-exit ");scanf("%d",&opt);
		

		if(opt==1){
			printf("\nEnter the term's coefficent ");scanf("%d",&t.coeff);
		printf("Enter the term's exponent ");scanf("%d",&t.exp);
			insertFront(p,t);
		}
		else if(opt==2){
			printf("\nEnter the term's coefficent ");scanf("%d",&t.coeff);
		printf("Enter the term's exponent ");scanf("%d",&t.exp);
			insertEnd(p,t);
		}
		else if(opt==3){
			int exp;
			printf("\nEnter the term's coefficent ");scanf("%d",&t.coeff);
		printf("Enter the term's exponent ");scanf("%d",&t.exp);
			printf("Enter the exponent after which the term is to be inserted ");scanf("%d",&exp);
			insertAfterTerm(p,t,exp);
		}
		else if(opt!=0)
			printf("Invalid option\n");
		else
			break;
	}while(opt);
			
}

polyADT* polySimplify(polyADT  *p){//8. Simplifying the polynomial – Combining like terms
	polyADT *tmp1=p;
	
	
	while(tmp1->next!=NULL){
		polyADT *tmp2=tmp1->next;
		polyADT *prev=tmp1;
		while(tmp2->next!=NULL){
			if(tmp1->tm.exp==tmp2->tm.exp){
				tmp1->tm.coeff+=tmp2->tm.coeff;
				prev->next=tmp2->next;
				tmp2=tmp2->next;
			}
			else{	
				prev=tmp2;
				tmp2=tmp2->next;
			}
		}
		tmp1=tmp1->next;
	}
	return p;
}
	
polyADT* polyAdd(polyADT *p1, polyADT *p2){//4. Add two polynomials 
	polyADT *result;
	result=(polyADT*)malloc(sizeof(polyADT));
	
	polyADT *poly1=p1;
	polyADT *poly2=p2;
	
	term t;
	
	while(poly1->next!=NULL && poly2->next!=NULL){
		if(poly1->tm.exp>poly2->tm.exp){
			t=poly1->tm;
			insertEnd(result,t);
			poly1=poly1->next;
		}
		else if(poly2->tm.exp>poly2->tm.exp){
			t=poly2->tm;
			insertEnd(result,t);
			poly2=poly2->next;
		}
		else{
			t.coeff=poly1->tm.coeff+poly2->tm.coeff;
			t.exp=poly1->tm.exp;
			insertEnd(result,t);
			poly1=poly1->next;
			poly2=poly2->next;
		}
	}
	
	while(poly1->next!=NULL){
		t=poly1->tm;
		insertEnd(result,t);
		poly1=poly1->next;
	}
	
	while(poly2->next!=NULL){
		t=poly2->tm;
		insertEnd(result,t);
		poly2=poly2->next;
	}
	
	return result;
}


polyADT* polyMul(polyADT *p1, polyADT *p2){//5. Multiply two polynomials 
	polyADT *result;
	result=(polyADT*)malloc(sizeof(polyADT));
	
	polyADT *poly1=p1;
	polyADT *poly2=p2;
	
	term t;
	
	while(poly1->next!=NULL){
		while(poly2->next!=NULL){
			t.coeff=poly1->tm.coeff*poly2->tm.coeff;
			t.exp=poly1->tm.exp+poly2->tm.exp;
			insertEnd(result,t);
			poly2=poly2->next;
		}
		poly1=poly1->next;
	}
	
	result=polySimplify(result);
	
	return result;
}


void polyDegree(polyADT *p){//6. Find the degree of polynomial

	polyADT *tmp=p;
	int max=0;
	while(tmp->next!=NULL){
		if(tmp->tm.exp>max)
			max=tmp->tm.exp;
		tmp=tmp->next;
	}
	printf("The degree of the polynomial is %d\n ",max);
}

double polyEvaluate(polyADT *p){//7. Evaluate a polynomial 
	double x=0;                //Accepting value of variable
	printf("Enter value of variable ");scanf("%d",&x);
	polyADT *t=p;
	double result=0;
	while(t->next!=NULL){
		double power=pow(x,t->tm.exp);
		double pdt=power*t->tm.coeff;
		result+=pdt;
	}
	return result;
}
	
void sort(polyADT *p){
	p=polySimplify(p);
	
	polyADT *tmp1=p;
	
	int max=0;
	
	while(tmp1->next!=NULL){
		polyADT *tmp=tmp1->next;
		polyADT *maxTerm=tmp;
		max=tmp1->tm.exp;
		while(tmp->next!=NULL){
			if(tmp->tm.exp>max){
				max=tmp->tm.exp;
				maxTerm=tmp;
			}
			tmp=tmp->next;
		}
		polyADT *swap=maxTerm;
		maxTerm=tmp1;
		tmp1=swap;
		tmp1=tmp1->next;
	}
}

void display(polyADT *p){
	//sort(p);
	polyADT *t=p;

	printf("\n");
	do{
		//t=t->next;		
		if(t->tm.coeff>0)
			printf("+");
		printf("%d",t->tm.coeff,"x ^ %d",t->tm.exp," ");
		
	}while(t->next!=NULL);
	printf("\n");
}	


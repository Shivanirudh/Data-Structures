#include<polyProto.h>

void initialise(polyADT *p){
	p->t.exp=p->t.coeff=0;
	p->next=NULL;
}

void insertFront(polyADT *p,term t){//1. Input a polynomial through insertion at the front
	polyADT tmp=NULL;initialise(&tmp);
	polyADT *t=p;
	while(t->next!=NULL)
		t=t->next;
		
	tmp.exp=p->exp;
	tmp.coeff=p->coeff;
	tmp.next=t->next;
	t->next=tmp;	
}

void insertEnd(polyADT *p,term t){//2. Input a polynomial through insertion at the end
	polyADT tmp=NULL;initialise(&tmp);
	
	tmp.exp=p->exp;
	tmp.coeff=p->coeff;
	tmp.next=p;
	p=tmp;
		
}

void insertAfterTerm(polyADT *p, term t, int exp){//3. Input a polynomial after a term
	polyADT tmp=NULL;initialise(&tmp);
	
	polyADT *t=p;
	while(t->(t.exp) != exp&&t->next!=NULL)
		t=t->next;
	
	if(t->next==NULL)
		insertFront(p,t);
	else{	
		tmp.exp=p->exp;
		tmp.coeff=p->coeff;
		tmp.next=t->next;
		t->next=tmp;
	}
}	

void create(polyADT *p){
	term t;
	int opt=0;
	do{
		printf("\nWhere to insert? 1-Insert at Front 2-Insert at End 3-Insert after term 0-exit ");scanf("%d",&opt);
		printf("\nEnter the term's coefficent ");scanf("%d",&t.coeff);
		printf("Enter the term's exponent ");scanf("%d",&t.exp);

		if(opt==1){
			insertFront(p,t);
		}
		else if(opt==2){
			insertEnd(p,t);
		}
		else if(opt==3){
			int exp;
			printf("Enter the exponent after which the term is to be inserted ");scanf("%d",&exp);
			insertAfterTerm(p,t,exp);
		}
		else if(opt!=0)
			printf("Invalid option\n");
		else
			break;
	}while(opt);
			
}
polyADT polySimplify(polyADT  p){//8. Simplifying the polynomial – Combining like terms
	polyADT *t=&p;
	while(t->next!=NULL){
		polyADT *tmp=t;
		polyADT *del=tmp;
		tmp=tmp->next;
		while(tmp->next!=NULL){
			if(tmp->(t.exp)==t->(t.exp){
				t->(t.coeff)+=tmp->(t.coeff);
				del->next=tmp->next;
				tmp=tmp->next;
			}
			else{
				del->next=tmp->next;
				del=tmp;
				tmp=tmp->next;
			}
		}
	}
	return p;
}
	
polyADT polyAdd(polyADT p1, polyADT p2){//4. Add two polynomials 
	polyADT *result;initialise(*result);
	polyADT *tmp=result;
	polyADT sum;initialise(&sum);
	polyADT *poly1=p1;
	polyADT *poly2=p2;
	
	while(poly1->next!=NULL&&poly->next!=NULL){
		if(poly1->(t.exp) > poly2->(t.exp)){
			sum.t.exp=poly1->(t.exp);
			sum.t.coeff=poly1->(t.coeff);
			poly1=poly1->next;
			
		}
		else if(poly2->(t.exp) > poly1->(t.exp)){
			sum.t.exp=poly2->(t.exp);
			sum.t.coeff=poly2->(t.coeff);
			poly2=poly2->next;
		}
		else{
			sum.t.exp=poly1->(t.exp);
			sum.t.coeff=poly1->(t.coeff)+poly2->(t.coeff);
			poly1=poly1->next;poly2=poly2->next;
		}
		tmp->next=&sum;
		tmp=tmp->next;
	}
	
	return &result;
}


polyADT polyMul(polyADT p1, polyADT p2){//5. Multiply two polynomials 
	polyADT *result;initialise(*result);
	polyADT *tmp=result;
	polyADT pdt;initialise(&pdt);
	polyADT *poly1=p1;
	polyADT *poly2=p2;
	
	while(poly1->next!=NULL){
		while(poly2->next!=NULL){
			pdt.t.exp=(poly1->t.exp)+(poly2->t.exp);
			pdt.t.coeff=(poly1->t.coeff)*(poly2->t.coeff);
		}
		tmp->next=&pdt;
		tmp=tmp->next;
	}
		
	polySimplify(*result);	
	return &result;
}


void polyDegree(polyADT  p){//6. Find the degree of polynomial

	polyADT *t=p;
	int max=0;
	while(t->next!=NULL){
		if(t->(t.exp)>max)
			max=t->(t.exp);
		t=t->next;
	}
	printf("The degree of the polynomial is %d\n ",max);
}

int polyEvaluate(polyADT p){//7. Evaluate a polynomial 
	int x=1;                //Assuming value of variable
	polyADT *t=p;int result=0;
	while(t->next!=NULL){
		int power=pow(x,t->(t.exp));
		int pdt=power*t->(t.coeff);
		result+=pdt;
	}
	return result;
}
	
void sort(polyADT p){
	p=polySimplify(p);
	polyADT *t=&p;polyADT *del=NULL;
	polyADT *tmp=NULL;initialise(tmp);
	
	while(TRUE){
		int max=0;term tempo;
		while(t->next!=NULL){
			if(t->(t.exp)>max){
				max=t->(t.exp);
				tempo=t->t;
			}
			t=t->next;
		}
		insertEnd(tmp,tempo);
		while(t->(t.exp))!=max){
			del=t;
			t=t->next;
		}
		del->next=t->next;
		t=&p;del=NULL;
		if(!max)
			break;
	}
	p=tmp;

}

void display(polyADT p){
	sort(p);
	polyADT *t=&p;

	while(t->next!=NULL){
		if(t->(t.coeff)>0)
			printf("+");
		printf("%d",t->(t.coeff),"x^%d",t->(t.exp)," ");
	}
}	


#include"PriQProto.h"

int mystrcmp(char s1[],char s2[]){
	int flag=0;
	int i;
	for(i=0;s1[i]&&s2[i]&&!flag;i++)
		if(s1[i]>s2[i])
			flag=1;
		else if(s1[i]<s2[i])
			flag=-1;
	if(s1[i]&&!s2[i])
		flag=1;
	if(!s1[i]&&s2[i])
		flag=-1;
	return flag;
}

void initialise(priorityQueueADT *P,int max){
	P->capacity=max;
	P->size=0;
	P->emp[0].name[0]= '\0';
	P->emp[0].id=0;
	P->emp[0].salary=0;
}

void insert(priorityQueueADT *P, empDetails x){
	int i;
	for( i=++P->size;P->emp[i/2].salary>x.salary; i/=2)
		P->emp[i] = P->emp[i/2];
	P->emp[i]=x;
}

void dispEmpName(empDetails emp){
	printf("Name: %s \n",emp.name);
}
void dispEmpID(empDetails emp){
	printf("ID: %d\n",emp.id);
}
void dispEmpSalary(empDetails emp){
	printf("Salary: %lf\n",emp.salary);
} 
void spacing(int n){
	if(n%2)n--;
	for(int i=1;i<n;i++)
		printf("\t");
}

void disp(priorityQueueADT *P,int index){
	if(index<=P->size){
		printf("\n");
		spacing(index);dispEmpName(P->emp[index]);
		spacing(index);dispEmpID(P->emp[index]);
		spacing(index);dispEmpSalary(P->emp[index]);
		disp(P,2*index);
		disp(P,2*index+1);
	}
}

empDetails delete(priorityQueueADT *P){ 
	int i,child;
	empDetails min,last;
	min=P->emp[1];
	last=P->emp[P->size--];
	
	for(i=1;i*2<P->size;i=child){
		child=i*2;
		if(P->emp[child+1].salary<P->emp[child].salary)
			child++;
		if(last.salary>P->emp[child].salary)
			P->emp[i]=P->emp[child];
		else
			break;
	}
	
	P->emp[i]=last;
	return min;
}
		

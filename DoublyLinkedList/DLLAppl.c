#include"DLLImpl.h"

void setPIN(Person *p,DLList *dll){
	/*printf("\nHello1\n");
	//srand(time(0));
	printf("\nHello2\n");*/
	if(dll->right==NULL)
		p->PIN=0;
	else{
		DLList *tmp=dll;
		int count=0;
		while(tmp->right!=NULL){
			count++;
			tmp=tmp->right;
		}
		p->PIN=count;
	}

	/*int x,flag=0;
	do{
		x=rand();
		if(x==tmp->per.PIN){
			flag=1;
			break;
		}
		else
			tmp=tmp->right;
	}while(tmp->right!=NULL);
	
	if(!flag)
		p->PIN=x;*/
}

void getPerson(Person *p,DLList *dll){
	printf("Enter name: ");scanf(" %[^\n]",p->name);getchar();
	printf("Enter age: ");scanf("%d",&p->age);getchar();
	printf("Enter sex: ");scanf("%c",&p->sex);
	printf("Enter City Address: ");scanf(" %[^\n]",p->cityAddress);getchar();
	printf("Enter Street Address: ");scanf(" %[^\n]",p->streetAddress);getchar();
	printf("Enter mobile number: ");scanf(" %[^\n]",p->mobNo);getchar();
	if(dll->right==NULL)
		p->PIN=0;
	else
		setPIN(p,dll);
}

void main(){

	DLList *dll;
	dll=(DLList*)malloc(sizeof(DLList));
	
	initPerson(&((*dll).per));
	dll->right=NULL;
	dll->left=NULL;	
	//initList(dll);
	
	Person *p;//initPerson(p);
	p=(Person*)malloc(sizeof(Person));
	(*p).name=(char*)malloc(50*sizeof(char));
	(*p).PIN=0;(*p).age=0;
	(*p).sex='M';(*p).mobNo=(char*)malloc(10*sizeof(char));
	(*p).cityAddress=(char*)malloc(100*sizeof(char));
	(*p).streetAddress=(char*)malloc(100*sizeof(char));	
	char opt;
	int work;
	
	do{	
		printf("\nWhat do you want to do ?\n");
		printf("[1]-insert at the front \n[2]-insert at the end \n");
		printf("[3]-insert after PIN \n[4]-list senior citizens \n");
		printf("[5]-list adults \n[6]-list location-wise \n");
		printf("[7]-sort and display \n[8]-Print number of persons \n");
		printf("[9]-give gender ratio \n[10]-Display persons in list \n");
		printf("[0]-exit \nYour choice: ");scanf("%d",&work);
		
		if(work==1){
			p=(Person*)malloc(sizeof(Person));
			(*p).name=(char*)malloc(50*sizeof(char));
			(*p).PIN=0;(*p).age=0;
			(*p).sex='M';(*p).mobNo=(char*)malloc(10*sizeof(char));
			(*p).cityAddress=(char*)malloc(100*sizeof(char));
		(*p).streetAddress=(char*)malloc(100*sizeof(char));	
			getPerson(p,dll);
			insertFront(dll,*p);
			listPersons(dll);
		}
		else if(work==2){
			p=(Person*)malloc(sizeof(Person));
			(*p).name=(char*)malloc(50*sizeof(char));
			(*p).PIN=0;(*p).age=0;
			(*p).sex='M';(*p).mobNo=(char*)malloc(10*sizeof(char));
			(*p).cityAddress=(char*)malloc(100*sizeof(char));
		(*p).streetAddress=(char*)malloc(100*sizeof(char));	
			getPerson(p,dll);
			insertEnd(dll,*p);
			listPersons(dll);
		}
		else if(work==3){
			p=(Person*)malloc(sizeof(Person));
			(*p).name=(char*)malloc(50*sizeof(char));
			(*p).PIN=0;(*p).age=0;
			(*p).sex='M';(*p).mobNo=(char*)malloc(10*sizeof(char));
			(*p).cityAddress=(char*)malloc(100*sizeof(char));
			(*p).streetAddress=(char*)malloc(100*sizeof(char));	
			getPerson(p,dll);
			int pin;
			printf("Enter PIN after which entry is to be done ");
			scanf("%d",&pin);
			insertPIN(dll,*p,pin);
			listPersons(dll);
		}
		else if(work==4){
			DLList *seniors;
			seniors=(DLList*)malloc(sizeof(DLList));
			seniors=seniorPerson(dll);
			listPersons(dll);
		}
		else if(work ==5){
			DLList *adults;
			adults=(DLList*)malloc(sizeof(DLList));
			adults=adult(dll);
			listPersons(dll);
		}
		else if(work==6){
			DLList *location;
			location=(DLList*)malloc(sizeof(DLList));
			char area[50];
			printf("Enter the location to search for ");
			scanf("%[^\n]",area);
			location=locatePerson(dll,area);
		}
		else if(work==7){
			listSort(dll);
		}
		else if(work==8){
			printf("\n\nThe number of people in the list is %d\n", noPersons(dll));
		}
		else if(work==9){
			Ratio rat;
			rat=adultPerson(dll);
			printf("\nThe gender ratio is %.2lf:%.2lf\n",rat.noMale,rat.noFemale);
		}
		else  if(work==10){
			listPersons(dll);
		}
		else if(work!=0)
			printf("\nInvalid Input\n");
		else;
			
		getchar();
		printf("\nDo you want to perform any other operation (y/n)");
		scanf("%c", &opt);
	}while(opt=='y'||opt=='Y');
	
	//displayList(dll);
}


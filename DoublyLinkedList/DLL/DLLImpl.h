#include"DLLProto.h"

void initPerson(Person *p){
	(*p).name=(char*)malloc(50*sizeof(char));
	(*p).PIN=0;(*p).age=0;
	(*p).sex='M';(*p).mobNo=(char*)malloc(10*sizeof(char));
	(*p).cityAddress=(char*)malloc(100*sizeof(char));
	(*p).streetAddress=(char*)malloc(100*sizeof(char));
}

void initList(DLList *dll){
	dll=(DLList*)malloc(sizeof(DLList));
	
	initPerson(&((*dll).per));
	dll->right=NULL;
	dll->left=NULL;
}

void insertFront(DLList *dll,Person p){
	DLList *tmp;
	tmp=(DLList*)malloc(sizeof(DLList));
	
	if(!tmp)
		printf("No space allotted ");
	else{
		tmp->per=p;
		if(dll->right==NULL){
			tmp->right=NULL;
			dll->right=tmp;
			tmp->left=dll;
		}
		else{
			tmp->right=dll->right;
			(dll->right)->left=tmp;
			dll->right=tmp;
			tmp->left=dll;
		}
	}
}

void insertEnd(DLList *dll, Person p){
	DLList *tmp;
	tmp=(DLList*)malloc(sizeof(DLList));
	if(!tmp)
		printf("No space allotted ");
	else{
		tmp->per=p;
		if(dll->right==NULL){
			tmp->right=NULL;
			dll->right=tmp;
			tmp->left=dll;
		}
		else{
			DLList* rear=dll;
			while(rear->right!=NULL)rear=rear->right;
			
			tmp->right=rear->right;
			rear->right=tmp;
			tmp->left=rear;
		}
	}
}

void insertPIN(DLList *dll, Person p, int pin){
	DLList *tmp;
	tmp=(DLList*)malloc(sizeof(DLList));
	if(!tmp)
		printf("No space allotted ");
	else{
		DLList *reqNode=dll;int flag=0;
		while(reqNode->per.PIN!=pin){
			reqNode=reqNode->right;
			if(reqNode->per.PIN==pin)		
				flag=1;
		}
		if(flag){
			tmp->per=p;
			tmp->right=reqNode->right;
			(reqNode->right)->left=tmp;
			reqNode->right=tmp;	
			tmp->left=reqNode;
		}
		else
			printf("\nPIN not found ");
	}
}

DLList* seniorPerson(DLList *dll){
	DLList *seniors;
	seniors=(DLList*)malloc(sizeof(DLList));
	
	initPerson(&((*seniors).per));
	seniors->right=NULL;
	seniors->left=NULL;	

	DLList *tmp=dll;
	while(tmp->right!=NULL){
		printf("\nSenior\n");
		if(tmp->per.age>=60){
			insertFront(seniors,tmp->per);
		}
		tmp=tmp->right;
	}
	
	return seniors;
}

DLList* adult(DLList *dll){
	DLList *adults;
	adults=(DLList*)malloc(sizeof(DLList));
	
	initPerson(&((*adults).per));
	adults->right=NULL;
	adults->left=NULL;	
	DLList *tmp=dll;
	while(tmp->right!=NULL){
		if(tmp->per.age>=18){
			insertFront(adults,tmp->per);
		}
		tmp=tmp->right;
	}
	
	return adults;
}

DLList* locatePerson(DLList *dll, char * s){
	DLList *location;
	location=(DLList*)malloc(sizeof(DLList));
	
	initPerson(&((*location).per));
	location->right=NULL;
	location->left=NULL;	
	DLList *tmp=dll;
	while(tmp->right!=NULL){
		if(!strcmp(tmp->per.cityAddress,s)){
			insertFront(location,tmp->per);
		}
		tmp=tmp->right;
	}
	
	return location;
}

void displayPerson(Person p){
	printf("\nName: %s\nPIN: %d\nAge: %d\nSex: %c",p.name,p.PIN,p.age,p.sex);
	printf("\nCity Address: %s\nStreet Address: %s\nMobile: %s\n\n", p.cityAddress,p.streetAddress,p.mobNo);
}		

void listPersons(DLList *dll){
	printf("\n Forward order: \n");
	DLList *tmp=dll;
	/*
	while(tmp->right!=NULL){
		displayPerson(tmp->per);
		tmp=tmp->right;
	}*/
	do{	
		tmp=tmp->right;
		displayPerson(tmp->per);
		
	}while(tmp->right!=NULL);
	
	printf("\n Reverse order: \n");
	while(tmp->left!=NULL){
		displayPerson(tmp->per);
		tmp=tmp->left;
	}
	
}

void listSort(DLList *dll){
	
	DLList *tmp1=dll;
	int min;
	
	while(tmp1->right!=NULL){
		min=tmp1->per.age;
		DLList *tmp2=tmp1->right;
		DLList *minAge=tmp2;
		while(tmp2&&tmp2->right!=NULL){
			if(tmp2->per.age<min){
				min=tmp2->per.age;
				minAge=tmp2;
			}
			tmp2=tmp2->right;
		}
		Person p;
		p=minAge->per;
		minAge->per=tmp1->per;
		tmp1->per=p;
		tmp1=tmp1->right;
	}
	
	printf("\n Ascending order: \n");
	DLList *tmp=dll;
	do{	
		tmp=tmp->right;
		displayPerson(tmp->per);
		
	}while(tmp->right!=NULL);
	
	printf("\n Descending order: \n");
	while(tmp->left!=NULL){
		displayPerson(tmp->per);
		tmp=tmp->left;
	}
		
}

int noPersons(DLList *dll){
	int count=0;
	DLList *tmp=dll;
	while(tmp->right!=NULL){
		count++;
		tmp=tmp->right;
	}
	return count;
}

Ratio adultPerson(DLList *dll){
	Ratio rat;
	rat.noMale=0;
	rat.noFemale=0;
	DLList *tmp=dll;
	while(tmp->right!=NULL){
		if(tmp->per.sex=='M'||tmp->per.sex=='m')
			rat.noMale++;
		else if(tmp->per.sex=='F'||tmp->per.sex=='f')
			rat.noFemale++;
		else;
		tmp=tmp->right;
	}
	printf("\n%d %d\n",rat.noMale,rat.noFemale);
	return rat;
}

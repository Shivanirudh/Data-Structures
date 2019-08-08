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
			//listPersons(dll);
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
			//listPersons(dll);
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
			//listPersons(dll);
		}
		else if(work==4){
			DLList *seniors;
			seniors=(DLList*)malloc(sizeof(DLList));
			seniors=seniorPerson(dll);
			DLList *tmp=seniors;
			do{	
				tmp=tmp->right;
				displayPerson(tmp->per);
		
			}while(tmp->right!=NULL);
			//listPersons(seniors);
		}
		else if(work ==5){
			DLList *adults;
			adults=(DLList*)malloc(sizeof(DLList));
			adults=adult(dll);
			DLList *tmp=adults;
			do{	
				tmp=tmp->right;
				displayPerson(tmp->per);
		
			}while(tmp->right!=NULL);
			//listPersons(adults);
		}
		else if(work==6){
			DLList *location;
			location=(DLList*)malloc(sizeof(DLList));
			char area[50]; getchar();
			printf("Enter the location to search for ");
			scanf("%[^\n]",area);
			location=locatePerson(dll,area);
			listPersons(location);
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
	
}


/*

Output:

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 1
Enter name: a
Enter age: 19
Enter sex: m
Enter City Address: a 
Enter Street Address: a
Enter mobile number: 1


Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 2
Enter name: b
Enter age: 2
Enter sex: b
Enter City Address: b
Enter Street Address: b
Enter mobile number: 2


Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 1
Enter name: c
Enter age: 65
Enter sex: m
Enter City Address: c
Enter Street Address: c
Enter mobile number: 3


Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 2
Enter name: d
Enter age: 45
Enter sex: f
Enter City Address: d
Enter Street Address: d
Enter mobile number: 4


Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 3
Enter name: e
Enter age: 54
Enter sex: f
Enter City Address: e
Enter Street Address: e
Enter mobile number: 5
Enter PIN after which entry is to be done 3

Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 4

Name: c
PIN: 2
Age: 65
Sex: m
City Address: c
Street Address: c
Mobile: 3


Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 5

Name: a
PIN: 0
Age: 19
Sex: m
City Address: a
Street Address: a
Mobile: 1


Name: c
PIN: 2
Age: 65
Sex: m
City Address: c
Street Address: c
Mobile: 3


Name: e
PIN: 4
Age: 54
Sex: f
City Address: e
Street Address: e
Mobile: 5

Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 6
Enter the location to search for b

Name: b
PIN: 1
Age: 2
Sex: b
City Address: b
Street Address: b
Mobile: 2

Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 8


The number of people in the list is 4

Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 9

The gender ratio is 3.00:2.00

Do you want to perform any other operation (y/n)y

What do you want to do ?
[1]-insert at the front 
[2]-insert at the end 
[3]-insert after PIN 
[4]-list senior citizens 
[5]-list adults 
[6]-list location-wise 
[7]-sort and display 
[8]-Print number of persons 
[9]-give gender ratio 
[10]-Display persons in list 
[0]-exit 
Your choice: 10

 Forward order: 

Name: c
PIN: 2
Age: 65
Sex: m
City Address: c
Street Address: c
Mobile: 3


Name: a
PIN: 0
Age: 19
Sex: m
City Address: a
Street Address: a
Mobile: 1


Name: b
PIN: 1
Age: 2
Sex: b
City Address: b
Street Address: b
Mobile: 2


Name: d
PIN: 3
Age: 45
Sex: d
City Address: d
Street Address: d
Mobile: 4

Name: e
PIN: 4
Age: 54
Sex: f
City Address: e
Street Address: e
Mobile: 5

 Reverse order: 

Name: e
PIN: 4
Age: 54
Sex: f
City Address: e
Street Address: e
Mobile: 5

Name: d
PIN: 3
Age: 45
Sex: d
City Address: d
Street Address: d
Mobile: 4


Name: b
PIN: 1
Age: 2
Sex: b
City Address: b
Street Address: b
Mobile: 2


Name: a
PIN: 0
Age: 19
Sex: m
City Address: a
Street Address: a
Mobile: 1


Name: c
PIN: 2
Age: 65
Sex: m
City Address: c
Street Address: c
Mobile: 3


Do you want to perform any other operation (y/n)n
*/

#include"PriQImpl.h"

int main(){
	priorityQueueADT p;
	empDetails e;
	
	int max;
	printf("Enter capacity ");scanf("%d",&max);
	
	initialise(&p,max);
	
	int option;
	
	do{
		printf(" \n Wassup? \n 1-Insert \n 2-Display \n 3-Delete \n Your choice: ");scanf("%d",&option);
		
		if(option==1){
			printf("\n Enter name: ");scanf(" %[^\n]",e.name);
			printf("\n Enter id: ");scanf("%d",&e.id);
			printf("\n Enter salary: ");scanf("%lf",&e.salary);
			insert(&p,e);
		}
		else if(option==2){
			disp(&p,1);
		}
		else if(option==3){
			delete(&p);
			disp(&p,1);
		}
		else if(option!=0){
			printf("\nInvalid option\n ");
		}
		else;
		
	}while(option);
}

/*
Output:

Enter capacity 100
 
 Wassup? 
 1-Insert 
 2-Display 
 3-Delete 
 Your choice: 1

 Enter name: Shiva

 Enter id: 1

 Enter salary: 100
 
 Wassup? 
 1-Insert 
 2-Display 
 3-Delete 
 Your choice: 1

 Enter name: Shar

 Enter id: 2

 Enter salary: 1000
 
 Wassup? 
 1-Insert 
 2-Display 
 3-Delete 
 Your choice: 1

 Enter name: Shashu

 Enter id: 3

 Enter salary: 20
 
 Wassup? 
 1-Insert 
 2-Display 
 3-Delete 
 Your choice: 1

 Enter name: Siddharth

 Enter id: 4

 Enter salary: 50000
 
 Wassup? 
 1-Insert 
 2-Display 
 3-Delete 
 Your choice: 2

Name: Shashu 
ID: 3
Salary: 20.000000

	Name: Shar 
	ID: 2
	Salary: 1000.000000

			Name: Siddharth 
			ID: 4
			Salary: 50000.000000

	Name: Shiva 
	ID: 1
	Salary: 100.000000
 
 Wassup? 
 1-Insert 
 2-Display 
 3-Delete 
 Your choice: 3

Name: Shiva 
ID: 1
Salary: 100.000000

	Name: Shar 
	ID: 2
	Salary: 1000.000000

	Name: Siddharth 
	ID: 4
	Salary: 50000.000000
 
 Wassup? 
 1-Insert 
 2-Display 
 3-Delete 
 Your choice: 0
*/

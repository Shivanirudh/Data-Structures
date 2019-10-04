#include"SortImpl.h"

void main(){
	numberADT N;
	init(&N);
	
	int x[100];

	int option;
	int key;
	do{
		printf("\n Wassup?\n 1-Selection Sort\n 2-Shell Sort\n");
		printf(" 3-Display\n 0-Exit \n Your choice: ");
		scanf("%d",&option);

		if(option==1){
			printf("\nEnter the elements of the array: ");
			for(int i=0;i<N.size;i++)
				scanf("%d",&N.arr[i]);
			
			selSort(&N);
			display(&N);
		}
		else if(option==2){
			printf("\nEnter the elements of the array: ");
			for(int i=0;i<N.size;i++)
				scanf("%d",&N.arr[i]);
			
			ShellSort(&N);
			display(&N);
		}
		else if(option==3){
			display(&N);
		}
		else if(option!=0)
			printf("\nInvalid option ");
		else;
			
	}while(option);
}

/*
Output:
Enter size of array 10

 Wassup?
 1-Selection Sort
 2-Shell Sort
 3-Display
 0-Exit 
 Your choice: 1

Enter the elements of the array: 5 6 78 94 64 57 12 34 1 0

 The array is : 
 0  1  5  6  12  34  57  64  78  94 

 Wassup?
 1-Selection Sort
 2-Shell Sort
 3-Display
 0-Exit 
 Your choice: 2

Enter the elements of the array: 5 6 78 94 64 57 12 34 1 0

 The array is : 
 0  1  5  6  12  34  57  64  78  94 

 Wassup?
 1-Selection Sort
 2-Shell Sort
 3-Display
 0-Exit 
 Your choice: 3

 The array is : 
 0  1  5  6  12  34  57  64  78  94 

 Wassup?
 1-Selection Sort
 2-Shell Sort
 3-Display
 0-Exit 
 Your choice: 0
*/

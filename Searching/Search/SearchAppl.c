#include"SearchImpl.h"

void main(){
	numberADT N;
	init(&N);
	
	int x[100];
	
	printf("\nEnter the elements of the array: ");
	for(int i=0;i<N.size;i++)
		scanf("%d",&N.arr[i]);

	int option;
	int key;
	do{
		printf("\n Wassup?\n 1-Linear search\n 2-Binary Search\n");
		printf("  3-Display\n 0-Exit \n Your choice: ");
		scanf("%d",&option);
		
		if(option==1){
			printf("Enter key to search for ");scanf("%d",&key);
			if(lsearchElements(&N,key)!=-1)
				printf("\n Linear Search successful\n ");
		}
		else if(option==2){
			printf("Enter key to search for ");scanf("%d",&key);
			if(bsearchElements(&N,key)!=-1)
				printf("\n Binary Search successful\n ");
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

Enter the elements of the array: 13 5 6 48 75 94 47 9 4 27

 Wassup?
 1-Linear search
 2-Binary Search
 3-Display
 0-Exit 
 Your choice: 1
Enter key to search for 48
 48 found at index 3 
 Linear Search successful
 
 Wassup?
 1-Linear search
 2-Binary Search
 3-Display
 0-Exit 
 Your choice: 1
Enter key to search for 10
 Not found 
 Wassup?
 1-Linear search
 2-Binary Search
 3-Display
 0-Exit 
 Your choice: 2
Enter key to search for 48
 48 found at index 7 
 Binary Search successful
 
 Wassup?
 1-Linear search
 2-Binary Search
 3-Display
 0-Exit 
 Your choice: 2
Enter key to search for 10
 Not found 
 Wassup?
 1-Linear search
 2-Binary Search
 3-Display
 0-Exit 
 Your choice: 3

 The array is : 
 4  5  6  9  13  27  47  48  75  94 

 Wassup?
 1-Linear search
 2-Binary Search
 3-Display
 0-Exit 
 Your choice: 0
*/

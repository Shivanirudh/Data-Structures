#include"HashImpl.h"

void main(){
	
	HashADT hash;
	
	initialise(&hash);
	
	int option;
	
	do{
		printf(" Wassup? 1-Insert 2-Display 0-Exit \n Your choice: ");scanf("%d",&option);
		
		if(option==1){	
			int x;
			
			printf(" Enter value to be inserted ");scanf("%d",&x);
			
			insert(&hash,x);
		}
		else if(option==2){
			displayTable(&hash);
		}
		else if(option){
			printf("\nInvalid choice \n");
		}
		else;
	}while(option);
}

/*
Output:
Enter table size: 10
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 1 
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 11
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 39
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 25
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 45
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 84
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 67
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 7
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 23
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 64
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 1
 Enter value to be inserted 95
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 2

0-- 

1--  1  11 

2-- 

3--  23 

4--  84  64 

5--  25  45  95 

6-- 

7--  67  7 

8-- 

9--  39 
 Wassup? 1-Insert 2-Display 0-Exit 
 Your choice: 0
 */


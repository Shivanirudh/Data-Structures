#include "AVLImpl.h"

void main(){
	dictionaryADT *D=NULL;
	wordMeaning wm;
	
	int option;
	
	do{
		printf("\n Wassup?\n 1.Insert\n 2.Display\n 3.Search\n 0.Exit\n");
		printf(" Your choice: ");scanf("%d",&option);
		
		if(option==1){
			printf("Enter word to insert ");scanf(" %[^\n]",wm.word);
			printf("Enter its meaning ");scanf(" %[^\n]",wm.meaning); 
			
			D=insert(D,wm);
		}
		else if(option==2){
			disp(D,0);
		}
		else if(option==3){
			char word[100];
			printf("Enter word to search for ");scanf(" %[^\n]",word);
			
			search(D,word);
		}
		else if(option){
			printf("\nInvalid Option\n");
		}
		else;
	}while(option);
}

/*
Output:
 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert h
Enter its meaning h

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert d
Enter its meaning d

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert e
Enter its meaning e

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert a
Enter its meaning a

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert f
Enter its meaning f

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert l
Enter its meaning l

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert m
Enter its meaning m

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert i
Enter its meaning i

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 1
Enter word to insert k
Enter its meaning k

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 2
l	-	l
	i	-	i
		h	-	h
			e	-	e
				d	-	d
					a	-	a
				f	-	f
		k	-	k
	m	-	m

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 3
Enter word to search for h
h	-	h

 Wassup?
 1.Insert
 2.Display
 3.Search
 0.Exit
 Your choice: 0
*/

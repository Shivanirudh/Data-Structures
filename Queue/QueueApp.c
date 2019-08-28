#include "CQImpl.h"

void main(){
	Queue q;
	initialise(&q);
	
	int opt=0;
	char choice;
	do{
		printf("\nWassup? 1-enqueue 2-dequeue 3-display ");scanf("%d",&opt);
		
		if(opt==1){
			int x;
			printf("\nEnter value to enqueue ");scanf("%d",&x);
			enqueue(&q,x);
		}
		else if(opt==2){
			int x;
			x=dequeue(&q);
			printf("\n%d has been dequeued \n",x);
		}
		else if(opt==3)
			display(&q);
		else if(opt){
			printf("\nInvalid choice \n");
		}
		else;
										
		getchar();		
		printf("\n Continue? y/n ");scanf("%c",&choice);
	}while(choice=='Y'||choice=='y');
} 

/*
Output:

LINEAR QUEUE

Enter capacity 5

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 1

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 2

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 3

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 4

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 5

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 6
Queue is full 
 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

1 2 3 4 5

  Continue? y/n y


Wassup? 1-enqueue 2-dequeue 3-display 2

1 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2

2 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2

3 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2

4 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2

5 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2
Queue is empty
0 has been dequeued 

 Continue? y/n n




CIRCULAR QUEUE

Enter capacity 5

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 1

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 2

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 3

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 4

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 5

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 3
1 2 3 4 5 
 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2

1 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2

2 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 6

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 7

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 3
3 4 5 6 7 
 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 8
Queue is full 
 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 2

3 has been dequeued 

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter value to enqueue 8

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 3
4 5 6 7 8 
 Continue? y/n n


*/

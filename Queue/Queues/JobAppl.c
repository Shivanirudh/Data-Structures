#include "CQImplV2.h"

void main(){
	Queue q1,q2;
	initialise(&q1);initialise(&q2);
	
	int opt=0;
	char choice;
	do{
		printf("\nWassup? 1-enqueue 2-dequeue 3-display ");scanf("%d",&opt);
		
		if(opt==1){
			Data x;
			getchar();
			printf("\nEnter job to enqueue ");scanf(" %c",&x.Job);
			printf("\nEnter time for job to enqueue ");scanf("%d",&x.time);
			if(q1.waitTime<=q2.waitTime)
				enqueue(&q1,x);
			else
				enqueue(&q2,x);
		}
		else if(opt==2){
			Data x;
			x.Job='\0';
			x.time=0;
			int num;
			printf("\nWhich queue is to be dequeued ");scanf("%d",&num);
			if(num==1)
				x=dequeue(&q1);
			else 
				x=dequeue(&q2);
			printf("\nJob: %c Time Needed: %d has been dequeued\n",x.Job,x.time);
		}
		else if(opt==3){
			printf("\nQueue 1:\n");
			display(&q1);
			printf("\nWaiting Time: %d\n",q1.waitTime);
			printf("\nQueue 2:\n");
			display(&q2);
			printf("\nWaiting Time: %d\n",q2.waitTime);
		}
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

Enter capacity 100
Enter capacity 100

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue A

Enter time for job to enqueue 9

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue B

Enter time for job to enqueue 4

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue C

Enter time for job to enqueue 8

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue D

Enter time for job to enqueue 3

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue E

Enter time for job to enqueue 1

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue F

Enter time for job to enqueue 2

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue G

Enter time for job to enqueue 5

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 1

Enter job to enqueue H

Enter time for job to enqueue 6

 Continue? y/n y

Wassup? 1-enqueue 2-dequeue 3-display 3

Queue 1:
A 9; D 3; E 1; G 5; 
Waiting Time: 18

Queue 2:
B 4; C 8; F 2; H 6; 
Waiting Time: 20

 Continue? y/n n
*/

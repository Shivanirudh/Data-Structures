#include"PQueue2.h"
int main()
{
	pq 		q,p,r,t;
	any 	data1;
	int 	temp,option;
			temp=0;
			data1=0;
			do{
				printf("\n\n Priority Queue \n\n");
				printf(" 1. Create And Display \n");
				printf(" 2. EnQueue \n");
				printf(" 3. DeQueue \n");
				printf(" 4. Peek \n");
				printf(" 5. Pop \n");
				scanf("%d",&option);
				
				if(option==1){
					printf("\n\n Create And Display \n\n");
					t=create(q);
					printf("\n\n");
					temp=display(t);
				}
				else if(option==2){
					printf("\n\n EnQueue \n\n");
					printf(" Enter Data To Be Inserted : ");
					scanf("%d",&data1);
					p=enqueue(t,data1);
					printf(" Enter Data To Be Inserted : ");
					scanf("%d",&data1);
					r=enqueue(p,data1);
					printf("\n\n Displaying The Inserted Priority Queue \n\n");
					temp=display(r);
				}
				else if(option==3){
					printf("\n\n DeQueue \n\n");
					p=dequeue(r);
					printf("\n\n Displaying The Deleted Priority Queue \n\n");
					temp=display(p);
				}
				else if(option==4){
					printf("\n\n Peek \n\n");
					printf("\n\n Data Deleted Is %d \n\n",peek(p));
				}
			}while(option);
			
			printf("\n\n The End \n\n");
			return 0;
}

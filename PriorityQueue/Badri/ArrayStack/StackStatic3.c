#include"StackStatic2.h"
int main()
{
	Stack 	s,*s1,*s2,*s3,*t;
	int   	temp;
	any 	datatobepushed;
			printf("\n\n Static Stack \n\n");
			printf(" 1. Create And Display \n");
			printf(" 2. Push \n");
			printf(" 3. Pop \n");
			printf(" 4. Peep \n");
			printf(" 5. Is Full \n");
			printf(" 6. Is Empty \n");

			printf("\n\n Creating The Stack \n\n");
			t=stackinput(&s);

			printf(" Displaying The Stack \n\n");
			temp=stackdisplay(&s);

			printf(" Push \n\n");
			printf(" Enter Data To Be Pushed : ");
			scanf("%d",&datatobepushed);
			t=push(&s,datatobepushed);
			printf("\n\n Displaying The Pushed Stack \n\n");
			temp=stackdisplay(t);

			printf(" Pushing A Data Element \n\n");
			printf(" Enter Data To Be Pushed : ");
			scanf("%d",&datatobepushed);
			s1=push(t,datatobepushed);
			printf("\n\n Displaying The Pushed Stack \n\n");
			temp=stackdisplay(s1);

			printf(" Pop \n\n");
			s2=pop(s1);
			printf("\n\n Displaying The Popped Stack \n\n");
			temp=stackdisplay(s2);

			printf(" Pop \n\n");
			s3=pop(s2);
			printf("\n\n Displaying The Popped Stack \n\n");
			temp=stackdisplay(s3);

			printf(" Peep \n\n");
			printf("\n\n Data Element Popped Is %d \n\n",peep(s3));

			printf(" Peep \n\n");
			printf("\n\n Data Element Popped Is %d \n\n",peep(s3));

			printf(" Is Full \n\n");
			temp=isfull(s3);

			printf(" Is Empty \n\n");
			temp=isempty(s3);

			return 0;
}

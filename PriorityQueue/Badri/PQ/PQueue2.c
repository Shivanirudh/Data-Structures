#include"PQueue1.h"
int 	isfull(pq q)
{
		return q->size==q->maxsize;
}
int 	isempty(pq q)
{
		return q->size==0;
}
pq 		pqcreate(int maxsize)
{
	pq 	tmp;	
		printf("\n\n Data At Index 0 Is -999 \n\n");
		tmp=(pq)malloc(sizeof(priorityqueue));
		tmp->maxsize=maxsize;
		tmp->size=0;
		tmp->data=(any*)malloc(sizeof(any)*maxsize);
		tmp->data[0]=-999; 
		return tmp;
}
pq 		create(pq q)
{
	int 	size,maxsize;
	any 	data1;
			size=maxsize=0;
			data1=0;
			printf(" Enter Max Size : ");
			scanf("%d",&maxsize);
			printf(" Enter Size : ");
			scanf("%d",&size);
			q=pqcreate(maxsize);
			for(int i=0;i<size;i++)
			{
				printf(" Enter Data : ");
				scanf("%d",&data1);
				enqueue(q,data1);
			}
			return q;
}
int 	display(pq q)
{
	if(q->size>q->maxsize)
	{
		printf("\n\n Dsiplay Not Possible \n\n");
		return -999;
	}
	else
	{
		for(int i=1;i<=q->size;i++)
		{
			printf("  %d  ",q->data[i]);
		}
		return 1;
	}
}
pq 		enqueue(pq q,any data1)
{
	if(isfull(q))
	{
		printf("\n\n Queue Full!!!! \n\n");
		return NULL; 
	}	
	int 	i;
			i=++q->size;
			for(; q->data[i/2]>data1;i/= 2)
			{
				q->data[i]=q->data[i/2];	
			}
			q->data[i]=data1; 
			return q;
}
pq 		dequeue(pq q)
{
	if(isempty(q))
	{
		printf("\n\n Queue Empty!!! \n\n");
		return NULL; 
	}
	int 	i,child;
	any 	last;
			last=q->data[q->size--];
			for(i = 1;i*2<=q->size;i=child)
			{
					child=i*2;
					if((child!=q->size)&&(q->data[child+1]<q->data[child]))child ++;
					if(last>q->data[child])q->data[i]=q->data[child];
					else break;
			}
			q->data[i]=last;
			return q;
}
any 	peek(pq q)
{
	if(isempty(q))
	{
		printf("\n\n Queue Empty!!! \n\n");
		return -999; 
	}
	int 	i,child;
	any 	min,last;
			min=q->data[1];
			last=q->data[q->size--];
			for(i = 1;i*2<=q->size;i=child)
			{
					child=i*2;
					if((child!=q->size)&&(q->data[child+1]<q->data[child]))child ++;
					if(last>q->data[child])q->data[i]=q->data[child];
					else break;
			}
			q->data[i]=last;
			return min;
}

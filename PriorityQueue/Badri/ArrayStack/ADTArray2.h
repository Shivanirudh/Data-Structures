#include "ADTArray1.h"
Array* 	input(Array *p)
{
	int	i;
		printf(" Enter Maximum Size : ");
		scanf("%d",&p->maxsize);
		p->data=(any*)malloc(p->maxsize*sizeof(any));
		printf(" Enter Size : ");
		scanf("%d",&p->size);
		if(p->size<=p->maxsize)
		{
			for(i=0;i<p->size;i++)
			{
				printf(" Enter Values : ");
				scanf("%d",&p->data[i]);
			}
			printf("\n\n");
			return	p;
		}
		else
		{
			printf(" Size Entered Greater Than Max Size \n\n");
			return NULL;
		}
}
Array* 	input1(Array *p)
{
	int	i;
		printf(" Enter Maximum Size : ");
		scanf("%d",&p->maxsize);
		p->data=(any*)malloc(p->maxsize*sizeof(any));
		printf(" Enter Size : ");
		scanf("%d",&p->size);
		if(p->size<=p->maxsize)
		{
			for(i=p->size-1;i>=0;i--)
			{
				printf(" Enter Values : ");
				scanf("%d",&p->data[i]);
			}
			printf("\n\n");
			return	p;
		}
		else
		{
			printf(" Size Entered Greater Than Max Size \n\n");
			return NULL;
		}
}
int 	display(Array *p)
{
	int	i;
		if(p->size>p->maxsize)
		{
			printf(" Display Not Possible \n\n");
			return -1;
		}
		for(i=0;i<p->size;i++)
		{
			printf(" %d  ",p->data[i]);
		}
		printf("\n\n");
		return 1;
}
int search(Array *p,any datasearched)
{
	int	i,flag;
		flag=-1;
		for(i=0;i<p->size;i++)
		{
			if(p->data[i]==datasearched)
			{
				printf("\n Data Found @ Index %d \n\n",i);
				flag=1;
			}
		}
		if(flag==-1)
		{
			printf("\n Data Not Found \n\n");
			return 0;
		}
		else return 1;
}
Array*	sort(Array *p)
{
	int i,j;
		for(i=0;i<p->size-1;i++)
		{
			for(j=0;j<p->size-i-1;j++)
			{
				if(p->data[j]>p->data[j+1])
				{
					any 	temp;
						temp=p->data[j];
						p->data[j]=p->data[j+1];
						p->data[j+1]=temp;
				}
			}
					
		}
		printf(" Array Sorted In Ascending Order \n\n");
		return p;
}
Array*	modify(Array *p,any olddata,any newdata)
{
	int i,flag;
		flag=-1;
		for(i=0;i<p->size;i++)
		{
			if(p->data[i]==olddata)
			{
				flag=1;
				p->data[i]=newdata;
			}		
		}
		if(flag==-1)
		{
			printf(" Data Does Not Exist\n\n");
			return p;
		}
		else
		{
			printf(" Data Modified \n\n");
			return p;
		}
}
Array*	reverse(Array *p,Array *q)
{
	int i,j;
		q->size=p->size;
		q->maxsize=p->maxsize;
		q->data=(any*)malloc(q->maxsize*sizeof(any));
		for(i=0,j=p->size-1;i<p->size;i++,j--)
		{
			q->data[i]=p->data[j];
		}
		printf(" Reversed Array \n\n");
		return q;

}
Array* swapadjacentdigits(Array *p)
{
	int i;
		if(p->size%2==0)
		{
			for(i=0;i<p->size;i+=2)
			{
				any    temp;
				temp=p->data[i];
				p->data[i]=p->data[i+1];
				p->data[i+1]=temp;
			}
			printf(" Adjacent Digits Have Been Swapped \n\n");
			return p;
		}
		else
		{
			printf(" Can Swap Only For Arrays With Even Size \n\n");
			return p;
		}
}
Array*	insert(Array *p,any datainserted,int index)
{
		if(index>p->size)
		{
			printf(" Data Cannot Be Inserted \n\n");
			return p;
		}
		else
		{
			for(int i=p->size;i>=index;i--)
			{
				p->data[i]=p->data[i-1];
			}
			p->data[index]=datainserted;
			p->size+=1;
			return p;
		}
}
Array*	insertbeforeadata(Array *p,Array *q,any olddata,any newdata)
{
	int 	i,j,flag;
			flag=-1;
			q->size=p->size;
			q->maxsize=p->maxsize;
			q->data=(any*)malloc(q->maxsize*sizeof(any));
			for(i=0,j=0;i<p->size;i++,j++)
			{
				if(p->data[i]==olddata)
				{
					q->data[j]=newdata;
					j++;
					flag=1;
					q->size++;
				}
				q->data[j]=p->data[i];
			}
			if(flag==-1)
			{
				printf(" Data Does Not Exist \n\n");
				return q;
			}
			else
			{
				printf(" Data Inserted \n\n");
				return q;
			}
}
Array*	insertafteradata(Array *p,Array *q,any olddata,any newdata)
{
	int n,i,j,flag,c;
		flag=-1;
		q->size=p->size;
		q->maxsize=p->maxsize;
		q->data=(any*)malloc(q->maxsize*sizeof(any));
		n=q->size;
		for(i=0,j=0;i<p->size;i++,j++)
		{
			q->data[j]=p->data[i];
			if(p->data[i]==olddata)
			{
				j++;
				q->data[j]=newdata;
				flag=1;
				q->size++;
			}
		}
		if(flag==-1)
		{
			printf(" Data Does Not Exist \n\n");
			return q;
		}
		else
		{
			printf(" Data Inserted \n\n");
			return q;
		}
}
Array*	deletebasedondata(Array *p,any datadeleted)
{
	int n,data,flag;
		n=0;
		n=p->size;
		for(int i=0,flag=-1;i<n;i++)
		{
			if(p->data[i]==datadeleted)
			{
				for(int j=i;j<n-1;j++)
				{
					p->data[j]=p->data[j+1];
				}
				flag=1;
				n--;
				i--;
			}
		}
		if(flag==-1)
		{
			printf(" Data Not Found \n\n");
			return p;
		}
		else
		{
			printf(" Data Deleted \n\n");
			p->size=n;
			return p;
		}
}
Array*	deletebasedonposition(Array *p,int pos)
{
		if(pos>p->size)
		{
			printf(" Deletion Not Possible \n\n");
			return p;
		}
		else
		{
			for(int i=pos-1;i<p->size-1;i++)
			{
				p->data[i]=p->data[i+1];
			}
			p->size--;
			return p;
		}
}
any	deletebasedonposition1(Array *p,int pos)
{
		if(pos>p->size)
		{
			printf("\n\n Deletion Not Possible \n\n");
			return -1;
		}
		else
		{
			any 	d=0;
				d=p->data[pos-1];
				for(int i=pos-1;i<p->size-1;i++)
				{
					p->data[i]=p->data[i+1];
				}
				p->size--;
				return d;
		}
}
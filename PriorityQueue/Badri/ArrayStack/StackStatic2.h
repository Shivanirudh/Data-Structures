#include"StackStatic1.h"
Stack* stackinput(Stack *s)
{
		int	i;
		printf(" Enter Maximum Size : ");
		scanf("%d",&s->maxsize);
		s->data=(any*)malloc(s->maxsize*sizeof(any));
		printf(" Enter Size : ");
		scanf("%d",&s->size);
		if(s->size<s->maxsize)
		{
			for(i=s->size-1;i>=0;i--)
			{
				printf(" Enter Values : ");
				scanf("%d",&s->data[i]);
			}
			printf("\n\n");
			return	s;
		}
		else
		{
			printf(" Size Entered Greater Than Max Size \n\n");
			return NULL;
		}
}
int   stackdisplay(Stack *s)
{
		return display(s);
}
Stack* push(Stack *s,any datatobepushed)
{
		return insert(s,datatobepushed,0);
}
Stack* pop(Stack *s)
{
		return deletebasedonposition(s,1);
}
any   peep(Stack *s)
{
		return deletebasedonposition1(s,1);
}
int   isfull(Stack *s)
{
		if(s->size==s->maxsize)
		{
				printf("\n\n Stack Is Full \n\n");
				return 100;
		}
		else
		{
				printf("\n\n Stack Is Not Full \n\n");
				return -100;
		}
}
int   isempty(Stack *s)
{
		if(s->size==0)
		{
			printf("\n\n Stack Is Empty \n\n");
			return 100;
		}
		else
		{
			printf("\n\n Stack Is Not Empty \n\n");
			return -100;
		}
}
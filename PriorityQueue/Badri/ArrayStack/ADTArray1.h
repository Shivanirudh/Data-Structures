#ifndef ADTArray1_h
#define	ADTArray1_h
#include<stdio.h>
#include<stdlib.h>
typedef 	int		any;
typedef		struct
{
		any		*data;
		int		size,maxsize;
}Array;		
Array* 	input(Array *p);
Array* 	input1(Array *p);
int 	display(Array *p);
int	    search(Array *p,any datasearched);
Array*	sort(Array *p);
Array*	modify(Array *p, any olddata, any newdata);
Array*	reverse(Array *p,Array *q);
Array*	swapadjacentdigits(Array *p);
Array*	insert(Array *p,any datainserted,int index);
Array* 	insertbeforeadata(Array *p,Array *q,any olddata,any newdata);
Array* 	insertafteradata(Array *p,Array *q,any olddata,any newdata);
Array*	deletebasedondata(Array *p,any datadeleted);
Array*	deletebasedonposition(Array *p,int pos);
any 	deletebasedonposition1(Array *p,int pos);
#endif
#ifndef PQueue1_h
#define	PQueue1_h
#include<stdio.h>
#include<stdlib.h>
typedef 	int		any;
typedef 	struct 	PriorityQueue
{
		int 	size,maxsize;
		any 	*data;
}priorityqueue;
typedef 	priorityqueue* 	pq;
int 	isfull(pq q);
int 	isempty(pq q);
pq 		pqcreate(int maxsize);
pq 		create(pq q);
int 	display(pq q);
pq 		enqueue(pq q,any data1);
pq 		dequeue(pq q);
any 	peek(pq q);
#endif
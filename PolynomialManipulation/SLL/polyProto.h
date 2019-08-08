#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct trm{
	int exp;
	float coeff;
};

typedef struct trm term;

struct pADT{
	term tm;
	struct pADT* next;
};

typedef struct pADT polyADT;

void initialise(polyADT *p);

void sort(polyADT *p);

void create(polyADT *p);

void display(polyADT *p);

void insertFront(polyADT *p,term t);//1. Input a polynomial through insertion at the front

void insertEnd(polyADT *p,term t);//2. Input a polynomial through insertion at the end

void insertAfterTerm(polyADT *p, term t, int exp);//3. Input a polynomial after a term

polyADT* polyAdd(polyADT *p1, polyADT *p2);//4. Add two polynomials 

polyADT* polyMul(polyADT *p1, polyADT *p2);//5. Multiply two polynomials 

void polyDegree(polyADT  *p);//6. Find the degree of polynomial

double polyEvaluate(polyADT  *p);//7. Evaluate a polynomial 

polyADT* polySimplify(polyADT  *p);//8. Simplifying the polynomial – Combining like terms



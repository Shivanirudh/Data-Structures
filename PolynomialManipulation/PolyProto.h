#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct polyADT{
	int exp;
	float coeff;
	struct polyADT* next;
};

void insertFront(polyADT p,term t);//1. Input a polynomial through insertion at the front

void insertEnd(polyADT p,term t);//2. Input a polynomial through insertion at the end

void insertAfterTerm(polyADT p, term t, int exp);//3. Input a polynomial after a term

polyADT polyAdd(polyADT p1, polyADT p2);//4. Add two polynomials 

polyADT polyAdd(polyADT p1, polyADT p2);//5. Multiply two polynomials 

void polyDegree(polyADT  p);//6. Find the degree of polynomial

int polyEvaluate(polyADT  p);//7. Evaluate a polynomial 

polyADT polySimplify(polyADT  p);//8. Simplifying the polynomial – Combining like terms



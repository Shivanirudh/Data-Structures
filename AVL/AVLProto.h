#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char word[100];
	char meaning[100];
}wordMeaning;

struct dict{
	wordMeaning wm;
	struct dict *left;
	struct dict *right;
	int height; 
};

typedef struct dict dictionaryADT;


dictionaryADT* insert(dictionaryADT *D, wordMeaning x);

void disp(dictionaryADT *D,int depth);

void search(dictionaryADT *D, char word[]);




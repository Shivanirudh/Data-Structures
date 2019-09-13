#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
typedef struct 
{
	char word[100];
    char def[1000];
}Data;
struct DictADT
{ 
    Data key;
    struct DictADT *left; 
    struct DictADT *right; 
    int height; 
}; 

int height(struct DictADT *N);
int max(int a, int b);
struct DictADT* newNode(Data key);
struct DictADT *rightRotate(struct DictADT *y);
struct DictADT *leftRotate(struct DictADT *x);
int getBalance(struct DictADT *N);
struct DictADT* insert(struct DictADT* node, Data key);
void search(struct DictADT* root, char key[100]);
void display(struct DictADT *root, int space);
void preOrder(struct DictADT *root); 








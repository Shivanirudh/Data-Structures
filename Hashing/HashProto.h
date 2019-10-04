/* Implement hash table with separate chaining, on integers. Input size of table from user. Hash function is number mod size of table */


#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node Block;

typedef struct{
	Block* table[100];
	int table_size;
}HashADT;

void initialise(HashADT* hashTable);

int hashFunction(int x,int table_size);

void insert(HashADT* hashTable,int x);

void displayChain(Block *link);
		
void displayTable(HashADT* hashTable);		

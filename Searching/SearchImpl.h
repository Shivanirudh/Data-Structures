#include"SearchProto.h"

void init(numberADT *N){
	int size;
	printf("Enter size of array ");
	scanf("%d",&size);
	
	N->size=size;
}

void insertElements(numberADT *N,int x[100]){
	for(int i=0;i<N->size;i++)
		N->arr[i]=x[i];
}

int lsearchElements(numberADT *N,int key){
	for(int i=0;i<N->size;i++){
		if(N->arr[i]==key){
			printf(" %d found at index %d ",key,i);
			return i;
		}
	}
	printf(" Not found ");
	return -1;
}

void sort(int a[100],int size){
	for(int i=0;i<size;i++){
		int min=i;
		for(int j=i+1;j<size;j++)
			if(a[j]<a[min])
				min=j;
		int swap=a[min];
		a[min]=a[i];
		a[i]=swap;
	}
}
int bsearchElements(numberADT *N,int key){
	
	sort(N->arr,N->size);
	
	int gap=N->size/2;
	int lower=0;
	int upper=N->size-1;
	int m=(lower+upper)/2;
	
	while(lower<=upper){
		m=(lower+upper)/2;
		if(N->arr[m]==key){
			printf(" %d found at index %d ",key,m);
			return m;
		}
		else if(key>N->arr[m]){
			lower=m+1;
		}
		else{
			upper=m-1;
		}
	}
	printf(" Not found ");
	return -1;
}

void display(numberADT *N){
	printf("\n The array is : \n");
	for(int i=0;i<N->size;i++)
		printf(" %d ",N->arr[i]);
	printf("\n");
}
	

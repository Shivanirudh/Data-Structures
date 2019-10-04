#include"SortProto.h"

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

void selSort(numberADT *N){
	for(int i=0;i<N->size;i++){
		int min=i;
		for(int j=i+1;j<N->size;j++)
			if(N->arr[j]<N->arr[min])
				min=j;
		int swap=N->arr[min];
		N->arr[min]=N->arr[i];
		N->arr[i]=swap;
	}
}

void ShellSort(numberADT *N){
	for(int gap=N->size/2;gap>0;gap/=2){
		for (int i=gap;i<N->size;i+=1){ 
			int temp=N->arr[i];
            int j;             
            for (j=i;j>=gap&&N->arr[j-gap]>temp;j-=gap) 
                N->arr[j]=N->arr[j-gap]; 
            N->arr[j]=temp; 
        } 
    } 
}


void display(numberADT *N){
	printf("\n The array is : \n");
	for(int i=0;i<N->size;i++)
		printf(" %d ",N->arr[i]);
	printf("\n");
}
	

#include "TSImpl.h"

int main(){
	cityADT c;
	
	c.NoC=0;
	create(&c);
	int option;
	do{
		printf("\nEnter your choice: \n 1.Display graph\n 2.Perform Topological Sort\n");
		printf(" 0.Exit\n Your choice: ");
		scanf("%d",&option);
		
		if(option==1){
			disp(&c);
		}
		else if(option==2){
			TopologicalSort(&c);
		}
		else if(option)
			printf("\nInvalid input\n");
		else;
	}while(option);		
	return 0;		
}

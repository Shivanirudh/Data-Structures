#include "FWImpl.h"

int main(){
	cityADT c;
	
	c.NoC=0;
	create(&c);
	int option;
	do{
		printf("\nEnter your choice: \n 1.Display graph\n 2.Perform Floyd Warshall\n");
		printf(" 3.Find shortest path\n 0.Exit\n Your choice: ");
		scanf("%d",&option);
		
		if(option==1){
			disp(&c);
		}
		else if(option==2){
			FW_Algorithm(&c);
		}
		else if(option==3){
			char source[100],dest[100];
			printf("Enter source: ");scanf(" %[^\n]",source);
			printf("Enter destination: ");scanf(" %[^\n]",dest);
			displayPath(&c,source,dest);	
		}
		else if(option)
			printf("\nInvalid input\n");
		else;
	}while(option);		
	return 0;		
}

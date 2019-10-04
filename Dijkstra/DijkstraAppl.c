#include "DijkstraImpl.h"

int main(){
	cityADT c;
	
	c.NoC=0;
	create(&c);
	int option;
	do{
		printf("\nEnter your choice: \n 1.Display graph\n 2.Perform Dijkstra\n");
		printf(" 3.Find shortest path\n 0.Exit\n Your choice: ");
		scanf("%d",&option);
		
		if(option==1){
			disp(&c);
		}
		else if(option==2){
			char source[100];
			printf("Enter source: ");scanf(" %[^\n]",source);
			Dijkstra_Algorithm(&c,source);
		}
		else if(option==3){
			char source[100],dest[100];
			printf("Enter source: ");scanf(" %[^\n]",source);
			printf("Enter destination: ");scanf(" %[^\n]",dest);
			
			if(displayPath(&c,source,dest))
				printf("\n%s\n",displayPath(&c,source,dest));
			else
				printf("\nNo path exists from %s to %s\n",source,dest);
		}
		else if(option)
			printf("\nInvalid input\n");
		else;
	}while(option);		
	return 0;		
}

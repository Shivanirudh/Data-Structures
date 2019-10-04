#include"DFSImpl.h"

void main(){
	cityADT c;
	
	c.NoC=0;
	create(&c);
	int option;
	do{
		printf("\n Wassup?\n 1.Display graph\n 2.Perform DFS\n");
		printf(" 3.Check connection\n 0.Exit\n Your choice: ");
		scanf("%d",&option);
		
		if(option==1){
			disp(&c);
		}
		else if(option==2){
			DFS(&c);
		}
		else if(option==3){
			char source[100],dest[100];
			printf("Enter source: ");scanf(" %[^\n]",source);
			printf("Enter destination: ");scanf(" %[^\n]",dest);
			
			printf("\n%s\n",path(&c,source,dest));
		}
		else if(option)
			printf("\nInvalid input\n");
		else;
	}while(option);				
}

/*
Output:
Enter the number of cities: 7
Enter the cities
 
City 1 : A

City 2 : B

City 3 : C

City 4 : D

City 5 : E

City 6 : F

City 7 : G
Enter Connectivity information:
 
 Is there a connection from A to A? 1-Yes 0-No 0

 Is there a connection from A to B? 1-Yes 0-No 1

 Is there a connection from A to C? 1-Yes 0-No 0

 Is there a connection from A to D? 1-Yes 0-No 0

 Is there a connection from A to E? 1-Yes 0-No 0

 Is there a connection from A to F? 1-Yes 0-No 0

 Is there a connection from A to G? 1-Yes 0-No 0

 Is there a connection from B to A? 1-Yes 0-No 0

 Is there a connection from B to B? 1-Yes 0-No 0

 Is there a connection from B to C? 1-Yes 0-No 1

 Is there a connection from B to D? 1-Yes 0-No 1

 Is there a connection from B to E? 1-Yes 0-No 1

 Is there a connection from B to F? 1-Yes 0-No 0

 Is there a connection from B to G? 1-Yes 0-No 0

 Is there a connection from C to A? 1-Yes 0-No 0

 Is there a connection from C to B? 1-Yes 0-No 0

 Is there a connection from C to C? 1-Yes 0-No 0

 Is there a connection from C to D? 1-Yes 0-No 0

 Is there a connection from C to E? 1-Yes 0-No 1

 Is there a connection from C to F? 1-Yes 0-No 0

 Is there a connection from C to G? 1-Yes 0-No 0

 Is there a connection from D to A? 1-Yes 0-No 0

 Is there a connection from D to B? 1-Yes 0-No 0

 Is there a connection from D to C? 1-Yes 0-No 0

 Is there a connection from D to D? 1-Yes 0-No 0

 Is there a connection from D to E? 1-Yes 0-No 1

 Is there a connection from D to F? 1-Yes 0-No 0

 Is there a connection from D to G? 1-Yes 0-No 0

 Is there a connection from E to A? 1-Yes 0-No 0

 Is there a connection from E to B? 1-Yes 0-No 0

 Is there a connection from E to C? 1-Yes 0-No 0

 Is there a connection from E to D? 1-Yes 0-No 0

 Is there a connection from E to E? 1-Yes 0-No 0

 Is there a connection from E to F? 1-Yes 0-No 1

 Is there a connection from E to G? 1-Yes 0-No 0

 Is there a connection from F to A? 1-Yes 0-No 0

 Is there a connection from F to B? 1-Yes 0-No 0

 Is there a connection from F to C? 1-Yes 0-No 0

 Is there a connection from F to D? 1-Yes 0-No 0

 Is there a connection from F to E? 1-Yes 0-No 0

 Is there a connection from F to F? 1-Yes 0-No 0

 Is there a connection from F to G? 1-Yes 0-No 0

 Is there a connection from G to A? 1-Yes 0-No 0

 Is there a connection from G to B? 1-Yes 0-No 0

 Is there a connection from G to C? 1-Yes 0-No 0

 Is there a connection from G to D? 1-Yes 0-No 1

 Is there a connection from G to E? 1-Yes 0-No 0

 Is there a connection from G to F? 1-Yes 0-No 0

 Is there a connection from G to G? 1-Yes 0-No 0

 Wassup?
 1.Display graph
 2.Perform DFS
 3.Check connection
 0.Exit
 Your choice: 1
The connections are from:
 A to B 
 B to C 
 B to D 
 B to E 
 C to E 
 D to E 
 E to F 
 G to D 

 Wassup?
 1.Display graph
 2.Perform DFS
 3.Check connection
 0.Exit
 Your choice: 2
Enter maximum limit 100

 A 

 B 

 C 

 E 

 F 

 D 

 G 

 Wassup?
 1.Display graph
 2.Perform DFS
 3.Check connection
 0.Exit
 Your choice: 3
Enter source: A
Enter destination: G

 There does not exist a connection from A to G

(null)

 Wassup?
 1.Display graph
 2.Perform DFS
 3.Check connection
 0.Exit
 Your choice: 3
Enter source: A
Enter destination: F

ABCEF

 Wassup?
 1.Display graph
 2.Perform DFS
 3.Check connection
 0.Exit
 Your choice: 0
 */

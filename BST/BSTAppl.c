#include"BSTImpl.h"

void main(){
	int option;
	
	playerProfile *P=NULL;
	playerInfo pi;
	
	do{
		printf("\n Wassup?\n 1.Insert\n 2.Delete\n 3.Display tree\n");
		printf(" 4.Search using name\n 5.Preorder traversal\n");
		printf(" 6.Inorder traversal\n 7.Postorder traversal\n ");
		printf("0.Exit\n Your choice: ");scanf("%d",&option);
		
		if(option==1){
			printf("Enter name: ");scanf(" %[^\n]",pi.name);
			printf("Enter role: ");scanf(" %[^\n]",pi.role);
			
			//displayPlayer(pi);
			P=insert(P,pi);
			//displayPlayer(P->pi);
		}
		else if(option==2){
			char name[100];
			printf("Enter name: ");scanf(" %[^\n]",name);
			
			deleteNode(P,name);
		}
		else if(option==3){
			disp(P,0);
		}
		else if(option==4){
			char name[100];
			printf("Enter name: ");scanf(" %[^\n]",name);
			
			search(P,name);
		}
		else if(option==5){
			preorder(P);
		}
		else if(option==6){
			inorder(P);
		}
		else if(option==7){
			postorder(P);
		}
		else if(option)
			printf("\n Invalid option \n");
		else;
	}while(option);	
}

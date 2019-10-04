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

/*
Output:

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 1
Enter name: Shiva
Enter role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 1
Enter name: Shar
Enter role: Bowl

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 1
Enter name: Sid
Enter role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 1
Enter name: Shash
Enter role: Bowl

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 1
Enter name: Sathish
Enter role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 1
Enter name: Sib
Enter role: Bowl

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 1
Enter name: Sram
Enter role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 3
Name: Shiva	Role: Bat
	Name: Shar	Role: Bowl
		Name: Sathish	Role: Bat
		Name: Shash	Role: Bowl
	Name: Sid	Role: Bat
		Name: Sib	Role: Bowl
		Name: Sram	Role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 2
Enter name: Shash

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 3
Name: Shiva	Role: Bat
	Name: Shar	Role: Bowl
		Name: Sathish	Role: Bat
	Name: Sid	Role: Bat
		Name: Sib	Role: Bowl
		Name: Sram	Role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 2
Enter name: Sid

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 3
Name: Shiva	Role: Bat
	Name: Shar	Role: Bowl
		Name: Sathish	Role: Bat
	Name: Sram	Role: Bat
		Name: Sib	Role: Bowl

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 4
Enter name: Sram

Name: Sram	Role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 5
Name: Shiva	Role: Bat
Name: Shar	Role: Bowl
Name: Sathish	Role: Bat
Name: Sram	Role: Bat
Name: Sib	Role: Bowl

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 6
Name: Shar	Role: Bowl
Name: Sathish	Role: Bat
Name: Shiva	Role: Bat
Name: Sram	Role: Bat
Name: Sib	Role: Bowl

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 7
Name: Shar	Role: Bowl
Name: Sathish	Role: Bat
Name: Sram	Role: Bat
Name: Sib	Role: Bowl
Name: Shiva	Role: Bat

 Wassup?
 1.Insert
 2.Delete
 3.Display tree
 4.Search using name
 5.Preorder traversal
 6.Inorder traversal
 7.Postorder traversal
 0.Exit
 Your choice: 0
*/

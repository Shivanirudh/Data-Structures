#include"DictionaryImpl.h"
void main()
{
	struct DictADT *root;
	root=(struct DictADT*)malloc(sizeof(struct DictADT));
	Data d; 
    int opt,choice;
    char key[100];
    do
   {
   	printf("Enter choice:\n1.Insert\n2.Search\n3.Display\n");
   	scanf("%d",&choice);
   	switch(choice)
   	{
     case 1:printf("Enter word to insert:\n");
     getchar();
     scanf("%[^\n]",d.word);
     printf("Enter the definition:\n " );
     getchar();
     scanf("%[^\n]",d.def);
     root = insert(root,d);
     break;
     case 2:printf("Enter the word to search for:\n");
     getchar();
     scanf("%[^\n]",key);
     search(root,key);
     break;
     case 3:display(root,0);
     break;
    }
    printf("Enter 1 to continue,0 to exit:\n");
    scanf("%d",&opt);
   }while(opt!=0); 
}

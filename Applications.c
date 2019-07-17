#include "Implementations.c"

int main(){
    Student s;initialiseStudent(&s);
    listADT l;initialiseList(&l);

    int option;
    char choice;
    int numLimit;
    int regNum;
    Student PassList[100];
    for(int i=0;i<100;i++)
	initialiseStudent(&PassList[i]);
    listADT NameList;
    initialiseList(&NameList);
    char *name=NULL;
    name=(char*)malloc(100*sizeof(char));

    printf("Enter the number of elements: ");scanf("%d",&(l.numLimit));

        do{
        printf("What operation do you want to perform? \n1-Insert Node in Front \n2-Insert Node at End \n");
        printf("3-Insert Record after register number \n4-Return record with given register number \n");
        printf("5-List records based on register number \n6-Delete and display record \n");
        printf("7-Compute and Update Result \n8-List Passed Students \n9-List Number of Passed Students \n0-Exit \n");
        printf("Enter your choice: ");scanf("%d",&option);

        switch(option){
            case 1:
                printf("Enter details of student to be written: \n");
                getStudentDetails(&s);
                insertFront(&l,s);
                break;
            case 2:
                printf("Enter details of student to be written: \n");
                getStudentDetails(&s);
                insertEnd(&l,s);
                break;
            case 3:
                printf("Enter register number after which data is to be written ");scanf("%d",&regNum);
                printf("Enter details of student to be written: \n");
                getStudentDetails(&s);
                insertRegNo(&l,s,regNum);
                break;
            case 4:
                printf("Enter register number of which data is to be returned ");scanf("%d",&regNum);
                searchRegNo(l,regNum);
                break;
            case 5:
                printf("Enter name to be searched for ");scanf("%[^\n]",name);
                NameList=searchName(l,name);
                for(int i=0;i<NameList.numLimit;i++)
                    displayStudentDetails(NameList.Record[i]);

                break;
            case 6:
                printf("Enter register number of which data is to be deleted ");scanf("%d",&regNum);
                deleteRecord(&l,regNum);
                break;
            case 7:
                computeResult(&l);
                break;
            case 8:

                listResult(l);
                break;
            case 9:
                printf("\n Number of students passed is %d",listClass(l));
                break;
            default:
                printf("\n Invalid option\n");


        }
        printf("Do you want to continue?(y/n)");scanf("%c",&choice);
    }while(choice=='Y'||choice=='y');

}


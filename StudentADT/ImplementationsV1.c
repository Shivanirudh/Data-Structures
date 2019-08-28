#include "PrototypesV1.c"

void initialiseStudent(Student *s){
    (*s).Name[0]='\0';
    (*s).regNo=0;
    (*s).Marks1=0.0;
    (*s).Marks2=0.0;
    (*s).Marks3=0.0;
    (*s).Total=0.0;
    (*s).Result='\0';
}

void initialiseList(listADT *l){
	(*l).front=0;
	(*l).back=-1;
	(*l).numLimit=0;
}

void getStudentDetails(Student *s){
    printf("Enter Register Number: ");scanf("%d",&(*s).regNo);
    printf("Enter name: ");scanf(" %[^\n]", &(*s).Name);
    printf("Enter the marks in three subjects ");scanf("%lf %lf %lf",&(*s).Marks1,&(*s).Marks2,&(*s).Marks3);
    (*s).total = (*s).Marks1+(*s).Marks2+(*s).Marks3;
}

void displayStudentDetails(Student s){
    printf("Name: %s\n",s.Name);
    printf("Register Number: %d\n",s.regNo);
    printf("Marks: %lf %lf %lf\n",s.Marks1,s.Marks2,s.Marks3);
    printf("Total: %lf\n",s.Total);
    printf("Result: %c\n",s.Result);
}

void insertFront(listADT *l,student s){       //1.	Insert a record in the front of the list
	if((*l).numLimit==0){
		(*l).Record[++(*l).back]=s;
		(*l).numLimit++;
	}
	else if((*l).numLimit<100){
		for(int i=numLimit;i>=0;i--){
			(*l).Record[i+1]=(*l).Record[i];
			(*l).numLimit++;
		}
	}
	else
		printf("No space available");
}

void insertEnd(listADT *l,student s){        //2.	Insert a record at the end of the list
	if((*l).numLimit<100){
		(*l).Record[++(*l).back]=s;
		(*l).numLimit++;
	}
	else
		printf("NO space available");

}

void insertRegNo(listADT *l,student s,int regNum){   //3.	Insert a record after a given Regno in the list
    if((*l).numLimit<100){
        for(int i=0;i<numLimit;i++){
            if((*l).Record[i].regNo==int regNum){
                for(int j=numLimit-1;j<i+1;j--){
                    (*l).Record[j+1]=(*l).Record[j];
                }
                (*l).Record[i+1]=s;
                (*l).numLimit++;(*l).back++;
                break;
            }
        }
        printf("Register Number not found");
    }
    else
        printf("No space available");
}

Student searchRegNo(listADT l,int regNum){           //4.	Return the record with the given Regno from the list
    for(int i=0;i<l.numLimit;i++)
        if(l.Record[i].regNo==regNum)
            return l.Record[i];
    printf("Register Number not found ");
}

Student* searchName(listADT l,char name[]){          //5.	List the records of students based on his register number

}

void deleteRecord(listADT *l, int regNum){                  //6.	Delete a given student record given his register number
    Student s;                                       //and display all the details
    for(int i=0;i<(*l).numLimit;i++)
        if((*l).Record[i].regNo==regNum){
            for(int j=i+1;j<(*l).numLimit;j++)
                (*l).Record[j-1]=(*l).Record[j];
            s= (*l).Record[i];
            (*l).back--;
        }
    displayStudentDetails(s);
}

void computeResult(listADT *l){                      //7.	Calculate the Total and update the Result field
    for(int i=0;i<(*l).numLimit;i++){
        if(((*l).Record[i]).Total > 90)
            ((*l).Record[i]).Result='O';
        else if(((*l).Record[i]).Total > 80)
            ((*l).Record[i]).Result='A';
        else if(((*l).Record[i]).Total > 70)
            ((*l).Record[i]).Result='B';
        else if(((*l).Record[i]).Total > 60)
            ((*l).Record[i]).Result='C';
        else if(((*l).Record[i]).Total > 50)
            ((*l).Record[i]).Result='D';
        else
            ((*l).Record[i]).Result='F';
    }
}

Student* listResult(listADT l){                     //8.	List the students who have passed
    Student PassList[100];
    int passCounter=0;
    for(int i=0;i<l.numLimit;i++){
        if((l.Record[i]).Result!='F')
            PassList[passCounter++]=l.Record[i];
    }
    return PassList;
}

int listClass(listADT l){                           //9.	List the students how many have secured FirstClass
    int firstClassCounter=0;
    for(int i=0;i<l.numLimit;i++){
        if((l.Record[i]).Result=='O')
            firstClassCounter++;
    }
    return firstClassCounter;
}

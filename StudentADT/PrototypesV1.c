#include<stdio.h>
typedef struct{
	int regNo;
	char Name[50];
	double Marks1,Marks2,Marks3,Total;
	char Result;
}Student;

typedef struct{
	Student Record[100];
	int front;
	int back;
	int numLimit;
}listADT;

void initialiseStudent(Student *s);

void initialiseList(listADT *l);

void getStudentDetails(Student *s);

void displayStudentDetails(Student s);

void insertFront(listADT *l,student s);//1.	Insert a record in the front of the list

void insertEnd(listADT *l,student s);//2.	Insert a record at the end of the list

void insertRegNo(listADT *l,student s,int regNum);//3.	Insert a record after a given Regno in the list

Student searchRegNo(listADT l,int regNum);//4.	Return the record with the given Regno from the list

Student* searchName(listADT l,char name[]);//5.	List the records of students based on his register number

void deleteRecord(listADT l, int regNum);//6.	Delete a given student record given his register number and display all the details

void computeResult(listADT *l);//7.	Calculate the Total and update the Result field

Student* listResult(listADT l);//8.	List the students who have passed

int listClass(listADT l);//9.	List the students how many have secured FirstClass

/* main.c
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "student.c"
#include "grade.c"
#include "calculateGPA.c"

int main(int argc, char** argv) {
	
	int choice = 0;
	int listSize = 2;
	int numStudents = 0;
	Student **studentList = malloc(sizeof(Student) * listSize);
	
	
	while(choice != 7) {
	
		printf("\nPlease select from the following options:\n");
		printf("1. Add student\n");
		printf("2. Remove student\n");
		printf("3. Add grade\n");
		printf("4. Sort list of students\n");
		printf("5. Print list of students\n");
		printf("6. Print grade bar chart\n");
		printf("7. Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			
			case 1:
				
				int idInput = 0;
				printf("\nEnter the student's id: ");
				scanf("%d", &idInput);
				
				char nameInput[MAX_NAME_LENGTH];
				printf("Enter the student's name: ");
				scanf(" %[^\n]", nameInput);
				
				//Student *s = constructStudent(nameInput, idInput);
				//studentList[numStudents++] = s;
				//printf("Student successfully added.\n");
				int ans = addStudent(studentList, &numStudents, &listSize, nameInput, idInput);
				
				if((float) numStudents / listSize >= 0.5f) { // Keep load factor < 0.5
					listSize = listSize * 2;
					studentList = realloc(studentList, sizeof(Student) * listSize);
					printf("Doubled student array size. Now %d\n", listSize);
				}
				
				break;
				
			case 2:
				
				//printf("Not yet implemented.\n");
				
				idInput = 0;
				printf("\nEnter the student's id you want to remove: ");
				scanf("%d", &idInput);
				
				if(removeStudent(studentList, &numStudents, idInput)){
					printf("student #%d has been removed successfully", idInput);
				}
				else{
					printf("could not find the student");
				}
				
				break;
				
			case 3:
				
				//printf("Not yet implemented.\n");
				idInput = 0;
				printf("\nEnter the student's id: ");
				scanf("%d", &idInput);
				
				Student* one;
				for(int i=0; i<numStudents; i++){
					if(studentList[i]->id == idInput){
						one = studentList[i];
					}
				}
				printf("found the student");
				if(one ==NULL){
					printf("could not find the student");
					break;
				}
				
				char gradeName[50];
				printf("\nEnter the name of the grade: (math/science/english)");
				scanf("%s", &gradeName);
				int gradeInput = 0;
				printf("\nEnter the grade of the student: ");
				scanf("%d", &gradeInput);
				
				if(addGrade(&one->grades, &one->numGrades, &one->maxGrades, gradeInput, gradeName)){
					printf("Grade added successfully");
					one->gpa = calculateGPA(&one->grades, one->numGrades);
				}
				else{
					printf("error");
				}
				
				if((float) one->numGrades / one->maxGrades >= 0.5f) { // Keep load factor < 0.5
					one->grades = realloc(one->grades, sizeof(Grade) * (one->maxGrades*2));
					one->maxGrades = one->maxGrades * 2;
					printf("Doubled grade array size. Now %d\n", one->maxGrades);
				}
				
					//would addGrade write to csv file???
				
				break;
				
			case 4:
				
				int sortchoice = 0;
				
				printf("\nSelect one of the following:\n");
				printf("1. Sort by id\n");
				printf("2. Sort by name\n");
				printf("3. Sort by GPA\n");
				scanf(" %d", &sortchoice);
				
				switch(sortchoice) {
					case 1:
						
						printf("Not yet implemented.\n");
						break;
						
					case 2:
						
						printf("Not yet implemented.\n");
						break;
						
					case 3:
						
						printf("Not yet implemented.\n");
						break;
						
					default:
						
						printf("Invalid selection. Cancelling sort.\n");
						break;
						
				}
				
				
				break;
				
			case 5:
				
				printf("---------------------------------------------------------\n");
				printf("ID        Name                                    GPA\n");
				
				for(int i = 0; i < numStudents; i++)
						printStudentInfo(studentList[i]);
				
				printf("---------------------------------------------------------\n");
				break;
				
			case 6:
				
				printf("Not yet implemented.\n");
				break;
				
			case 7:
				
				for(int i = 0; i < numStudents; i++)
					free(studentList[i]);
				free(studentList);
				printf("Goodbye.\n");
				break;
				
			default:
				
				printf("Invalid selection. Choose from 1-7\n");
				break;
		
		} // end switch
	} // end while
} // end main

void printStudentInfo(const Student *s) {
	printf("%-10d%-40s%-1f\n", s->id, s->name, s->gpa);
}

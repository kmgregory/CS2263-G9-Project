/* student.h
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "grade.h"

#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 40

typedef struct {
	int id;
	//char name[MAX_NAME_LENGTH];
	char * name;
	int numGrades;
	int maxGrades;
	Grade *grades;
	float gpa;

} Student;
/*
Student *constructStudent(const char *name, int id) {
	Student *s = malloc(sizeof(Student));
	s->id = id;
	strcpy(s->name, name);
	return s;
}
*/
// Function Prototypes
int addStudent(Student *students[], int *count, int *listSize, const char *name, int id);
void printStudentInfo(const Student *s);
float calculateGPA(Grade** grades, int count);
void sortByID(Student *students, int count);
void sortByName(Student *students[], int count);
void sortByGPA(Student *students, int count);
void printBarChart(Student* student);

#endif

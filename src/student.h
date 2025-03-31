/* student.h
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "grade.h"

#ifndef STUDENT_H
#define STUDENT_H

typedef struct {

	int id;
	char *name;
	GradeNode *gradesListHead;
	float gpa;

} Student;

typedef struct StudentNode {
	
	Student *data;
	struct StudentNode *next;
	
} StudentNode;

// Function Prototypes
Student *constructStudent(int id, char *name);
void deconstructStudent(Student *s);
void deconstructGrades(GradeNode **head);
StudentNode *constructStudentNode(Student *s);
void deconstructStudentNode(StudentNode *n);
void addStudent(StudentNode **head, int id, char *name);
void removeStudent(StudentNode **head, int id);
void printStudentInfo(const Student *s);
StudentNode *findStudent(StudentNode **head, int id);
float calculateGPA(GradeNode **head);
void sortByID(Student *students, int count);
void sortByName(Student *students[], int count);
void sortByGPA(Student *students, int count);
void printBarChart(const Student* student);

#endif

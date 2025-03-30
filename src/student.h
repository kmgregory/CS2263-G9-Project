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

typedef struct {

	int id;
	char *name;
	GradeNode *gradesList;
	float gpa;

} Student;

typedef struct StudentNode {
	
	Student *data;
	struct StudentNode *next;
	
} StudentNode;

// Function Prototypes
Student *constructStudent(int id, const char *name);
void deconstructStudent(Student *s);
void deconstructGrades(GradeNode *head);
StudentNode *constructStudentNode(Student *s);
void deconstructStudentNode(StudentNode *n);
void addStudent(StudentNode *head, int id, const char *name);
void removeStudent(StudentNode *head, int id);
void printStudentInfo(const Student *s);
float calculateGPA(Grade* grades, int count);
void sortByID(Student *students, int count);
void sortByName(Student *students[], int count);
void sortByGPA(Student *students, int count);
void printBarChart(Student* student);

#endif

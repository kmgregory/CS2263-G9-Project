/* student.h
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
	int id;
	char * name;
	Grade *grades;
	float gpa;

} Student;

// Function Prototypes
float calculateGPA(Grade* grades[], int count);
void displayStudent(const Student* student);
void sortByID(Student students[], int count);
void sortByName(Student students[], int count);
void sortByGPA(Student students[], int count);
void printBarChart(Student* student);

#endif

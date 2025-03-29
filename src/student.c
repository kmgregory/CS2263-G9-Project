/* student.c
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "student.h"

Student *constructStudent(const char *name) {
	
	Student *s = malloc(sizeof(Student));
	s->name = strdup(name);
	s->id = id;
	s->grades = NULL;

} // constructStudent()

void *deconstructStudent(Student *s) {
	
	free(s->name);
	deconstructGrades(s->grades);
	free(s);
	s = NULL;
	
	
} // deconstructStudent()

void *deconstructGrades(GradeNode *head) {
	
	*p = head;
	*q = p->next;
	while(q != NULL) {
		
		deconstructGradeNode(p);
		p = q;
		q = q->next;
		
	} 
	
	head = NULL;
	
} // deconstructGrades

StudentNode *constructStudentNode(Student *s) {
	
	StudentNode *n = malloc(StudentNode);
	n->data = s;
	n->next = NULL;
	
} // constructStudentNode()

void *deconstructStudentNode(StudentNode *n) {
	
	deconstructStudent(n->data);
	free(n);
	n = NULL;
	
} // deconstructStudentNode()

void addStudent(StudentNode *head, const char *name, int id) {
	
	Student *s = constructStudent(name, id);
	StudentNode *n = constructStudentNode(s);
	
	StudentNode *p = head;
	while(p->next != NULL)
		p = p->next;
	
	p->next = n;
	
} // addStudent()

void printStudentInfo(const Student *s) {
	printf("%d: %s (%.2f)\n", s->id, s->name, s->gpa);
} // printStudentInfo()

/*
Unimplemented Functions
-----------------------
float calculateGPA(Grade* grades, int count);
void sortByID(Student *students, int count);
void sortByName(Student *students[], int count);
void sortByGPA(Student *students, int count);
void printBarChart(Student* student);
*/
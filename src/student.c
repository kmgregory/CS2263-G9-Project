/* student.c
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "student.h"

Student *constructStudent(int id, const char *name) {
	
	Student *s = malloc(sizeof(Student));
	if(!s)
		printf("Failed to allocate space for student %d\n", id);
	
	s->id = id;
	s->name = strdup(name);
	s->gradesList = NULL;
	
	return s;
	
} // constructStudent()

void deconstructStudent(Student *s) {
	
	free(s->name);
	deconstructGrades(s->gradesList);
	free(s);
	s = NULL;
	
	
} // deconstructStudent()

void deconstructGrades(GradeNode *head) {
	
	GradeNode *p = head;
	GradeNode *q = head->next;
	while(q != NULL) {
		
		deconstructGradeNode(p);
		p = q;
		q = q->next;
		
	} 
	
	head = NULL;
	
} // deconstructGrades

StudentNode *constructStudentNode(Student *s) {
	
	StudentNode *n = malloc(sizeof(StudentNode));
	n->data = s;
	n->next = NULL;
	
	return n;
	
} // constructStudentNode()

void deconstructStudentNode(StudentNode *n) {
	
	deconstructStudent(n->data);
	free(n);
	n = NULL;
	
} // deconstructStudentNode()

void addStudent(StudentNode *head, int id, const char *name) {
	
	Student *s = constructStudent(id, name);
	StudentNode *n = constructStudentNode(s);
	
	if(head == NULL) {
		head = n;
	}
	
	else {

		StudentNode *p = head;
		while(p->next != NULL)
			p = p->next;
		
		p->next = n;
		printf("Successfully added student '%d'\n", id);
		
	}
	
} // addStudent()

void removeStudent(StudentNode *head, int id) {
	
	// Empty list
	if(head == NULL) {
	
		printf("Student list is empty\n");
		return;
		
	}
	
	StudentNode *p = head;
	StudentNode *q = head->next;
	
	// First student in list
	if(head->data->id == id) {
		
		deconstructStudentNode(head);
		head = q;
		printf("Successfully removed student %d\n", id);
		return;
		
	}
	
	// Rest of list
	while(q != NULL) {
		
		if(q->data->id == id) {
			p->next = q->next;
			deconstructStudentNode(q);
			printf("Successfully removed student %d\n", id);
			return;
		}
		
		p = q;
		q = q->next;
		
	}
	
	printf("Could not find student %d in list\n", id);
	
} // removeStudent()

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
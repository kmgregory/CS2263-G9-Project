/* student.c
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "student.h"

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define NORMAL "\x1B[0m"

Student *constructStudent(int id,  char *name) {
	
	Student *s = (Student *)malloc(sizeof(Student));
	if(s == NULL) 
		printf("Failed to allocate space for student %d\n", id);
	
	s->id = id;
	s->name = strdup(name);
	s->gradesListHead = NULL;
	s->gpa = 0.0f;
	
	return s;
	
} // constructStudent()

void deconstructStudent(Student *s) {
	
	free(s->name);
	deconstructGrades(&s->gradesListHead);
	free(s);
	s = NULL;
	
	
} // deconstructStudent()

void deconstructGrades(GradeNode **head) {
	
	if(head == NULL)
		return;
	
	GradeNode *p = *head;
	GradeNode *q = (*head)->next;
	while(q != NULL) {
		
		deconstructGradeNode(p);
		p = q;
		q = q->next;
		
	} 
	
	deconstructGradeNode(p);
	head = NULL;
	
} // deconstructGrades

StudentNode *constructStudentNode(Student *s) {
	
	StudentNode *n = (StudentNode *)malloc(sizeof(StudentNode));
	if(n == NULL)
		printf("Failed to allocate space for node\n");
	
	n->data = s;
	n->next = NULL;
	
	return n;
	
} // constructStudentNode()

void deconstructStudentNode(StudentNode *n) {
	
	deconstructStudent(n->data);
	free(n);
	n = NULL;
	
} // deconstructStudentNode()

void addStudent(StudentNode **head, int id, char *name) {
	
	Student *s = constructStudent(id, name);
	StudentNode *n = constructStudentNode(s);
	
	if(*head == NULL) {
		*head = n;
		printf("Successfully added student '%d'\n", id);
	}
	
	else {

		StudentNode *p = *head;
		while(p->next != NULL)
			p = p->next;
		
		p->next = n;
		printf("Successfully added student '%d'\n", id);
		
	}
	
} // addStudent()

void removeStudent(StudentNode **head, int id) {
	
	// Empty list
	if(*head == NULL) {
	
		printf("Student list is empty\n");
		return;
		
	}
	
	StudentNode *p = *head;
	
	// First student in list
	if(p->data->id == id) {
		*head = p->next;
		deconstructStudentNode(p);
		printf("Successfully removed student %d\n", id);
		return;
		
	}
	
	StudentNode *q = p->next;
	
	
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

StudentNode *findStudent(StudentNode **head, int id) {
	
	StudentNode *p = *head;
	
	while(p != NULL) {
		if(p->data->id == id)
			return p;
		
		p = p->next;
	}
	
	printf("Could not find student %d", id);
	return p;
	
} // findStudent()

void printStudentInfo(const Student *s) {
	printf("%d: %s (%.2f)\n", s->id, s->name, s->gpa);
} // printStudentInfo()

void printBarChart(const Student* student) {
	
	if(student == NULL) {
	
		printf("No student provided.\n");
		return;
		
	}
	
	if(student->gradesListHead == NULL) {
		
		printf("Student has no grades.\n");
		return;
		
	}
	
	GradeNode *p = student->gradesListHead;
	int run = 0;
	
	while(p != NULL) {
		
		// cycle through RGB for bar graph
		if(run % 3 == 0)
			printf("%s", RED);
		if(run % 3 == 1)
			printf("%s", GREEN);
		if(run % 3 == 2)
			printf("%s", BLUE);
		
		for(int i = 0; i <= p->data->gradePercent / 10; i++)
			printf("#");
		printf(" (%d)\n", p->data->gradePercent);
		
		p = p->next;
		
		run++;
	}
	
	printf("%s", NORMAL); // set text colour to normal
	
}

/*
Unimplemented Functions
-----------------------
void sortByID(Student *students, int count);
void sortByName(Student *students[], int count);
void sortByGPA(Student *students, int count);
*/

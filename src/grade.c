/* grade.h
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "grade.h"

Grade *constructGrade(const char *courseNum, float gradePercent) {
	
	Grade *g = (Grade *)malloc(sizeof(Grade));
	if(g == NULL) 
		printf("Failed to allocate space for grade\n");
	
	g->courseNum = strdup(courseNum);
	if(g->courseNum == NULL)
		printf("Failed to allocate space for grade name\n");
	g->gradePercent = gradePercent;
	return g;
	
} // constructGrade()

void deconstructGrade(Grade *g) {
	
	free(g->courseNum);
	free(g);
	g = NULL;
	
} // deconstructGrade()

GradeNode *constructGradeNode(Grade *g) {
	
	GradeNode *n = (GradeNode *)malloc(sizeof(GradeNode));
	if(n == NULL) 
		printf("Failed to allocate space for node\n");
	n->data = g;
	n->next = NULL;
	return n;
	
} //constructGradeNode()

void deconstructGradeNode(GradeNode *n) {
	
	deconstructGrade(n->data);
	free(n);
	n = NULL;
	
} // deconstructGradeNode()

void addGrade(GradeNode **head, char *courseNum, int grade) {
	
	Grade *g = constructGrade(courseNum, grade);
	GradeNode *n = constructGradeNode(g);
	
	if(*head == NULL) {
		*head = n;
		return;
	}
	
	GradeNode *p = *head;
	while(p->next != NULL)
		p = p->next;
	
	p->next = n;
	
} // addGrade()

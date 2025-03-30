/* calculateGPA.c
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "grade.h"

float calculateGPA(GradeNode **head) {
	
	float gpSum = 0.0f;
	int numGrades = 0;
	int grade = 0;
	GradeNode *p = *head;
	
	if(p == NULL)
		return 0.0f;
	
	while(p != NULL) {
		
		grade = p->data->gradePercent;
		
		if(grade > 90) { gpSum += 4.3; }
		
		else if(grade >85) { gpSum += 4.0; }
		
		else if(grade >80) { gpSum += 3.7; }
		
		else if(grade >75) { gpSum += 3.3; }
		
		else if(grade >70) { gpSum += 3.0; }
		
		else if(grade >65) { gpSum += 2.7; }
		
		else if(grade > 60) { gpSum += 2.3; }
		
		else if(grade > 55) { gpSum += 2.0; }
		
		else if(grade >50) { gpSum += 1.0; }
		
		else { gpSum += 0.0f; }
		
		numGrades++;
		p = p->next;

	}
	
	return gpSum / numGrades;

} // calculateGPA()

/* grade.h
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef GRADE_H
#define GRADE_H

typedef struct {
	
	char *courseNum;
	float gradePercent;
	
} Grade;

typedef struct {
	
	Grade *data;
	GradeNode *next;
	
} GradeNode;

// Function Prototypes
Grade *constructGrade(const char *name, float gradePercent);
void deconstructGrade(Grade *g);
GradeNode *constructGradeNode(Grade *g);
void deconstructGradeNode(GradeNode *n);
void addGrade(GradeNode *head, char *name, float grade);

#endif

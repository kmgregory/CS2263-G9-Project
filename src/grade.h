/* grade.h
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#ifndef GRADE_H
#define GRADE_H

typedef struct {
	char *name;
	float grade;
} Grade;

// Function Prototypes
void addGrade(Grade *grades, int count);

#endif

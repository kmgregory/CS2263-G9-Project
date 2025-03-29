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
	char *name;
	float grade;
} Grade;

// Function Prototypes
int addGrade(Grade *grades[], int *count, int *maxCount, float grade, char *name);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "grade.h"
#include <string.h>

int addGrade(Grade *grades[], int *count, int *maxCount, float grade, char *name){
	/*if((float) *count / *maxCount >= 0.5f) { // Keep load factor < 0.5
		grades = realloc(grades, sizeof(Grade) * (*count*2));
		*count = *count * 2;
		printf("Doubled grade array size. Now %d\n", *count);
	}
	*/
	/*if(*count == *maxCount){
		
		printf("grades are full");
		return 0;
	}*/
	
	Grade * newGrade = malloc(sizeof(Grade));
	if(!newGrade){
		printf("memory allocation for new grade failed");
		return 0;
	}
	
	newGrade->name = malloc(strlen(name));
	if(newGrade->name ==NULL){
		printf("grade name memory allocation failed");
		free(newGrade);
		return 0;
	}
	strcpy(newGrade->name, name);
	
	newGrade->grade = grade;
	grades[*count] = newGrade;
	*count = *count +1;
	
	return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


Student *constructStudent(const char *name, int id) {
	printf("in construct student\n");
	Student* s = malloc(sizeof(Student));
	if(s == NULL){
		printf("memory allocation failed");
		return NULL;
	}
	s->id = id;
	s->name = (char*)malloc(strlen(name));
	s->numGrades = 0;
	s->gpa = 0;
	s->maxGrades = 0;
	if(!s->name){
		printf("memory allocation for student name failed");
		free(s);
		return NULL;
	}
	s->name = strdup(name);
	return s;	
}

int addStudent(Student *students[], int *count, int *listSize, const char *name, int id){
	if(*count == *listSize){
		printf("array is full");
		return 0;
	}
	
	Student * newStudent = constructStudent(name, id);
	if(!newStudent){
		printf("error allocating memory");
		return 0;
	}
	
	//newStudent = constructStudent(name, id);
	students[*count] = newStudent;
	*count = *count +1;
	return 1;
}

int removeStudent(Student *students[], int *count, int id){
	if(*count == 0){
		printf("array is empty");
		return 0;
	}
	
	for(int i=0; i<*count; i++){
		if(students[i]->id == id){
			if(i==*count){ //last student is being removed
				free(students[i]->name);
				free(students[i]);
				*count = *count -1;
			}
			else{
				free(students[i]->name);
				free(students[i]);
				students[i] = students[*count];
			}
			*count = *count -1;
			return 1;
		}
	}
	return 0;
}

/**
void printStudentInfo(const Student *s){
	printf("in print student info\n");
	if(!s){
		printf("doesn't exist");
		return;
	}
	if(s->grades == NULL){
		printf("Name: %s, ID: %d, GPA: 0\n", s->name, s->id);
	}
	for(int i=0; i<s->numGrades; i++){
		printf("Name: %s, ID: %d, GPA: %f\n", s->name, s->id, s->gpa); 
	}
	
}*/
	

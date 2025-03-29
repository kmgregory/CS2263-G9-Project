#include <stdio.h>
#include <stdlib.h>

float calculateGPA(Grade* grades[], int numGrades){
	float gpa = 0;
	for(int i=0; i<numGrades; i++){
		float grade = grades[i]->grade;
		if(grade > 89){
			grade = 4.3;
		}
		else if(grade >84){
			grade = 4.0;
		}
		else if(grade >79){
			grade = 3.7;
		}
		else if(grade >74){
			grade = 3.3;
		}
		else if(grade >69){
			grade = 3.0;
		}
		else if(grade >64){
			grade = 2.7;
		}
		else if(grade > 59){
			grade = 2.3;
		}
		else if(grade > 54){
			grade = 2.0;
		}
		else if(grade >49){
			grade = 1.0;
		}
		else {
			grade = 0.0;
		}
		gpa += grade;
	
	}
	
	return gpa/numGrades;
}

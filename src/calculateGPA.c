/* calculateGPA.c
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include <stdio.h>
#include <stdlib.h>

float calculateGPA(float grades[], int numGrades){
	float gpa = 0;
	for(int i=0; i<numGrades; i++){
		float grade = grades[i];
		if(grade > 90){
			grade = 4.3;
		}
		else if(grade >85){
			grade = 4.0;
		}
		else if(grade >80){
			grade = 3.7;
		}
		else if(grade >75){
			grade = 3.3;
		}
		else if(grade >70){
			grade = 3.0;
		}
		else if(grade >65){
			grade = 2.7;
		}
		else if(grade > 60){
			grade = 2.3;
		}
		else if(grade > 55){
			grade = 2.0;
		}
		else if(grade >50){
			grade = 1.0;
		}
		else {
			grade = 0.0;
		}
		gpa += grade;
	
	}
	
	return gpa/numGrades;
}

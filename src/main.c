/* main.c
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "grade.h"
#include "student.c"
#include "calculateGPA.c"
#include "sortbygpa.c"
#include "quicksort.c"
#include "sortbyname.c"
#define MAX_NAME_LEN 50

StudentNode* deepCopy(StudentNode* h);
void printMenu();
void destroyList(StudentNode **head);
void sortingList();

int main(int argc, char** argv) {
	
	int choice = 0;
	StudentNode *head = NULL;
	
	int id = 0;
	char name[MAX_NAME_LEN];
	int gradePercent = 0;
	
	while(choice != -1) {
		
		printMenu();
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: // Add student
				
				printf("Enter the student's id: ");
				scanf("%d", &id);
				
				printf("Enter the student's name: ");
				scanf(" %[^\n]", name);
				
				addStudent(&head, id, name);
				
				break;
				
			case 2: // Remove student
				
				
				printf("Enter the student's id: ");
				scanf("%d", &id);
				
				removeStudent(&head, id);
				break;
				
			case 3: // Add grade
				
				printf("Enter the student's id: ");
				scanf("%d", &id);
				
				printf("Enter the course number (ex. CS2263): ");
				scanf(" %[^\n]", name);
				
				printf("Enter the grade percent without %% (ex. 93): ");
				scanf("%d", &gradePercent);
				
				StudentNode *n = findStudent(&head, id);
				if(n == NULL) 
					break;
				printf("Found Student.\n");
				
				addGrade(&n->data->gradesListHead, name, gradePercent);
				printf("Successfully added grade.\n");
				
				n->data->gpa = calculateGPA(&n->data->gradesListHead);
				printf("Student %d's GPA is now %.2f.\n", n->data->id, n->data->gpa);
				
				break;
			
			case 4: // Sort list of students
			
				// TODO
				//StudentNode* one = constructStudentNode(head->data);
				sortingList(head);
				printf("Not implemented\n");
				break;
				
			case 5: // Print list of students
				
				StudentNode *p = head;
				while(p != NULL) {
					printStudentInfo(p->data);
					p = p->next;
				}
				
				break;
				
			case 6: // Print grade bar chart
				
				// TODO
				printf("Not implemented\n");
				break;
				
			case -1:
				break; // Exit
				
				
			default: // Invalid input
				printf("Please select from the listed options\n.");
				break;
		}
		
		
		
	}
	
	destroyList(&head);
	return EXIT_SUCCESS;
	
} // main()

StudentNode* deepCopy(StudentNode* h){
	StudentNode* copy =NULL;
	if(h->data == NULL){
		return NULL;
	}
	addStudent(&copy, h->data->id, h->data->name);
	StudentNode * ptr = h;
	copy->data->gpa = ptr->data->gpa;
	while(ptr->next != NULL){
		ptr = ptr->next;
		addStudent(&copy, ptr->data->id, ptr->data->name);
		copy->data->gpa = ptr->data->gpa;
	}
	return copy;
} 

void printMenu() {

	printf("\nPlease select from the following options:\n");
	printf("1. Add student,\n");
	printf("2. Remove student,\n");
	printf("3. Add grade,\n");
	printf("4. Sort list of students,\n");
	printf("5. Print list of students,\n");
	printf("6. Print grade bar chart.\n");
	printf("Select '-1' to exit.\n");

} // printMenu()

void sortingList(StudentNode* head) {
	
	printf("\nSelect one of the following:\n");
	printf("1. Sort by ID,\n");
	printf("2. Sort by name,\n");
	printf("3. Sort by GPA.\n");
	
	int sortChoice = 0;
	scanf(" %d", &sortChoice);
	StudentNode* copy = deepCopy(head);
	StudentNode *s;
	switch(sortChoice) {
		case 1: // sort by ID
		
			// TODO
			StudentNode* sortedID = quickSortID(copy);
			s = sortedID;
			while(s != NULL) {
				printStudentInfo(s->data);
				s = s->next;
			}

			break;
		
		case 2: // sort by name
			//TODO
			StudentNode* sortedName = quickSortName(copy);
			s = sortedName;
			while(s != NULL) {
				printStudentInfo(s->data);
				s = s->next;
			}
				
			break;
		
		case 3: // sort by GPA
			//TODO
			StudentNode* sortedGpa = quickSortGpa(copy);
			s = sortedGpa;
			while(s != NULL) {
				printStudentInfo(s->data);
				s = s->next;
			}

			break;
		
		default:
			printf("Invalid choice, cancelling sorting.\n");
	}
	StudentNode *p = copy;
	StudentNode *q = p->next;
	while(q != NULL) {
		deconstructStudentNode(p);
		p = q;
		q = q->next;
	}
		
	deconstructStudentNode(p);
	copy = NULL;

} // sortingList()

void destroyList(StudentNode **head) {
	
	if(*head == NULL)
		return;
	
	StudentNode *p = *head;
	StudentNode *q = p->next;
	while(q != NULL) {
		deconstructStudentNode(p);
		p = q;
		q = q->next;
	}
	
	deconstructStudentNode(p);
	head = NULL;
	
}

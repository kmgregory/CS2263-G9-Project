/* main.c
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include "grade.h"
#include "student.h"

#define MAX_NAME_LEN 50

void printMenu();
void destroyList(StudentNode **head);
void sortingList();

int main(int argc, char** argv) {
	
	int choice = 0;
	StudentNode *head = NULL;
	
	int id = 0;
	char name[MAX_NAME_LEN];
	
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
				
				// TODO
				printf("Not implemented\n");
				break;
			
			case 4: // Sort list of students
			
				// TODO
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

void sortingList() {
	
	printf("\nSelect one of the following:\n");
	printf("1. Sort by ID,\n");
	printf("2. Sort by name,\n");
	printf("3. Sort by GPA.\n");
	
	int sortChoice = 0;
	scanf(" %d", &sortChoice);
	
	switch(sortChoice) {
		case 1: // sort by ID
			// TODO
			break;
		
		case 2: // sort by name
			//TODO
			break;
		
		case 3: // sort by GPA
			//TODO
			break;
		
		default:
			printf("Invalid choice, cancelling sorting.\n");
	}
	
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

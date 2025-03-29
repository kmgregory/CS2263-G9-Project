/* main.c
 * 
 * By Group 8:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */
 
// scanf(" %[^\n]", nameInput);

#include "grade.c"
#include "student.c"

int main(int argc, char** argv) {
	
	int choice = 0;
	
	while(choice != -1) {
		
		printMenu();
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: // Add student
				// TODO
				break;
				
			case 2: // Remove student
				// TODO
				break;
			
			case 3: // Add grade
				// TODO
				break;
			
			case 4: // Sort list of students
				sortListChosen();
				break;
			
			case 5: // Print list of students
				// TODO
				break;
			
			case 6: // Print grade bar chart
				// TODO
				break;
				
			case -1:
				break; // Exit
				
			default: // Invalid input
				printf("Please select from the listed options\n.")
				break;
		}
		
	}
	
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
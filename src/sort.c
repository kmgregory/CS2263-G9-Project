/* sort.c
 *
 * By Group 9:
 * Kamren M. Gregory - 3759472
 * Anush Matevosyan - 3758790
 * Sharmila Sadia Ahmed - 3741966
 *
 */

#include "sort.h"

StudentNode *getLast(StudentNode *head) {
	
	if(head == NULL)
		return head;
	
	StudentNode *p = head;
	while(p->next != NULL)
		p = p->next;
	return p;
	
} // getLast()

StudentNode *quickSort(StudentNode *head, int choice) {
	
	if(choice < 1 || choice > 3) {
		printf("Invalid choice - cancelling sorting procedure.\n");
		return head;
	}
	
	StudentNode *last = getLast(head);
	quickSortHelper(head, last, choice);
	
	return head;
	
} // quickSort()

void quickSortHelper(StudentNode *head, StudentNode *last, int choice) {
	
	if(head == NULL || head == last)
		return;
	
	StudentNode *pivot = partition(head, last, choice);
	
	// Recursive call for left and right half of list.
	quickSortHelper(head, pivot, choice);
	quickSortHelper(pivot->next, last, choice);
	
} // quickSortHelper()

StudentNode *partition(StudentNode *head, StudentNode *last, int choice) {
	
	if(head == NULL || last == NULL)
		return NULL;
	
	StudentNode *pivot = head;
	
	StudentNode *p = head;
	StudentNode *q = head;
	
	int compare = 0;
	
	while(p != last->next) {
		
		
		
		if(choice == 1) // sorting by id
			compare = (p->data->id < pivot->data->id);
			
			
		if(choice == 2) // sorting by name
			compare = (strcmp(p->data->name, pivot->data->name) < 0);
			
		
		if(choice == 3) // sorting by gpa
			compare = (p->data->gpa < pivot->data->gpa);
		
		if(compare) {
		
			swap(p->data, q->next->data);
			q = q->next;

		}
		
		p = p->next;
		
	}
	
	swap(pivot->data, q->data);
	return q; // set q to be the next pivot
	
} // partition()

void swap(Student *x, Student *y) {
	
	Student tmp = *x;
	*x = *y;
	*y = tmp;
	
}
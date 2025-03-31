#include <stdio.h>
#include "student.h"

/*StudentNode* quickSort(StudentNode* head){
	if(head==NULL||head->next == NULL){
		return head;
	}
	
	StudentNode* curr = head;
	StudentNode* next = head->next;
	StudentNode* prev = NULL;
	StudentNode* p = head;
	
	
	while(next!=NULL){
		if(*/

StudentNode* quickSortHelper(StudentNode* head){
	if(head==NULL || head->next == NULL){
		return head;
	}
	
	StudentNode* lowerHead = NULL;
	StudentNode* lowerTail = NULL;
	StudentNode* higherHead = NULL;
	StudentNode* higherTail = NULL;
	StudentNode* p = head;
	StudentNode* curr = head->next;
	
	while(curr!=NULL){
		if(curr->data->id < p->data->id){
			 if(lowerHead ==NULL){
			 	lowerHead = curr;
			 	lowerTail = curr;
			 }
			 else{
			 	lowerTail->next = curr;
			 	lowerTail = curr;
			 }
		}
		else{
			if(higherHead ==NULL){
			 	higherHead = curr;
			 	higherTail = curr;
			 }
			 else{
			 	higherTail->next = curr;
			 	higherTail = curr;
			 }	
		}
		curr = curr->next;
		p->next = NULL;
		if(lowerTail){
			lowerTail->next = NULL;
		}
		if(higherTail){
			higherTail->next = NULL;
		}
	}
	//StudentNode* pivot = partition(head, tail);
	StudentNode* here = lowerHead;
	while(here != NULL){
		printf("here low: %p, %d\n", here, here->data->id);
		here = here->next;
	}
	lowerHead = quickSortHelper(lowerHead);
	here = higherHead;
	while(here != NULL){
		printf("here high: %p, %d\n", here, here->data->id);
		here = here->next;
	}
	higherHead = quickSortHelper(higherHead);
	/*if(lowerHead){
		printf("in lowerHead\n");
		lowerTail->next = p;
	}
	else{
		printf("in lowerHead else\n");
		lowerHead = p;
	}*/
	if(lowerTail){
		printf("in lowertail\n");
		lowerTail->next = p;
	}
	p->next = higherHead;
	
	return lowerHead;
}

void quickSortID(StudentNode ** head){
	printf("head: %d\n", (*head)->data->id);
	*head = quickSortHelper(*head);
}

#include <stdio.h>
#include "student.h"
#include <string.h>

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
	printf("%s\n", p->data->name);
	while(curr!=NULL){
		if(strcmp(curr->data->name, p->data->name) < 0){//kam<10<30
			 printf("%s\n", curr->data->name);
			 printf("%s\n", p->data->name);
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
	StudentNode* here = lowerHead;
	while(here != NULL){
		printf("here low: %p, %s\n", here, here->data->name);
		here = here->next;
	}
	lowerHead = quickSortHelper(lowerHead);
	here = higherHead;
	while(here != NULL){
		printf("here high: %p, %s\n", here, here->data->name);
		here = here->next;
	}
	higherHead = quickSortHelper(higherHead);
	if(lowerTail){
		printf("in lowertail\n");
		lowerTail->next = p;
	}
	p->next = higherHead;
	
	return lowerHead;
}

void quickSortName(StudentNode ** head){
	printf("head: %s\n", (*head)->data->name);
	*head = quickSortHelper(*head);
}

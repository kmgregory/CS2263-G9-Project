#include <stdio.h>
//#include "student.c"

StudentNode* deepCopy(StudentNode* head){
	StudentNode * copy =NULL;
	if(head->data == NULL){
		return NULL;
	}
	addStudent(&copy, head->data->id, head->data->name);
	StudentNode * ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
		addStudent(&copy, ptr->data->id, ptr->data->name);
	}
	return copy;
} 

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
		StudentNode* next = curr->next;
		curr->next = NULL;
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
		curr = next;
	}
	p->next = NULL;
	lowerHead = quickSortHelper(lowerHead);
	higherHead = quickSortHelper(higherHead);
	
	//StudentNode* pivot = partition(head, tail);
	/*StudentNode* here = lowerHead;
	while(here != NULL){
		printf("here low: %p, %d\n", here, here->data->id);
		here = here->next;
	}
	lowerHead = quickSortHelper(lowerHead);
	here = higherHead;
	while(here != NULL){
		printf("here high: %p, %d\n", here, here->data->id);
		here = here->next;
	}*/
	StudentNode* newHead = p;
	if(lowerHead !=NULL){
		newHead = lowerHead;
		lowerTail->next = p;
	}
	/*
	if(lowerTail!=NULL){
		lowerTail->next = p;
	}
	p->next = higherHead;  
	/*if(lowerHead){
		printf("in lowerHead\n");
		lowerTail->next = p;
	}
	else{
		printf("in lowerHead else\n");
		lowerHead = p;
	}*//*
	if(lowerTail){
		printf("in lowertail\n");
		lowerTail->next = p;
	}
	*/
	p->next = higherHead;
	
	return newHead;
}

void quickSortID(StudentNode ** head){
	printf("head: %d\n", (*head)->data->id);
	StudentNode* copy = deepCopy(*head);
	copy = quickSortHelper(copy);
	/*StudentNode *p = copy;
	while(p != NULL) {
		printf("%d: %s (%.2f)\n", p->data->id, p->data->name, p->data->gpa);
		p = p->next;
	}*/

	if(copy == NULL)
		return;
	
	StudentNode *p = copy;
	//StudentNode *p = head;
	while(p != NULL) {
		printf("%d: %s (%.2f)\n", p->data->id, p->data->name, p->data->gpa);
		p = p->next;
	}
	p = copy;	
	StudentNode *q = p->next;
	while(q != NULL) {
		deconstructStudentNode(p);
		p = q;
		q = q->next;
	}
	
	deconstructStudentNode(p);
	copy = NULL;

	
}

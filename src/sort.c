#include <stdio.h>
#include "student.h"

StudentNode* partition(StudentNode *head, StudentNode *end, StudentNode** newHead, StudentNode** newTail){
	StudentNode* pivot = end;//p
	StudentNode* prev = NULL;//p
	StudentNode* curr = head;
	StudentNode* tail = pivot;
	//StudentNode* p = lowest;
	
	while(curr != pivot){
		if(curr->data->id < pivot->data->id){
			if((*newHead)==NULL){
				*newHead = curr;
			}
			prev = curr;
			curr = curr->next;
		}
		else{
			if(prev){
				prev->next = curr->next;
			}
			StudentNode* tmp = curr->next;
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
			curr = tmp;
		}
	}
	if(*newHead == NULL){
		*newHead = pivot;
	}
	
	*newTail = tail;
	return pivot;
}

StudentNode* quickSort(StudentNode* head, StudentNode* tail){
	if(head == NULL || head==tail){
		return head;
	}
	
	StudentNode *newHead = NULL;
	StudentNode *newTail = NULL;
	
	StudentNode* pivot = partition(head, tail, &newHead, &newTail);
	
	if(newHead != pivot){
		StudentNode* tmp = newHead;
		while(tmp->next != pivot){
			tmp = tmp->next;
		}
		tmp->next = NULL;
		
		newHead = quickSort(newHead, tmp);
		
		while(tmp != NULL && tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = pivot;
	}
	
	pivot->next = quickSort(pivot->next, newTail);
	
	return newHead;
}

void quickSortID(StudentNode ** head){
	StudentNode * tail = *head;
	while(tail != NULL && tail->next != NULL){
		tail = tail->next;
	}
	//printf("%p, %p", head, tail);
	*head = quickSort(*head, tail);
}


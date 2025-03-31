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
	printf("inside quickSortHelper\n");
	StudentNode* lowerHead = NULL;
	//StudentNode* lowerTail = NULL;
	StudentNode* higherHead = NULL;
	//StudentNode* higherTail = NULL;
	StudentNode* p = head;
	StudentNode* curr = head->next;
	
	while(curr!=NULL){
		printf("inside while\n");
		StudentNode* next = curr->next;
		curr->next = NULL;
		if(curr->data->id < p->data->id){
			printf("inside if #1\n");
			printf("%p", lowerHead);
			if(lowerHead ==NULL){
				printf("lowerhead == NULL");
				lowerHead = curr;
				//lowerTail = curr;
			}
			else{
				printf("lowerhead !=NULL");
				StudentNode* tail = lowerHead;
				while(tail->next !=NULL){
					printf("looping thoruhg tail");
					tail = tail->next;
				}
				tail->next = curr;
			 	//lowerTail->next = curr;
			 	//lowerTail = curr;
			}
		}
		else{
			printf("inside else");
			if(higherHead ==NULL){
			 	higherHead = curr;
			 	//higherTail = curr;
			 }
			 else{
			 	StudentNode* tail = higherHead;
			 	while(tail->next !=NULL){
			 		tail = tail->next;
			 	}
			 	tail->next = curr;
			 	//higherTail->next = curr;
			 	//higherTail = curr;
			 }	
		}
		printf("outside if else");
		curr = next;
	}
	p->next = NULL;
	lowerHead = quickSortHelper(lowerHead);
	higherHead = quickSortHelper(higherHead);
	
	StudentNode* newHead = p;
	if(lowerHead !=NULL){
		newHead = lowerHead;
		StudentNode* hold = newHead;
		while(hold->next !=NULL){
			hold - hold->next;
		}
		hold->next = p;
	}
	p->next = higherHead;
	
	return newHead;
}

void quickSortID(StudentNode ** head){
	StudentNode* copy = deepCopy(*head);
	copy = quickSortHelper(copy);
	
	if(copy == NULL)
		return;
	
	StudentNode *p = copy;
	while(p != NULL) {
		printf("\n%d: %s (%.2f)\n", p->data->id, p->data->name, p->data->gpa);
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

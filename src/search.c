#include "student.h"

void searchByID(int id, StudentNode * head){
	StudentNode* curr = head;
	if(head == NULL){
		printf("student doesnt exist");
		return;
	}
	if(head->data == NULL){
		return;
	}
	if(head->data->id == id){
		printf("Found Student %d, %s, %f\n", head->data->id, head->data->name, head->data->gpa);
		return;
	}
	while(curr->next != NULL){
		if(curr->next->data->id == id){
			printf("Found Student %d, %s, %f\n", curr->next->data->id, curr->next->data->name, curr->next->data->gpa);
			return;
		}
		curr = curr->next;
	}
	printf("student doesnt exist\n");
}

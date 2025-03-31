#include "student.c"
#include "sort.c"
//#include "grade.c"
#include <stdio.h>
#include <stdlib.h>

void destroyList(StudentNode **head) {
	
	if(*head == NULL)
		return;
	
	StudentNode *p = *head;
	
	StudentNode *q = NULL; //= p->next;
	
	while(p->next != NULL) {
		printf("Inside while loop\n%d, %s\n", p->data->id,p->data->name);
		q = p->next;
		deconstructStudentNode(p);
		p = q;
		q = q->next;
	}
	printf("%p\n", p); 
	deconstructStudentNode(p);
	printf("%p\n", p); 
	head = NULL;
	printf("here\n");
	
}

int main(){
	StudentNode * head;
	addStudent(&head, 1, "kam");
	
	printf("%d, %s\n", head->data->id, head->data->name);
	
	addStudent(&head, 2, "anu");
	
	printf("%d, %s\n", head->next->data->id, head->next->data->name);
	
	//destroyList(&head);
	
	
	//printf("%d, %s\n", head->data->id, head->data->name);
	/*
	int one;
	one=50;
	printf("%d\n", one);
	StudentNode * tail;
	printf("here");
	if(!head){//head==null
		printf("nothing in the list");
		return 1;
	}
	else{
		one = 1;
		printf("in else");
		tail = head;
		//if head->next = null either error or =NUll
	}
				
	while(head->next){
		printf("in while");
		tail = tail->next;
		one++;//idk if it counts right 
	}*/
	printf("send to sort");
	quickSortID(&head);
	printf("Not implemented\n");
	return 0;
}
			

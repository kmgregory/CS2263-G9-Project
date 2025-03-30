#include <stdio.h>

void swap(StudentNode* low, StudentNode* high){
	StudentNode temp = *low;
	low->next = high->next;
	low->data = high->data;
	high->next = temp->next;
	high->data = temp->data;
}

int partition(StudentNode *head, StudentNode *tail, int low, int high){
	Student lowest = head->data;//p
	Student highest = tail->data;//p
	int i = low;
	int j = high;
	Student p = first;
	
	while(i<j){
		while(lowest->id <= p->id &&  i<= high-1){//think high > high-1
			i++;
			lowest = lowest->next;
		}
		
		while(highest > p->data && j>=low+1){
			j--;
			highest = highest->next;
		}
		if(i<j){
			swap(&lowest, &highest);
		}
	}
	swap(&head, &tail);
	return j;
}

void quickSortID(StudentNode * first, StudentNode * last, int low, int high){
	if(low<high){
		int pi = partition(first, last, low, high);
		
		quickSort(first, last, low, pi-1);
		quickSort(first, last, pi+1, high);
			
			
			

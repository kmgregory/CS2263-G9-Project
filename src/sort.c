#include <stdio.h>

void swap(StudentNode* low, StudentNode* high){
	StudentNode temp = *low;
	low->next = high->next;
	low->data = high->data;
	high->next = temp->next;
	high->data = temp->data;
}

int partition(StudentNode *head, StudentNode *tail, int low, int high){
	StudentNode lowest = head;//p
	StudentNode highest = tail;//p
	int i = low;
	int j = high;
	StudentNode p = lowest;
	
	while(i<j){
		while(lowest->data->id <= p->data->id &&  i<= high-1){//think high > high-1
			i++;
			lowest = lowest->next;
		}
		
		while(highest->data->id > p->data->id && j>=low+1){
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
	}
}
			
			

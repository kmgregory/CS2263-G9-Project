#include <stdlib.h>
#include <stdio.h>
//#include "student.c"


// Partition the list around the pivot
StudentNode* partitionName(StudentNode* head, StudentNode** left, StudentNode** right) {
    StudentNode* pivot = head;
    *left = NULL;
    *right = NULL;

    StudentNode* current = head->next;
    while (current) {
        StudentNode* next = current->next;
        if(strcmp(current->data->name, pivot->data->name) < 0){
            current->next = *left;
            *left = current;
        }
        else{
            current->next = *right;
            *right = current;
        }
        current = next;
    }

    pivot->next = NULL;  // Disconnect pivot from the rest
    return pivot;
}

// Recursive Quick Sort
StudentNode* quickSortName(StudentNode* head) {
    if (!head || !head->next) {
        return head;
    }

    StudentNode *left = NULL;
    StudentNode *right = NULL;
    StudentNode* pivot = partitionName(head, &left, &right);

    // Sort left and right partitions recursively
    left = quickSortName(left);
    right = quickSortName(right);

    // Merge sorted left, pivot, and sorted right
    if (left) {
        StudentNode* temp = left;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = pivot;
    }
    else{
        left = pivot;
    }

    pivot->next = right;
    return left;
}

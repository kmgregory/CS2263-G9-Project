/* sort.h
 *
 * By Group 9:
 * Kamren M. Gregory - 3759472
 * Anush Matevosyan - 3758790
 * Sharmila Sadia Ahmed - 3741966
 *
 */

#include "student.h"

#ifndef SORT_H
#define SORT_H

StudentNode *getLast(StudentNode *head);
StudentNode *quickSort(StudentNode *head, int choice);
void quickSortHelper(StudentNode *head, StudentNode *last, int choice);
StudentNode *partition(StudentNode *head, StudentNode *last, int choice);
void swap(Student *x, Student *y);

#endif
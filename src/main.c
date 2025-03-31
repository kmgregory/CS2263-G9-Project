/* main.c
 *
 * By Group 9:
 * Kamren M. Gregory - 3759472
 * Anush Matevosyan - 3758790
 * Sharmila Sadia Ahmed - 3741966
 *
 */

#include "grade.h"
#include "student.h"
#include "csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

void printMenu();
void sortingList();
void destroyList(StudentNode **head);

void loadLinkedListFromCSV(StudentNode **head) {
    FILE *file = fopen("students.csv", "r");
    if (!file) {
        printf("CSV file not found. Starting with an empty list.\n");
        return;
    }
    char line[256];
    int lineNum = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNum++;
        if (lineNum == 1) continue; 
        if (strlen(line) < 3) continue; 
       
        char *token = strtok(line, ",");
        if (!token) continue;
        int id = atoi(token);
       
        token = strtok(NULL, ",");
        if (!token) continue;
        char name[MAX_NAME_LEN];
        strncpy(name, token, MAX_NAME_LEN);
        name[MAX_NAME_LEN - 1] = '\0';
        
        char *newline = strchr(name, '\n');
        if(newline) *newline = '\0';
       
        token = strtok(NULL, ",");
        char course[100] = "";
        if (token) {
            strncpy(course, token, 100);
            course[99] = '\0';
            newline = strchr(course, '\n');
            if(newline) *newline = '\0';
            
        }
       
        token = strtok(NULL, ",");
        int gradePercent = 0;
        if (token) {
            gradePercent = atoi(token);
        }
       
        // Add student if not already in the linked list.
        StudentNode *snode = findStudent(head, id);
        if (snode == NULL) {
            addStudent(head, id, name);
            snode = findStudent(head, id);
        }
        // If course and grade info exist, add the grade.
        if (strlen(course) > 0 && gradePercent > 0) {
            addGrade(&snode->data->gradesListHead, course, gradePercent);
            snode->data->gpa = calculateGPA(&snode->data->gradesListHead);
        }
    }
    fclose(file);
    printf("Linked list loaded from CSV.\n");
}

// saveLinkedListToCSV() overwrites the CSV file with the current linked list data.
// It writes the header and then, for each student, writes one line per grade record.
// If a student has no grade, a line is written with empty course and a grade of 0.
void saveLinkedListToCSV(StudentNode *head) {
    // Open file in write mode and write header.
    FILE *file = fopen("students.csv", "w");
    if (!file) {
        printf("Error opening CSV for writing.\n");
        return;
    }
    fprintf(file, "ID, Name, Course, Grade\n");
    fclose(file);
   
    // Now, for each student, append their records.
    StudentNode *p = head;
    while (p != NULL) {
        Student *s = p->data;
        if (s->gradesListHead != NULL) {
            GradeNode *g = s->gradesListHead;
            while (g != NULL) {
                char gradeStr[10];
                sprintf(gradeStr, "%d", g->data->gradePercent);
                // Use your write_csv() to append the record.
                write_csv(s->id, s->name, g->data->courseNum, gradeStr);
                g = g->next;
            }
        } else {
            // Student with no grades.
            write_csv(s->id, s->name, "", "0");
        }
        p = p->next;
    }
    printf("Linked list saved to CSV.\n");
}

int main(int argc, char** argv) {
    int choice = 0;
    StudentNode *head = NULL;
    int id = 0;
    char name[MAX_NAME_LEN];
    int gradePercent = 0;
    StudentNode *n = NULL;
    StudentNode *p = NULL;
   
    // Ensure CSV exists (creates file with headers if necessary)
    initialize_csv();
    // Load existing student data from CSV into the linked list.
    loadLinkedListFromCSV(&head);
   
    while(choice != -1) {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Add student
                printf("Enter the student's id: ");
                scanf("%d", &id);
                printf("Enter the student's name: ");
                scanf(" %[^\n]", name);
                addStudent(&head, id, name);
                break;
            case 2: // Remove student
                printf("Enter the student's id: ");
                scanf("%d", &id);
                removeStudent(&head, id);
                break;
            case 3: // Add grade
                printf("Enter the student's id: ");
                scanf("%d", &id);
                printf("Enter the course number (ex. CS2263): ");
                scanf(" %[^\n]", name); // reuse 'name' for course input
                printf("Enter the grade percent without %% (ex. 93): ");
                scanf("%d", &gradePercent);
                n = findStudent(&head, id);
                if(n == NULL)
                    break;
                printf("Found Student.\n");
                addGrade(&n->data->gradesListHead, name, gradePercent);
                printf("Successfully added grade.\n");
                n->data->gpa = calculateGPA(&n->data->gradesListHead);
                printf("Student %d's GPA is now %.2f.\n", n->data->id, n->data->gpa);
                break;
            case 4: // Sort list of students
                printf("Not implemented\n");
                break;
            case 5: // Print list of students
                p = head;
                while(p != NULL) {
                    printStudentInfo(p->data);
                    p = p->next;
                }
                break;
            case 6: // Print grade bar chart
                printf("Enter the student's id: ");
                scanf("%d", &id);
                n = findStudent(&head, id);
                if(n == NULL)
                    break;
                printBarChart(n->data);
                break;
            case -1:
                break; // Exit
            default:
                printf("Please select from the listed options\n.");
                break;
        }
    }
   
    // Before exiting, save all student data back to CSV.
    saveLinkedListToCSV(head);
    destroyList(&head);
    return EXIT_SUCCESS;
}

void printMenu() {
    printf("\nPlease select from the following options:\n");
    printf("1. Add student,\n");
    printf("2. Remove student,\n");
    printf("3. Add grade,\n");
    printf("4. Sort list of students,\n");
    printf("5. Print list of students,\n");
    printf("6. Print grade bar chart.\n");
    printf("Select '-1' to exit.\n");
}

void sortingList() {
    printf("\nSelect one of the following:\n");
    printf("1. Sort by ID,\n");
    printf("2. Sort by name,\n");
    printf("3. Sort by GPA.\n");
    int sortChoice = 0;
    scanf(" %d", &sortChoice);
    switch(sortChoice) {
        case 1: // sort by ID
            // TODO
            break;
        case 2: // sort by name
            // TODO
            break;
        case 3: // sort by GPA
            // TODO
            break;
        default:
            printf("Invalid choice, cancelling sorting.\n");
    }
}

void destroyList(StudentNode **head) {
    if(*head == NULL)
        return;
    StudentNode *p = *head;
    StudentNode *q = p->next;
    while(q != NULL) {
        deconstructStudentNode(p);
        p = q;
        q = q->next;
    }
    deconstructStudentNode(p);
    *head = NULL;
}

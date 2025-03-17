#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.csv"
#define MAX_NAME_LENGTH 100
#define MAX_COURSE_LENGTH 100
#define MAX_GRADE_LENGTH 3  // Maximum length for grades like "A+" and "WF"

// List of valid grades
const char *valid_grades[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D", "F", "WF"};
const int num_valid_grades = 11; // Number of valid grades

// Function to check if the file exists
int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;  // File exists
    }
    return 0;  // File does not exist
}

// Function to initialize the CSV file with headers if it doesn't exist
void initialize_csv() {
    if (!file_exists(FILE_NAME)) {
        FILE *file = fopen(FILE_NAME, "w");
        if (!file) {
            printf("Error creating file.\n");
            return;
        }
        fprintf(file, "ID, Name, Course, Grade\n");  // Write column headers
        fclose(file);
        printf("New file created with headers.\n");
    }
}

// Function to read the CSV file when the program starts
void read_csv() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No existing data found. Starting fresh...\n");
        return;
    }

    char line[256];
    int is_first_line = 1;
   
    printf("\nExisting Records:\n");
    while (fgets(line, sizeof(line), file)) {
        if (is_first_line) {
            printf("%s", line);  // Print headers
            is_first_line = 0;
        } else {
            printf("%s", line);
        }
    }

    fclose(file);
}

// Function to validate the grade
int is_valid_grade(char *grade) {
    for (int i = 0; i < num_valid_grades; i++) {
        if (strcmp(grade, valid_grades[i]) == 0) {
            return 1;  // Grade is valid
        }
    }
    return 0;  // Grade is invalid
}

// Function to write new student records
void write_csv(int id, char name[], char course[], char grade[]) {
    FILE *file = fopen(FILE_NAME, "a");  // Open in append mode
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d, %s, %s, %s\n", id, name, course, grade);
    fclose(file);
}

int main() {
    int id;
    char name[MAX_NAME_LENGTH];
    char course[MAX_COURSE_LENGTH];
    char grade[MAX_GRADE_LENGTH];

    // Ensure CSV file exists with headers
    initialize_csv();

    // Read previous records when the program starts
    read_csv();

    while (1) {
        printf("\nEnter student ID (or -1 to exit): ");
        scanf("%d", &id);
        if (id == -1) break;

        printf("Enter student name: ");
        scanf(" %[^\n]", name);

        printf("Enter course name: ");
        scanf(" %[^\n]", course);

        while (1) {
            printf("Enter student grade (A+, A, A-, B+, B, B-, C+, C, D, F, WF): ");
            scanf(" %s", grade);

            if (is_valid_grade(grade)) {
                break; // Valid grade, exit loop
            }
            printf("Invalid grade! Please enter a valid grade.\n");
        }

        write_csv(id, name, course, grade);
        printf("Record added successfully!\n");
    }

    printf("Program exited.\n");
    return 0;
}

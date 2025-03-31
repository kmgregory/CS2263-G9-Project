/* csv.c
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.csv"

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

// Function to write new student records
void write_csv(int id, char name[], char course[], char grade[]) {
	FILE *file = fopen(FILE_NAME, "a");  // Open in append mode
	if (!file) {
		printf("Error opening file for writing.\n");
		return;
	}

	fprintf(file, "%d,%s,%s,%s\n", id, name, course, grade);
	fclose(file);
}


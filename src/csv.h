/* csv.h
 * 
 * By Group 9:
 * 	Kamren M. Gregory - 3759472
 * 	Anush Matevosyan - 3758790
 * 	Sharmila Sadia Ahmed - 3741966
 *
 */

#ifndef CSV_H
#define CSV_H

int file_exists(const char *filename);
void initialize_csv();
void read_csv();
void write_csv(int id, char name[], char course[], char grade[]);

#endif

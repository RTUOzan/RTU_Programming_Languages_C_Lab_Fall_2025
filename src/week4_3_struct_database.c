/*
 * week4_3_struct_database.c
 * Author: Ozan Yurekli
 * Student ID: 230ADB077
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct Student with fields name, id, grade
struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student *students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  // Allocate memory for n Student structs using malloc
  students = malloc(n * sizeof(struct Student));

  // Check if allocation succeeded
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Read student data in a loop
  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d: ", i + 1);
    // Read name (no spaces), id, and grade
    scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade);
  }

  // Display all student records
  printf("\n%-6s %-12s %-6s\n", "ID", "Name", "Grade");
  for (int i = 0; i < n; i++) {
    printf("%-6d %-12s %.1f\n", students[i].id, students[i].name,
           students[i].grade);
  }

  // Free allocated memory
  free(students);

  return 0;
}

// week5_task4_struct_binary_io.c
// Task 4: Save and load structured records in binary format
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define BIN_FILE "student.bin"

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

// Function prototypes
void save_student_binary(Student s, const char *filename);
Student load_student_binary(const char *filename);

int main(void) {
  Student s1;
  strcpy(s1.name, "Alice");
  s1.age = 21;
  s1.gpa = 3.75f;

  // Save student in binary format
  printf("Saving student in binary format...\n");
  save_student_binary(s1, BIN_FILE);

  // Load student from binary file
  printf("Loading student from binary file...\n");
  Student s2 = load_student_binary(BIN_FILE);

  // Print loaded data
  printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

  // Optional: check binary file size
  FILE *fp = fopen(BIN_FILE, "rb");
  if (fp) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    printf("Binary file size: %ld bytes\n", size);
  }

  return 0;
}

// Save student in binary format
void save_student_binary(Student s, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Error: Could not open file '%s' for writing.\n", filename);
    exit(1);
  }
  fwrite(&s, sizeof(Student), 1, fp);
  fclose(fp);
}

// Load student from binary format
Student load_student_binary(const char *filename) {
  Student s;
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error: Could not open file '%s' for reading.\n", filename);
    exit(1);
  }
  fread(&s, sizeof(Student), 1, fp);
  fclose(fp);
  return s;
}

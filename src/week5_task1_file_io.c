// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char filename[100];
  char line[256];
  int line_count = 0;

  // BONUS: Ask user for filename
  printf("Enter filename to use (default: data.txt): ");
  if (fgets(filename, sizeof(filename), stdin)) {
    // Remove trailing newline if present
    char *newline = strchr(filename, '\n');
    if (newline) *newline = '\0';
    if (filename[0] == '\0') {  // Use default if empty input
      snprintf(filename, sizeof(filename), "data.txt");
    }
  } else {
    snprintf(filename, sizeof(filename), "data.txt");
  }

  // 1. Open file for writing (mode = "w")
  fp = fopen(filename, "w");
  // 2. Check if file opened successfully
  if (!fp) {
    fprintf(stderr, "Error: Could not open file '%s' for writing.\n", filename);
    return 1;
  }

  printf("Writing lines to %s...\n", filename);

  // 3. Write 2–3 lines of text using fprintf()
  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");
  fprintf(fp, "File operations are fun!\n");

  // 4. Close the file
  fclose(fp);

  // 5. Open file again for reading (mode = "r")
  fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "Error: Could not open file '%s' for reading.\n", filename);
    return 1;
  }

  printf("Reading contents of %s:\n", filename);

  // 6. Use fgets() in a loop to read and print each line
  while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
    line_count++;
  }

  // 7. Close the file
  fclose(fp);

  printf("\nTotal lines read: %d\n", line_count);

  return 0;
}

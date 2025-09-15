
#include <stdio.h>

int main(int argc, char *argv[]) {
  // This is your first C program my friend
  printf("Hello from Ozan yurekli!\n");
  printf("You passed %d argument(s).\n", argc - 1);
  //it will show how many arguments we have passed with this for loop
  for (int i = 1; i < argc; ++i) {
    printf("  arg[%d] = %s\n", i, argv[i]);
  }
  return 0;
}

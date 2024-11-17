// program to count number of new lines in given input
#include <stdio.h>

int main() {
  long num_lines;
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      num_lines++;
  }
  printf("no. of lines is %ld", num_lines);
}

// program to count number of characters in given input
#include <stdio.h>

int main() {
  long num_chars;
  int c;
  while ((c = getchar()) != EOF)
    num_chars++;
  printf("no. of chars is %ld",num_chars);
}

// print words in each line
#include <stdio.h>

int main() {
  int c, state;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ')
      printf("\n");
    else
      printf("%c", c);
  }
}

// count number of lines,tabs and blank spaces
#include <stdio.h>

int main() {
  long num_lines = 0;
  long num_tabs = 0;
  long num_blanks = 0;
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++num_lines;
    if (c == '\t')
      ++num_tabs;
    if (c == ' ')
      ++num_blanks;
  }
  printf("no. of lines = %ld tabs = %ld blanks = %ld", num_lines, num_tabs,
         num_blanks);
}

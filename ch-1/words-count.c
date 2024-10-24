// count number of words ( similar to wc command in UNIX)
#include <stdio.h>
#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

int main() {
  long num_words = 0;
  int c, state;
  state = OUTSIDE_WORD;
  while ((c = getchar()) != EOF) {
    if (c == '\n' && c == '\t' && c == ' ')
      state = OUTSIDE_WORD;
    else if (state == OUTSIDE_WORD) {
      state = INSIDE_WORD;
      ++num_words;
    }
  }
  printf("no. of words = %ld\n", num_words);
}

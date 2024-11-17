
// display words and their lengths using simple histogram
#include <stdio.h>

int main() {
  int c, current_word_length = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      if (current_word_length > 0) {
        printf("| ");
        for (int i = 0; i < current_word_length; i++)
          printf("#");
        printf(" %d", current_word_length);
        current_word_length = 0;
      }
      printf("\n");
    } else {
      current_word_length++;
      printf("%c", c);
    }
  }
}

#include <stdio.h>

// gets a new word from the user
int get_word(char *word, int max_len) {
  // handle invalid arguments
  if (word == NULL || max_len <= 0)
    return 0;
  char c;
  int len = 0;
  printf("enter a word:\n");
  while (len < max_len - 1 && (c = getchar()) != EOF && c != '\n')
    *word++ = c;
  // add null terminator and increment value of len
  // only if a valid word was provided
  if (len > 0)
    word[len] = '\0';
  return len;
}
int main() {
  char word[100];
  int len = get_word(word, 100);
  printf("word: %s and length: %d\n", word, len);
}

#include <stdio.h>

// gets a new word from the user
int get_word(char *word) {
  char c;
  char *original_word_ptr = word;
  printf("enter a word:\n");
  while ((c = getchar()) != EOF && c != '\n')
    *word++ = c;
  // add null terminator at the end of word to make it a valid string
  *word = '\0';
  return word - original_word_ptr;
}
int main() {
  char *word;
  int len = get_word(word);
  printf("\nword: %s length: %d\n", word, len);
}

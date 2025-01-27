#include <stdio.h>

// gets a new word from the user
int get_word(char word[], int max_len) {
  char c;
  int len = 0;
  printf("enter a word:\n");
  while (len < max_len - 1 && (word[len] = c = getchar()) != EOF && c != '\n')
    len++;
  // add null terminator at the end of word to make it a valid string
  word[len] = '\0';
  return len;
}
int main() {
  char word[100];
  int len = get_word(word, 100);
  printf("word: %s length: %d\n", word, len);
}

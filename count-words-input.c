// This program counts the number of occurences of the words given from  the
// input its uses binary search instead of linear search as it grows
// quadratically with input i.e its time complexity is O(n^2)
// For each word in input, the tree is traversed and compared with root node
// If the input word is same as word of root node its count is incremented
// If the word of root node is smaller then we go to left node
// otherwise we go to right node and countinue this process.
// We need to add new node if no node has same word as in input.
// This process helps to keep track of input word count as well in building the
// tree itself. The left node is always lexicographically smaller and right node
// is greater than root node

#include <string.h>
#define MAX_WORD 100
#include <stdio.h>

// node of a binary tree data structure
// it holds word and its frequency count
// it also points to the nodes on the either side
struct Node {
  char word[MAX_WORD];
  int count;
  struct Node *left;
  struct Node *Right;
};

int get_word(char *word, int max_len) {
  // handle invalid word and max_len arguments
  if (word == NULL || max_len <= 0)
    return 0;
  char c;
  int len = 0;
  printf("enter a word:\n");
  while (len < max_len - 1 && (c = getchar()) != EOF && c != '\n')
    word[len++] = c;
  // add null terminator and increment value of len
  // only if word was provided
  if (len > 0)
    word[len] = '\0';
  return len;
}

int main() {
  struct Node *nodeptr;
  char word[MAX_WORD];
  while (get_word(word, MAX_WORD) > 0) {
    // TODO: complete logic to traverse the tree and sorting it while adding new
    // node whenever necessary
  }
}

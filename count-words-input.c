// This program counts the number of occurences of the words given from the
// input. It uses binary tree data structure to store word and its count. It
// also uses binary search instead of linear search as latter one grows
// quadratically with input i.e its time complexity is O(n^2).For each word in
// input, the tree is traversed and compared with root node. If the input word
// is same as word of root node its count is incremented. else if the word of
// root node is smaller then left node is traversed otherwise we go to right
// node. Similarly,a new node is added if no node has same word as in input.This
// process is repeated until word is provided from the input.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node of a binary tree data structure
// it holds word and its frequency count
// it also points to the nodes on the either side
struct Node {
  char *word;
  int count;
  struct Node *left;
  struct Node *right;
};

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

// allocates memory for the new node
struct Node *alloc_node() { return (struct Node *)malloc(sizeof(struct Node)); }

// creates a copy of given word pointer and returns its pointer
char *copy_word(char *word) {
  char *p;
  // allocate memory for the word to be copied and extra null character
  p = (char *)malloc(strlen(word) + 1);
  if (p != NULL) {
    // copy given word to new word if allocation was successful
    strcpy(p, word);
  }
  return p;
}

// traverses through binary tree and does one of the following action for each
// node: a) Initialize a new node with current word if there is no node b)
// traverse on left side of the node if the current word is smaller than word on
// the current node c) otherwise, traverse on right side of the node
// It returns the pointer to the node which contains the given word
struct Node *traverse_tree(struct Node *nodeptr, char *word) {
  int cond;
  if (nodeptr == NULL) {
    // create a new node if there is no node pointed by nodeptr
    nodeptr = alloc_node();
    nodeptr->word = copy_word(word);
    nodeptr->count = 1;
    nodeptr->left = NULL;
    nodeptr->right = NULL;
  } else if ((cond = strcmp(word, nodeptr->word)) == 0) {
    // increment word counter if node with same word is found
    nodeptr->count++;
  } else if (cond < 0) {
    // traverse left node given word is smaller than word on the current node
    traverse_tree(nodeptr->left, word);
  } else if (cond > 0) {
    // traverse right node given word is smaller than word on the current node
    traverse_tree(nodeptr->right, word);
  } else {
    printf("error: unable to proceed!");
  }
  return nodeptr;
}

// display the given node and other nodes it contain
// it recursively shows node on left and right side of the current node
void show_node_tree(struct Node *node) {
  if (node == NULL)
    return;
  show_node_tree(node->left);
  printf("word: %s count:%d\n", node->word, node->count);
  show_node_tree(node->right);
}

int main() {
  struct Node *current_node;
  char *word;
  while (get_word(word) > 0) {
    traverse_tree(current_node, word);
  }
}

// Program to reverse a string
#include <stdio.h>

// maximum length of input line
#define MAX_LINE_LENGTH 100

int get_line(char line[]) {
  int c, i;
  // add character to line string if its valid
  for (i = 0; i < MAX_LINE_LENGTH - 1 && (c = getchar()) != '\n' && c != EOF;
       i++)
    line[i] = c;
  // add new line character encountered at the end of the line
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  // put null character at the string to make it valid string
  line[i] = '\0';

  return i;
}

// swap two characters in a string
void swap(char *a, char *b) {
  char temp = *a; // store the value of 'a' temporarily
  *a = *b;        // assign the value of 'b' to 'a'
  *b = temp;      // assign the stored value to 'b'
}

// calculate the length of a string
int string_length(char s[]) {
  int i = 0;
  while (s[i] != '\0') { // loop until the end of the string
    i++;
  }
  return i; // return the total length of the string
}

// reverse the characters in a string
void reverse_string(char s[]) {
  int len = string_length(s);
  int front = 0;      // front index (starting from the beginning)
  int back = len - 1; // back index (starting from the end)

  // swap characters until the front index meets the back index
  while (front < back) {
    swap(&s[front], &s[back]); // Swap characters at 'front' and 'back' indices
    front++;                   // Move the front index forward
    back--;                    // Move the back index backward
  }
}

int main() {
  char s[MAX_LINE_LENGTH];
  printf("enter a string\n");
  int len = get_line(s);
  printf("given string: %s\n", s);
  reverse_string(s);
  printf("reversed string: %s\n", s);
  return 0; // Exit the program
}

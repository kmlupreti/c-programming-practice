#include <stdio.h>
// maximum limit of input line
#define MAX_LINE_LIMIT 100
// reads character and puts in line[] and returns its length
int get_line(char line[]);
// returns length of the line
int len(char line[]);
// copy string (or array) of characters
void copy(char from[], char to[]);

int main() {
  char current_line[MAX_LINE_LIMIT];
  char longest_line_found[MAX_LINE_LIMIT];
  int max_length_found = 0;
  int current_line_length;

  while ((current_line_length = get_line(current_line)) > 0) {
    if (current_line_length > max_length_found) {
      max_length_found = current_line_length;
      copy(current_line, longest_line_found);
    }
  }

  // print if any valid longest line is found
  if (max_length_found > 0) {
    printf("longest line is given below:\n");
    printf("%s", longest_line_found);
  } else
    printf("no longest line found");
  return 0;
}

int get_line(char line[]) {
  int c, i;
  // add character to line string if its valid
  for (i = 0; i < MAX_LINE_LIMIT - 1 && (c = getchar()) != '\n' && c != EOF;
       i++)
    line[i] = c;
  // add new line encountered at the end of the line
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  // put null character at the string to make it valid string
  line[i] = '\0';

  return i;
}

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}

#include <stdio.h>
#define MAX_LINE_LENGTH 100

int get_line(char line[]);
void push_stack(float item);
float pop_stack();
float stack_top();

extern float stack[100];

int main() {
  char input[MAX_LINE_LENGTH];
  get_line(input);

  int i =0;
  while(input[i] != '\0'){
    switch(input[i])
    case '+':
      push_stack(pop_stack() + pop_stack()); 
    
  }
  return 0;
}

int get_line(char line[]) {
  int c, i;
  // add character to line string if its valid
  for (i = 0; i < MAX_LINE_LENGTH - 1 && (c = getchar()) != '\n' && c != EOF;
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

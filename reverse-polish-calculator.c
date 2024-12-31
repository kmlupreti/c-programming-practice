#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// maximum length of expression
#define MAXLEN 150
// maximum number of operands
#define MAXOP 100
// character flag that signifies that a valid number is found
#define NUMBER_FOUND '0'

// stack to hold operands for calculation
char stack[MAXOP];
// next free position in the stack
int next_free_pos = 0;

// it returns operator or letter '0' if its an operand
// the passed string is populated with and operand if its found
char getop(char[]);
// get next buffered character
char getch();
// unget character i.e return to the state before reading the previous character
void ungetch();
// push operand to the stack
void push(double);
// pop an operand from the stack
double pop();

int main() {
  char c;
  char s[MAXOP];
  double op2; // second operand
  while ((c = getop(s)) != EOF) {
    switch (c) {
    case 'o':
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      if (op2 == 0.0) {
        printf("error: cannot divide by zero!\n");
        return 1;
      }
      push(pop() / op2);
      break;
    case '\n':
      printf("result: %f", pop());
      break;
    }
  }
  return 0;
}

void push(double n) {
  if (next_free_pos < MAXOP)
    stack[next_free_pos++] = n;
  else
    printf("error: too many operands!\n");
}

double pop() {
  if (next_free_pos > 0)
    return stack[--next_free_pos];
  else {
    printf("error: too few operands");
    return 0.0;
  }
}

char getop(char n[]) {
  char c;
  int i;
  // repeatedly take input and skip if its a whitespace or tab.
  // string n gets the final whitespace or tab character
  while ((n[0] = c = getch()) && c == ' ' || c == '\t')
    ;
  n[1] = '\0';
  if (!isdigit(c) && c != '.')
    // return if there is not valid character
    return c;
  // collect the digits before decimal
  if (isdigit(c)) {
    while (isdigit(c = n[i++] = getch()))
      ;
  }
  // collect the digits after the decimal
  if (c == '.') {
    while (isdigit(c = n[++i] = getch()))
      ;
  }
  n[i] = '\0';
  if (c != EOF)
    ungetch();
  return NUMBER_FOUND;
}

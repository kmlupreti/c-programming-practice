#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// maximum length of expression
#define MAXLEN 150
// maximum number of operands
#define MAXOP 100
// character flag that signifies that a valid number is found
#define NUMBER_FOUND '0'
// maxmimum length of character in a buffer
#define BUF_LEN 32

// stack to hold operands for calculation
double stack[MAXOP];
// next free position in the stack
int sp = 0;
// buffer to store characters for ungetch operation
char buf[BUF_LEN];
// index to next free position on character buffer
int bp = 0;

// it returns operator or letter '0' if its an operand
// the passed string is populated with and operand if its found
char getop(char[]);
// get next buffered character
char getch();
// put back the character back to input buffer
void ungetch(char);
// push operand to the stack
void push(double);
// pop an operand from the stack
double pop();

int main() {
  char c;
  char s[MAXLEN];
  double op2; // second operand
  while ((c = getop(s)) != EOF) {
    switch (c) {
    case '0':
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
      }
      push(pop() / op2);
      break;
    case '\n':
      printf("%.4f\n", pop());
      break;
    default:
      printf("error: unknown operation '%s'\n", s);
    }
  }
  return 0;
}

void push(double n) {
  if (sp < MAXOP)
    stack[sp++] = n;
  else
    printf("error: too many operands!\n");
}

double pop() {
  if (sp > 0)
    return stack[--sp];
  else {
    printf("error: too few operands\n");
    return 0.0;
  }
}

char getop(char n[]) {
  char c;
  int i = 0;
  // skip whitespaces and tabs
  while ((c = getch()) == ' ' || c == '\t')
    ;
  n[0] = c;
  n[1] = '\0';
  // return the character if its not a number
  if (!isdigit(c) && c != '.')
    return c;
  // collect the digits before decimal point
  if (isdigit(c)) {
    n[i++] = c;
    while (isdigit(c = getch()))
      n[i++] = c;
  }
  // collect the digits after the decimal point
  if (c == '.') {
    n[i] = '.';
    while (isdigit(c = getch()))
      n[i++] = c;
  }
  n[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER_FOUND;
}

char getch() {
  if (bp > 0)
    return buf[--bp];
  else
    return getchar();
}

void ungetch(char c) {
  if (bp < BUF_LEN)
    buf[bp++] = c;
  else
    printf("error: character buffer full!\n");
}

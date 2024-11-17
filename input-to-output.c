#include <stdio.h>

int main() {
  int c;
  c = getchar(); // read a character from stdin
  while (c != EOF) { // EOF marks end of input
    putchar(c); // print a character to stdout
    c = getchar(); // get another character
  }
}

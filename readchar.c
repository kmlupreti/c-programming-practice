// This program contains simple implementation of function similar to getchar()
// function using read and write unix syscalls It contains buffer to hold
// chars. It is initially empty. When the user reads first time,chars are
// read from stdin to fill the buffer and then whenever user requests a char it
// is retreived from the buffer until it is empty again. A buffer pointer is
// used to point to the char in the buffer to be retreived which is incremented
// after retrieval of each char from the buffer.
#include <stdio.h>
#define BUFSIZE 8192
#include <unistd.h>
int readchar() {
  static char buf[BUFSIZE]; // buffer to store chars read from stdin
  static char *bufp = buf;  // pointer to char in buffer
  static int n = 0;         // no. of chars in buffer

  // if buffer is empty then read the chars from stdin and fill the
  // buffer and point the buffer pointer to start of the buffer
  if (n == 0) {
    n = read(0, buf, BUFSIZE);
    bufp = buf;
  }
  // check if there is any char in buffer and then decrement n
  if (n-- > 0)
    // return the chracter pointed by buffer pointer and increment it to point
    // to next char
    return (unsigned char)*bufp++;
  else
    return -1; // return EOF if read syscall returned error(-1) or EOF(0)
}
int main() {
  char c;
  while ((c = readchar()) != EOF) {
    putchar(c);
  }
  return 0;
}

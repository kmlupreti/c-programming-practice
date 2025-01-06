#include <stdio.h>

// argc is no. of command line arguments and argv is array consisting those
// arguments. The first argument argv[0] is program name so argc is 1 more than
// no. of arguments supplied
int main(int argc, char *argv[]) {
  // the condition helps in both situations: checking if arguments is supplied
  // and loop is run within array bound.
  while (--argc > 0) {
    // pointer is increment first as it points to argv[0] but first argument is
    // argv[1]. If the argument is not last then space is added at its end.
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
  }
  return 0;
}

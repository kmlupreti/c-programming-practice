#include <stdio.h>

// argc is no. of command line arguments and argv is array consisting those
// arguments. The first argument argv[0] is program name so argc is 1 more than
// no. of arguments supplied
int main(int argc, char *argv[]) {
  // we need to check if there is more than one argument
  if (argc > 1) {
    int i = 1;
    while (i < argc) {
      // add space at the end of arguments before last one
      printf("%s", argv[i]);
      if (i < argc - 1)
        printf(" ");
      i++;
    }
  } else {
    printf("\n");
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  char c;
  if (argc == 1) {
    while ((c = getchar()) != EOF)
      putchar(c);
  } else {
    FILE *fp;
    for (int i = 1; i < argc; i++) {
      fp = fopen(argv[i], "r");
      if (fp == NULL) {
        fprintf(stderr, "error opening file: %s", argv[i]);
        exit(1);
      }
      while ((c = getc(fp)) != EOF)
        putchar(c);
      fclose(fp);
    }
  }
  return 0;
}

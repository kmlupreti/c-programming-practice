#include <stdio.h>
int main(int argc, char *argv[]) {
  char c;
  if (argc == 1) {
    while ((c = getchar()) != EOF)
      putchar(c);
  } else {
    FILE *fp;
    for (int i = 1; i < argc; i++) {
      fp = fopen(argv[i], "r");
      while ((c = getc(fp)) != EOF)
        putchar(c);
      fclose(fp);
    }
  }
  return 0;
}

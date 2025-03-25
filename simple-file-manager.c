#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void create_file() {
  char *file_name;
  char *text;
  printf("enter filename to create:");
  scanf("%s", file_name);
  int fd = creat(file_name, 0755);
  if (fd < 0) {
    printf("error: unable to create file %s", file_name);
    return;
  }
  printf("enter text to add to file below:\n");
  scanf("%s", text);
  int nbytes_written = write(fd, text, sizeof(text));

  if (nbytes_written < 0) {
    printf("error: unable to write text to file %s", file_name);
    return;
  }
  printf("%d bytes written to file %s", nbytes_written, file_name);
  return;
}

void read_file() {}
void update_file() {}
void delete_file() {}

int main(int argc, char **argv) {
  char opt;
  while (1) {
    printf("\n--------------------------------------------\n");
    printf("what file operation do you want to do?\n"
           "(c)create\n(r)read\n(u)update\n(d)delete\n(q)quit\n");
    char opt = getchar();
    switch (opt) {
    case 'c':
      create_file();
      break;
    case 'r':
      read_file();
      break;
    case 'u':
      update_file();
      break;
    case 'd':
      delete_file();
      break;
    case 'q':
      exit(0);
      break;
    default:
      printf("invalid option!\n");
    }
  }
  return 0;
}

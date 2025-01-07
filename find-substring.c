#include <stdio.h>

// maximum length of input line
#define MAX_LINE_LENGTH 100

// reads character and puts in line[] and returns its length
int get_line(char line[]);

// returns index of substring `substr` in string `str`, returns -1 if not found
int find_substr(char str[], char substr[]);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("error:invalid usage!\n");
    printf("usage: find_substr <substring>\n");
    return 1;
  } else {
    char line[MAX_LINE_LENGTH];
    printf("enter the lines to search:\n");
    while (get_line(line) > 0) {
      int found_index = find_substr(line, argv[1]);
      if (found_index >= 0)
        printf("substring `%s` found in index %d\n", argv[1], found_index);
    }
  }
  return 0;
}

int find_substr(char str[], char substr[]) {
  int i, j, k;
  // iterate over each character of a string
  for (i = 0; str[i] != '\0'; i++) {
    // check if string matches first character of a substring
    if (str[i] == substr[0]) {
      k = i;
      // check if string contains whole substring
      for (j = 0; substr[j] != '\0' && substr[j] == str[k]; j++, k++)
        ;
      // if match was found then substring would have been iterated completely
      // thus value of j will be a null character
      if (substr[j] == '\0')
        return i;
    }
  }
  return -1;
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
  // put null character at the end of line to make it valid string
  line[i] = '\0';

  return i;
}

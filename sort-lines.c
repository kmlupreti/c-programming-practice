#include <stdio.h>
#include <string.h>

// maximum number of lines
#define MAXLINES 5000
// maximum length of a line
#define MAX_LINE_LENGTH 100

// array of line pointers
char *lineptr[MAXLINES];

// reads character and puts in line[] and returns its length
int get_line(char line[]);

// reads lines into lineptr
int readlines(char *lineptr[]);

// swap the values pointed by two pointers of a string
void swap(char *lineptr[], int x, int y);

// sorts the lines lexicographically using quick sort
void sort_lines(char *lineptr[], int first, int last);

// prints the lines
void print_lines(char *lineptr[], int nlines);

int main() {
  int nlines;
  if ((nlines = readlines(lineptr)) >= 0) {
    sort_lines(lineptr, 0, nlines - 1);
    print_lines(lineptr, nlines);
  } else {
    printf("error: too big to sort!");
  }
  return 0;
}

// reads character and puts in line[] and returns its length
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

int readlines(char *lineptr[]) {
  int nlines, len;
  // this globally scoped 2d array contains array of lines
  static char lines[MAXLINES][MAX_LINE_LENGTH];
  char *p;
  nlines = 0;
  char temp_line[MAX_LINE_LENGTH];
  while ((len = get_line(temp_line)) > 0) {
    if (nlines >= MAXLINES) {
      printf("err: nlines= %d", nlines);
      return -1;
    } else {
      // remove newline by replacing it with null character
      if (temp_line[len - 1] == '\n')
        temp_line[len - 1] = '\0';
      // copy temporay line into static array
      strcpy(lines[nlines], temp_line);
      // store the given line into lineptr[]
      lineptr[nlines] = lines[nlines];
      nlines++;
    }
  }
  return nlines;
}

void print_lines(char *lineptr[], int nlines) {
  printf("\nlines sorted lexicographically:\n");
  for (int i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

void swap(char *lineptr[], int x, int y) {
  char *temp;
  *temp = *lineptr[x];
  *lineptr[x] = *lineptr[y];
  *lineptr[y] = *temp;
}

int partition(char *lineptr[], int first, int last) {
  // set last element as pivot
  char *p = lineptr[last];
  // position of elements smaller than pivot
  int l = first - 1;

  for (int i = first; i < last; i++) {
    if (strcmp(lineptr[i], p) < 0) {
      l++;
      swap(lineptr, i, l);
    }
  }
  swap(lineptr, last, l + 1);
  return l + 1;
}

void sort_lines(char *lineptr[], int left, int right) {
  // do nothing if there is less than two elements
  if (strcmp(lineptr[left], lineptr[right]) > 0) {

    int p = partition(lineptr, left, right);
    sort_lines(lineptr, left, p - 1);
    sort_lines(lineptr, p + 1, right);
  }
}

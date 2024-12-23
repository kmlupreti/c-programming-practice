#include <stdio.h>
// function to compare two strings
//  returns zero if they are exactly same otherwise the difference between given
//  two strings. The returned value is 0 is they are same, < 0 if s1<s2 or >0 if
//  s1>s2. The difference is calculated from the character position from which
//  they differ.
int string_compare(char s1[], char s2[]) {
  int i = 0;
  for (; s1[i] == s2[i]; i++) {
    if (s1[i] == '\0')
      return 0;
  }
  return s1[i] - s2[i];
}
int main() {
  char n1[] = "Ram bahadur";
  char n2[] = "Ram bhakta";
  printf("%d\n", string_compare(n1, n2));
}

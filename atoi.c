// program to convert string to integer
#include <stdio.h>
int atoi(char s[]) {
  int n = 0;

  for (int i = 0; s[i] > '0' && s[i] <= '9'; i++) {
    n = n * 10 + (s[i] - '0');
  }
  return n;
}

int main(){
  char nums[] = "25";
  printf("%d",atoi(nums));
  return 0;
}

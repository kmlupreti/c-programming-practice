// demo of function by writing simple power function
#include <stdio.h>
// declare function
int power(int x, int y);

int main() {
  printf("square of 3 is %d", power(3, 2));
  return 0;
}
// actual function definition
int power(int m, int n) {
  int p = 1;
  for (int i = 0; i < n; i++)
    p *= m;
  return p;
}

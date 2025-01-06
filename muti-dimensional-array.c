#include <stdio.h>
// Here the passed argument is pointer to first row which is an array of
// length 3. *a is wrapped around () as it has lower precedence than []
void print_array(int (*a)[3]) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      printf("position: (%d,%d) value: %d\n", i, j, a[i][j]);
}
int main() {
  int a[4][3] = {{1, 2, 3}, {5, 4, 3}, {1, 2, 8}, {4, 1, 6}};
  print_array(a);
  return 0;
}

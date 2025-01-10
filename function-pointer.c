#include <stdio.h>
void show_int(int x) { printf("%d\n", x); }
void show(int x, void (*f)(int)) { (*f)(x); }
int main() {
  int x = 5;
  show(5, show_int);
}

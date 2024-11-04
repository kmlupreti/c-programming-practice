// program showing various data types and their sizes
#include <stdio.h>
#include<math.h>

int main() {

  // character
  char c = 'k';
  printf("character\nvalue: %c size: %lu bit\n\n", c, sizeof(char) * 8);

  // integer
  int i = 55;
  printf("integer\nvalue: %d size: %lu bit\n\n", i, sizeof(int) * 8);

  // unsigned integer
  unsigned int u = 100;
  printf("unsigned integer\nvalue: %u size: %lu bit\n\n", u,
         sizeof(unsigned int) * 8);

  // short integer
  short int s = 100;
  printf("short integer\nvalue: %d size: %lu bit\n\n", s,
         sizeof(short int) * 8);

  // long integer
  long int l = 100;
  printf("long integer\nvalue: %ld size: %lu bit\n\n", l, sizeof(long int) * 8);

  // single percision float
    printf("single precision float\nvalue: %.7f size: %lu bit\n\n", M_PI,
         sizeof(float) * 8);

  // double percision float
  printf("double precision float\nvalue: %.15f size: %lu bit\n\n", M_PI,
         sizeof(double) * 8);

  return 0;
}

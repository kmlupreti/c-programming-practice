// different version of program showing fahrenheit to celsius table
// It used for loop and symbolic constants
#include <stdio.h>
#define INITIAL 0
#define FINAL 300
#define STEP 20

int main() {
  printf("°F\t°C\n");
  for (float fahrenheit = INITIAL; fahrenheit <= FINAL; fahrenheit += STEP)
    printf("%.2f\t%.2f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}

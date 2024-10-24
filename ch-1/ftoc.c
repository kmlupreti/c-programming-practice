// Fahrenheit to celsius table
#include <stdio.h>

int main() {
  float fahrenheit, celsius; // temp in °F and °C
  int initial, final, step;
  initial = 0; // starting temperature
  final = 300; // final temperature
  step = 20;   // step between temperatures

  fahrenheit = initial; // set inital temperature
  printf("°F\t°C\n");
  while (fahrenheit <= final) {
    celsius =
        (5.0 / 9.0) * (fahrenheit - 32); // convert fahrenheit into celsius
    printf("%.2f\t%.2f\n", fahrenheit, celsius); // print table with two digits after decimal
    fahrenheit += step; // set next temperature
  }
}

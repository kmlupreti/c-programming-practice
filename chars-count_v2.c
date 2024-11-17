// count characters using for loop
#include <stdio.h>

int main() {
  double num_chars; // we can also use double to store number of characters
  for (int c = getchar(); c != EOF; ++num_chars)
    ; // null statement
  printf("no of characters: %.0f",
         num_chars); // show no of characters without decimal point
}

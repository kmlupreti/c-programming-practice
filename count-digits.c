// count number of digits
#include <stdio.h>

int main() {
  int c;
  // array of length 10 for digits 0..9
  int num_digit[10];

  // initialize count of each digits to 0
  for (int i = 0; i < 10; i++)
    num_digit[i] = 0;

  while ((c = getchar()) != EOF) {
    // check if character represents valid digits
    // note that single quote is used because we want to
    // compare with ASCII value of digits instead of integer value
    if (c >= '0' && c <= '9')
      // increment the counter of respective digit
      // we need to convert char c to int so we have
      // used expression c-'0' which does that
      ++num_digit[c - '0'];
  }
  // print number of each digits
  for (int i = 0; i < 10; i++)
    printf("%d = %d\n", i, num_digit[i]);
}

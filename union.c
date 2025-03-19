// union allows us to have a single variable that can hold values of different
// types but it can hold only one type at a time
#include <stdio.h>
union value {
  int ival;
  char *sval;
  float fval;
};

int main() {
  union value v;
  v.ival = 10;
  printf("integer value is %d", v.ival);
  v.sval = "hello";
  printf("string value is %s", v.sval);
  v.fval = 199.88;
  printf("float value is %f", v.fval);
}

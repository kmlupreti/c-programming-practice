// program showing  various types of operators
int main() {
  // aritmetic operators
  int sum = 5 + 2;
  int diff = 5 - 2;
  int product = 5 * 2;
  int modulo = 5 % 2;

  // relational operators
  int a = 5;
  int b = 3;
  int a_less_than_b = a < b;
  int a_greater_than_b = a > b;
  int a_less_than_or_equals_b = a <= b;
  int a_greater_than_or_equals_b = a >= b;
  int a_equals_b = a == 0;
  int a_not_equals_b = a != 0;

  // logical operators
  int x = 1;
  int y = 0;
  int x_and_y = x && y;
  int x_or_y = x || y;

  // bitwise operators
  int m = 0b101;
  int n = 0b110;
  int m_and_n = m & n;
  int m_or_n = m | n;
  int m_xor_n = m ^ n;
  int m_complement = ~m;
  int left_shift_m = m << 2;
  int right_shift_m = m >> 2;

  return 0;
}

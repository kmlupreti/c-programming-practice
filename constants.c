int main() {

  // character ( inside single quote)
  char a = 'x';

  // integer
  int i = 123;
  int j = 0x15B; // hexadecimal ( 0x prefix)
  int k = 043;   // octal (leading with 0)

  // long integer(can be suffixed with l or L)
  long int b = 13413462346L;

  // unsigned integer (can be suffixed with U)
  unsigned int n = 102U;

  // some escape sequences
  char BACKSPACE = '\b';
  char CARRIAGE_RETURN = '\r';
  char VERTICAL_TAB = '\v';

  // abitrary byte-sized bit patterns
  char VTAB = '\013'; // pattern 1: \ooo where o is a octal digit
  char BELL = '\x7';  // pattern 2: \xhh where h is a hexadecimal digit

  // enumeration constant
  // value begins at 0 unless specified and continue progression as 0,1,2,3..
  // if any entry has value unspecified then it gets next value of the
  // progression from last unspecified value
  enum state { LOW, HIGH }; // former gets value 0 and latter gets 1
  enum DAY { SUN = 1, MON, TUE, WED, THR, FRI, SAT }; // MON gets 2 and so on
}

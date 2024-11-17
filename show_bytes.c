#include <stdio.h>
typedef char *byte_ptr;
void show_bytes(byte_ptr b, size_t len) {
  for (int i = 0; i < len; i++)
    printf("%x", b[i]);
}
int main() { return 0; }

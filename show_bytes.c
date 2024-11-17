#include <stdio.h>
typedef char *byte_ptr;
void show_bytes(byte_ptr b, size_t len) {
  for (int i = 0; i < len; i++)
    printf("%x\t", b[i]);
}
int main() {
  int x = 0x12345678;
  show_bytes((byte_ptr)&x, sizeof(int));
  printf("\n");
  return 0;
}

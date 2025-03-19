#include <stdlib.h>
#include <string.h>
char *string_duplicate(char *src) {
  char *dest;
  dest = (char *)malloc(strlen(src) + 1);
  if (dest != NULL)
    strcpy(src, dest);
  return dest;
}

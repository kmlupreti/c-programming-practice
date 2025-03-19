#include <string.h>
typedef char *String;
typedef int Length;

struct response {
  String message;
  int code;
};

typedef struct response Response;

int main() {
  String text = "Hello world";
  Length txt_len = strlen(text);
  String users[] = {"kml11", "user33"};
  Response r = {"success", 7};
  return 0;
}

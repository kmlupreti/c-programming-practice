#include <stdio.h>

struct Point {
  int x;
  int y;
};

struct Point new_point(int x, int y) {
  struct Point p = {x, y};
  return p;
}

struct Point mid_point(struct Point p1, struct Point p2) {
  struct Point m = new_point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
  return m;
}
int main() {
  struct Point p1, p2, m;
  printf("enter x1 and y1\n");
  scanf("%d%d", &p1.x, &p1.y);
  printf("enter x2 and y2\n");
  scanf("%d%d", &p2.x, &p2.y);
  m = mid_point(p1, p2);
  printf("mid point is (%d,%d)", m.x, m.y);
  return 0;
}

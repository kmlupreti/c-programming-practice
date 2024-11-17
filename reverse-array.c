#include <stdio.h>
void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}
void reverse_array(int a[], int count) {
  int first, last;
  for (first = 0, last = count - 1; first < last; first++, last--)
    inplace_swap(&a[first], &a[last]);
}
int main() {
  int nums[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    printf("%d", nums[i]);
  printf("\n");

  reverse_array(nums, 5);
  for (int i = 0; i < 5; i++)
    printf("%d", nums[i]);
  printf("\n");

  return 0;
}

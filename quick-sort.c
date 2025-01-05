#include <stdio.h>

// swap array elements at index i and j
void swap(int nums[], int i, int j);
// sort the given array
void quicksort(int nums[], int first, int last);
// partition the array using lomuto partition method and return its index
int partition(int nums[], int first, int last);

int main() {
  int i;
  int n = 5;
  int nums[n];
  for (i = 0; i < n; i++) {
    printf("enter a number: \n");
    scanf("%d", &nums[i]);
  }
  quicksort(nums, 0, n - 1);
  printf("sort number list:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", nums[i]);
  }
}

int partition(int nums[], int first, int last) {
  // set last element as pivot
  int p = nums[last];
  // position of elements smaller than pivot
  int l = first - 1;

  for (int i = first; i < last; i++) {
    if (nums[i] < p) {
      l++;
      swap(nums, i, l);
    }
  }
  swap(nums, last, l + 1);
  return l + 1;
}
void quicksort(int nums[], int first, int last) {
  if (first < last) {
    int p = partition(nums, first, last);
    quicksort(nums, first, p - 1);
    quicksort(nums, p + 1, last);
  }
}

void swap(int nums[], int i, int j) {
  int t;
  t = nums[i];
  nums[i] = nums[j];
  nums[j] = t;
}

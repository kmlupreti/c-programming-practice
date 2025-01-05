#include <stdio.h>

// swap array elements at index i and j
void swap(int nums[], int i, int j);
// sort the given array
void quicksort(int nums[], int first, int last);

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

void quicksort(int nums[], int first, int last) {
  if (first < last) {
    int mid = (first + last) / 2;
    // use middle element for partitioning
    int p = mid;
    // swap between elements at first index and middle partition index
    swap(nums, first, p);
    // test mid-value with other values in the array.Here mid-value is currently
    // in first index so iteration starts from first+1 index
    for (int i = first + 1; i <= last; i++) {
      if (nums[i] < nums[mid])
        // if value at current index is smaller than mid-value then
        // swap values between those indices.It keeps the values less than
        // mid-value on left indices of mid-value index
        swap(nums, ++mid, i);
    }
    // restore index of first and middle which were swapped previously
    swap(nums, first, mid);
    // recursively sort left and right subarray consisting of values less than
    // value at partition index i.e mid value in this case
    quicksort(nums, first, mid - 1);
    quicksort(nums, mid + 1, last);
  }
}

void swap(int nums[], int i, int j) {
  int t;
  t = nums[i];
  nums[i] = nums[j];
  nums[j] = t;
}

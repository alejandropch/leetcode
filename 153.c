#include <limits.h>
#include <stdio.h>
int findMin(int* nums, int numsSize) {
  printf("agaa: %d\n", 1/2);
  int l = 0, r = numsSize - 1, mid;
  while (l < r) {
    mid = l + (r - l)/2;
    if(nums[mid] > nums[r])
      l = mid + 1;
    if(nums[mid] < nums[r])
      r = mid;
  }
  mid = l + (r - l)/2;
  return nums[mid];
}

int main(){

  int a[] = {3,1,2};
  int r = findMin(a, sizeof(a)/ sizeof(int));
  printf("res: %d\n", r);

  return 0;
}

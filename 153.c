#include <limits.h>
#include <stdio.h>
int findMin(int* nums, int numsSize) {

  int l= 0, r = numsSize - 1, mid;
  while(l <= r)
  {
    mid = l + (r - l)/2;
    if (nums[mid] > nums[r])
      l = mid + 1;
    else
      r = mid;
  }
  return nums[l];
}

int main(){

  int a[] = {3,1,2};
  int r = findMin(a, sizeof(a)/ sizeof(int));
  printf("res: %d\n", r);

  return 0;
}

#include <stdio.h>
int search(int* nums, int numsSize, int target) {
  int l = 0, r = numsSize - 1, mid = numsSize/2; 
  while ( l <= r ) {
    if(target == nums[mid])
      return mid;
    if(target < nums[mid])
      r = mid - 1;
    if(target > nums[mid])
      l = mid + 1;

    mid = l + (r - l) / 2;
  } 
  return -1;
}

int main(){
  int nums[] = {-1,0,3,5,9,12};
  int r = search(nums, sizeof(nums)/sizeof(int), 9);
  printf("res: %d\n", r);
  return 0;
  
}

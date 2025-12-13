#include <limits.h>
int findMin(int* nums, int numsSize) {
   int l= 0, r = numsSize - 1, mid, min = INT_MIN;
   while (l < r) {
     mid = l + (r - l)/2;
     if(nums[mid] )
   
   }

}
int main(){
  int a[] = {3,4,5,1,2};
  int r = findMin(a, sizeof(a)/sizeof(int));
  printf("res: %d", r);


return 0}

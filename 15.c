#include <stdlib.h>
#include <stdio.h>
int comp(void const *a, void const *b){
  return *(int*)a - *(int*)b;
} 
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int),  comp);
  int a, left = 0, right = numsSize - 1, i, dup, target;
  int **res = malloc(sizeof(int) * numsSize);
  for (i = 0; i < numsSize; i++) {
    a = i;
    target = 0 - nums[a];
    while (1) {
      if (nums[left] + nums[right] == target){
        printf("[ %d, %d, %d ]\n", nums[a], nums[left],nums[right]);
        break;
      }
      if (nums[left] == nums[a] || nums[left] + nums[right]< target){
        left++;
      }
      if (nums[right] == nums[a] || nums[right] + nums[left]> target){
        right--;
      }
    }
  }
  return res;
}

int main(){

  int nums[]={-1,0,1,2,-1,-4} ;
  int numsSize = sizeof(nums)/sizeof(int);
  int *rs;
  int **rsc;
  threeSum(nums, numsSize, rs, rsc);


  return 0;
}

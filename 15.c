#include <stdlib.h>
int comp(void const *a, void const *b){
  return *(int*)a - *(int*)b;
} 
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int),  comp);
  int  left, right,  i, three_sum, c = 0;
  int *r;
  int **res = malloc(sizeof(int*) * numsSize * (numsSize-1)/2);
  for (i = 0; i < numsSize; i++) {
    if(i > 0 && nums[i] == nums[i - 1]){
      continue;
    }
    left = i + 1; 
    right = numsSize - 1;
    while (left < right) {
      three_sum = nums[i] + nums[left] + nums[right];
      if (three_sum < 0){
        left++;
      }
      else if (three_sum > 0){
        right--;
      }
      else {
        r = malloc(3 * sizeof(int));
        r[0] = nums[i];
        r[1] = nums[left];
        r[2] = nums[right];
        res[c++] = r;
        left++;
        right--;
        while(nums[left] == nums[left-1] && left < right) left++;
        while(nums[right] == nums[right+1] && right > left) right--;

      }
    }
  }
  *returnSize=c;
  *returnColumnSizes = malloc(sizeof(int) * (c));
  for (int i = 0; i < c; i++)
      (*returnColumnSizes)[i] = 3;

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

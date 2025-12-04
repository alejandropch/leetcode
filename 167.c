#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
  int left = 0, right = numbersSize - 1;
  *returnSize = 2;
  int *res = malloc(sizeof(int) * (*returnSize));

  while(1){
     if(numbers[left] + numbers[right] == target)
     {
       res[0] = left + 1;
       res[1] = right + 1;
       return res;
     }
     if(numbers[left] + numbers[right] < target)
       left++;
     if(numbers[left] + numbers[right] > target)
       right--;
  } 
  return NULL;
}
int main(){
  int a[] = {0, 0, 3, 4}; 
  
  int target = 0;
  int n;
  int* res = twoSum(a, sizeof(a)/sizeof(int), target, &n);
  printf("res: %d, %d\n",res[0], res[1]); 

  return 0;
}

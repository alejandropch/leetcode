#include <stdio.h>

int main(){

  int nums[] = {100, 4, 200,1,3,2};

  for(int i = 0; i< sizeof(nums)/sizeof(int); i++){
    printf("%d\n", nums[i]);
  }

  return 0;
}

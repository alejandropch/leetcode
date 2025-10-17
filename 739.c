#include <stdlib.h>
#include <stdio.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
   *returnSize = temperaturesSize;
   int i=0,j=0;
   int *res = (int*)malloc(temperaturesSize * sizeof(int));
   for(; i < temperaturesSize; i++){
     for (j = i; j < temperaturesSize; j++) {
      if(temperatures[i] < temperatures[j]){
          res[i] = j - i;
          break;
      }
     }
     if(j == temperaturesSize)
      res[i] = 0;
   }
   return res;
}
int main(){
  int temperatures[] = {73,74,75,71,69,72,76,73};
  int a = sizeof(temperatures)/sizeof(int);
  int * res = dailyTemperatures(temperatures, sizeof(temperatures)/sizeof(int), &a);
  for ( int i = 0; i < a; i++)
    printf("? %d\n", res[i]);
  return 0;
}

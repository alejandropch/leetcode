#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int top;
  int *arr;
} Stack;

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
   Stack stack;
   stack.arr = calloc(temperaturesSize, sizeof(int));
   stack.top = -1;
   *returnSize = temperaturesSize;
   int i=0,j=0;
   int *res = (int*)calloc(temperaturesSize, sizeof(int));

   for(i = 0; i < temperaturesSize; i++){
     while ( stack.top >= 0 && temperatures[i] > temperatures[stack.arr[stack.top]] ){
        res[stack.arr[stack.top]] = i - stack.arr[stack.top];
        stack.top--;
     }
     stack.arr[++stack.top] = i;
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

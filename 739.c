#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
   int *res = malloc(temperaturesSize * sizeof(int));
   int *stack = malloc(temperaturesSize * sizeof(int));
   int top = -1;
   *returnSize = temperaturesSize;
   int i=0,j=0;

   for(i = 0; i < temperaturesSize; i++){
     for(; top >= 0; top--){
       if(temperatures[i] > temperatures[stack[top]]) {
         res[stack[top]] = i - stack[top];
       }else break;
     }
     stack[++top] = i;
   }
   for(j; j <= top; j++)
     res[stack[top - j]] = 0;
   free(stack);
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

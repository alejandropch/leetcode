#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b){

  return *(int*)a - *(int*)b;
}
int largestRectangleArea(int* heights, int heightsSize) {
  qsort(heights, heightsSize, sizeof(int), comp);
  int r, out = 0; 
   for( int i = 0; i < heightsSize; i++)
   {
     r = heights[i] * (heightsSize - i);
     if(r>out)
       out=r;
   }
   return out;
}
int main() {

  int a[] = {2,1,5,6,2,3};
  int b = largestRectangleArea(a, 6);
  printf("res: %d\n", b);
return 0;

}

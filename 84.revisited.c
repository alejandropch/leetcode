#include <stdio.h>
int largestRectangleArea(int* heights, int heightsSize) {
  int i, r, l, w, head = -1, ca, max = -1, h;
  int stack[heightsSize];
  for (i = 0; i < heightsSize; i++) {
    while (head != -1 && heights[stack[head]] > heights[i]) {

    }
    stack[++head] = i; 
  } 
  return max;
}
int main(){
  int a[] = {2,1,5,6,2,3};
  int r = largestRectangleArea(a, sizeof(a)/ sizeof(int));
  printf("res: %d\n", r);


return 0;}

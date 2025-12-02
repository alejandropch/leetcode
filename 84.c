#include <stdlib.h>
#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize) {
  int area, h, head=-1, i = 0, max = 0, w, currentHeight; 
  int *stack = malloc((heightsSize + 1) * sizeof(int)); // +1 so i when calculating the area of the last element, i don't get a seg fault
  for( i = 0; i <= heightsSize; i++)
  {
    if( i == heightsSize) 
      currentHeight = 0;
    else
     currentHeight=heights[i];

    while( head != -1 && currentHeight < heights[stack[head]]){ // if true, then an item(s) in the stack will be popped
      h = heights[stack[head--]]; // previous bar
      if(head == -1)
        w = i;
      else 
        w= i - stack[head] -1;
      area = h * w;
      if(h > area)
        max = h;
      else if (area > max)
       max = area;
    }
    stack[++head] = i;
    
  }
  return max;
}
int main() {
  int a[] = {2,1,5,6,3};
  int b = largestRectangleArea(a, 5);
  printf("res: %d\n", b);

  return 0;

}

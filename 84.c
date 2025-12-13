#include <stdio.h>
int largestRectangleArea(int* heights, int heightsSize) {
  int i, r, l, w, head = -1, ch, carea, max = -1, h;
  int stack[heightsSize+1];
  for (i = 0; i <= heightsSize; i++) {
    h = i ==  heightsSize? 0 : heights[i];
    while (head != -1 && heights[stack[head]] >= h) {
      ch = heights[stack[head--]];
      l = head == -1 ? -1 : stack[head];
      r = i;
      w = r - l - 1;
      carea = w * ch;
      if(carea > max)
        max = carea;
    }
    stack[++head] = i; 
  } 
  return max;
}
int main(){
  int a[] = {2,1,5,6,2,3};
  int r = largestRectangleArea(a, sizeof(a)/ sizeof(int));
  printf("res: %d\n", r);
  return 0;
}

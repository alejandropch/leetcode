#include <stdio.h>
int maxArea(int* height, int heightSize) {
  int i, l = 0, r = heightSize - 1, area, max=0;
  while (l < r) {
    area = ( height[l] < height[r] ? height[l] : height[r] ) * (r-l);
    if(area > max)
      max = area;
    if(height[l] > height[r])
      r--;
    else
      l++;
  }
  
  return max;  
    
}
int main(){
  int height[]={1,8,6,2,5,4,8,3,7};
  int a = maxArea(height, sizeof(height)/sizeof(int));
  printf("res: %d", a);
  return 0;
}

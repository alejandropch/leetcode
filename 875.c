#include <limits.h>
#include <stdio.h>
int minEatingSpeed(int* piles, int pilesSize, int h) {
  int max = INT_MIN, mid, i= 0, k = 0, res;
  for (int i = 0; i < pilesSize; i++) {
    if (piles[i] > max)
        max = piles[i];
  }
  long l = 1, r= max;
  while (l <= r) {
    mid = l + (r - l)/2;
    k = 0;
    for (i=0; i < pilesSize; i++){
      k += (piles[i] + mid - 1) / mid;
    }
    if(k <= h ){
      res = mid  ;
      r = mid - 1;
    }
    if(k > h){
      l = mid + 1;
    }
  }
  return res; 
}
int main(){

  int a[] = {3, 6, 7, 11};
  int r = minEatingSpeed(a, sizeof(a)/sizeof(int), 8);
  printf("res: %d\n", r);

  return 0;
}

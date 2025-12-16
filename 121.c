#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
 int l = 0, r = 1, profit = 0;
  while ( r < pricesSize ) {
   if(prices[r] < prices[l])
     l = r;
   if (prices[l] < prices[r] && profit < (prices[r] - prices[l])) {
     profit = prices[r] - prices[l];
   }
   r++;
 }
 return profit;
}

int main(){
  int a[] = {7,1,5,3,6,4};
  int r = maxProfit(a, sizeof(a)/sizeof(int));
  printf("res: %d\n", r);
  return 0;
}

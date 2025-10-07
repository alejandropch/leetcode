#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestConsecutive(int* nums, int numsSize) {
   printf("GA?");
   unsigned MOD = numsSize * 4; 
   int unique[numsSize], set[MOD], uniquen = 0, hash, longest;;
   memset(set, 0x7f, sizeof(set));
   int INF = set[0];
#define HASH(v) ((unsigned)(v) % MOD)
#define AVAILABLE_SLOT(hash, n) {int step = 1; while(set[hash] != INF && set[hash] != (n)) (hash)=(hash + (step++))% MOD;}
   for (int i = 0; i < numsSize; i++)
   {
     hash = HASH(nums[i]); 
     AVAILABLE_SLOT(hash, nums[i]);
     set[hash] = nums[i];
     unique[uniquen++] = nums[i];
   }
   longest = 0;
   for (int i = 0; i < uniquen; i++){
      hash = HASH(nums[i] - 1);
      if(set[hash] == INF)
      {
       for(int j = 0, len=0; ;j++, len++)
       {
         hash = HASH(nums[j]);
         if(nums[hash] == INF)
         {
           if ( len > longest) longest = len;
           break;
         }
       }
        
      }
   }
   return longest;
   
}
int main(){

  printf(": dn");
  int nums[] = {100, 4, 200,1,3,2};
  int a = 6;
  int l = longestConsecutive(nums, a);
  printf("res: %d\n", l);
  return 0;
}

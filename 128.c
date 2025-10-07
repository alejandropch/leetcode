#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestConsecutive(int* nums, int numsSize) {
  if (numsSize == 0) return 0;
  unsigned int MOD = numsSize * 4;
  int set[MOD], unique[numsSize], uniqueN = 0, hash;
  memset(set, 0x7f, sizeof(set));
  int INF = set[0];
  #define HASH(n) ((unsigned)(n) % MOD)
  #define AVAILABLE_HASH(hash, n) {int step = 1; while(set[hash] != INF && set[hash] != n) hash = ((hash + step++)%MOD);}
  for ( int i = 0; i < numsSize; i++ )
  {
    hash = HASH(nums[i]);
    AVAILABLE_HASH(hash, nums[i]);
    if(set[hash] == INF)
      unique[uniqueN++] = nums[i];
    set[hash] = nums[i];
  }
  int longest = 0;
  for (int i = 0; i < uniqueN; i++)
  {
    hash = HASH(unique[i] - 1);
    AVAILABLE_HASH(hash, unique[i] - 1);
    if( set[hash] == INF){
      for(int len = 0, j = unique[i];;len++, j++)
      {
        hash = HASH(j);
        AVAILABLE_HASH(hash, j);
        if(set[hash] == INF)
        {
          if(len > longest) longest = len;
          break;
        }
      }
    }
  }
  return longest;
}
int main(){

  int nums[] = {100, 4, 200, 1, 2, 3} ;


  int a = sizeof(nums);
  int l = longestConsecutive(nums, a);
  printf("res: %d\n", l);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>

int comp (const void *a, const void*b) {
  return *(int*)b - *(int*)a;
}
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
  /*
   * 100
  0 4=> 4 
  2 2 => 4 
  4 1 => 5

  0 4 => 4 -> |
                => 4, 2 => 6
  2 2 => 4 -> |
  4 1 => 5
  5 1 => 6    =>  5, 1 => 6
  */
  // sorting 
  qsort(position, positionSize, sizeof(int), comp);
  int t, head = 0;
  int *fleet = calloc(speedSize, sizeof(int));
  fleet[head] = speed[0];
  //filling up the fleets
  for (int i = positionSize - 1; i >= 0; i--) {
    t = (target - position[i]) / speed[i];
    if (t <= fleet[head]){
      fleet[++head] = speed[i];
    }
  }
  return head;
}

int main(){
  int position[] = {0,2,4};
  int speed[] = {4,2,1};
  int target = 100;
  printf("res: %d\n", carFleet(target, position, 3, speed, 3));

return 0;
}

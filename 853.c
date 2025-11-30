#include <stdlib.h>
#include <stdio.h>
typedef struct{ 
  int position;
  int speed;
}Car;
int comp (const void *a, const void*b) {
  return ((Car*)b)->position - ((Car*)a)->position ;
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
  Car *cars = malloc(sizeof(Car) * positionSize);
  for (int i = 0; i < positionSize; i++) {
    cars[i].position = position[i];
    cars[i].speed = speed[i];
  }
  // sorting 
  qsort(cars, positionSize, sizeof(Car), comp);
  int t, head = 0;
  float *fleet = calloc(speedSize + 1, sizeof(float));
  
  //filling up the fleets
  for (int i = 0; i < positionSize; i++) {
    fleet[++head] = (float)(target - cars[i].position) / (float)cars[i].speed;
    if( head >= 2 && (fleet[head - 1]  >= fleet[head]) ) {
      fleet[head--] = 0;
    }
  }
  return head;
}

int main(){
  int position[] = {10,8,0,5,3};
  int speed[] = {2,4,1,1,3};
  int target = 12;
  printf("res: %d\n", carFleet(target, position, 5, speed, 5));

return 0;
}

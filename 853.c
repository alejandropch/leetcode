#include <stdio.h>
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {

  int i, count = 0;
  float time_location[target + 1], maxt = 0;

  for (i = 0; i <= target; i++)
    time_location[i] = 0;

  for (i = 0; i < positionSize; i++) 
    time_location[position[i]] = (float) (target - position[i]) / speed[i];
  
  for (i = target; i >=0 ; i--)
    if(maxt < time_location[i]){
      count++;
      maxt = time_location[i];
    }
  
  return count;
}

int main(){
  int position[] = {6,8};
  int speed[] = {3,2};
  int target = 10;
  printf("res: %d\n", carFleet(target, position, 2, speed, 2));

return 0;
}

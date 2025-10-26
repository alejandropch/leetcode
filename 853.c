#include <stdlib.h>
#include <stdio.h>
typedef struct {
  int speed;
  int position;
} Fleet;
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
  Fleet* stack  = malloc((sizeof(Fleet) * positionSize));
  int mem = -1;
  int top = -1;
  int i = -1;
  for( i= 0; i < positionSize; i++){
    mem = position[i] + speed[i];
    if(mem <= target) {
      if( top == -1 ) {
        stack[++top].position = position[i];
        stack[top].speed= speed[i];
        continue;
      } 
      if(stack[top].position + stack[top].speed == mem){ 
        stack[top].position = position[i]; 
        stack[top].speed= stack[top].speed > speed[i]? speed[i]: stack[top].speed; 
      }
      else { 
        stack[++top].position = position[i]; 
        stack[top].speed= speed[i];
      }
    }
  }
  mem = -1;
  i = -1; 
  for(int j = 0; j <= top; j++){ 
    printf("stack[%d]: pos-> %d \t speed-> %d\n", j, stack[j].position, stack[j].speed);
    if(stack[j].position + stack[j].speed == mem){ 
      stack[j].position = position[j]; 
      stack[j].speed= stack[j].speed > speed[i]? speed[i]: stack[j].speed; 
      top--;
    }
    mem = stack[j].position + stack[j].speed;
    i = j;
  }
  return top + 1;
}

int main(){
  int position[] = {0,2,4};
  int speed[] = {4,2,1};
  int target = 100;
  printf("res: %d\n", carFleet(target, position, 3, speed, 3));

return 0;
}

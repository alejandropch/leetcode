#include <stdlib.h>
#include <stdio.h>
#define SIZE 10000


typedef struct {
  int v;
  int min;
} Node;

typedef struct {
  int top;
  Node *arr;
} MinStack;

MinStack* minStackCreate() {
  MinStack *obj = malloc(sizeof(MinStack));
  Node *arr = malloc(sizeof(Node) * SIZE);
  obj->top = -1;
  return obj;
}

void minStackPush(MinStack* obj, int val) {
  Node n; 
  if(obj->top == -1){
    n.v = val;
    n.min = val;
    obj->arr[++obj->top] = n;
    return;
  }
  if (val < obj->arr[obj->top].min) n.min = val; 
  else n.min = obj->arr[obj->top].min;
  n.v = val;
  obj->arr[++obj->top] = n;
}

void minStackPop(MinStack* obj) {
   obj->arr[obj->top--];
}

int minStackTop(MinStack* obj) {
   return obj->arr[obj->top].v;
}

int minStackGetMin(MinStack* obj) {
   return obj->arr[obj->top].min;
}

void minStackFree(MinStack* obj) {
  free(obj->arr);
  free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

void main(){

  MinStack *obj = minStackCreate();
  minStackPush(obj, -2);
  minStackPush(obj, 1);
  minStackPush(obj, -3);
 
 int param_2 = minStackGetMin(obj);
  printf("whaT? %d\n", param_2);
  minStackPop(obj);
 
 int param_3 = minStackGetMin(obj);
  printf("whaT? %d\n", param_3);
 
 int param_4 = minStackGetMin(obj);
  printf("whaT? %d\n", param_4);
 
 minStackFree(obj);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int top;
  int *arr;
} Stack;

int evalRPN(char** tokens, int tokensSize) {
  Stack stack;
  stack.top = -1;
  int data[tokensSize];
  stack.arr = data; 
  for ( int i= 0; i < tokensSize; i++){
    
    printf("i: %d\n", i);
      if(strcmp(tokens[i], "*") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top] * stack.arr[stack.top -1]; stack.top--; continue;};
      if(strcmp(tokens[i], "/") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top] / stack.arr[stack.top -1]; stack.top--; continue;};
      if(strcmp(tokens[i], "-") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top] * stack.arr[stack.top -1]; stack.top--; continue;};
      if(strcmp(tokens[i], "+") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top] * stack.arr[stack.top -1]; stack.top--; continue;};
    int n = atoi(tokens[i]); 

    stack.arr[++stack.top] = n;
    printf("arr: %d\t top: %d\n", stack.arr[stack.top], stack.top);
  }
  return stack.arr[stack.top];
}


int main() {
  int s = 5;
  char *t[5] = {"2", "1", "+", "3", "*"};
  printf("res: %d", evalRPN(t, s));
  return 0;
}

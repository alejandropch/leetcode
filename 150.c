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
    if(strcmp(tokens[i], "*") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top - 1] * stack.arr[stack.top]; stack.top--; continue;};
    if(strcmp(tokens[i], "/") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top - 1] / stack.arr[stack.top]; stack.top--; continue;};
    if(strcmp(tokens[i], "-") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top - 1] - stack.arr[stack.top]; stack.top--; continue;};
    if(strcmp(tokens[i], "+") == 0){ stack.arr[stack.top - 1] = stack.arr[stack.top - 1] + stack.arr[stack.top]; stack.top--; continue;};
    int n = atoi(tokens[i]); 

    stack.arr[++stack.top] = n;
  }
  return stack.arr[stack.top];
}


int main() {
  int s = 13;
  char *t[13] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000
typedef struct {
  int top;
  int arr[MAX_SIZE];
} Stack;

void initialize(Stack *stack){
  stack->top = -1;
}
int getTop(Stack *stack){
  return stack->top;
}
void insert (Stack *stack, int value){
  if(stack->top != MAX_SIZE){
    stack->top++;
    stack->arr[stack->top] = value;
  }
}
int pop (Stack *stack){
  int popped = stack->arr[stack->top];
  stack->top--;
  return popped;
}
int openEquivalent (char closeSign)
{
  if(closeSign == ')')
    return '(';
  if(closeSign == '}')
    return '{';

  return '[';
}
bool isValid(char *s)
{
  Stack stack;
  initialize(&stack);
  if(sizeof s%2 != 0) return false;
  for (int i = 0; s[i] != '\0' ;i++)
  {
    if (s[i] == '[' || s[i] == '{' || s[i] == '(')
      insert(&stack, s[i]); 
    if (s[i] == ']' || s[i] == '}' || s[i] == ')')
      if(pop(&stack) != openEquivalent(s[i])){
        return false;}
  }
  if (getTop(&stack) == -1){
    return true;
  }
  return false;
}


int main()
{
  char *c ="([})";
  printf("result: %d\n", isValid(c));
}

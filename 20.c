#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int top;
  char *arr;
} Stack;

void initialize(Stack *stack){
  stack->top = -1;
}
int getTop(Stack *stack){
  return stack->top;
}
void insert (Stack *stack, int value){
    stack->top++;
    stack->arr[stack->top] = value;
}
int pop (Stack *stack){
  int popped = '\0';
  if (stack->top > -1) {
    popped = stack->arr[stack->top];
    stack->top--;
  }
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
  int len = strlen(s);
  if(len%2 != 0) return false;
  Stack stack;
  char data[len];
  stack.arr = data;
  initialize(&stack);
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
  char *c ="){";
  printf("result: %d\n", isValid(c));
}

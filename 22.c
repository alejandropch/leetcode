#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int top;
  char **arr;
} Stack;

char** generateParenthesis(int n, int* returnSize) {
 int start = 0, closing = 0;
 char str[2 * n + 1];
 char ** res = malloc(sizeof(char*) * (*returnSize));
 for (int i = 0; i < n; i++){

   if( closing < start) {
   } else {
     
    
   }
 }
  
}

int main()
{
  int a = 5;

  generateParenthesis(3, &a);
  return 0;
}

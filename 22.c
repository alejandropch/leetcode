#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void backtracking(char ***res, int start, int end, int *returnSize, int *n, char *str, int *cap)
{
  if(start < *n){
    str[start + end] = '(';
    backtracking(res, start + 1, end, returnSize, n, str, cap);
  }
  if(end < start){
    str[start + end] = ')';
    backtracking(res, start, end + 1, returnSize, n, str, cap);
  }
  if((end + start ) == 2 *(*n)){
    if(*returnSize >= *cap){
      *cap *=2;
      *res =  (char **)realloc(*res, sizeof(char *) * (*cap));
    }
    (*res)[*returnSize] = strdup(str);
    (*returnSize)++;
    return;
  }

}

char** generateParenthesis(int n, int* returnSize) {
 int start = 0, close = 0, cap = 8;
 *returnSize = 0;
 char * str = calloc( n * 2 + 1, sizeof(char));
 char ** res = (char **)malloc(sizeof(char*) * cap);
 backtracking(&res, start, close, returnSize, &n, str,&cap);
 return res;
}

int main()
{
  int a = 0;
  int b = 8;
  char ** res = generateParenthesis(b, &a);
  for ( int i = 0; i < a; i++)
    printf("res: %s\n", res[i]);
  return 0;
}

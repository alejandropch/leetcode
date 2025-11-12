#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrome(char* s) {
  int j = 0, i, z;
  int len = strlen(s);
  char *modified =  malloc(len + 1); 
  for(i = 0; i < len; i++ ){
    if (s[i] == ' ')
      continue;
    if (s[i] >= 65 && s[i] <= 90) {
     modified[j++] =  s[i] - 'A' + 'a';
    }
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
     modified[j++] =  s[i];
    }
  }
  modified[j] = '\0';
  int modifiedlen = strlen(modified);
  for(i = 0, z = modifiedlen - 1; i < z ; i++, z--){
      if(modified[i] != modified[z]){
        return false;
      }
  }
  return true;
}
int main()
{
  char *s = " ";
  char r = isPalindrome(s);
  printf("res: %d", r);
  return 0;
}

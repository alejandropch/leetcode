#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
  int start = 0, end = strlen(s) - 1;
  while(start < end){
    while(start < end && !isalnum(s[start])){
      start++;
    }
    while(end > start && !isalnum(s[end])){
      end--;
    }
    
    if(tolower(s[start]) != tolower(s[end]))
      return false;
    start++;
    end--;
  }
  return true;
}
int main()
{
  char *s = "0P";
  char r = isPalindrome(s);
  printf("res: %d", r);
  return 0;
}

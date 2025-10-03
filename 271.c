#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * encode(char **a, size_t size)
{
  int total_len_encoded_str;

  for(int i = 0; i < size; i++)
  {
    int str_size = strlen(a[i]); 
    int word_metadata_len = snprintf(NULL,0,"%d#",str_size); 
    total_len_encoded_str += str_size + word_metadata_len;

  }
  printf("encoded len: %d\n", total_len_encoded_str);
  char * encoded_str = malloc(total_len_encoded_str + 1);
  int counter = 0;
  for(int i = 0; i < size; i++)
  {
    counter += sprintf(encoded_str + counter, "%ld#%s", strlen(a[i]), a[i]);
  }
  encoded_str[total_len_encoded_str + 1] = '\0'; 
  return encoded_str;

};

int getStringSize(char *str)
{
  int i = 0;
  while (str[i] != '\0')
    i++;

  return i;
}
int getWordCounter(int begin, int end, char *str)
{
  int l = end - begin;
  char number_lenght[l];
  for (int i = 0; i < l; i++)
    number_lenght[i] = str[begin + i];
  return atoi(number_lenght);
}
char * decode(char * encoded_str)
{
  int i=0,j=0;
  int text_size = getStringSize(encoded_str); // size of the whole encoded string
  int word_size = 0;
  char * word = NULL;

  for(;i < text_size;)
  {
    j = i; 
    for (;encoded_str[j] != '#'; j++);
    word_size = getWordCounter(i, j, encoded_str); //getting the size of one word
    word = (char *) malloc(word_size * sizeof(char) + 1); // first time allocating memory
    j++; //skiping the delimiter
    // saving the word (respecting the order of the message)
    for(int t = 0; t < word_size; t++)
    {
      word[t] = encoded_str[j+t];
    }
    i = j + word_size;
      
    if ( word != NULL ){
      word[word_size] = '\0';
      printf("word: %s\n", word);
      free(word);
      word = NULL;
      word_size = 0;
    }
  }
}
int main(){

  char *a [] = {"hola", "c###omo", "estas"}; // 3 slots, 3 addreses, 8 * 3
  printf("%ld\n", sizeof(a));
  size_t len = sizeof(a)/ sizeof(&a);
  char res [len];
  char * encoded = encode(a, len);
  printf("%s\n", encoded);
  decode(encoded, res, len);
  return 0; 
}

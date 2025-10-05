#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
  int i = 0, j= 0, a, b;
  bool hi[9] = {false};
  bool hj[9] = {false};
  bool box[9][9] = {{false}};
  for(; i < 9; i++){
    for( j=0; j < 9; j++){
      a = board[i][j] - '1';
      b = board[j][i] - '1';
      if (a != -3)
      {
        if(hi[a] == true)
        {
          return 0; 
        } else 
          hi[a] = true;
       int8_t partition= (i/3) * 3 + j/3; 
        if (box[partition][a] == true){
          return 0;
        }
        else 
         box[partition][a] = true;
        
      }
      if (b != -3) 
      {  
        if(hj[b] == true)
        {
          return 0; 
        } else 
          hj[b] = true;
      }

    }
    memset(hi, false, sizeof(hi));
    memset(hj, false, sizeof(hj));
  }
  return 1;
}

int main(){
  
 char *board[9] = {
    "53...7...",
    "...195..6",
    ".98....2.",
    "8...6...3",
    "...8.3.41",
    "7...2....",
    ".6....28.",
    ".2.41...5",
    "....8..79"
};
 int col = 9;
 bool result = isValidSudoku(board, 9, &col);

 result ? printf("Valid Sudoku\n") : printf("Invalid Sudoku\n");


  return 0;
}

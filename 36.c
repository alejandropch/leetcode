#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
  int i = 0, j= 0, a, b;
  bool hi[9] = {false};
  bool hj[9] = {false};
  bool box[3][3][9] = {{{false}}};
  for(; i < boardSize; i++){
    for( j=0; j < *boardColSize; j++){
      a = board[i][j] - '1';
      b = board[j][i] - '1';
      if (a != -3)
      {
        if(hi[a] == true)
        {
          return 0; 
        } else 
          hi[a] = true;

        if (box[i/3][j/3][a] == true)
        {
          return 0; 
        } else {
          box[i/3][j/3][a] = true;
        }
      }
      if (b != -3) 
      {  
        printf("a: %d, b: %d\n", a,b);
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
    "...8.3..1",
    "7...2...4",
    ".6....28.",
    ".2.41...5",
    "....8..79"
};
 int col = 9;
 bool result = isValidSudoku(board, 9, &col);

 result ? printf("Valid Sudoku\n") : printf("Invalid Sudoku\n");


  return 0;
}

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
  unordered_map<int, int> hashmap_row;
  unordered_map<int, int> hashmap_columns;
  unordered_set<char> box[3][3];

  for (int i = 0; i < board.size(); i++)
  {
    int r = i / 3;

    for (int j = 0; j < board[i].size(); j++)
    {

      int c = j / 3;

      if (hashmap_row[board[i][j]] ||
          hashmap_columns[board[j][i]] ||
          box[r][c].count(board[i][j]))
      {
        return false;
      }
      if (board[i][j] != '.')
      {
        hashmap_row[board[i][j]]++;
        box[r][c].insert(board[i][j]);
      }

      if (board[j][i] != '.')
        hashmap_columns[board[j][i]]++;
    }
    hashmap_row.clear();
    hashmap_columns.clear();
  }

  vector<int> output;

  return true;
}

int main()
{
  vector<vector<char>> nums =
      {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
       {'2', '.', '.', '1', '9', '5', '.', '.', '.'},
       {'.', '1', '8', '.', '.', '.', '.', '6', '.'},
       {'8', '.', '2', '.', '6', '.', '.', '.', '3'},
       {'7', '.', '.', '9', '.', '3', '.', '.', '1'},
       {'4', '.', '.', '.', '.', '.', '.', '.', '6'},
       {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
       {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
       {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  bool output = isValidSudoku(nums);

  printf("%d\n", output);

  return 0;
}
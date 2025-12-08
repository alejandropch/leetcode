#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
  int i, mid, l, h;
  for (i = 0; i < matrixSize; i++) {
    l = 0;
    h = *matrixColSize - 1;
    while (l <= h) {
      mid = l + (h-l)/2;
      if(matrix[i][mid] == target)
        return 1;
      if(matrix[i][mid] > target)
        h = mid - 1;
      if(matrix[i][mid] < target)
        l = mid + 1;
    }
  
  }
    return 0;
}
int main(){

  int matrix[][4]={{1,3,5,7},{10,11,16,20},{23,30,34,60}};

  int rowsize = 3;
  int colsize = 4;
  int **m = malloc(rowsize * sizeof(int*));
  for (int i = 0; i < 3; i++) {
    m[i] = matrix[i];
  }
  bool r = searchMatrix(m, rowsize, &colsize, 61);
  printf("res: %d\n", r);
return 0;
}

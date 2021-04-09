
/*
  Today's problem:
    You are given a matrix A of order n x n.
    Write a program to determine whether the matrix A is orthogonal or not.

  * Orthogonal Matrix:
  Definition - A matrix 'A' is said to be orthogonal when A x A^T = I.
  
  * A^T = Transpose
  Rows and columns are interchanged
  A =
  | 1 2 3 |
  | 4 5 6 |
  | 7 8 9 |

  A ^ T =
  Transpose =
  | 1 4 7 |
  | 2 5 8 |
  | 3 6 9 |

  1 * 1 + 2 * 2 + 3 * 3 = 1 + 4 + 9 = 14
  1 * 4 + 2 * 5 + 3 * 6 = 4 + 10 + 18 = 32

  Multiplication of Matrices:
  Condition = Number of columns of A must be equal to the number of rows of B

  A is a matrix of order m x n
  B is a matrix of order p x q

  1 * 1 + 2 * 2 + 3 * 3 = 1 + 4 + 9 = 14
  1 * 4 + 2 * 5 + 3 * 6 = 4 + 10 + 18 = 32

  sum = 0;

  sum += 1 * 1;
  sum += 2 * 2;
  sum += 3 * 3;

  | 1 2 3 |   | 1 4 7 10 20 |   | 14 32 . . . |
  | 4 5 6 | x | 2 5 8 30 40 | = | .  .  . |
  | 7 8 9 |   | 3 6 9 50 60 |   | .  .  . |

  Condition is n == p.
  The new matrix formed will be m x q.
*/

#include <stdio.h>

void transpose(int m, int n, int matrix[m][n], int result[n][m])
{
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      result[i][j] = matrix[j][i];
    }
  }
}

int multiply_matrices(int m, int n, int A[m][n], int p, int q, int B[p][q], int result[m][q])
{
  if (n != p)
  {
    return 0;
  }

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < q; ++j)
    {
      int sum = 0;
      for (int k = 0; k < n; ++k)
      {
        sum += A[i][k] * B[k][j];
      }

      result[i][j] = sum;
    }
  }

  return 1;
}

// This function will return 1 if the matrix is orthogonal, and it will return 0 if the matrix is not orthogonal
int is_orthogonal_matrix(int m, int n, int matrix[m][n])
{
  // ortho = A * A ^ T

  int transpose_matrix[n][m];
  transpose(m, n, matrix, transpose_matrix);

  int resultant_matrix[m][m];
  multiply_matrices(m, n, matrix, n, m, transpose_matrix, resultant_matrix);

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (i == j && resultant_matrix[i][j] != 1)
      {
        return 0;
      }
      else if (i != j && resultant_matrix[i][j] != 0)
      {
        return 0;
      }
    }
  }

  return 1;
}

int main()
{
  int matrix[2][2] = {
    { -1, 0},
    { 0, 1 }
  };
  int m = 2, n = 2;

  if (is_orthogonal_matrix(m, n, matrix))
  {
    printf("The given matrix is orthogonal!\n");
  }
  else
  {
    printf("The given matrix is not orthogonal!\n");
  }
  return 0;
}

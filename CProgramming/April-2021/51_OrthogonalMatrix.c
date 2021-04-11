
#include <stdio.h>

// Calculates the transpose of mxn matrix
void transpose(int m, int n, double matrix[m][n], double result[n][m])
{
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      result[i][j] = matrix[j][i];
    }
  }
}

// Calculates the product of two matrices
int multiply_matrices(int m, int n, double A[m][n], int p, int q, double B[p][q], double result[m][q])
{
  if (n != p)
  {
    return 0;
  }

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < q; ++j)
    {
      double sum = 0;
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
int is_orthogonal_matrix(int m, int n, double matrix[m][n])
{
  // ortho when A * A ^ T = I

  double transpose_matrix[n][m];
  transpose(m, n, matrix, transpose_matrix);

  double resultant_matrix[m][m];

  if (!multiply_matrices(m, n, matrix, n, m, transpose_matrix, resultant_matrix))
  {
    return 0;
  }

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
  int m, n;

  printf("Enter the number of rows of matrix A: ");
  scanf("%d", &m);

  printf("Enter the number of columns of matrix A: ");
  scanf("%d", &n);

  double A[m][n];

  printf("Enter matrix A: ");
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      printf("A[%d][%d] = ", i + 1, j + 1);
      scanf("%lf", &A[i][j]);
    }
  }

  printf("\n");
  if (is_orthogonal_matrix(m, n, A))
  {
    printf("The matrix is orthogonal.\n");
  }
  else
  {
    printf("The Matrix is not orthogonal.\n");
  }

  return 0;
}

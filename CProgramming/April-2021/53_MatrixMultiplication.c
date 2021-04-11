
#include <stdio.h>

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

int main()
{
  int m, n;
  int p, q;

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

  // number of columns of [A] is equal to number of rows of matrix of [B].
  p = n;

  printf("[DEFINITION LIMIT : The number of columns of matrix A must be equal to the number of rows of matrix B]\nNumber of rows in matrix B = %d\n", p);

  printf("\nEnter the number of columns of matrix B: ");
  scanf("%d", &q);

  double B[p][q];

  printf("Enter matrix B: ");
  for (int i = 0; i < p; ++i)
  {
    for (int j = 0; j < q; ++j)
    {
      printf("B[%d][%d] = ", i + 1, j + 1);
      scanf("%lf", &B[i][j]);
    }
  }

  double product[m][q];

  multiply_matrices(m, n, A, p, q, B, product);

  printf("\nResult:\n");
  for(int i = 0; i < m; ++i)
  {
    for(int j = 0; j < q; ++j)
    {
      printf("%lf\t", product[i][j]);
    }
    printf("\n");
  }

  return 0;
}

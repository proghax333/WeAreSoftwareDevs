
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int matrices(int m, int n)
{
  double p = fmin(m, n) - 1;
  return (p + 1) * (m * n - p * (m + n) / 2 + p * (2 * p + 1) / 6);
}

int main()
{
  int m, n, result;

  while(1)
  {
    scanf("%d%d", &m, &n);
    if(m < 0 || n < 0)
    {
      break;
    }
    result = matrices(m, n);
    printf("Result = %d\n", result);
  }
  return 0;
}

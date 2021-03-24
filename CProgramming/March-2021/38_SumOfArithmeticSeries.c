
#include <stdio.h>

int main()
{
  long long a, d, n;

  printf("*** Sum of Arithmetic Progression Calculator ***\n\n");

  printf("Enter the first term(a): ");
  scanf("%ld", &a);

  printf("Enter the difference between two consecutive terms(d): ");
  scanf("%ld", &d);

  printf("Enter how many terms do you want to sum up(n): ");
  scanf("%ld", &n);

  long long sum = (double)n / 2 * (2 * a + (n - 1) * d);

  printf("The sum of first %ld terms of the arithmetic progression is = %ld\n", n, sum);

  return 0;
}

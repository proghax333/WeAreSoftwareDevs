
// Daily Problem #1 : 20/03/2021
// Multiplication table of a number.

#include <stdio.h>

int main()
{
  long long int n;

  printf("Enter the number of which you want a multiplication table: ");
  scanf("%ld", &n);

  printf("\n[Multiplication table of %ld]\n", n);
  for(long long int i = 1; i <= 10; ++i)
  {
    printf("%ld x %ld = %ld\n", n, i, n * i);
  }

  return 0;
}
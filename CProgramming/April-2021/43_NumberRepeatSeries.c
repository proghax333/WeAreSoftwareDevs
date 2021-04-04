
#include <stdio.h>

int main()
{
  unsigned long int n, repeatingDigit;

  printf("Enter how many terms you want to sum up: ");
  scanf("%ld", &n);

  printf("Enter the digit which repeats in the series: ");
  scanf("%ld", &repeatingDigit);

  unsigned long int term = 0, sum = 0;
  for (int i = 0; i < n; ++i)
  {
    term = term * 10 + repeatingDigit;
    sum += term;
  }

  printf("\nSum = %ld\n", sum);

  return 0;
}


#include <stdio.h>

int main()
{
  unsigned long int n, repeatingDigit;

  printf("Enter how many terms you want to sum up: ");
  scanf("%lu", &n);

  printf("Enter the digit which repeats in the series: ");
  scanf("%lu", &repeatingDigit);

  // Save all the terms in this array
  unsigned long int terms[n];
  unsigned long int term = 0, sum = 0;
  for (int i = 0; i < n; ++i)
  {
    term = term * 10 + repeatingDigit;
    terms[i] = term;
    sum += term;
  }

  if (n)
  {
    printf("%lu ", terms[0]);
    for (int i = 1; i < n; ++i)
    {
      printf(" + %lu", terms[i]);
    }
    printf(" = %lu\n", sum);
  }
  else
  {
    printf("Sum = 0\n");
  }

  return 0;
}

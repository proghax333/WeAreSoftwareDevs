
// Daily Problem #2 : 20/03/2021
// Print first 100 odd natural numbers

#include <stdio.h>

int main()
{
  int n = 100;

  for(int i = 1; i <= n; ++i)
  {
    printf("%d\n", 2 * i - 1);
  }

  return 0;
}

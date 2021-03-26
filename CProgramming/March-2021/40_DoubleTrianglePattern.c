
#include <stdio.h>

int main()
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  // Upper triangle
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      printf("* ");
    }
    printf("\n");
  }

  // Lower triangle
  for (int i = n - 2; i >= 0; --i)
  {
    for (int j = 0; j <= i; ++j)
    {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}
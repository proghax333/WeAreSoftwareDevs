
#include <stdio.h>

int main()
{
  int n;
  printf("Enter the number of rows you want to print: ");
  scanf("%d", &n);

  for(int i = 0; i < n; ++i)
  {
    for(int j = i; j < n - 1; ++j)
    {
      printf(" ");
    }
    for(int j = 0; j <= i; ++j)
    {
      printf("%d ", i + 1);
    }
    printf("\n");
  }

  return 0;
}

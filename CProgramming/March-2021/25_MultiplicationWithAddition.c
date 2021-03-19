
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d%d", &a, &b);

  int result = 0;
  int x = a, y = b;

  if (y < x)
  {
    x = b, y = a;
  }
  x = abs(x), y = abs(y);

  for (int i = 0; i < x; ++i)
  {
    result += y;
  }
  if((a < 0) ^ (b < 0))
  {
    result = -result;
  }

  printf("%d * %d = %d\n", a, b, result);

  return 0;
}
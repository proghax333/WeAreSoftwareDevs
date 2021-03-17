
#include <stdio.h>

int main()
{
  int a, b;

  printf("Enter a: ");
  scanf("%d", &a);

  printf("Enter b: ");
  scanf("%d", &b);

  int result = a - (-b);

  printf("%d + %d = %d\n", a, b, result);

  return 0;
}

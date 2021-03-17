
#include <stdio.h>

int add(int a, int b)
{
  int carry = (a & b) << 1;
  int result = a ^ b;

  if(carry == 0)
  {
    return result;
  }

  add(carry, result);
}

int main()
{
  int a, b;

  printf("Enter a: ");
  scanf("%d", &a);

  printf("Enter b: ");
  scanf("%d", &b);

  int result = add(a, b);

  printf("%d + %d = %d", a, b, result);

  return 0;
}

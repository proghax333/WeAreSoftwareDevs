
#include <stdio.h>

int main()
{
  int a, b;

  printf("Enter a: ");
  scanf("%d", &a);

  printf("Enter b: ");
  scanf("%d", &b);

  printf(
      "You entered:\n"
      "a = %d | b = %d\n",
      a, b);

  int t = a;
  a = b;
  b = t;

  printf(
      "Values swapped.\n"
      "a = %d | b = %d\n",
      a, b);
  
  return 0;
}

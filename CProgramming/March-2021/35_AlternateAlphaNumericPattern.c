
#include <stdio.h>

int main()
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  for(int i = 0; i < 2 * n; ++i)
  {
    for(int j = 0; j <= i; ++j)
    {
      if(i % 2 == 0) {
        printf("%d", (i/2) + 1);
      } else {
        printf("%c", (i/2) + 'A');
      }
    }
    printf("\n");
  }
  return 0;
}

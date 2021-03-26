
#include <stdio.h>
#include <ctype.h>

int main()
{
  int shiftValue;
  printf("Enter shift value[-26 to 26]: ");
  scanf("%d%*c", &shiftValue);

  char c;
  while ((c = getchar()) != '\n')
  {
    if (isalpha(c))
    {
      if (c & (1 << 5))
      {
        printf("%c", (26 + shiftValue + c - 'a') % 26 + 'a');
      }
      else
      {
        printf("%c", (26 + shiftValue + c - 'A') % 26 + 'A');
      }
    }
    else
    {
      printf("%c", c);
    }
  }

  return 0;
}

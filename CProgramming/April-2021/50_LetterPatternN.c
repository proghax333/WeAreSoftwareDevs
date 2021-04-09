
#include <stdio.h>

int main()
{
  char letter;

  printf("Enter a letter: ");
  scanf("%c", &letter);

  char limit = letter - 'A';

  for(int i = 0; i <= limit; ++i)
  {
    for(int j = 0; j <= i; ++j)
    {
      printf("%c ", 'A' + i);
    }
    printf("\n");
  }
  return 0;
}


#include <stdio.h>

int main()
{
  long long number;
  
  printf("Enter a number: ");
  scanf("%ld", &number);
  
  long long t = number, counter = 0;
  while(t)
  {
    ++counter;
    t /= 10;
  }

  printf("Number of digits in %ld is %ld\n", number, counter);

  return 0;
}

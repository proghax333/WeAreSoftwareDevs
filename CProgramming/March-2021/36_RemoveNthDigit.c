
#include <stdio.h>
#include <math.h>

long long int absolute_value(long long int x)
{
  return -x * (x < 0) + x * (x >= 0);
}

int main()
{
  long long int number, n;

  printf("Enter a number: ");
  scanf("%ld", &number);

  printf("Enter the number of digit(from right) which you remove from %ld: ", number);
  scanf("%ld", &n);

  long long int t = absolute_value(number);
  long long int number_of_digits = log10(t) + 1;

  if(n <= number_of_digits && n > 0)
  {
    long long int counter = 1, u = 0, digit_to_be_removed, factor = 1;
    
    while(counter != n)
    {
      u = (t % 10) * factor + u;
      t /= 10;
      factor *= 10;
      ++counter;
    }
    digit_to_be_removed = t % 10;
    t /= 10;
    t = t * pow(10, n - 1) + u;
    
    // Restore the original sign
    if(number < 0)
      t = -t;
    
    printf(
      "Removed %ld\n"
      "The new number is: %ld\n", digit_to_be_removed, t);
  }
  else
  {
    printf("[Error] You Entered invalid index %d.\n", n);
    if(n <= 0)
    {
      printf("[Error] Only positive indexes allowed.\n");
    }
    else
    {
      printf("[Error] %ld is greater than the number of digits in %ld(which is %ld)\n", n, number, number_of_digits);
    }
  }

  return 0;
}

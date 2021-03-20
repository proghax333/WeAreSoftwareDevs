
// Daily Problem #3 : 20/03/2021
// Sum of first n prime numbers

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
  if(n < 2)
  {
    return 0;
  }
  if(n == 2)
  {
    return 1;
  }
  if(n % 2 == 0)
  {
    return 0;
  }
  for(int i = 3; i <= sqrt(n); i += 2)
  {
    if(n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int n = 10;
  int count = 0;

  int sum = 2; // because first prime is 2 (only even prime number)
  ++count;
  
  for(int i = 3; count < n; i += 2)
  {
    if(isPrime(i))
    {
      sum += i;
      ++count;
    }
  }

  printf("Sum of first %d prime numbers = %d\n", n, sum);

  return 0;
}

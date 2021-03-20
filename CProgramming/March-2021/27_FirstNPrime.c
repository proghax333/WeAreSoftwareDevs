
// Daily Problem #3 : 20/03/2021
// Sum of first n prime numbers

#include <stdio.h>
#include <math.h>

/**
 * If n is prime, the function return 0.
 * If n is not prime, the function returns 1.
 */
int isPrime(int n) {
  // Negative numbers, 0, and 1 are not prime numbers. So, return 0.
  if(n < 2)
  {
    return 0;
  }

  // 2 is the only even prime number, so return 1.
  if(n == 2)
  {
    return 1;
  }

  // Except 2, any number divisible by 2 is not a prime number. So, return 0.
  if(n % 2 == 0)
  {
    return 0;
  }

  // Check if n is divisible by any odd number less than or equal to sqrt(n).
  // We already checked if the number is even or not. If it is even, it is not prime.
  // So we only check odd numbers.
  // Hence start all the odd numbers from 3.
  // To skip over even numbers, we add 2 to i by doing i += 2 at the end of each cycle.
  // So the loop will go like: i = 3, 5, 7, ...
  for(int i = 3; i <= sqrt(n); i += 2)
  {
    // If n is divisible by i, it is not a prime number. So, return 0.
    if(n % i == 0)
    {
      return 0;
    }
  }

  // If it is divisible by nothing, n is a prime number. So, return 1.
  return 1;
}

int main()
{
  // Total number of prime numbers to be printed
  int n = 10;

  // Number of prime numbers printed.
  int count = 0;

  // Print the first prime number
  printf("2\n");
  // Add 1 to count, because we printed a prime number.
  ++count;
  
  // We already printed the only even prime number, 2.
  // Hence, we now only need to check odd numbers. Because no even number is prime except for 2.
  // Run the loop and check odd natural numbers until we print 10 prime numbers.
  for(int i = 3; count < n; i += 2)
  {
    // Check if i is prime.
    if(isPrime(i))
    {
      // If i is prime, print i and add 1 to 'count'.
      printf("%d\n", i);
      ++count;
    }
  }

  return 0;
}

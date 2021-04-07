
/**
 * Project Euler : Problem 16
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26
 * What is the sum of digits of the number 2^1000?
 */

/*

We can use arrays to store each digits of the big number.

Let's consider a number 12345678.

It'll be stored into the array as follows:
digits[] = { 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, ...};

Here,
digits[0] will be the first digit of the number
digits[1] will be the second digit of the number
and so on...

How will we multiply the number stored as an array by 2?
The same way we did it when we were in 1st, 2nd grade.

    1 1 0 -> carry
    2 5 6 
  x     2
  --------- 
    5 1 2

1 0 0 0
0 5 1 2
  x   2
--------
1 0 2 4


Let's consider
  digits[] = { 6, 5, 2, 0, 0, 0, ... more 0s for future}

  number of digits in 256 is 3 ( which are 2, 5, 6 )
  so, int number_of_digits = 3;

  Start from the first digit.
  int i = 0;
  carry = 0;
  Process:
    i = 0)
    product = digits[i] * 2 + carry = 12 + 0 = 12
    digit = product % 10 = 12 % 10 = 2
    carry = product / 10 = 12 / 10 = 1


    If i == number_of_digits - 1:
      If carry == 0:
        stop
      Else
        number_of_digits++;

    Go to the next digit.
    i++

    i = 1)
    product = digits[i] * 2 + carry = 10 + 1 = 11
    digit = product % 10 = 11 % 10 = 1
    carry = product / 10 = 11 / 10 = 1

    If i == number_of_digits - 1:
      If carry == 0:
        stop
      Else
        number_of_digits++;

    Go to the next digit
    i++

    {6, 5, 2, 0, 0}

    512
    *2 = 1024

    i = 2)
    product = digits[i] * 2 + carry = 4 + 1 = 5
    digit = product % 10 = 5 % 10 = 5
    carry = product / 10 = 5 / 10 = 0

    If i == number_of_digits - 1:
      If carry == 0:
        stop
      Else
        number_of_digits++;

    Go to the next digit
    i++

    We'll keep on multiplying the number with 2 for 1000 times.

    For example:
    // This will run a thousand times
    for(int i = 1; i <= 1000; ++i)
      multiply(digits, 2);

    where multiply function which will take the array of digits as input and will perform the multiplication.

    1 * 2 ^ 1000 = 2 ^ 1000

    5 1 2
    2
    -----
    1024
    
    digits = { 6, 5, 2, 0, 0...}
    digits = { 2, 1, 5, 0..}
*/

#include <stdio.h>

int multiply(int* digits, int n, int number_of_digits)
{
  int carry = 0, product;
  for(int i = 0; i < number_of_digits; ++i)
  {
    product = digits[i] * n + carry;
    digits[i] = product % 10;
    carry = product / 10;

    if(i == number_of_digits - 1)
    {
      if(carry != 0)
      {
        number_of_digits++;
      }
    }
  }

  return number_of_digits;
}

// 2 ^ 8 = 256
// 2 + 5 + 6 = 13

int main()
{
  int digits[1000] = { 0 };
  int number_of_digits = 1;

  const int power = 8;
  digits[0] = 1;

  for(int i = 1; i <= power; ++i)
  {
    number_of_digits = multiply(digits, 2, number_of_digits);
  }

  int sum = 0;
  for(int i = 0; i < number_of_digits; ++i)
  {
    sum += digits[i];
  }

  printf("Sum = %d\n", sum);

  return 0;
}

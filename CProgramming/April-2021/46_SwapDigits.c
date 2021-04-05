
/* Write a program to swap ith and jth digits of a number */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Function prototypes/declarations */

/* Returns nth digit of a number */
long int nth(long int number, int n);

/* Returns how many digits are there in a number */
long int count_digits(long int number);

/* Sets the nth digit of a number */
long int set_nth_digit(long int number, int n, int digit);

/* Swaps the ith and jth digits of a number */
long int swap_digits(long int number, int i, int j);

int main()
{
  long int input_number;

  /* Ask user for input */
  printf("Enter a number: ");
  scanf("%ld", &input_number);

  int i, j;
  printf("Enter ith and jth number of digits which you want to swap: ");
  scanf("%d%d", &i, &j);

  long int swapped_result = swap_digits(input_number, i - 1, j - 1);
  printf("\nBefore Swapping: %ld\nAfter Swapping: %ld\n", input_number, swapped_result);

  return 0;
}

/* Returns nth digit of a number */
long int nth(long int number, int n)
{
  return (number / (long int)powl(10, n)) % 10;
}

/* Returns how many digits are there in a number */
long int count_digits(long int number)
{
  return log10(number) + 1;
}

/* Sets the nth digit of a number */
long int set_nth_digit(long int number, int n, int digit)
{
  long int power = (long int)powl(10, n),
           upper = (number / (power * 10)) * (power * 10),
           new_digit = digit * power,
           lower = number % power;

  return upper + new_digit + lower;
}

/* Swaps the ith and jth digits of a number */
long int swap_digits(long int number, int i, int j)
{
  int ith = nth(number, i);
  int jth = nth(number, j);

  long int result = set_nth_digit(number, i, jth);
  result = set_nth_digit(result, j, ith);

  return result;
}
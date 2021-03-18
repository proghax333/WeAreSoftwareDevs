
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define BIG_NUMBER_LIMIT 100

struct big_number
{
  char number_buffer[BIG_NUMBER_LIMIT + 1];
  bool is_negative;
  size_t length;
};

typedef struct big_number big_number_t;

big_number_t big_number_default()
{
  big_number_t number;

  number.number_buffer[0] = '0';
  number.number_buffer[1] = '\0';

  number.is_negative = false;

  number.length = 1;

  return number;
}

size_t big_number_length(big_number_t number)
{
  return number.length;
}

big_number_t big_number_read()
{
  big_number_t number = big_number_default();
  char ch;

  /* Flush the standard input stream */
  fflush(stdin);

  size_t counter = 0;
  /* Get first digit or sign. */
  ch = getchar();
  if (isdigit(ch))
  {
    number.number_buffer[counter] = ch;
    ++counter;
  }
  else if (ch == '-')
  {
    number.is_negative = true;
  }
  else
  {
    return number;
  }

  /* Take remaining digits as input */
  while (counter < BIG_NUMBER_LIMIT && isdigit(ch = getchar()))
  {
    number.number_buffer[counter] = ch;
    ++counter;
  }

  if(counter != 0) {
    number.number_buffer[counter] = '\0';
    number.length = counter;
  } else {
    number.is_negative = false;
  }

  return number;
}

char *big_number_stringify(big_number_t number)
{
  char *str = (char *)calloc(BIG_NUMBER_LIMIT + 2, sizeof(char));
  int index = 0;

  if (number.is_negative == true)
  {
    str[index] = '-';
    ++index;
  }
  int i = 0;
  while (number.number_buffer[i] != '\0')
  {
    str[index] = number.number_buffer[i];
    ++i;
    ++index;
  }
  str[index] = '\0';

  return str;
}

/**
 * @info: Unoptimized implementation of adder function.
 * @status: Currently only supports positive numbers. 
 * @todo: Add functionality to handle addition of negative numbers.
 */
big_number_t big_number_add(big_number_t a, big_number_t b)
{
  big_number_t result = big_number_default();

  int i = a.length - 1;
  int j = b.length - 1;
  int rem = 0, t;
  size_t count = 0;

  char *num1 = a.number_buffer, *num2 = b.number_buffer;
  char *buf = result.number_buffer;

  while (i > -1 && j > -1)
  {
    t = (num1[i] - '0') + (num2[j] - '0') + rem;
    rem = t / 10;
    t = t % 10;

    buf[count] = t + '0';

    --i, --j;
    ++count;
  }

  while (i > -1)
  {
    t = (num1[i] - '0') + rem;
    rem = t / 10;
    t = t % 10;

    buf[count] = t + '0';
    --i, ++count;
  }

  while (j > -1)
  {
    t = (num2[j] - '0') + rem;
    rem = t / 10;
    t = t % 10;

    buf[count] = t + '0';
    --j, ++count;
  }

  if (rem)
  {
    buf[count] = rem + '0';
    ++count;
  }

  buf[count] = '\0';

  char temp;
  for (int i = 0; i < count / 2; ++i)
  {
    temp = buf[i];
    buf[i] = buf[count - i - 1];
    buf[count - i - 1] = temp;
  }

  return result;
}

/**
 * @todo: Implement the subtractor function for big numbers.
 */
big_number_t big_number_subtract(big_number_t a, big_number_t b);

int main()
{
  printf("Enter a = ");
  big_number_t a = big_number_read();

  printf("Enter b = ");
  big_number_t b = big_number_read();

  big_number_t result = big_number_add(a, b);

  char *a_string = big_number_stringify(a);
  char *b_string = big_number_stringify(b);
  char *result_string = big_number_stringify(result);

  printf("%s + %s = %s\n", a_string, b_string, result_string);

  free(a_string);
  free(b_string);
  free(result_string);

  return 0;
}

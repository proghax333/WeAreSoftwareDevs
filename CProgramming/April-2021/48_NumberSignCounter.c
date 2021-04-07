
/*
  Daily Problem #1:
  Write a program that takes n integers and stores them in an array. After taking the input, the program must print the number of negative integers, positive integers and the number of zeros in the array.
*/

#include <stdio.h>

// Takes inputs and saves them into the input array
int take_inputs(int *array, int n);

// Counts positive, negative and zero numbers in an array
int count_numbers(int *array, int n, int *number_count);

// Prints an array
int print_array(int *array, int n);

// Print the statistics
int print_statistics(int *number_count);

/****
 * MAIN DRIVER FUNCTION
 */
int main()
{
  int n;
  printf("Enter the number of inputs you want to give: ");
  scanf("%d", &n);

  int array[n];
  int number_count[3];

  take_inputs(array, n);

  printf("\nYou entered: \n");
  print_array(array, n);

  count_numbers(array, n, number_count);
  print_statistics(number_count);

  return 0;
}


/***
 * FUNCTION DEFINITIONS
 * These can be moved to separate source files
 */
int take_inputs(int *array, int n)
{
  for (int i = 0; i < n; ++i)
  {
    printf("Enter array[%d] = ", i);
    scanf("%d", &array[i]);
  }
  return n;
}

int count_numbers(int *array, int n, int *number_count)
{
  number_count[0] = number_count[1] = number_count[2] = 0;

  for (int i = 0; i < n; ++i)
  {
    if (array[i] > 0)
    {
      ++number_count[0];
    }
    else if (array[i] < 0)
    {
      ++number_count[1];
    }
    else
    {
      ++number_count[2];
    }
  }
  return n;
}

int print_array(int *array, int n)
{
  for(int i = 0; i < n; ++i)
  {
    printf("array[%d] = %d\n", i, array[i]);
  }
  return n;
}

int print_statistics(int *number_count)
{
  printf("\n\n[Statistics]\n");
  printf(
      "  Number of positive integers: %d\n"
      "  Number of negative integers: %d\n"
      "  Number of zeros: %d\n",
      number_count[0], number_count[1], number_count[2]);
  return 3;
}
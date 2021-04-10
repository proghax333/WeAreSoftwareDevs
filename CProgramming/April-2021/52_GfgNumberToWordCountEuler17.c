#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include <ctype.h>

#define MAXARRAY 1500
#define MAXNUM 1000

char buffer[MAXARRAY] = { 0 };

void lprintf(const char* format, ...)
{
  va_list args;
  va_start(args, format);
  vsprintf((&buffer[0]) + strlen(buffer), format, args);
}

int lpop()
{
  int count = 0;
  for(int i = 0; i < strlen(buffer); ++i)
  {
    if(isalpha(buffer[i]))
    {
      ++count;
    }
  }
  buffer[0] = 0;
  return count;
}

/* A function that prints given number in words */
void convert_to_words(char* num, char* output)
{
    int len = strlen(
        num); // Get number of digits in given number
    char* numstr = num;
 
    /* Base cases */
    if (len == 0) {
        fprintf(stderr, "empty string\n");
        return;
    }
    if (len > 4) {
        fprintf(stderr,
                "Length more than 4 is not supported\n");
        return;
    }

    int size = strlen(num);
 
    /* The first string is not used, it is to make
        array indexing simple */
    char* single_digits[]
        = { "zero", "one", "two",   "three", "four",
            "five", "six", "seven", "eight", "nine" };
 
    /* The first string is not used, it is to make
        array indexing simple */
    char* two_digits[]
        = { "",          "ten",      "eleven",  "twelve",
            "thirteen",  "fourteen", "fifteen", "sixteen",
            "seventeen", "eighteen", "nineteen" };
 
    /* The first two string are not used, they are to make
        array indexing simple*/
    char* tens_multiple[] = { "",       "",        "twenty",
                              "thirty", "forty",   "fifty",
                              "sixty",  "seventy", "eighty",
                              "ninety" };
 
    char* tens_power[] = { "hundred", "thousand" };
 
    /* For single digit number */
    if (len == 1) {
       lprintf("%s", single_digits[*num - '0']);
        return;
    }
 
    /* Iterate while num is not '\0' */
    while (*num != '\0') {
        /* Code path for first 2 digits */
        if (len >= 3) {
            if (*num - '0' != 0) {
               lprintf("%s ", single_digits[*num - '0']);
               lprintf("%s ",
                       tens_power[len - 3]); // here len can
                                             // be 3 or 4
            }
            --len;
        }
 
        /* Code path for last 2 digits */
        else {
            /* Need to explicitly handle 10-19. Sum of the
            two digits is used as index of "two_digits"
            array of strings */
            if (*num == '1') {
                int sum = *num - '0' + *(num + 1) - '0';
                if(size > 2)
                {
                  lprintf("and ");
                }
                lprintf("%s", two_digits[sum]);
                return;
            }
 
            /* Need to explicitely handle 20 */
            else if (*num == '2' && *(num + 1) == '0') {
              if(size > 2)
              {
               lprintf("and ");
              }
               lprintf("twenty");
                return;
            }
 
            /* Rest of the two digit numbers i.e., 21 to 99
             */
            else {
                int i = *num - '0';
                if(i)
                {
                  if(size > 2)
                  {
                   lprintf("and ");
                  }
                 lprintf("%s ", tens_multiple[i]);
                }
                ++num;
                if (*num != '0')
                {
                  if(numstr[1] == '0' && size > 2)
                  {
                    lprintf("and ");
                  }
                   lprintf("%s ",
                           single_digits[*num - '0']);
                }
            }
        }
        ++num;
    }
}

int main(int argc, char const *argv[])
{
    char arr[MAXARRAY], result[MAXARRAY];
    int sum=0, len;

    for (int i = 1; i <= MAXNUM; i++)
    {
      sprintf(arr, "%d", i);
      convert_to_words(arr, result);
      sum += lpop();
    }

    printf("%d\n", sum);

    return 0;
}

#include <stdio.h>

int main() {
  int number, t;

  printf("Enter the number which you want to convert to binary: ");
  scanf("%d", &number);

  int number_of_bytes = sizeof(number) * 8;
  
  printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
    (number >> 16) & 1,
    (number >> 15) & 1,
    (number >> 14) & 1,
    (number >> 13) & 1,
    (number >> 12) & 1,
    (number >> 11) & 1,
    (number >> 10) & 1,
    (number >> 9) & 1,
    (number >> 8) & 1,
    (number >> 7) & 1,
    (number >> 6) & 1,
    (number >> 5) & 1,
    (number >> 4) & 1,
    (number >> 3) & 1,
    (number >> 2) & 1,
    (number >> 1) & 1,
    (number >> 0) & 1);

  return 0;
}

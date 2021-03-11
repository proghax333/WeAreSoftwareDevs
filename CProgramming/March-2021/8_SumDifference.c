
#include <stdio.h>
#include <math.h>

int main() {
  int n = 10;

  long long int sum_of_squares = n * (n + 1) * (2 * n + 1) / 6,
    square_of_sum = pow(n * (n + 1) / 2, 2),
    difference = square_of_sum - sum_of_squares;

  printf("%lld", difference);
  
  return 0;
}

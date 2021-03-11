
#include <stdio.h>
#include <math.h>

int main() {
  int n = 100;

  long long sum_of_squares = n * (n + 1) * (2 * n + 1) / 6;
  long long square_of_sum = pow(n * (n + 1) / 2, 2);
  long long difference = abs(square_of_sum - sum_of_squares);

  printf("%lld", difference);
  
  return 0;
}

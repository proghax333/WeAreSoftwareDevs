
#include <stdio.h>

long long int factorial_helper(long long int n) {
  if(n == 2) {
    return 2;
  }
  return n * factorial_helper(n - 1);
}

long long int factorial(long long int n) {
  if(n == 0 || n == 1) {
    return 1;
  }
  return factorial_helper(n);
}

int main() {
  long long int n = 1, answer;

  printf("Enter n: ");
  scanf("%lld", &n);

  if(n >= 0) {
    answer = factorial(n);
    printf("Factorial is: %lld\n", answer);
  } else {
    printf("[ERROR] Enter positive numbers only.\n");
  }

    return 0;
}

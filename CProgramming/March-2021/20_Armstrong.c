
#include <stdio.h>

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  int t = n, sum = 0, p;

  while(t) {
    p = t % 10;
    sum += p * p * p;
    t /= 10;
  }

  if(sum == n) {
    printf("%d is an armstrong number.\n", n);
  } else {
    printf("%d is not an armstrong number.\n", n);
  }

  return 0;
}

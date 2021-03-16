
#include <stdio.h>

int reverse_number(int n) {
  int t = n, reversed = 0, r;
  while(t) {
    reversed = reversed * 10 + t % 10;
    t /= 10;
  }
  return reversed;
}

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  int reversed = reverse_number(n);

  if(n == reversed) {
    printf("%d is a palindromic number.\n", n);
  } else {
    printf("%d is not a palindromic number.\n", n);
  }

  return 0;
}

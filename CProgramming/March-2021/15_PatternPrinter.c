
#include <stdio.h>

int main() {
  int n;
  printf("Enter the size of the square: ");
  scanf("%d", &n);

  printf("* ");
  for(int i = 0; i < n - 2; ++i) {
    printf("* ");
  }
  printf("*\n");

  for(int i = 0; i < n - 2; ++i) {
    printf("* ");

    for(int j = 0; j < n - 2; ++j) {
      if(j == i || j == n - i - 3) {
        printf("* ");
      } else {
        printf("  ");
      }
    }

    printf("*\n");
  }
  printf("* ");
  for(int i = 0; i < n - 2; ++i) {
    printf("* ");
  }
  printf("*\n");

  return 0;
}

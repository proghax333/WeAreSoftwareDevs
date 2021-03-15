
#include <stdio.h>

/* Custom power function */
int power(int x, int y) {
  if(y == 0) return 1;
  if(y == 1) return x;
  
  int result = x;
  while(y != 1) {
    result *= x;
    y--;
  }
  return result;
}

int main() {
  int x, y;
  printf("Enter x: ");
  scanf("%d", &x);

  printf("Enter y: ");
  scanf("%d", &y);

  printf("pow(%d, %d) = %d\n", x, y, power(x, y));

  return 0;
}

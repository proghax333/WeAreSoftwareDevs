
#include <stdio.h>

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  
  int temp = n, binary = 0;
  
  binary += (temp % 10) * 1;
  temp /= 10;

  binary += (temp % 10) * 2;
  temp /= 10;
  
  binary += (temp % 10) * 4;
  temp /= 10;

  binary += (temp % 10) * 8;
  temp /= 10;

  binary += (temp % 10) * 16;
  temp /= 10;

  printf("%d = %d\n", n, binary);

  return 0;
}

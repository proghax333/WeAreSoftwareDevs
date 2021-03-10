
#include <stdio.h>

int main() {
  int n, t;

  printf("Enter a number: ");
  scanf("%d", &n);

  /*
    n is an integer. Size of n is 4 bytes.
    4 bytes = 4 * 8 bits = 32 bits.
    That's why an array of size (sizeof(n) * 8) is created
    to store each bit of binary number.
  */
  short arr[sizeof(n) * 8] = { 0 };
  t = n;
  
  int index = 0;
  while(t) {
    arr[index] = t % 2;
    t /= 2;
    index += 1;
  }

  for(int i = index - 1; i >= 0; --i) { 
    printf("%d", arr[i]);
  }
  printf("\n");

  return 0;
}

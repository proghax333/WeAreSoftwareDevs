
#include <stdio.h>

int main() {
  int n;

  printf("Enter a number between 1 to 10: ");
  scanf("%d", &n);

  switch(n) {
    case 1: printf("1\n");
    case 2: printf("2\n");
    case 3: printf("3\n");
    case 4: printf("4\n");
    case 5: printf("5\n");
    case 6: printf("6\n");
    case 7: printf("7\n");
    case 8: printf("8\n");
    case 9: printf("9\n");
    case 10: printf("10\n");
      break;
    default:
      printf("Invalid Number Entered!\n");
  }

  return 0;
}

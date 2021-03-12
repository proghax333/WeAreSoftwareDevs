
#include <stdio.h>

int main() {
  int a[3][3];
  int b[3][3];

  printf("Enter elements of 3x3 matrix A: ");
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter elements of 3x3 matrix B: ");
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      scanf("%d", &b[i][j]);
    }
  }

  int c[3][3];
  for(int i = 0; i < 3; ++i) {
    for(int k = 0; k < 3; ++k) {
      c[i][k] = 0;
      for(int j = 0; j < 3; ++j) {
        c[i][k] += a[i][j] * b[j][k];
      }
    }
  }

  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      printf("%d\t", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}

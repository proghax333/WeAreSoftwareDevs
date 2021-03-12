
#include <stdio.h>

int main() {
  int
    a11, a12, a13,
    a21, a22, a23,
    a31, a32, a33;
  
  int
    b11, b12, b13,
    b21, b22, b23,
    b31, b32, b33;

  printf("Enter elements of 3x3 matrix A: ");
  scanf("%d%d%d%d%d%d%d%d%d",
    &a11, &a12, &a13,
    &a21, &a22, &a23,
    &a31, &a32, &a33);
  
  printf("Enter elements of 3x3 matrix B: ");
  scanf("%d%d%d%d%d%d%d%d%d",
    &b11, &b12, &b13,
    &b21, &b22, &b23,
    &b31, &b32, &b33);
  

  int
    c11, c12, c13,
    c21, c22, c23,
    c31, c32, c33;

  c11 = a11 * b11 + a12 * b21 + a13 * b31;
  c12 = a11 * b12 + a12 * b22 + a13 * b32;
  c13 = a11 * b13 + a12 * b23 + a13 * b33;
  c21 = a21 * b11 + a22 * b21 + a23 * b31;
  c22 = a21 * b12 + a22 * b22 + a23 * b32;
  c23 = a21 * b13 + a22 * b23 + a23 * b33;
  c31 = a31 * b11 + a32 * b21 + a33 * b31;
  c32 = a31 * b12 + a32 * b22 + a33 * b32;
  c33 = a31 * b13 + a32 * b23 + a33 * b33;

  printf(
    "A x B = \n"
    "%d\t%d\t%d\n"
    "%d\t%d\t%d\n"
    "%d\t%d\t%d\n",
      c11, c12, c13,
      c21, c22, c23,
      c31, c32, c33);
  
  printf("\n");

  return 0;
}

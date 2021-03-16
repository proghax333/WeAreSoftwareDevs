
#include <stdio.h>

int main() {
  printf("[Sizes of inbuild data types]\n");

  printf(
    "Size of int: %d\n"
    "Size of float: %d\n"
    "Size of double: %d\n"
    "Size of char: %d\n"
      , sizeof(int), sizeof(float), sizeof(double), sizeof(char));

  return 0;
}

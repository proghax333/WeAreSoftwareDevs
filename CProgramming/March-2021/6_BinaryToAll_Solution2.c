
#include <stdio.h>

int main() {
  unsigned long long binary, size = sizeof(binary), index = 0;
  char c = 0;

  while(index < 64 && (c = getchar()) != '\n') {
    binary |= (c - '0') << (size - index);
    ++index;
  }
  unsigned long long number = binary >> (size - index + 1);

  printf(
    "Decimal: %lld\n"
    "Octal: %o\n"
    "Hexadecimal: %x\n"
    , number, number, number);

  return 0;
}

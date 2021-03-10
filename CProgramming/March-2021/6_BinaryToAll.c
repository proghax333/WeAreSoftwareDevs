
#include <stdio.h>

int main() {
  char bits[65] = { 0 };
  int index = 0;

  printf("Enter the number in binary form: ");
  while(index < 64 && (bits[index] = getchar()) != '\n') {
    ++index;
  }
  bits[index] = 0;
  
  unsigned long long number = 0;
  for(int i = 0; i < index; ++i)
    number += ((unsigned long long)1 << (index - i - 1)) * (bits[i] - '0');

  printf(
    "Binary: %s\n"
    "Decimal: %lld\n"
    "Octal: %o\n"
    "Hexadecimal: %x\n"
    , bits, number, number, number);

  return 0;
}
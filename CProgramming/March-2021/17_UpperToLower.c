
#include <stdio.h>
#include <ctype.h>

char lower(char ch) {
  if(isalpha(ch)) {
    return ch | (1 << 5);
  }
  return ch;
}

int main() {
  char letter;

  printf("Enter a letter: ");
  scanf("%c", &letter);
  
  if(isalpha(letter)) {
    char lowercase_letter = lower(letter);
    printf("The lowercase representation of the letter %c is %c.\n", letter, lowercase_letter);
  } else {
    printf("The character you entered is not a letter.\n");
  }

  return 0;
}

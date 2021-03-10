
#include <stdio.h>

int main() {
  int n;
  
  printf("Enter rupees(n): ");
  scanf("%d", &n);

  int one_rupee_notes = 0, two_rupee_notes = 0, five_rupee_notes = 0,
    ten_rupee_notes = 0, fifty_rupee_notes = 0, hundred_rupee_notes = 0;
  
  hundred_rupee_notes = n / 100;
  n %= 100;

  fifty_rupee_notes = n / 50;
  n %= 50;

  ten_rupee_notes = n / 10;
  n %= 10;

  five_rupee_notes = n / 5;
  n %= 5;

  two_rupee_notes = n / 2;
  n %= 2;

  one_rupee_notes = n;

  printf(
    "Hundred Rupee Notes: %d\n"
    "Fifty Rupee Notes: %d\n"
    "Ten Rupee Notes: %d\n"
    "Five Rupee Notes: %d\n"
    "Two Rupee Notes: %d\n"
    "One Rupee Notes: %d\n"
    , hundred_rupee_notes, fifty_rupee_notes, ten_rupee_notes
    , five_rupee_notes, two_rupee_notes, one_rupee_notes
  );

  return 0;
}

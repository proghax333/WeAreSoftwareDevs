
#include <stdio.h>

int main() {
  int a, b, c, d, e;
  const int min = 39, min_passed_subjects = 4;
  int subject_count = 0;

  printf("Enter marks of 5 subjects: \n");
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

  subject_count = (a > min) + (b > min) + (c > min) + (d > min) + (e > min);

  printf(subject_count >= min_passed_subjects ? "Passed\n" : "Failed\n");
  
  return 0;
}

#include <stdio.h>

int main() {
  const int min_marks = 39;
  const int min_passed_subjects = 4;

  int a, b, c, d, e;

  printf("Enter marks of 5 subjects: \n");
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

  int total_passed_subjects = 0;

  if(a > min_marks)
    ++total_passed_subjects;

  if(b > min_marks)
    ++total_passed_subjects;

  if(c > min_marks)
    ++total_passed_subjects;
  
  if(d > min_marks)
    ++total_passed_subjects;
  
  if(e > min_marks)
    ++total_passed_subjects;

  if(total_passed_subjects >= min_passed_subjects) {
    printf("Passed\n");
  } else {
    printf("Failed\n");
  }

  return 0;
}

#include <stdio.h>
#include <stdbool.h>

int main() {
  const int NUMBER_OF_SUBJECTS = 3;
  const int MIN_PER_SUBJECT_MARKS = 33;
  const int MIN_PASSING_PERCENTAGE = 40;
  
  float subject_marks[NUMBER_OF_SUBJECTS], total_marks = 0;
  bool isPass = true;

  for(int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
    printf("Enter the marks for subject %d: ", i + 1);
    scanf("%f", &subject_marks[i]);
  }

  for(int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
    if(subject_marks[i] >= MIN_PER_SUBJECT_MARKS) {
      total_marks += subject_marks[i];
    } else {
      isPass = false;
      break;
    }
  }
  isPass = isPass && (total_marks / NUMBER_OF_SUBJECTS) >= MIN_PASSING_PERCENTAGE;

  if(isPass) {
    printf("You Passed the exam!\n");
  } else {
    printf("You failed the exam!\n");
  }

  return 0;
}

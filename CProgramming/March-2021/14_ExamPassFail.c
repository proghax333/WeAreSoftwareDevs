
#include <stdio.h>
#include <stdbool.h>

int main() {
  /* Constants that are necessary for making decisions */
  const int NUMBER_OF_SUBJECTS = 3;
  const int MIN_PER_SUBJECT_MARKS = 33;
  const int MIN_PASSING_PERCENTAGE = 40;

  /* An array which stores the marks of all subjects */
  float subject_marks[NUMBER_OF_SUBJECTS];
  
  /* A variable for storing total marks */
  float total_marks = 0;

  /* A flag which tells whether the student is passed or not */
  bool isPass = true;

  /* Take the marks of all the subjects as input from the user */
  for(int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
    printf("Enter the marks for subject %d: ", i + 1);
    scanf("%f", &subject_marks[i]);
  }

  /* Calculate total and check the conditions for passing */
  for(int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
    if(subject_marks[i] >= MIN_PER_SUBJECT_MARKS) {
      total_marks += subject_marks[i];
    } else {
      isPass = false;
      break;
    }
  }

  /* Check whether total percentage is above minimum passing percentage */
  isPass = isPass && (total_marks / NUMBER_OF_SUBJECTS) >= MIN_PASSING_PERCENTAGE;

  /* Display the result whether the student is passed or failed */
  if(isPass) {
    printf("You Passed the exam!\n");
  } else {
    printf("You failed the exam!\n");
  }

  return 0;
}


#include <stdio.h>

int main()
{
  int marks;
  
  printf("Enter marks: ");
  scanf("%d", &marks);

  printf("\nYour marks are: %d\n", marks);

  if(marks >= 90)
  {
    printf("Grade is A+");
  }
  else if(marks >= 80)
  {
    printf("Grade is A");
  }
  else if(marks >= 70)
  {
    printf("Grade is B");
  }
  else if(marks >= 60)
  {
    printf("Grade is C");
  }
  else if(marks >= 50)
  {
    printf("Grade is D");
  }
  else
  {
    printf("Grade is F");
  }

  return 0;
}

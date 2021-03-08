
#include <stdio.h>

int main() {
  double max_carbon_content = 0.8;
  double min_hardness = 11.2;
  double min_tensile_strength = 14.8;

  double carbon_content, hardness, tensile_strength;
  
  printf("Enter Carbon Content: ");
  scanf("%lf", &carbon_content);

  printf("Enter Hardness: ");
  scanf("%lf", &hardness);

  printf("Enter Tensile Strength: ");
  scanf("%lf", &tensile_strength);

  int flags =
    (carbon_content < max_carbon_content) << 2 |
    (hardness > min_hardness) << 1 |
    (tensile_strength > min_tensile_strength) << 0;
  
  char grade;

  if(flags == 0b111) {
    grade = 'A';
  } else if(flags == 0b110) {
    grade = 'B';
  } else if(flags == 0b011) {
    grade = 'C';
  } else if(flags == 0b101) {
    grade = 'D';
  } else if(flags == 0b000) {
    grade = 'F';
  } else {
    grade = 'E';
  }

  printf("\nGrade of Steel Bar: %c\n", grade);

  return 0;
}
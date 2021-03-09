
#include <stdio.h>
#include <math.h>

int main()
{
  double a, b, c;

  printf("Enter a: ");
  scanf("%lf", &a);

  printf("Enter b: ");
  scanf("%lf", &b);

  printf("Enter c: ");
  scanf("%lf", &c);
  

  // For checking if the roots exist.
  // This will be reused in the quadratic formula
  double delta = b*b - 4*a*c;

  // 'a' cannot be zero. If it is, the equation will result undefined
  if(delta >= 0 && a != 0) {
    // The solution for equation exists
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);

    printf("x1 = %lf | x2 = %lf\n", x1, x2);
  } else {
    // The solution to the equation does not exist
    printf("The solution does not exist.\n");
  }
  
  return 0;
}

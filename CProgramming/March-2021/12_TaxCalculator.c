
#include <stdio.h>

int main() {
  const unsigned int lac = 100000;
  double income_amount, tax_percent = 0, total_tax;

  printf("Enter income amount: ");
  scanf("%lf", &income_amount);

  if(income_amount > (10 * lac)) {
    tax_percent = 5.0;
  } else if(income_amount > (5 * lac)) {
    tax_percent = 20.0;
  } else if(income_amount > (2.5 * lac)) {
    tax_percent = 30.0;
  }

  total_tax = income_amount * tax_percent / 100;

  printf("Total Income Tax to be paid: %lf\n", total_tax);

  return 0;
}

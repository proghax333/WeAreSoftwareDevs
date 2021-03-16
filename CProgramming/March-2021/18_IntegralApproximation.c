
#include <stdio.h>
#include <math.h>

typedef long double Number;
typedef long long int Integer;
typedef Number (*Function)(Number);

/* Implementation of Riemann sum for the approximation of definite integrals. */
Number RiemannSum(Function f, Number a, Number b, Number n)
{
  Number result = 0;
  Number xi, deltaX = (b - a) / n;

  for (Number i = 1; i <= n; ++i)
  {
    xi = a + i * deltaX;
    result += f(xi) * deltaX;
  }

  return result;
}

/* Implementation of Simpson's 3/8th rule for the approximation of definite integrals. */
Number SimpsonsThreeEight(Function f, Number a, Number b, Number n)
{
  Number result = 0, p, q, r, s;
  Number h = (b - a) / n;

  /* First Part */
  p = f(a);
  q = 0;
  r = 0;

  /* Second Part */
  for (Integer i = 1; i <= n - 1; ++i)
  {
    if (i % 3)
    {
      q += f(a + i * h);
    }
  }
  q *= 3;

  /* Third Part */
  for (Integer j = 1; j <= (Integer)n / 3 - 1; ++j)
  {
    r += f(a + 3 * j * h);
  }
  r *= 2;

  /* Fourth Part */
  s = f(b);

  result = 3 * (h / 8) * (p + q + r + s);
  return result;
}

/* Circle Function */
const Number radius = 2;
Number circle_function(Number x)
{
  return sqrt(radius * radius - x * x);
}

/* Square function */
Number square_function(Number x)
{
  return x * x;
}

int main()
{
  const Integer RIEMANN_ITERATIONS = 5000000;
  const Integer SIMPSON_THREE_EIGHT_ITERATIONS = 5000000;

  printf("\n*** Integral approximatation calculator ***\n\n");

  /* -------------- Riemann Sum --------------- */
  printf("[Testing Riemann Sum Approximation]\n");

  Function integrand = square_function;
  const Number a = 0, b = 2;

  Number riemann_approximation = RiemannSum(
      integrand,
      a, b,
      RIEMANN_ITERATIONS);
  printf("\tNumber of iterations for Riemann Sum: %ld\n", RIEMANN_ITERATIONS);
  printf("\tApproximation = %Lf\n\n", riemann_approximation);

  /* --------- Simpson's 3/8 Rule ------------- */
  printf("[Testing Simpson's 3/8 Rule Approximation]\n");

  Number simpson_three_eight_approximation = SimpsonsThreeEight(
      integrand,
      a, b,
      SIMPSON_THREE_EIGHT_ITERATIONS);

  printf("\tNumber of iterations for Simpson's 3/8 Rule: %ld\n", SIMPSON_THREE_EIGHT_ITERATIONS);
  printf("\tApproximation = %Lf\n\n", simpson_three_eight_approximation);
  return 0;
}

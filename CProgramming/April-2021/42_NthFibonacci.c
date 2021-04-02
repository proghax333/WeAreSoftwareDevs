
#include <stdio.h>

#define MAX 100

/* nth Fibonacci term calculator (with caching) */
long long int cache[MAX];
long long nth_fibonacci_cached(long long int n)
{
  if (n < 0)
  {
    return 0;
  }
  if (cache[n] >= 0)
  {
    return cache[n];
  }
  cache[n] = nth_fibonacci_cached(n - 1) + nth_fibonacci_cached(n - 2);
  return cache[n];
}

/* nth Fibonacci term calculator (without caching) */
long long nth_fibonacci(long long int n)
{
  if (n <= 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
}

void initialize_cache()
{
  /* Initialize Cache */
  for (int i = 0; i < MAX; ++i)
    cache[i] = -1;

  cache[0] = 0;
  cache[1] = 1;
}

int main()
{
  /* Initialize Cache */
  initialize_cache();

  /* The program begins here */
  long long n;

  printf("Enter n: ");
  scanf("%ld", &n);

  long long result_cached = nth_fibonacci_cached(n);
  printf("nth fibonacci number is = %ld (cache function)\n", result_cached);

  long long result = nth_fibonacci(n);
  printf("nth fibonacci number is = %ld (no cache function)\n", result);

  return 0;
}

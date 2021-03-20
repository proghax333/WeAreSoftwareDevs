#include <stdio.h>

int main()
{
    int m = 0, n = 0, prime_no = 1, i = 1;
    while (n < 10)
    {
        i = 1;
        m = 0;
        while (i <= prime_no)
        {
            if (prime_no % i == 0)
                m++;
            i++;
        }
        if (m == 2)
        {
            printf("%d ", prime_no);
            n++;
        }
        prime_no++;
    }
    return 0;
}
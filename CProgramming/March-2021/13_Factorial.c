
#include <stdio.h>

int main() {
    long long int n = 1;
    long long int fact = 1;

    printf("Enter n: ");
    scanf("%lld", &n);

    if(n >= 0) {
        for(long long int i = 2; i <= n; ++i) {
                fact *= i;
        }
        printf("Factorial is: %lld\n", fact);
    } else {
        printf("[ERROR] Enter positive numbers only.\n");
    }

    return 0;
}

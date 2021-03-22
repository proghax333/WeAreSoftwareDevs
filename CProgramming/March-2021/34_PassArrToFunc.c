
#include <stdio.h>

/* Passing multidimensional arrays to functions */
int matrix_add_elements(int m, int n, int matrix[m][n])
{
    int sum = 0;

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int main()
{
    int m = 3, n = 3;
    int matrix[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    int sum = matrix_add_elements(m, n, matrix);

    printf("Sum: %d\n", sum);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void makeMatrix(int n, int **matrix, int start)
{
    if (n % 2 == 0)
    {
        int num = n * n;
        for (int i = 0; i < n; i++)
        {
            matrix[start][start + i] = 2 * num;
            num--;
        }
        for (int i = 0; i < n - 1; i++)
        {
            matrix[start + 1 + i][start + n - 1] = 2 * num;
            num--;
        }
        for (int i = 0; i < n - 1; i++)
        {
            matrix[start + n - 1][start + n - 2 - i] = 2 * num;
            num--;
        }
        for (int i = 0; i < n - 2; i++)
        {
            matrix[start + n - 2 - i][start] = 2 * num;
            num--;
        }
        if (n == 2)
        {
            return;
        }
        n -= 2;
        makeMatrix(n, matrix, ++start);
    }
    else
    {
        int num = n * n;
        for (int i = 0; i < n; i++)
        {
            matrix[start + n - 1][start + n - 1 - i] = 2 * num;
            num--;
        }
        for (int i = 0; i < n - 1; i++)
        {
            matrix[start + n - 2 - i][start] = 2 * num;
            num--;
        }
        for (int i = 0; i < n - 1; i++)
        {
            matrix[start][start + 1 + i] = 2 * num;
            num--;
        }
        for (int i = 0; i < n - 2; i++)
        {
            matrix[start + 1 + i][start + n - 1] = 2 * num;
            num--;
        }
        if (n == 1)
        {
            return;
        }
        n -= 2;
        makeMatrix(n, matrix, ++start);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
    }
    makeMatrix(n, matrix, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if ((matrix[i][j] - matrix[i][j + 1] == 2) || (matrix[i][j] - matrix[i][j + 1] == -2) && j != n - 1)
            {
                printf("%-4d  -  ", matrix[i][j]);
            }
            else
            {
                printf("%-9d", matrix[i][j]);
            }
        }
        printf("\n");

        for (int j = 0; j < n; j++)
        {
            if ((matrix[i][j] - matrix[i + 1][j] == 2) || (matrix[i][j] - matrix[i + 1][j] == -2) && i != n - 1)
            {
                printf("|        ", matrix[i][j]);
            }
            else
            {
                printf("         ");
            }
        }
        printf("\n");
    }
    return 0;
}

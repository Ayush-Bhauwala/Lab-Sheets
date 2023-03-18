#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int n1, n2;
    int **rowA = (int **)malloc(m * sizeof(int *));
    int **rowB = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        rowA[i] = (int *)malloc(n * sizeof(int));
        rowB[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &rowA[i][j]);
            rowB[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                rowB[i][j] = rowA[i][j];
            }
            else
            {
                for (int k = 0; k <= i; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        rowB[i][j] += rowA[k][l];
                        if (l == j && k == i)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    int ri, ci, rh, ch;
    scanf("%d", &ri);
    scanf("%d", &ci);
    scanf("%d", &rh);
    scanf("%d", &ch);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", rowB[i][j]);
        }
        printf("\n");
    }
    if (ri + rh > m || ci + ch > n)
    {
        printf("NOT POSSIBLE");
    }
    for (int i = 0; i < rh; i++)
    {
        for (int j = 0; j < ch; j++)
        {
            sum += rowB[i + ri][j + ci];
        }
    }
    printf("%d", sum);
    return 0;
}
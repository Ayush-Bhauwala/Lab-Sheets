#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, p, q;
    scanf("%d", &m);
    scanf("%d", &n);
    int **rowA = (int **)malloc(m * sizeof(int *));
    int **rowB = (int **)malloc(p * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        rowA[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &rowA[i][j]);
        }
    }
    scanf("%d %d", &p, &q);
    for (int i = 0; i < p; i++)
    {
        rowB[i] = (int *)malloc(q * sizeof(int));
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &rowB[i][j]);
        }
    }

    int isSubMatrix = 0, rowMatches = 0, colMatches = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= n - q && i <= m - p)
            {
                int checkSubMatrix = 1;
                for (int k = 0; k < p; k++)
                {
                    for (int l = 0; l < q; l++)
                    {
                        if (rowA[i + k][j + l] != rowB[k][l])
                        {
                            checkSubMatrix = 0;
                        }
                    }
                }
                if (checkSubMatrix == 1)
                {
                    isSubMatrix = 1;
                }
            }
            if (j <= n - q && isSubMatrix == 0)
            {
                for (int k = 0; k < p; k++)
                {
                    int checkRowMatches = 1;
                    for (int l = 0; l < q; l++)
                    {
                        if (rowA[i][j + l] != rowB[k][l])
                        {
                            checkRowMatches = 0;
                        }
                    }
                    if (checkRowMatches == 1)
                    {
                        rowMatches = 1;
                        break;
                    }
                }
            }
            if (i <= m - p && isSubMatrix == 0)
            {
                int *colA = (int *)malloc(sizeof(int) * p);
                for (int k = 0; k < p; k++)
                {
                    colA[k] = rowA[i + k][j];
                }
                for (int l = 0; l < q; l++)
                {
                    int checkColMatches = 1;
                    for (int k = 0; k < p; k++)
                    {
                        if (rowB[k][l] != colA[k])
                        {
                            checkColMatches = 0;
                        }
                    }
                    if (checkColMatches == 1)
                    {
                        colMatches = 1;
                        break;
                    }
                }
            }
        }
    }
    if (isSubMatrix)
    {
        printf("YES\n");
    }
    else if (rowMatches == 1 || colMatches == 1)
    {
        printf("PARTIAL\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
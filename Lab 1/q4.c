#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < 0)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] > 0)
                {
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                    i--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
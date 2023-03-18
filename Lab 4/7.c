#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define int long long

int main()
{
    int n;
    scanf("%lld", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    printf("\n");
    int k = 0;
    while (max > 0)
    {
        k++;
        max /= 10;
    }
    for (int j = 0; j < k; j++)
    {
        int count[10] = {0};
        for (int i = 0; i < n; i++)
        {
            int dig = (a[i] % (int)pow(10, j + 1)) / pow(10, j);
            count[dig]++;
        }
        int *arr = (int *)malloc(sizeof(int) * n);
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int dig = (a[i] % (int)pow(10, j + 1)) / pow(10, j);
            arr[count[dig] - 1] = a[i];
            count[dig]--;
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = arr[i];
        }
        printf("\n");
    }
    return 0;
}
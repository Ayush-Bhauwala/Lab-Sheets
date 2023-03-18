#include <stdio.h>
#include <stdlib.h>
#define int long long

int main()
{
    int n, k, t;
    scanf("%lld %lld %lld", &n, &k, &t);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    for (int i = k - 1; i < n; i++)
    {
        if (i == k - 1 && a[i] >= t * k)
            count++;
        else if (a[i] - a[i - k] >= t * k)
            count++;
    }
    printf("%lld", count);
    return 0;
}
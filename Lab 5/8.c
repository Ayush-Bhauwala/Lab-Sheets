#include <stdio.h>
#include <stdlib.h>
#define int long long

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
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
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] % k;
    }
    int *freq = (int *)malloc(sizeof(int) * k);
    freq[0] = 1;
    for (int i = 1; i < k; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count += freq[a[i]];
        freq[a[i]]++;
    }
    printf("%lld", count);
    return 0;
}
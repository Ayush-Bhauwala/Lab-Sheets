#include <stdio.h>
#include <stdlib.h>
#define int long long

int trailingZeroes(int n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }
    return count;
}

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
    int maxZeroes = trailingZeroes(max);
    int *trailingZeroesCount = (int *)malloc(sizeof(int) * (maxZeroes + 1));
    for (int i = 0; i < maxZeroes + 1; i++)
    {
        trailingZeroesCount[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        trailingZeroesCount[trailingZeroes(a[i])]++;
    }
    int pairs = 0;
    for (int i = 0; i < maxZeroes + 1; i++)
    {
        if (trailingZeroesCount[i] > 1)
        {
            pairs += (trailingZeroesCount[i] * (trailingZeroesCount[i] - 1)) / 2;
        }
    }
    printf("\n%lld\n", pairs);
}
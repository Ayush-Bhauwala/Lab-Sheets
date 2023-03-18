#include <stdio.h>
#include <stdlib.h>
#define int long long

int nCr(int n)
{
    if (n == 1)
        return 0;
    return (n * (n - 1)) / 2;
}

int pairs(int *arr, int length)
{
    int pairs = 0;
    for (int i = 0; i < length; i++)
    {
        pairs += nCr(arr[i]);
    }
    return pairs;
}

int minAllies(int n, int m)
{
    int minPerBanquet = n / m;
    int rem = n % m;
    int *banquets = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        banquets[i] = minPerBanquet;
        if (rem > 0)
            banquets[i] += 1;
        rem--;
    }
    return pairs(banquets, m);
}
int maxAllies(int n, int m)
{
    int *banquets = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        banquets[i] = 1;
    }
    banquets[0] = n - m + 1;
    return pairs(banquets, m);
}
int main()
{
    int n, m;
    scanf("%lld %lld", &n, &m);
    int min = minAllies(n, m);
    int max = maxAllies(n, m);
    printf("\n%lld %lld", min, max);
    return 0;
}
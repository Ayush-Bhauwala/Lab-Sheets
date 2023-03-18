#include <stdio.h>
#include <stdlib.h>
#define int long long

int main()
{
    int n, q;
    scanf("%lld %lld", &n, &q);
    int *a = (int *)malloc(sizeof(int) * q);
    int *primes = (int *)malloc(sizeof(int) * (n + 1));
    primes[1] = 0;
    for (int j = 2; j < n + 1; j++)
    {
        primes[j] = 1;
    }
    for (int j = 2; j * j <= n; j++)
    {
        if (primes[j])
        {
            for (int k = j * j; k <= n; k += j)
            {
                primes[k] = 0;
            }
        }
    }
    for (int j = 3; j < n + 1; j++)
    {
        primes[j] += primes[j - 1];
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%lld", &a[i]);
        printf("%d ", primes[a[i]]);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define int long long

int xor (int *arr, int n) {
    int xor = 0;
    for (int i = 0; i < n; i++)
    {
        xor ^= arr[i];
    }
    return xor;
}

    int xorOfxor(int *a, int *b, int n, int m)
{
    int x1 = xor(a, n);
    int x2 = xor(b, m);

    int a1, a2;
    if (m % 2)
        a1 = x1;
    else
        a1 = 0;

    if (n % 2)
        a2 = x2;
    else
        a2 = 0;

    return a1 ^ a2;
}

int main()
{
    int n, m;
    scanf("%lld", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &m);
    int *b = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &b[i]);
    }
    int ans = xorOfxor(a, b, n, m);
    printf("%lld", ans);
    return 0;
}
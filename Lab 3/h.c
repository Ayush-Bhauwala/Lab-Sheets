#include <stdio.h>
#include <stdlib.h>
#define long unsigned long long

long sqroot(long low, long high, long n)
{
    long mid = (low + high) / 2;
    if (mid * mid > n)
    {
        return sqroot(low, mid, n);
    }
    else if ((mid + 1) * (mid + 1) <= n)
    {

        return sqroot(mid, high, n);
    }
    else
    {
        return mid;
    }
}

int main()
{
    long n;
    scanf("%lld", &n);
    printf("%lld", sqroot(1, n, n));
}
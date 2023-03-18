#include <stdio.h>
#define long long long

long halfWay(long low, long high, long n)
{
    long mid = (low + high) / 2;
    long num1 = (mid * n) - (mid * (mid + 1) / 2);
    long num2 = ((mid - 1) * n) - ((mid - 1) * (mid) / 2);

    if (num1 < (n * (n - 1)) / 4)
    {
        return halfWay(mid, high, n);
    }
    else if ((num1 >= (n * (n - 1)) / 4) && num2 <= (n * (n - 1)) / 4)
    {
        return mid;
    }
    else
    {
        return halfWay(low, mid, n);
    }
}

long main()
{
    long n;
    scanf("%lld", &n);
    printf("%lld", halfWay(1, n - 1, n));
    return 0;
}

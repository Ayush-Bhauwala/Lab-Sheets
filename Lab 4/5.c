#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define int long long

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    int a, b;
    scanf("%lld %lld", &a, &b);
    int num = sqrt(a);
    int i;
    int ans = 0;
    for (i = 1; i <= num; i++)
    {
        if (gcd(a / i, b) == 1)
        {
            if (a / i > ans & a % i == 0)
                ans = a / i;
        }
        if (gcd(i, b) == 1)
        {
            if (i > ans)
                ans = i;
        }
    }
    printf("\n%lld\n", ans);
    return 0;
}
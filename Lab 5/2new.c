#include <stdio.h>
#include <stdlib.h>
#define int long long

int kill(int n, int dir)
{
    if (n == 1)
        return 1;

    if (dir == -1 && n % 2 == 0)
        return (2 * kill(n / 2, -dir)) - 1;
    else
        return (2 * kill(n / 2, -dir));
}

int main()
{
    int n;
    scanf("%lld", &n);
    printf("%lld\n", kill(n, 1));
    return 0;
}
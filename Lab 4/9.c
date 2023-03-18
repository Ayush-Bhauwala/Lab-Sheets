#include <stdio.h>
#include <stdlib.h>
#define int long long

int main()
{
    int n;
    scanf("%lld", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int gcd = max;
    int index = 0;
    for (int i = max; i >= 1; i--)
    {
        int check = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % i != 0)
            {
                index = j;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (a[j] % i != 0 && index != j)
            {
                check = 1;
            }
        }
        if (!check)
        {
            gcd = i;
            break;
        }
    }
    printf("%d", gcd);
    return 0;
}
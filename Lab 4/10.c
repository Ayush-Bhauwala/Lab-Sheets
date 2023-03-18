#include <stdio.h>
#include <stdlib.h>
#define int long long

int main()
{
    int n;
    scanf("%lld", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    int each = sum / n;
    int op = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > each)
        {
            op += a[i] - each;
        }
        else if (a[i] < each)
        {
            op += each - a[i];
        }
    }
    printf("%lld\n", op);
    return 0;
}
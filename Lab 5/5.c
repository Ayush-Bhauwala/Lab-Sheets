#include <stdio.h>
#include <stdlib.h>
#define int long long

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int left = 0;
    int right = 0;
    int max = 0;
    int sum = 0;
    int zeroCount = 0;
    while (right < n)
    {
        while (zeroCount < k + 1 && right < n)
        {
            if (a[right] == 0)
                zeroCount++;
            right++;
        }
        if (zeroCount == k + 1)
            sum = right - left - 1;
        else
            sum = right - left;
        if (sum > max)
            max = sum;
        while (left <= right && zeroCount == k + 1)
        {
            if (a[left] == 0)
                zeroCount--;
            sum = right - left - 1;
            left++;
        }
    }
    printf("%lld", max);
    return 0;
}
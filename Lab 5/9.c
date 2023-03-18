#include <stdio.h>
#include <stdlib.h>
#define int long long

int atMost(int *arr, int length, int k)
{
    if (k == -1)
        return 0;
    int left = 0;
    int count = 0;
    for (int right = 0; right < length; right++)
    {
        k -= arr[right] % 2;
        while (k < 0)
        {
            k += arr[left] % 2;
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int subArrays = atMost(a, n, k) - atMost(a, n, k - 1);
    printf("%lld", subArrays);
    return 0;
}
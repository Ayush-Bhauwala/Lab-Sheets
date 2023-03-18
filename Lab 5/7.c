#include <stdio.h>
#include <stdlib.h>
#define int long long

int maxInArray(int *arr, int length)
{
    int max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void distribute(int n, int k, int *total, int curr, int *min, int *bucketList)
{
    if (curr == n)
    {
        int max = maxInArray(total, k);
        *min = max > *min ? *min : max;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            total[i] += bucketList[curr];
            distribute(n, k, total, curr + 1, min, bucketList);
            total[i] -= bucketList[curr];
        }
    }
}

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    int *a = (int *)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int *totalBuckets = (int *)malloc(sizeof(int) * k);
    int min = 100000000;
    distribute(n, k, totalBuckets, 0, &min, a);
    printf("%lld", min);
    return 0;
}
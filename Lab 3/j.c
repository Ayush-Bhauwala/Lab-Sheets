#include <stdio.h>
#include <stdlib.h>

int plankSize(int low, int high, int n, int k, int *arr)
{
    int mid = (low + high) / 2;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] / mid;
    }
    if (sum == k)
    {
        return mid;
    }
    else if (sum > k)
    {
        return plankSize(mid + 1, high, n, k, arr);
    }
    else
    {
        return plankSize(low, mid - 1, n, k, arr);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    if (sum >= k)
    {
        printf("%d", plankSize(1, max, n, k, arr));
    }
    else
    {
        printf("0");
    }
    return 0;
}
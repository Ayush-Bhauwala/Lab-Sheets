#include <stdio.h>
#include <stdlib.h>
#define int long

void diffColl(int low, int high, int *count, int *arr, int num, int length)
{
    int mid = (low + high) / 2;
    if (arr[mid] > num)
    {
        diffColl(low, mid - 1, count, arr, num, length);
    }
    else if (arr[mid] < num)
    {
        diffColl(mid + 1, high, count, arr, num, length);
    }
    else if (arr[mid] == num && (mid + 1 == length || arr[mid + 1] != num))
    {
        *count += 1;
        if (mid + 1 == length)
        {
            return;
        }
        else
        {
            diffColl(mid + 1, length - 1, count, arr, arr[mid + 1], length);
        }
    }
    else
    {
        diffColl(mid + 1, high, count, arr, num, length);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int count = 0;
    diffColl(0, n - 1, &count, a, a[0], n);
    printf("%d", count);
    return 0;
}
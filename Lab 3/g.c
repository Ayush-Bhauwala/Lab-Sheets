#include <stdio.h>
#include <stdlib.h>

int calcDeduction(int low, int high, int max, int *arr, int length)
{
    int mid = (low + high) / 2;
    if (max < arr[mid])
    {
        return calcDeduction(low, mid - 1, max, arr, length);
    }
    else if (max >= arr[mid + 1])
    {
        if (mid + 2 == length)
        {
            return arr[mid + 1];
        }
        return calcDeduction(mid + 1, high, max, arr, length);
    }
    else
    {
        return arr[mid];
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
    int ded = calcDeduction(0, n - 1, k, arr, n);
    printf("%d", ded);
    return 0;
}

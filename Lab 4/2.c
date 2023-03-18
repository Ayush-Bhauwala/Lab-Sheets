#include <stdio.h>
#include <stdlib.h>
#define int long long

void merge(int *arr, int l, int mid, int r)
{
    int n_l, n_r;
    n_l = mid - l + 1;
    n_r = r - mid;
    int *left = (int *)malloc(sizeof(int) * n_l);
    int *right = (int *)malloc(sizeof(int) * n_r);
    for (int i = 0; i < n_l; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n_r; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n_l && j < n_r)
    {
        if (left[i] > right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n_l)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n_r)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    scanf("%lld", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    int score = n;
    for (score = n; score >= 1; score--)
    {
        if (arr[score - 1] >= score)
            break;
    }

    printf("\n%lld\n", score);
    return 0;
}
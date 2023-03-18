#include <stdio.h>
#include <stdlib.h>
#define int long long
struct Slot_t
{
    int start;
    int end;
};
typedef struct Slot_t Slot;

void merge(Slot *arr, int l, int mid, int r)
{
    int n_l = mid - l + 1;
    int n_r = r - mid;
    Slot *left = (Slot *)malloc(sizeof(Slot) * n_l);
    Slot *right = (Slot *)malloc(sizeof(Slot) * n_r);
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
        if (left[i].start < right[j].start)
        {
            arr[k].start = left[i].start;
            arr[k].end = left[i].end;
            i++;
        }
        else
        {
            arr[k].start = right[j].start;
            arr[k].end = right[j].end;
            j++;
        }
        k++;
    }
    while (i < n_l)
    {
        arr[k].start = left[i].start;
        arr[k].end = left[i].end;
        i++;
        k++;
    }
    while (j < n_r)
    {
        arr[k].start = right[j].start;
        arr[k].end = right[j].end;
        j++;
        k++;
    }
}

void mergeSort(Slot *arr, int l, int r)
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
    Slot *arr = (Slot *)malloc(sizeof(Slot) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &arr[i].start, &arr[i].end);
    }
    mergeSort(arr, 0, n - 1);
    int k = 0;
    Slot *ans = (Slot *)malloc(sizeof(Slot) * 1);
    ans[0].start = arr[0].start;
    ans[0].end = arr[0].end;
    int length = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].start <= ans[k].end)
            ans[k].end = ans[k].end > arr[i].end ? ans[k].end : arr[i].end;

        else
        {
            k++;
            length++;
            ans = realloc(ans, sizeof(Slot) * 2);
            ans[k].start = arr[i].start;
            ans[k].end = arr[i].end;
        }
    }
    printf("\n%lld\n", length);
    for (int i = 0; i < length; i++)
    {
        printf("%lld %lld\n", ans[i].start, ans[i].end);
    }
    return 0;
}
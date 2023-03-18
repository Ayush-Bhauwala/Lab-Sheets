#include <stdio.h>
#include <stdlib.h>
#define int long long
void merge(int *indexes, int *cand, int l, int mid, int r)
{
    int n_l = mid - l + 1;
    int n_r = r - mid;
    int *left = (int *)malloc(sizeof(int) * n_l);
    int *right = (int *)malloc(sizeof(int) * n_r);
    int *left_ind = (int *)malloc(sizeof(int) * n_l);
    int *right_ind = (int *)malloc(sizeof(int) * n_r);
    for (int i = 0; i < n_l; i++)
    {
        left[i] = cand[l + i];
        left_ind[i] = indexes[l + i];
    }
    for (int i = 0; i < n_r; i++)
    {
        right[i] = cand[mid + 1 + i];
        right_ind[i] = indexes[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n_l && j < n_r)
    {
        if (left[i] > right[j])
        {
            cand[k] = left[i];
            indexes[k] = left_ind[i];
            i++;
        }
        else
        {
            cand[k] = right[j];
            indexes[k] = right_ind[j];
            j++;
        }
        k++;
    }
    while (i < n_l)
    {
        cand[k] = left[i];
        indexes[k] = left_ind[i];
        i++;
        k++;
    }
    while (j < n_r)
    {
        cand[k] = right[j];
        indexes[k] = right_ind[j];
        j++;
        k++;
    }
}
void mergeSort(int *indexes, int *cand, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(indexes, cand, l, mid);
        mergeSort(indexes, cand, mid + 1, r);
        merge(indexes, cand, l, mid, r);
    }
}

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    int *a = (int *)malloc(sizeof(int) * n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    int *cand = (int *)malloc(sizeof(int) * (max));
    for (int i = 0; i < max; i++)
    {
        cand[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cand[a[i] - 1]++;
    }
    int *indexes = (int *)malloc(sizeof(int) * (max));

    for (int i = 0; i < max; i++)
    {
        indexes[i] = i + 1;
    }
    mergeSort(indexes, cand, 0, max - 1);
    // bubble sort
    //  for (int i = 0; i < max; i++)
    //  {
    //      for (int j = 0; j < max - i - 1; j++)
    //      {
    //          if (cand[j] < cand[j + 1])
    //          {
    //              int temp1 = indexes[j];
    //              indexes[j] = indexes[j + 1];
    //              indexes[j + 1] = temp1;
    //              int temp2 = cand[j];
    //              cand[j] = cand[j + 1];
    //              cand[j + 1] = temp2;
    //          }
    //      }
    //  }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", indexes[i]);
    }
    return 0;
}
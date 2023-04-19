#include <iostream>

using namespace std;

void merge(int a[], int l, int r, int mid, int *ctr)
{

    int count = 0;
    int n_l = mid - l + 1;
    int n_r = r - mid;
    int left[n_l];
    int right[n_r];
    for (int i = 0; i < n_l; i++)
    {
        left[i] = a[l + i];
    }
    for (int i = 0; i < n_r; i++)
    {
        right[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n_l && j < n_r)
    {
        if (left[i] < right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
            count += (n_l - i);
        }
        k++;
    }
    while (i < n_l)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n_r)
    {
        a[k] = right[j];
        j++;
        k++;
    }
    (*ctr) += count;
}

void mergeSort(int a[], int l, int r, int *ctr)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid, ctr);
        mergeSort(a, mid + 1, r, ctr);
        merge(a, l, r, mid, ctr);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;

    mergeSort(arr, 0, n - 1, &count);
    cout << count;
    return 0;
}
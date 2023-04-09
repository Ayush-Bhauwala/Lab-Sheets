#include <iostream>

using namespace std;

void merge(int a[], int l, int r, int mid)
{
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
    int i = 0;
    int j = 0;
    int k = l;
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
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, r, mid);
    }
}

int binarySearch(int left, int right, int k, int a[], int i)
{
    // if (start > end)
    // {
    //     return -1;
    // }

    // int mid = (start + end) / 2;
    // if (a[mid] - a[i] < k)
    // {
    //     return binarySearch(mid, end, k, a, i);
    // }
    // else if (a[mid - 1] - a[i] < k)
    // {
    //     return mid;
    // }
    // else
    // {
    //     return binarySearch(start, mid, k, a, i);
    // }
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;
    if (a[mid] - a[i] < k)
    {
        return binarySearch(mid + 1, right, k, a, i);
    }
    else if (a[mid - 1] - a[i] >= k)
    {
        return binarySearch(left, mid - 1, k, a, i);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);

    // check sorting
    // cout << "\nAfter sorting: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << "\n";

    int startIndex = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int index = binarySearch(startIndex + 1, n - 1, k, a, i);
        if (index != -1)
        {
            startIndex = index;
            count++;
        }
    }
    cout << count;
    return 0;
}
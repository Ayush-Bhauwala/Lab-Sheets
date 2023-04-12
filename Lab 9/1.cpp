// WRONG
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
        if (left[i] > right[j])
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

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    int sum = 0;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

void merge(string a[], int l, int mid, int r)
{
    int n_l = mid - l + 1;
    int n_r = r - mid;
    string left[n_l];
    string right[n_r];
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
        if (left[i].compare(right[j]) > 0)
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

void mergeSort(string a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}
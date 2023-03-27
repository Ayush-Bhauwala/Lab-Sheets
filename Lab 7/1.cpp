#include <iostream>
#include <cmath>

using namespace std;

void heapify_up(int *arr, int index, int *a)
{
    int p = (index - 1) / 2;
    if (p < 0)
        return;
    if (a[arr[index]] > a[arr[p]])
    {
        int temp = arr[index];
        arr[index] = arr[p];
        arr[p] = temp;
        heapify_up(arr, p, a);
    }
}

void heapify_down(int *arr, int index, int length, int *a)
{
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
    int largest = 0;
    if (left < length)
    {
        largest = left;
        if (a[arr[left]] > a[arr[right]] && right < length)
            largest = left;
        else if (right < length)
            largest = right;
    }
    else
        return;

    if (a[arr[largest]] > a[arr[index]])
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        heapify_down(arr, largest, length, a);
    }
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int *a = (int *)malloc(sizeof(int) * n);
    int *a_copy = (int *)malloc(sizeof(int) * n);
    int *maxHeap = (int *)malloc(sizeof(int) * n);
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a_copy[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        maxHeap[length] = i;
        length += 1;
        heapify_up(maxHeap, length - 1, a_copy);
    }
    int *count = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        count[maxHeap[0]]++;
        a_copy[maxHeap[0]] /= 2;
        heapify_down(maxHeap, 0, length, a_copy);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[maxHeap[i]] / pow(2, count[maxHeap[i]]);
    }
    cout << sum;
    return 0;
}
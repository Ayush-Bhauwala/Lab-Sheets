#include <iostream>
using namespace std;

void heapify_up(int *arr, int index)
{
    int p = (index - 1) / 2;
    if (p < 0)
        return;
    if (arr[index] > arr[p])
    {
        int temp = arr[index];
        arr[index] = arr[p];
        arr[p] = temp;
        heapify_up(arr, p);
    }
}

void heapify_down(int *arr, int index, int length)
{
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
    int largest = 0;
    if (left < length)
    {
        largest = left;
        if (arr[left] > arr[right] && right < length)
            largest = left;
        else if (right < length)
            largest = right;
    }
    else
        return;

    if (arr[largest] > arr[index])
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        heapify_down(arr, largest, length);
    }
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int *a = (int *)malloc(sizeof(int) * n);
    int *maxHeap = (int *)malloc(sizeof(int) * n);
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        maxHeap[length] = a[i];
        length += 1;
        heapify_up(maxHeap, length - 1);
    }
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        int given = (maxHeap[0] / 2);
        maxHeap[0] /= 2;
        heapify_down(maxHeap, 0, length);
    }
    cout << count;
    return 0;
}